struct Nodes
{
    ll cnt = 0;
    ll val = 0;
    ll lazy = 0;
};

ll sum(int l ,int r)
{
    return r *1LL *(r+1)/2LL - l * 1LL *(l-1)/2LL;
}
struct SegmentedTree
{
        vector<Nodes>nodes;
        SegmentedTree(int _n)
        {
            nodes.resize(_n * 4+ 1);
        }

        void Build(int l, int r, int id)
        {
            if(l == r)
            {
                nodes[id].val = a[l];
                return ;
            }
            int mid = (l+r) >> 1;
            Build(l , mid , id << 1);
            Build(mid+1 , r , id << 1 |1);

            nodes[id].val = nodes[id << 1].val + nodes[id << 1 |1].val;
        }

        void Down(int id ,int l, int r , ll cnt , ll lazy)
        {
            ll total = sum(l , r) * 1LL * cnt;
            total -= lazy *(r - l + 1);
            nodes[id].val += total;
            nodes[id].cnt += cnt;
            nodes[id].lazy += lazy;
        }

        void Update(int l, int r ,int id , int u ,int v)
        {
            if(l > v || u > r)
            {
                return ;
            }
            if(u <= l && r <= v)
            {
                nodes[id].lazy += u -1 ;
                nodes[id].val += sum(l , r) - (u-1) * 1LL * (r- l + 1) ;
                nodes[id].cnt++;
                return ;
            }
            int mid = (l+r) >> 1;
            Down(id << 1 , l , mid , nodes[id].cnt , nodes[id].lazy);
            Down(id << 1 |1 , mid+1 , r , nodes[id].cnt , nodes[id].lazy);
            nodes[id].cnt = 0;
            nodes[id].lazy = 0;
            Update(l , mid ,id << 1 , u , v);
            Update(mid+1 , r , id << 1 |1 , u ,v);

            nodes[id].val = nodes[id << 1].val + nodes[id << 1 |1].val;
        }

        ll Get(int l ,int r ,int id , int u ,int v)
        {
            if(l > v || u > r)
            {
                return 0;
            }
            if(u <= l && r <= v)
            {
                return nodes[id].val;
            }
            int mid = (l+r) >> 1;
            Down(id << 1 , l , mid , nodes[id].cnt , nodes[id].lazy);
            Down(id << 1 |1 , mid+1 , r , nodes[id].cnt , nodes[id].lazy);
            nodes[id].cnt = 0;
            nodes[id].lazy = 0;

            return Get(l , mid ,id << 1 , u , v ) + Get(mid+1 , r , id << 1 |1 , u , v);
        }
};