#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "围墙");
        set("long", @LONG
这是山庄的围墙，大约有三丈多高，笔直的向左右两边延伸着，把整个
山庄围了起来，墙的那边就是山庄的后山，
LONG );
        set("outdoors", "yandang");
        set("exits", ([ /* sizeof() == 2 */
            "south" :__DIR__"yueliangmen",
        ]));
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_jump", "jump");
}
int do_jump(string arg)
{
        int n;
        object weapon,me=this_player();
        if (arg != "wall") return 0;
        message_vision(CYN
"$N凝神提气，纵身向围墙上一跃！\n"NOR,me);

        if (me->query_skill("dodge") < 100)
        {
               message_vision(CYN
"结果只听啪叽一声，$N仰大八叉的摔到地上，眼前金星直冒....\n"NOR,me);
               me->set("neili",0);
               me->unconcious();
               return 1;
        }
        message_vision(CYN
"$N只听风带衣袂，嗖的一声，$N轻飘飘的跃过了围墙！\n"NOR,me);
        me->move(__DIR__"shanlu");        me->add("neili",-200);
        
        return 1;
}

