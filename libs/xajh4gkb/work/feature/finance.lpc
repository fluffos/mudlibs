// finance.c
// can_afford() checks if this_object() can afford a price, it returns:
//
//      0:      cannot afford.
//      1:      can afford with proper money(coins).
//

int can_afford_old(int amount)
{
    int total;
    object gold, silver, coin;
    gold = present("gold_money",this_player());
    silver = present("silver_money",this_player());
    coin = present("coin_money",this_player());
    total = 0;
    if( gold ) total += gold->value();
    if( silver ) total += silver->value();
    if( coin ) total += coin->value();
    if( total < amount ) return 0;
    return 1;
}
int pay_money_old(int amount)
{
    int total;
    object gold, silver, coin;

    gold = present("gold_money",this_player());
    silver = present("silver_money",this_player());
    coin = present("coin_money",this_player());
    total = 0;
    if( gold ) {
	total += gold->value();
	destruct(gold);
    }
    if( silver ) {
	total += silver->value();
	destruct(silver);
    }
    if( coin ) {
	total += coin->value();
	destruct(coin);
    }
    if( total < amount ) return 0;
    total-=amount;
    if( total > 10000 ) {
	gold=new(GOLD_OB);
	if (!gold->move(this_player())) gold->move(environment(this_player()));
	gold->set_amount(total/10000);
	total %= 10000;
    }
    if( total > 100 ) {
	silver=new(SILVER_OB);
	if (!silver->move(this_player())) silver->move(environment(this_player()));
	silver->set_amount(total/100);
	total %= 100;
    }
    if( total > 0 ){
	coin=new(COIN_OB);
	if (!coin->move(this_player())) coin->move(environment(this_player()));
	coin->set_amount(total);
    }
}
int can_afford(int amount)
{
    int money1,money2;
    int amount1,amount2;
    object player = this_player();
    money1 = player->query("money");
    money2 = player->query("more_money");
    amount1=amount%100000000;
    amount2=amount/100000000;
    if(amount2>money2)
	return 0;
    if(amount2<money2)
	return 1;
    if(amount1 > money1)
	return 0;
    return 1;
}
int pay_money(int amount)
{
    int amount1,amount2;
    int money1,money2;
    object player = this_player();
    amount1=amount%100000000;
    amount2=amount/100000000;
    money1 = player->query("money");
    money2 = player->query("more_money");
    if(amount1>money1)
    {
	money1+=100000000;
	money2--;
    }
    money1 -= amount1;
    money2 -= amount2;
    if(money1<0)
	money1=0;
    if(money2<0)
	money2=0;
    player->set("money",money1);
    player->set("more_money",money2);
    player->save();
    return 1;
}
