int n  , rmq[N][LOG] , lg[N] , q;

int Get_Min(int l ,int r)
{
    int o = lg[r - l +1];
    return min(rmq[l][o] , rmq[r - (1 << o) +1][o]);
}
void Input()
{
    cin >> n;
    for(int i =1;  i <= n ; i++)
    {
        while((1 << lg[i]) <= i) lg[i]++;
        lg[i]--;
    }

    for(int i = 1; i <= n ; i++)
    {
        cin >> rmq[i][0];
    }
    cin >> q;
    for(int j = 1 ; j < LOG ; j++)
    {
        for(int i = 1; i <= n ; i++)
        {
            if(i + (1 << j)-1 > n) break;
            rmq[i][j] = rmq[i][j-1];
            Minimize(rmq[i][j] , rmq[i+ (1 << (j-1))][j-1]);
        }
    }
}

void Process()
{
    while(q--)
    {
        int l ,r;
        cin >> l >> r;
        cout << Get_Min(l , r) <<'\n';
    }
}