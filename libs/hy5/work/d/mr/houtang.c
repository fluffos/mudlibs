// /u/beyond/mr/houtang.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"后堂"NOR);
         set("long", @long
这里摆着一张小床，床头是一张女人用的梳妆台，上面放着许多胭脂粉
盒。靠窗是一张长长的红木书桌，只要抬眼望去，太湖的万顷碧波，尽收眼
底。
long);
         set("exits",([
             "north" : __DIR__"xiaoting",
]));
	setup();
	replace_program(ROOM);
}
