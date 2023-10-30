void Update(int x)
{
    for(;x <= n ; x += x &-x)
    {
        BIT[x]++;
    }
}

int Get(int x , int total)
{
    x--;
    int mask = 0;
    int sum = 0;
    for(int i = 21 ; i >= 0 ; i--)
    {
        int new_mask  = mask | (1 << i);
        
        if(new_mask > n)
        {
            continue;
        }
        if(sum + BIT[new_mask] <= x)
        {
            mask = new_mask;
            sum += BIT[new_mask];
        }
    }
    return mask + 1;
}