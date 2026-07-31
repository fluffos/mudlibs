// boat4.c 扁舟
// By River 99.5.25
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short","小舟");
        set("long", @LONG
你正身处一叶扁舟之内，舟内狭小异常，最多也就能载二、三个人。你双
手扳桨，慢慢地顺溪而下。
LONG
        );
        set("outdoors","绝情谷"); 

        setup();
}

void init()
{
       object me= this_player();
       add_action("do_quit","quit");
       call_out("run",15, me);
}

void run(object me)
{
        if (environment(me)== this_object())
        environment(me)->set("ppl",0);
        write(HIC"\n\n远山青绿，溪水湛蓝。青绿远山倒映在湛蓝的溪水中，蓝翠如绿，绿浓如蓝。\n"+
                 "溪流曲折，小舟经划过了几个弯后，慢慢又能看见溪旁岸边绿柳成荫的踪迹。\n\n"NOR);
        me->move(__DIR__"boat5");
}

int do_quit()
{
        write("这里不准退出！\n");
        return 1;
}
