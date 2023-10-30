class ASSJOINTSET
{
    public:
        vector<int>lab;
        vector<multiset<int>>s;
 
        ASSJOINTSET(int _n)
        {
            lab.assign(_n+1 , -1);
            s.resize(_n+1 );
        }
        int Find(int u)
        {
            return (lab[u] < 0 ) ? u : lab[u ] = Find(lab[u]);
        }
 
        bool Join(int u ,int v ,int w)
        {
            u = Find(u);
            v = Find(v);
            if(u == v)
            {
                return false;
            }
            if(lab[u] > lab[v])
            {
                swap( u , v);
            }
            lab[u] += lab[v];
            lab[v] = u;
            vector<int>erase;
            foreach(int t in s[v])
            {
                if(s[u].count(t))
                {
                    erase.push_back(t);
                    Maximize(ans[t] , w);
                }else s[u].insert(t);
            }
            foreach(int x in erase)
            {
                s[u].erase(x);
            }
            s[v].clear();
            return true;
        }
};