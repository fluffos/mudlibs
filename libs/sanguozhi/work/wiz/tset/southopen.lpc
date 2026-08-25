// southopen.c "南村口"
#include <mudlib.h>
#include <ansi.h>

inherit OUTDOOR_ROOM;

void setup(){
    set_area("huayin");
    set_light(100);
    set_brief(YEL+"南村口"+NOR);
    set_long("
这里是一个村口，北面是一座小小的村庄。一个小牧童正在放牛。
南边有一条小河，可以从桥上(bridge)走过去。
\n\n");

    set_exits( ([
        "north" : FROOMPATH+"vnangxiao_hang",  // modified by fire Dec 11, 97
        "south" : __DIR__+"riverarea",
    ]) );

    set_exit_msg("south", "$N小心翼翼地走进小河。\n");
    set_enter_msg("north", "$N从小河里走上岸来。\n"); 

    set_objects( ([
        __DIR__"bridge" : 1,
        __DIR__+"mutong" :  1,
        __DIR__+"niu" : 1,
                    ]) ); 
}
 
