// Room: /u/pingpang/room/bridge.c
// Made by: pingpang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "太湖桥");
	set("long", "这就是闻名遐尔，风景优美的"YEL"太湖桥"NOR",桥上热闹非凡，穿梭着前来赏景的游客.\n");
	set("exits", ([ /* sizeof() == 3*/
  "south" : __DIR__"bridge1",
   "east":__DIR__"bridge2",
   "west":__DIR__"taihubian1",
   "north" : __DIR__"matou",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/ghost" :1,
]));

     set("outdoors","guiyunzhuang");
	setup();
	replace_program(ROOM);
}
