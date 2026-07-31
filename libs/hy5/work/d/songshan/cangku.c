// Room: /d/songshan/cangku.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <room.h>

void create()
{
	set("short", "仓库");
	set("long", @LONG
这是一个仓库，四周密不透风。你一进门便闻到一股霉味，满屋的
灰尘，成堆成堆的物品快堆满了整间房间。
LONG );
	set("exits" , ([
		"north" : __DIR__"westting",
	]) );
	set("objects" , ([
		__DIR__"npc/beixin" : 1,
		__DIR__"npc/huwan" : 1,
		__DIR__"npc/huxin" : 1,
		__DIR__"npc/huyao" : 1,
		__DIR__"npc/huzhi" : 1,
		__DIR__"npc/niupi" : 1,
		__DIR__"npc/shadai" : 1,
		__DIR__"npc/tengjia" : 1,
		__DIR__"npc/tiejia" : 1,
	]) );
	set("no_clean_up", 0);
	set("coor/x", -40);
	set("coor/y", 890);
	set("coor/z", 90);
	setup();
	create_door("north" , "木门", "south" , DOOR_CLOSED);
	replace_program(ROOM);
}

