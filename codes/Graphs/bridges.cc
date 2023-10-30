struct Edges
{
    int u , v;
    bool is_used = false;
    bool is_bridge = false;
    Edges(int _u ,int _v)
    {
        u = _u;
        v = _v;
    }
};
vector<Edges>edge;
vector<int>vertices[N];
int Num[N] , Low[N] ,cnt = 0;
int NumChild[N];
bool IsCut[N];
void Tarjan(int u)
{
    Low[u] = Num[u] = ++cnt;
    for(int i =  0 ; i<= (int)vertices[u].size()-1 ; i++)
    {
        int id = vertices[u][i];
        if(edge[id].is_used)continue;
        edge[id].is_used = true;
        int v = edge[id].v ^ edge[id].u  ^ u;
        if(Num[v])Minimize(Low[u] , Num[v]);
        else
        {
            Tarjan(v);
            Minimize(Low[u] , Low[v]);
            edge[id].is_bridge |= Low[v] > Num[u];
            NumChild[u]++;
            IsCut[u] |= Low[v] >= Num[u];
        }
    }
}


for(int i = 1; i <= n ;i++)
{
    if(Num[i] == 0)
    {
        Tarjan(i);
        if(NumChild[i] == 1)IsCut[i] = false;
    }
}
int ans = 0;
for(int  i = 1 ; i <= n ;i++)
{
    ans += IsCut[i];
}
cout << ans << ' '; // Khớp
ans = 0;
for(int i = 0 ; i <= (int)edge.size()-1 ; i++)
{
    ans += edge[i].is_bridge;
}

cout << ans; // Cầu