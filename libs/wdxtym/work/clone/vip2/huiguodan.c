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
    set_name(HIY"悔过丹"NOR, ({ "huiguodan" }) );
    set_weight(1);
            set("no_put", 1);
            set("xy_money", 100);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	       
            set("no_put", 1);
	     set("icon", "05006");
            set("no_steal", 1);
            set("no_beg", 1);
            set("no_pawn", 1);
            set("value", 800000000);
            set("treasure",1);
            set("unit", "颗");
            set("material", "paper");
            set("long", "清除叛师记录！！\n");
          }

    setup();
}

int do_eat(string arg)
{
        object me = this_player();
 	if (!id(arg))
	return notify_fail("你要吃什么？\n");
else 
{
me->set("betrayer",0);
message_vision(HIG"道祖见$N这么可怜，随手一挥你的叛师次数清零啦。\n"NOR, this_player());
}
	destruct(this_object());
	return 1;
}