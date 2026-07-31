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
	set_name(YEL"正常稚终转世补偿"NOR, ({"zczzzsbc"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("base_value", 100000000);
            set("no_sell",1);
			set("no_sell",1);
			set("no_give",1);
		 set("no_get", 1);
        set("no_drop", 1);
        set("no_give", 1);
		set("unit", "颗");
		set("base_unit", "颗");
		set("base_weight", 10);
		set("long","这是一颗稚终转世补偿的丹药"NOR"。\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	int zhuans;
	zhuans = me->query("zhuanshi");
	
	me->add("gain/max_qi",(1+zhuans)/2*zhuans*500);
	me->add("gain/damage",(1+zhuans)/2*zhuans*25);
	me->add("max_neili",(1+zhuans)/2*zhuans*25);
	me->add("max_jingli",(1+zhuans)/2*zhuans*100);
	me->add("str",(1+zhuans)*zhuans);
	me->add("int",(1+zhuans)*zhuans);
	me->add("dex",(1+zhuans)*zhuans);
	me->add("con",(1+zhuans)*zhuans);
	write(YEL"你获得转世补偿!"NOR"\n");
	add_amount(-1);
	return 1;
}