// /u/beyond/mr/xiaoting.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",HIW"小厅"NOR);
	set("long",@long
你走进这间小小的厅室, 看到里面放着一张紫檀木茶几和几张湘妃竹椅
子，紫檀木的茶几上摆放着茶壶和几只白玉杯，专供客人饮用。你忍不住想
坐在竹椅上，让疲惫的身心得到充分的休息。
long);
         set("exits",([
             "east" : __DIR__"xiangfang",
             "north" : __DIR__"chufang",
             "south" : __DIR__"houtang",
             "west" : __DIR__"xiaojing4",
]));
set("objects",([
__DIR__"npc/abi" : 1,
__DIR__"npc/dy" : 1,
__DIR__"obj/xiangcha" : 2,
]));
         setup();
}
int valid_leave(object me, string dir)
{
	if (dir == "north" && me->query("family/family_name") != "姑苏慕容"
	&& objectp(present("a bi", environment(me))))
		return notify_fail("阿碧喝道：“到慕容山庄不要乱闯呀”。\n");

	return ::valid_leave(me, dir);
} 
