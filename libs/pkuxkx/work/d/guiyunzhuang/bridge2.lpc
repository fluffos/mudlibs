// Room: bridge2.c
// Made by: pingpang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "太湖桥");
	set("long","这就是闻名遐尔，风景优美的"YEL"太湖桥"NOR",桥上热闹非凡，穿梭着前来赏景的游客。\n");
	set("exits", ([ /* sizeof() == 3*/
   "east":__DIR__"taihubian",
   "west":__DIR__"bridge",
   "north" : __DIR__"taihuge",
   "south" : __DIR__"machehang",
	]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/xiaofan" :1,__DIR__"npc/tiaofu":1,
]));

     set("outdoors","guiyunzhuang");
	setup();
	replace_program(ROOM);
}
