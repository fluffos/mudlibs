#include <ansi.h>
inherit ROOM;
void create ()
{
    set("short",BLK"黑松寨"NOR);
set("outdoors","xiangyang");
    set("long",
 CYN"这里名为山寨，实际上是一做废弃的庙宇，几个彪形大汉正围坐在
桌子旁边喝酒，看见你来，他们都惊恐地站了起来，拔出钢刀。屋后还有
一个后院，一座小门半掩着。\n"NOR

       );     
	set("objects", ([
		__DIR__"npc/tufei3" : 1,
                __DIR__"npc/tufei4" : 3,
        ]));  
	set("exits", ([

                "south"  : __DIR__"chukou3",
                "north"  : __DIR__"houshan",
	]));         
        setup();
        
}                                                         


