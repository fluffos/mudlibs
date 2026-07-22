#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIC"身法珠"NOR, ({ "jobzhu4" }) );
    set_weight(1);
            set("no_put", 1);
            set("value", 0);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	       
            set("no_put", 1);
            set("no_steal", 1);
            set("no_get", 1);
            set("no_beg", 1);
            set("value", 0);
            set("unit", "颗");
            set("material", "paper");
            set("long", "神珠之一。\n");
          }

    setup();
}
void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("你要吃什么？\n");

  	me->add("combat_exp", 2000);
	me->add("potential",1000);        
	me->add("max_neili",50);
        message_vision(HIG "$N吃把珠吃了下去，只觉得全身舒服了不少!\n" NOR, me);
	
	destruct(this_object());
	return 1;
}