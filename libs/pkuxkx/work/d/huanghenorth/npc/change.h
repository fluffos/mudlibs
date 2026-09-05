int change(int i,object me)
{
    int gold,silver,coin;
    object j,y,t;
    gold=0;
    silver=0;
    coin=0;
    while (i>=10000)
    {
        i=i-10000;
        gold=gold+1;
    }
    while (i>=100)
    {
        i=i-100;
        silver=silver+1;
    }
    coin=i;
    if (gold)
    {
        (j=new("/clone/money/gold"))->set_amount(gold);
    }
    if (silver)
    {
    
        (y=new("/clone/money/silver"))->set_amount(silver);
       
    }
    if (coin)
    {
        (t=new("/clone/money/coin"))->set_amount(coin);
    }
    if (j)
    {
        j->move(me);
    }
    if (y)
    {
        y->move(me);
    }
    if (t)
    {
        t->move(me);
    }
    tell_object(me,"老艄公把零钱找还给你。\n");
    return 1;
    
}
