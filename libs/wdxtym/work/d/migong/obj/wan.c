#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
        set_name(HIG"九花玉露丸"NOR, ({"jiuhuayulu wan", "jiuhua wan", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一颗晶莹碧绿的九花玉露丸，经桃花岛主精心练制，
有起死回生之功。\n");
                set("value", 500000);
        }
        setup();
}

int do_eat(string arg)
{
        int fw;
        object me = this_player();

	if (!id(arg))  return notify_fail("你要吃什么？\n");
        if(me->is_busy())
        return notify_fail("你现在正忙。\n");
	
                fw = (int)me->max_food_capacity();
                me->set("food", fw);
                fw = (int)me->max_water_capacity();
                me->set("water", fw);
		me->set("jing",me->query("max_jing"));
		me->set("qi",me->query("max_qi"));
		me->set("eff_jing",me->query("max_jing"));
		me->set("eff_qi",me->query("max_qi"));
		me->set("neili",me->query("max_neili"));
me->start_busy(5);
message_vision(HIG"$N吃下一颗九花玉露丸，一股清新凉爽从丹田升起，向全身扩散！\n"NOR,me);
		
        	destruct(this_object());
	return 1;
}

