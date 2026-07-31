// Room: /d/city/jiaowai7.c

#include <room.h>

inherit BUILD_ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
这是扬州郊外的一片芳草地，落英缤纷，蜂歌蝶舞，朝露
夕光，沁人心脾。真是踏青远足好时光。
LONG );
	 set("max_room", 8);
	set("exits", ([
		"east" : __DIR__"jiaowai6",
		"west" : __DIR__"nanmen",
	]));

	set("outdoors", "city");
	setup();
	//replace_program(BUILD_ROOM);
}
