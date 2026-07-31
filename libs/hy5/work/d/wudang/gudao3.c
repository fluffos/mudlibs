// /d/wudang/gudao3.c  古道

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIG"古道"NOR);
        set("long", @LONG
你走走停停，发现已到了路的尽头。这里凌空突出，长满青草，几只野兔
在你身边跳来跳去毫不怕生，下面十多丈深有一水潭，潭水清澈。你正满身臭
汗饥渴难当，恨不得马上跳下去凉快一番。
LONG                           
        );
        set("exits", ([
              "southup" : __DIR__"gudao2",
        ]));

        set("objects",([        
                __DIR__"npc/yetu" : 2,
        ]));

        setup();

}

void init()
{
        add_action("do_jump","tiao");
}

int do_jump(string arg)
{       object me,tmp;
        me=this_player();
        if ( !arg || arg != "down" )
            return notify_fail("你要往哪跳?\n");
        if ( me->query("combat_exp") < 100000)
            return notify_fail("你刚想往下跳，觉得水冰冷异常，不由缩回了脚。\n");
        message_vision(HIY"$N一招狗急跳墙，四肢平展猛得朝水潭跳下。\n"NOR, me);
        me->move(__DIR__"shuitan");
       message_vision(RED"扑通一声，$N肚子首先入水，五脏六腑一阵翻滚。张嘴想要惊呼，咕噜咕噜，
反而被灌了一肚子水。\n"NOR, me);
        me->receive_damage("jing", 20);
        me->set("water", me->max_water_capacity()+200);
         return 1;
}
