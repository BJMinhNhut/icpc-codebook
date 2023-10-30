int n , sub_size[N] , up[N][LOG] , depth[N] , Num[N] ,chain[N] , chainHead[N] , chainId ,  cnt = 0 , ar[N];
vector<pair<int,int >>vertices[N];
int U[N],V[N];

void DFS(int u ,int daddy)
{
    sub_size[u] = 1;
    foreach(pair<int ,int > adj in vertices[u])
    {
        int v = adj.first;
        if(v == daddy)
        {
            continue;
        }
        up[v][0] = u;
        depth[v] = depth[u] + 1;
        for(int j = 1 ; j < LOG ; j++)
        {
            up[v][j] = up[up[v][j-1]][j-1];
        }
        DFS(v , u );
        
        sub_size[u] += sub_size[v];
    }
}

int LCA(int a , int b)
{
    if(depth[a] < depth[b])
    {
        swap(a , b);
    }
    int k = depth[a] - depth[b];
    for(int j = LOG - 1 ; j >= 0 ; j--)
    {
        if(k& (1 << j))
        {
            a = up[a][j];
        }
    }
    if(a == b)
    {
        return a;
    }
    for(int j = LOG - 1;  j>= 0 ; j--)
    {
        if(up[a][j] != up[b][j])
        {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}

void Build_HLD(int u ,int daddy)
{
    Num[u] = cnt++;
    chain[u] = chainId;
    int BigChild = -1;
    int BigSize  = -1;
    int BigEdge = -1;
    foreach(pair<int ,int > adj in vertices[u])
    {
        int v = adj.first;
        if(v == daddy)
        {
            continue;
        }
        int w = adj.second;
        if(sub_size[v] > BigSize)
        {
            BigChild = v;
            BigSize = sub_size[v];
            BigEdge = w;
        }
    }
    if(BigChild != -1)
    {
        ar[cnt] = BigEdge;
        Build_HLD(BigChild, u );
    }
    for(pair<int ,int >adj in vertices[u])
    {
        int v = adj.first , w  = adj.second;
        if(v == daddy || v == BigChild)
        {
            continue;
        }
        chainId++;
        chainHead[chainId] = v;
        ar[cnt] = w;
        Build_HLD(v , u);
    }
}