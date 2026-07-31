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
	set_name(YEL"葡萄干"NOR, ({"putaogan"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("yuanbao", 10);
            set("no_sell",1);
		set("unit", "颗");
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
	players[i]->set("wenda",1);
    me->add("experience",exp2);
	CHANNEL_D->do_channel(this_object(), "chat", HIY"十年生死两茫茫"+ZJURL("cmds:wenda "+"不思量，自难忘 "+"1497163455!")ZJSIZE(15)+"回答"NOR"");
	me->add("potential",exp2);
	write(YEL"你吃下一颗"YEL"葡萄干"YEL"潜能与实战体会增加了"+exp2+"!"NOR"\n");
	add_amount(-1);
	return 1;
}