
#include <ansi.h>


inherit ITEM;

void create()

{
	set_name(HIG "龙丹" NOR, ({ "dan", "long dan", "longdan" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一颗老龙的内丹。\n");
                set("value", 10000);
		set("unit", "颗");
	}
}


void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me;

        if (! id(arg))
                return notify_fail("你要吃什么？\n");

        
me = this_player();
        message_vision("$N服下一颗龙丹" + this_object()->name() +
                       "。\n", me);
        if (random(20) > 11)
        {
                message_vision("$N只觉内力似乎增强了。\n", me);
                me->add("max_neili", 1);
 
        } else
        if (random(20) < 9)
        {
               message_vision("$N只觉精力旺盛。\n", me);

      me->add("max_jingli", 1);
   } else
        {
                      message_vision("$N什么感觉也没有。\n", me);                }

              destruct(this_object());
	return 1;
}
