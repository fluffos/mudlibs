#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIY"江湖小报"NOR, ({ "newspaper" }) );
    set_weight(1);
           set("base_value", 99);
           set("value", 99);
            set("unit", "张");
            set("material", "paper");
            set("long", "新出的江湖小报，记载了各种江湖信息。\n");
    if( clonep() )
            set_default_object(__FILE__);
    else {
	       
           set("base_value", 99);
           set("value", 99);
            set("unit", "张");
            set("material", "paper");
            set("long", "新出的江湖小报，记载了各种江湖信息。\n");
          }

    setup();
}
void init()
{
	add_action("do_eat", "kan");
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("你要看什么？\n");

        message_vision( "$N拿出了江湖小报，看了一下，对最近发生的江湖事有了了解!\n", me);
	me->set_temp("istask",1);
	destruct(this_object());
	return 1;
}