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
	set_name("补偿礼包",({"buchang box"}));
	if( clonep() )
		set_default_object(__FILE__);
	else
       {
	     set("long","补偿礼包！！！!\n");
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
	object gift;
	
	gift = new("/u/cx/luck/daputao"); 
	gift->set_amount(3);
	tell_object(me, "你打开补偿礼包，发现了" + gift->short() + "。\n");
	gift->move(me);
	add_amount(-1);
	return 1;
}
