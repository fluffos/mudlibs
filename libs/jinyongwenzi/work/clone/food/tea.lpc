// tea1.c

#include <ansi.h>

inherit ITEM;

void init()
{
     add_action("do_drink", "drink");
}


void create()
{
	set_name(HIW "金顶毛峰" NOR, ({"maofeng", "tea"}));
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是积峨嵋山金顶之日月灵气所制的极品茶。\n");
		set("unit", "杯");
		set("value", 10000);
               }
             }

int do_drink(string arg)
{
//	int i,lvl=1;
//	mapping skills;
//	string *sk;
	object me = this_player();
	if (!living(me)) return notify_fail("想当机吗？\n");
	if (!id(arg)) return 0;
	message_vision(HIG "$N品了一口"
	+this_object()->query("name")+
	HIG "，顿时觉得精神为之一振。\n"
	NOR,me);
        me->set("jing", me->query("max_jing"));
        me->set("water", me->max_water_capacity());
       	destruct(this_object());
	return 1;
}
