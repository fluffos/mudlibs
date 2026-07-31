// Room: /d/henshan/denggaotai.c
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "登高台");
	set("long", @LONG
这里是南天门登高望远的好去处。你站在这里，俯视诸峰，丘垤如
泥丸。看湘江北去，九向九背，时隐时现。周围烟霞，碧罗，紫盖，天
柱诸峰环抱，气象万千。
LONG);
	set("exits", ([ /* sizeof() == 4 */
	   "northdown"  : __DIR__"nantian",
	]));
	set("outdoors", "henshan");
	set("no_clean_up", 0);
	setup();
}

