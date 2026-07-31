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
	set_name(YEL"首赞血丹"NOR, ({"sou xue"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("yuanbao", 10);
            set("no_sell",1);
			set("no_sell",1);
			set("no_give",1);
		 set("no_get", 1);
        set("no_drop", 1);
		set("no_shop", 1);//下架
        set("no_give", 1);
		set("unit", "颗");
		set("base_unit", "颗");
		set("base_weight", 10);
		set("base_value", 100);
		set("long","这是一颗加5000气血的丹药"NOR"。\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	me->add("gain/max_qi",5000);
	write(YEL"你增加了5000点气血!"NOR"\n");
	add_amount(-1);
	return 1;
}