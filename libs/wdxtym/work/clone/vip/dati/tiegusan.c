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
	set_name(HIW"铁骨散"NOR, ({"tie gusan"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("no_sell", 1);set("base_value", 100);
		set("dajif", 5);    
				set("base_unit", "颗");
				set("unit", "颗");
		set("base_weight", 1);
		set("no_give", 1);
		set("no_put", 1);
		set("no_sell", 1);
		set("no_steal", 1);
		set("only_do_effect", 1);
		set("long","这是一颗铁骨散，"ZJURL("cmds:eat tie gusan")ZJSIZE(22)"服用"NOR"之后能增加1w肉身系数！注：可以连续服用。\n");
	}
	setup();
}

int do_effect(object me)
{
	object ob1;
        int times;

	me->add("bpoint", 10000);

    message_vision(me->query("name")+"服下一颗"HIM"铁骨散"NOR"，顿觉肉身强大不少！"NOR"\n",me);
	add_amount(-1);
	return 1;
}

//int query_autoload() { return 1; }