//  ghc 勾魂草
//  created by zine 26 Aug 2010
inherit ITEM;
#include <ansi.h>

void setup()
{}

void init()
{
        add_action("do_fu", "fu");
}

void create()
{
        set_name(BLU"勾魂草"NOR, ({"gouhun cao", "cao"}));
        if (clonep())
			set_default_object(__FILE__);
        else 
			{
				set("unit", "棵");
                set("long", "这是一颗勾魂草，传说中剧毒的东西。\n");
                set("value", 1);
                set("no_drop", 1);
                set("no_give",1);
                set("no_put",1);
			}
        setup();
}

int do_fu(string arg)
{	
	object me;
    me = this_player();
    if (!id(arg))
		{
			return notify_fail("你要吃什么？\n");
		}
	else 
		{
			me->set_temp("xiangyang/xxpass",1);
			me->add("jing", -500);
			me->add("qi", 500);
			message_vision(HIG"$N吞下一颗勾魂草。\n"NOR, this_player());
			message_vision(HIG"$N觉得药性甚是奇怪，精神萎靡，气息却更加充盈。\n"NOR, this_player());
			me->start_busy(2);
			destruct(this_object());
            return 1;
        }
}
