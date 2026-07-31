 // finance.c
// abandoned by Tie
// can_afford() checks if this_object() can afford a price, it returns:
//
//      0:      cannot afford.
//      1:      can afford with proper money(coins).
//      2:      can afford, but don't have enough proper money(coins).
//
int can_afford(int amount)
{
        int total;
        object cash, tencash, gold, silver, coin; 
        tencash = present("tenthousand-cash_money");
        cash = present("thousand-cash_money");  
        gold = present("gold_money");
        silver = present("silver_money");
        coin = present("coin_money"); 
        total = 0;
        if( tencash) total += tencash->value();
        if( cash) total += cash->value();
        if( gold ) total += gold->value();
        if( silver ) total += silver->value();
        if( coin ) total += coin->value(); 
        if( total < amount ) return 0; 
        return 1;
} 
int pay_all(int amount)
{
        int total;
        object cash, tencash, gold, silver, coin;
        string debug;
        tencash = present("tenthousand-cash_money");
        cash = present("thousand-cash_money");
        gold = present("gold_money");
        silver = present("silver_money");
        coin = present("coin_money");
        total = 0;
        if( tencash) total += tencash->value();
        debug = sprintf("tencash is %d\n", total);
        write(debug);
        if( cash) total += cash->value();
        debug = sprintf("cash is %d\n", total);
        write(debug);
        if( gold ) total += gold->value();
        debug = sprintf("gold is %d\n", total);
        write(debug);
        if( silver ) total += silver->value();
        debug = sprintf("silver is %d\n", total);
        write(debug);
        if( coin ) total += coin->value();
        debug = sprintf("coin is %d\n", total);
        write(debug);
        debug = sprintf("total is %d, amount is %d, and change is %d",
                        total, amount, total-amount);
        write(debug);
        return total-amount;
}    
