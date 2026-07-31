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
	set_name(YEL"稚终转世补偿减一"NOR, ({"zzzsbc"}));
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
	
	me->add("gain/max_qi",(1+(me->query("zhuanshi")-1))/2*(me->query("zhuanshi")-1)*500);
	me->add("gain/damage",(1+(me->query("zhuanshi")-1))/2*(me->query("zhuanshi")-1)*25);
	me->add("max_neili",(1+(me->query("zhuanshi")-1))/2*(me->query("zhuanshi")-1)*100);
	me->add("max_jingli",(1+(me->query("zhuanshi")-1))/2*(me->query("zhuanshi")-1)*100);
	me->add("str",(1+(me->query("zhuanshi")-1))/2*(me->query("zhuanshi")-1))*2;
	me->add("int",(1+(me->query("zhuanshi")-1))/2*(me->query("zhuanshi")-1))*2;
	me->add("dex",(1+(me->query("zhuanshi")-1))/2*(me->query("zhuanshi")-1))*2;
	me->add("con",(1+(me->query("zhuanshi")-1))/2*(me->query("zhuanshi")-1))*2;
	write(YEL"你获得转世补偿!"NOR"\n");
	add_amount(-1);
	return 1;
}