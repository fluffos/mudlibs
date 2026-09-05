 // muchang5.c 牧场
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","牧场");
        set("long",@LONG 
这里是一片茫茫无际的牧场，一眼望不到边的草原，远处能看到高耸的雪
山。附近能看到藏民们正在放牧牛马，小孩子们在奔跑玩耍。
LONG);
        set("exits",([
                "north" : __DIR__"muchang5",
                "south" : __DIR__"muchang6",
                "west" :__DIR__"muchang4",
                "east" :__DIR__"muchang5",
                "northeast" :__DIR__"muchang8",
        ]));


   setup();
}

void init()
{
	this_player()->set_temp("muchang/last_go_time",time());
	return;	
}

int valid_leave(object me, string dir)
{
    if ( dir == "northeast" && time()-me->query("xinan_block/last_time")>600&&me->query("combat_exp")-me->query("xinan_block/last_exp")>500000&&random(1000)>800)
        {
            me->set("xinan_block/last_exp",me->query("combat_exp"));
            me->set("xinan_block/last_time",time());
            me->set_temp("xinan_block/start",1);
            tell_object(me,HIR+BLINK+"牧民告诉你：牧场上最近出现了一只游荡的野狼，已经吞食了很多单身的旅人，没事最好经过这里。\n"+NOR);
        }
		me->set_temp("muchang/last_go_time",time());
        return ::valid_leave(me, dir);
}