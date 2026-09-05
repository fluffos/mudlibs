//dadian.c
// for xiakedao
// by aiai 98/10/29
// Modified by iszt@pkuxkx, 2007-04-02

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "大殿");
	set("long", @LONG
这是一间金碧辉煌的大殿，两行蟠龙巨柱，有如巨人般排列在大殿中央。巨
柱之间，又是一道猩红长毯。长毯尽头，石阶再起，上面一张巨桌，桌后一张巨
椅，桌椅俱有蟠龙雕花，闪耀著黄金色的光芒。
LONG);
	set("exits", ([ 
		"southdown" : __DIR__"dating",
		"north" : __DIR__"jingshe",
		"west"  : __DIR__"chucangshi",
		"east"  : __DIR__"tang",
	]));
    set("no_task",1);
	set("objects", ([
		__DIR__"npc/zhangsan" : 1,
	]) );
	create_door("west", "小门", "east", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}