#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	seteuid(geteuid(me));
	return 1;
}

void change_to_money(object player,object npc)
{
	object lp;
	string banghui;
	mixed *inv;
	int i,money,money_old;
	if(! npc|| userp(npc))	return;
	if( ! (banghui=npc->query("banghui")))	return;
	inv=all_inventory(player);
	if(! sizeof(inv))	{
		return;
	}
	money=0;
	for(i=0;i<sizeof(inv);i++)	{
		if(inv[i]->query("money_id"))	{
			money +=inv[i]->value();
			destruct(inv[i]);
		}
//		else if( inv[i]->query("base_value"))	{
//			money += inv[i]->query_amount()*
//				 inv[i]->query("base_value");
//			destruct(inv[i]);
//		}
		else if( inv[i]->query("value") && inv[i]->query("value")<20000)	{
			money += inv[i]->query("value");
			destruct(inv[i]);
		}
	}
	lp=new("/obj/lingpai");
	lp->create(banghui);
	if(lp->query("no_use"))	{
		destruct(lp);
		return;
	}
	money_old=lp->query("npc_money");
	if(! intp(money_old))	money_old=0;

	money+=money_old;
	lp->set("npc_money",money);
	lp->save();
	destruct(lp);
}

void save_money(object me,int much)
{
	string banghui;
	object area;
	int money_old=0;
	if(! (banghui=me->query("banghui")))	return;
	if(much<=0)	return;
	if(! me->query("area_name"))	return;
	area=new("/obj/area");
	area->create(me->query("area_name"));
	money_old=area->query("money");
	if(! intp(money_old))	money_old=0;
	money_old+=much;
	area->set("money",money_old);
	area->save();
	destruct(area);
	return;
}


