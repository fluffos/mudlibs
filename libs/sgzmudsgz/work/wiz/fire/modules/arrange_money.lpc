// arrange_money.c by fire on Dec.12 1997
// this function is used to query the amount of 
// a kind of money in a container (include human)
#include <sanguo.h>
void set_con_money(string type, int num)
{
	mixed contents;
	object ob;
	object ob_money;
	mixed ss;
	int i;
	int money_num;
	int find_money;
	int tmp;
	find_money=0;
	money_num=0;
	
	contents = all_inventory(this_object());
	i = sizeof(contents);
	while(i)
	{	i=i-1;
		ob=contents[i];
		ss=ob->query_id();
            	if(member_array(type, ss) != -1)
		{
			if (find_money)
			{
				destruct(ob);
			}
			else
			{
				find_money=1;
				ob_money=ob;
			}
		}
	}
	if(find_money)
	{
		if(num>0)
		{
			ob_money->set_m_num(num);
		}
		else
		{
			destruct(ob_money);
		}
	}
	else
	{
		if(num>0)
		{
			switch(type)
			{
				case "coin" :
					ob_money=new(M_COIN);
					break;
				case "silver" :
					ob_money=new(M_SILVER);
					break;
				case "gold" :
					ob_money=new(M_GOLD);
					break;
				default :
					ob_money=new(M_COIN);
					break;
			}
			ob_money->set_m_num(num);
			ob_money->move(this_object());
		}
	}
}
int query_con_money(string type)
{
	mixed contents;
	object ob;
	object ob_money;
	mixed ss;
	int i,j;
	int money_num;
	int find_money;
	int tmp;
	find_money=0;
	money_num=0;
	contents = all_inventory(this_object());
	j = sizeof(contents);
	i=0;
	while(i<j)
	{	
		ob=contents[i];
		i=i+1;
		ss=ob->query_id();
            	if(member_array(type, ss) != -1)
		{
			if (find_money)
			{
				tmp=ob->query_m_num();
				money_num=money_num+tmp;
				destruct(ob);
			}
			else
			{
				find_money=1;
				money_num=ob->query_m_num();
				ob_money=ob;
			}
		}
	}
	if(find_money)
	{
		if(money_num>0)
		{
			ob_money->set_m_num(money_num);
		}
		else
		{
			money_num=0;
			destruct(ob_money);
		}
	}
	return money_num;
}
	
// this is used to get a quick arrange of a container's money
void arrange_money()
{
	query_con_money("coin");
	query_con_money("silver");
	query_con_money("gold");
}		
int query_all_con_money()
{
	int p_coin,p_silver,p_gold;
	p_coin=query_con_money("coin");
	p_silver=query_con_money("silver");
	p_gold=query_con_money("gold");
	return p_coin+100*p_silver+10000*p_gold;
}
void set_all_con_money(int num)
{
	int p_coin,p_silver,p_gold;
	p_gold = num/10000;
        p_silver = (num%10000)/100;
        p_coin = num%10000%100;
	set_con_money("coin", p_coin);
	set_con_money("silver", p_silver);
	set_con_money("gold", p_gold);
}
