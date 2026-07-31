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
	set_name(YEL"葡萄干[绑]"NOR, ({"putaogan"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("yuanbao", 10);
            set("no_sell",1);
		set("unit", "颗");
		set("no_sell",1);
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1);
		set("base_unit", "颗");
		set("base_weight", 10);
		set("base_value", 100);
		set("long","这是一颗巫师亲自晒干的"YEL"葡萄干"NOR"。\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
int exp2;
      if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		    return notify_fail("正在战斗中，不能使用"+ name() +"。\n");
    exp2=1400+random(201);
    me->add("experience",exp2);
	me->add("potential",exp2);
	write(YEL"你吃下一颗"YEL"葡萄干"YEL"潜能与实战体会增加了"+exp2+"!"NOR"\n");
	add_amount(-1);
	return 1;
}