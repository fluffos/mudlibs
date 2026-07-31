// Room: /d/henshan/zhurongdian.c
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "祝融殿");
	set("long", @LONG
祝融殿，又名老圣殿，祠火神祝融。花岗石砌墙，铁瓦覆顶，殿宇
凌空傲雪，巍然屹立在衡山绝顶。殿门石楹上刻有:  "寅宾日出，峻极
于天" ，殿上有"圣德重华"的楣额。现在这里是衡山派掌门行在。
LONG);
	set("exits", ([ /* sizeof() == 4 */
	   "southdown"  : __DIR__"wangritai",
	   "northdown"  : __DIR__"wangyuetai",
	   "westup"     : __DIR__"zhurongfeng",
	]));
	set("objects", ([
		__DIR__"npc/moda" : 1,
	]));
	setup();
}

