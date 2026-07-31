// OBJECT:/d/suzhou/npc/obj/horse.c
//by dwolf
//97.11.4 

#include <ansi.h>
inherit ITEM;
void setup()
{}

void init()
{
        add_action("do_ride", "ride");
}

void create()
{
        set_name(BLK"军马"NOR, ({"horse", "jun ma", "ma"}));
        set_weight(45000);
        set_max_encumbrance(50000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "匹");
                set("long", "一匹良种的军马，可以骑(ride)，也可以驮东西。\n");
                set("value", 1000);
        }
}

int do_ride(string arg)
{
	object me = this_player();
        if (!id(arg))
                return notify_fail("你要骑什么？\n");
        if (this_player()->query_temp("marks/骑") ) {
                       write(RED"你已经骑在马上了。\n"NOR);
                        return 1;
        }
        else {
               message("vision",this_player()->name() + "翻身上马。\n",
                        environment(me), ({me}) );
               write(YEL"你战战兢兢爬上马背。还好，别人没看出来。\n"NOR);
                this_player()->set_temp("marks/骑", 1);
        return 1;
        }
}
