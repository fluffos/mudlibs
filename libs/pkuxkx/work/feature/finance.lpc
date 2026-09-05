// finance.c

// can_afford() checks if this_object() can afford a price, it returns:
//
//	0:	cannot afford.
//	1:	can afford with proper money(coins).
//	2: 	can afford, but don't have enough proper money(coins).
//
int can_afford(int amount)
{
	int total;
	object cash,gold, silver, coin;
    cash = present("cash_money",this_object());
	gold = present("gold_money",this_object());
	silver = present("silver_money",this_object());
	coin = present("coin_money",this_object());

	total = 0;
    if( cash ) total += cash->value();
	if( gold ) total += gold->value();
	if( silver ) total += silver->value();
	if( coin ) total += coin->value();

	if( total < amount ) return 0;
        return 1;
        
	/*if( coin ) amount -= (int)coin->value();
	if( amount <= 0 ) return 1;
	else if( amount % 100 ) return 2;

	if( silver ) amount -= (int)silver->value();
	if( amount <= 0 ) return 1;
	else if( amount % 10000 ) return 2;

	return 1;*/
}

int pay_money(int amount)
{
	int total;
	object cash, gold, silver, coin;
	int ncash,ngold,nsilver,ncoin;
   	cash = present("cash_money",this_object());
	gold = present("gold_money",this_object());
	silver = present("silver_money",this_object());
	coin = present("coin_money",this_object());
	total = 0;
	if( cash ) total += cash->value();
	if( gold ) total += gold->value();
	if( silver ) total += silver->value();
	if( coin ) total += coin->value();

	if( total < amount ) return 0;


	if(cash)
	destruct(cash);
	if(gold)
	destruct(gold);
	if(silver)
	destruct(silver);
	if(coin)
	destruct(coin);
	total-=amount;
        ncash=total/100000;

        ngold=(total-ncash*100000)/10000;
        nsilver=(total-ncash*100000-ngold*10000)/100;
        ncoin=(total-ncash*100000-ngold*10000-nsilver*100);
        if(ncash != 0)
    {
        cash=new(CASH_OB);
        cash->set_amount(ncash);
        cash->move(this_object());
    }
        if(ngold!=0) {
        gold=new(GOLD_OB);
        gold->set_amount(ngold);
        gold->move(this_object());
}
	if(nsilver!=0) {
        silver=new(SILVER_OB);
        silver->set_amount(nsilver);
        silver->move(this_object());
}
	if(ncoin!=0) {
        coin=new(COIN_OB);
        coin->set_amount(ncoin);
        coin->move(this_object());
        }
	return 1;
	
}

