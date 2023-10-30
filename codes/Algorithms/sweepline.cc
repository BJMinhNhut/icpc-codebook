int n;
int cnt[N * 4] , nodes[N * 4];

void Update(int l ,int r ,int id , int u , int v ,int w)
{
    if(l > v || r < u || l > r || u > v)
    {
        return ;
    }
    if(u <= l && r <= v)
    {
        nodes[id] += w;
        return ;
    }
    int mid = (l+r) >> 1;
    Update(l , mid , id <<1 , u , v ,w);
    Update(mid+1 , r , id << 1 |1 , u , v , w);
    int L = (nodes[id << 1] > 0 )? mid - l +1 : cnt[id << 1];
    int R = (nodes[id << 1 |1] > 0) ? r - mid : cnt[id << 1 |1];
    cnt[id] = L + R;
}


struct Rectangles
{
    int x , y , u , v;
    Rectangles(int _x ,int _y ,int _u ,int _v)
    {
        x = -x;
        y = _y;
        u = _u;
        v = _v;
    }
    Rectangles()
    {

    }
}a[N];
struct Events
{
    int l , r;
    Events(int _l ,int _r)
    {
        l = _l;
        r = _r;
    }
};
vector<Events>add[N]  ,del[N];

void Input()
{
    cin >> n;
    for(int i = 1; i <= n ; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].u >> a[i].v;
        a[i].x++;
        a[i].y++;
    }
    for(int i = 1; i <= n ; i++)
    {
        if(a[i].x > a[i].u || a[i].y > a[i].v)continue;
        add[a[i].x].push_back(Events(a[i].y , a[i].v));
        if(a[i].u + 1 != N)
            del[a[i].u+1].push_back(Events(a[i].y , a[i].v));
    }
}

void Process()
{
    long long res = 0;
    for(int i = 0 ; i <= N-1 ; i++)
    {
        foreach(Events &e in add[i])
        {
            Update(1 , N-1 , 1 , e.l , e.r , 1);
        }
        foreach(Events &e in del[i])
        {
            Update(1 , N-1 , 1 , e.l , e.r , -1);
        }
        res +=  (nodes[1] > 0 )? N-1 : cnt[1];
    }
    cout << res;
}