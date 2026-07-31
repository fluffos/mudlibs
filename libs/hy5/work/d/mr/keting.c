// /u/beyond/mr/keting.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",HIW"客厅"NOR);
	set("long",@long
你走进这间小小的厅室, 看到里面放着一张紫檀木茶几和几张湘妃竹椅
子，紫檀木的茶几上摆放着茶壶和几只白玉杯，专供客人饮用。你忍不住想
坐在竹椅上，让疲惫的身心得到充分的休息。
long);
         set("exits",([
             "east" : __DIR__"cl4-4",
             "north" : __DIR__"cl4-2",
             "west" : __DIR__"yunjinlou",
]));
         set("objects",([
             __DIR__"obj/putao" : 1,
             __DIR__"obj/guiyuan" : 1,
__DIR__"obj/xiangcha" : 2,
]));
         setup();
	 replace_program(ROOM);
}
