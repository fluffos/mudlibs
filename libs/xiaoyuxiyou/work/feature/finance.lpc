          // finance.c
// mon 12/31/96

// can_afford() checks if this_object() can afford a price, it returns:
//
//      0:      cannot afford.
//      1:      can afford with proper money(coins).
//      2:      can afford, but don't have enough proper money(coins).
//
int can_afford(int amount)
{
	if( this_object()->check_pay(amount) )
		return 1;
	else	return 0;	
}

int pay_money(int amount)
{
	object me = this_object();
	if( amount<=0 )
		return 0;
	if( !me->check_pay(amount) )
		return 0;
	me->money_add(-amount);		
        me->save();
        return 1;
}


