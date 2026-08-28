/*
 * MONEY SUPPORT FUNCTIONS (/secure/money)
 *
 */

#pragma strict_types

#define MONEY_LOG "/log/money"


int money;

/* function prototypes */

varargs int pay(object to, int amount, int l_exchange);

/*
 *   pay(object to, int amount, void | int limited_exchange)
 * 
 *  Pays amount of money in bmus to another object. 
 *  If limited_exchange is 1, target object has limited amount of
 *  money to give in exchange. 
 * 
 *  Return codes:              0   -   not enough money
 *                             1   -   transfer succesful
 *                             2   -   not enough exchange
 * 
 *  Coder                   Dazzt
 *
 * */

int coin_sort(mixed a, mixed b)
{
//	dump_variable(a);
	if (a[0] > b[0])
		return 1;
	if (a[0] < b[0])
		return -1;
	return 0;
}
		

int pay(object to, int amount, int l_exchange)
{
	string *base_coins = ({ "gold", "silver", "bronze", "copper" });
	mixed coins, inv;         /* coins in inventory */
	mixed paid, exchange;     /* list of money movement */
	object ob;
	string s;
	int i, sz, x, val, left;
	
	inv = all_inventory(THOB);
	
	coins = ({ });
	for (i = 0, sz = sizeof(inv); i < sz; i++)
		if (inv[i]->is_money())
			coins += ({ ({ inv[i]->query_bmuvalue(), inv[i] }) });
	
	coins = sort_array(coins, "coin_sort", THOB);
	
	left = amount;      	i = 0;
	paid = ({ });           sz = sizeof(coins);

	while (left > 0 && i < sz)
	{
		x = coins[i][1]->query_amount();
		val = coins[i][0];
		if ((left - x * val) >= 0)
			left -= x * val;
		else
		{
			x = left / val + 1;
			left -= x * val;
		}
		paid += ({ ({ coins[i][1], x })	});
		i++;
	}
	
	if (left > 0)                              /* not enough money */
		return 0;

	if (left < 0)                              /* need exchange */
	{
		if (!l_exchange)
		{
			i = 0;
			exchange = ({});
			while (left < 0 && i < sizeof(base_coins))
			{
				val = call_other("/obj/money/" + base_coins[i], "query_bmuvalue");
				exchange += ({ ({ "/obj/money/" + base_coins[i], 0 }) });
				while ((left + val) <= 0)
				{
					exchange[i][1] += 1;
					left += val;
				}
				if (left == 0)
					break;
				i++;
			}
		}
	}
	
	for (i = 0; i < sizeof(paid); i++)         /* pay money */
	{
		s = file_name(paid[i][0]);
		sscanf(s, "%s#%*s", s);
		ob = clone_object(s);
		ob->set_amount(paid[i][1]);
		ob->move(to);
		paid[i][0]->add_amount(-paid[i][1]);
	}
	
	for (i = 0; i < sizeof(exchange); i++)     /* get change back */
	{
		if (exchange[i][1] != 0)
		{
			ob = clone_object(exchange[i][0]);
			ob->set_amount(exchange[i][1]);
			ob->move(THOB);
		}
	}

	return 1;
}

/*
 *       int query_money()
 * 
 *    Returns the amount object possesses, in copper
 * 
 *    Coder                                    Dazzt
 * */

int
query_money ()
{
	object *inv;
	int i, sz, amount;
	
	inv = all_inventory(THOB);
	for (i = 0, sz = sizeof(inv); i < sz; i++)
		if (inv[i]->is_money())
			amount += inv[i]->query_value();
	
    return amount;
}


int add_money(int amount)
{
	string *base_coins = ({ "gold", "silver", "copper" });
	mixed coins, inv;         /* coins in inventory */
	mixed paid;               /* list of money movement */
	object ob;
	int i, sz, val, left;
	
	if (amount < 0)
		return pay(find_object("/obj/money_pool"), -amount, 0);
	
	inv = all_inventory(THOB);
	
//	i = call_other("/obj/money/" + base_coins[3], "query_bmuvalue");
//	amount = amount * i;
	
	coins = ({ });
	for (i = 0, sz = sizeof(inv); i < sz; i++)
		if (inv[i]->is_money())
			coins += ({ ({ inv[i]->query_bmuvalue(), inv[i] }) });
	
	coins = sort_array(coins, "coin_sort", THOB);
	
	paid = ({});
	left = amount;
	i = 0;

	while (left > 0 && i < sizeof(base_coins))
	{
		val = call_other("/obj/money/" + base_coins[i], "query_bmuvalue");
		if (val == 0)
			val = 1;
		paid += ({ ({ "/obj/money/" + base_coins[i], 0 }) });
		while ((left - val) >= 0)
		{
			paid[i][1] += 1;
			left -= val;
		}
		if (left <= 0)
			break;
		i++;
	}
	
	for (i = 0; i < sizeof(paid); i++)         /* pay money */
	{
		if (paid[i][1] > 0)
		{
			ob = clone_object(paid[i][0]);
			ob->set_amount(paid[i][1]);
			ob->move(THOB);
		}
	}
	return amount;
}
	
