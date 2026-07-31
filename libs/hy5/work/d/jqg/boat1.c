// boat1.c 小舟
// By River 99.5.25
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short","小舟");
        set("long", @LONG
你正身处一叶扁舟之内，舟内狭小异常，最多也就能载二、三个人。你双
手扳桨，慢慢地溯溪上行。
LONG
        );
        set("outdoors","绝情谷"); 

        setup();
}

void init()
{
       object me= this_player();
       add_action("do_quit","quit");
       call_out("run", 15, me);
}

void run(object me)
{
        if (environment(me)== this_object())
        write(HIC"\n\n划了一阵，小舟已划入一条极窄的溪水之中，真想不到这里居然别有洞天。\n"+
                 "两边山峰壁立，溪洞山石离水面不过三尺，你须得横卧舱中，小舟始能划入。\n"+
                 "抬头望天，只馀一线，景色极尽清幽，只是四下静寂无声息，隐隐透著凶险。\n\n"NOR);
        me->move(__DIR__"boat2");
}

int do_quit()
{
        write("这里不准退出！\n");
        return 1;
}
