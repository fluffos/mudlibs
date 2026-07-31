#include <ansi.h>

inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}

void create()
{
	set_name("新手套装",({"buchang box"}));
	if( clonep() )
		set_default_object(__FILE__);
	else
       {
	     set("long","装备礼包！！！!\n");
		set("no_sell",1);
		set("no_put", 1);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_steal", 1);
		set("unit", "个");
		set("base_unit", "个");
		set("base_weight", 10);
		set("base_value", 100);
		set("only_do_effect", 1);
	}
	setup();
}


int do_effect(object me)
{
	object gift,gift1,gift2,gift3,gift4,gift5;
	
	gift = new("/clone/suit/new1/new_sword"); 	
	gift1 = new("/clone/suit/new1/new_pants"); 
	gift2 = new("/clone/suit/new1/new_hands"); 
	gift3 = new("/clone/suit/new1/new_boots"); 
	gift4 = new("/clone/suit/new1/new_blade"); 
	gift5 = new("/clone/suit/new1/new_cloth"); 
	gift->set_amount(1);
	gift1->set_amount(1);
	gift2->set_amount(1);
	gift3->set_amount(1);
	gift4->set_amount(1);
	gift5->set_amount(1);
	tell_object(me, "你打开新人装备，发现了套装。\n");
	gift->move(me);
	gift1->move(me);
	gift2->move(me);
	gift3->move(me);
	gift4->move(me);
	gift5->move(me);
	add_amount(-1);
	return 1;
}
