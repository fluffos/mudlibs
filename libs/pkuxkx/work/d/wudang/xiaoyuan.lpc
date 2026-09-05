// xiaoyuan.c 竹林小院
// by llin

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "竹林小院");
	set("long",@LONG 
小院藏身于竹林之间，围着一重竹篱笆。院外修篁森森，
院内绿荫满地；地上打扫的干干净净，不见一丝落叶。一间小
屋子独立院中，屋子不大，却是青竹制成，显得格外清幽淡雅。
LONG
	);
	set("exits", ([
		"west" : __DIR__"zhulin1",
		"north" : __DIR__"xiaowu",
		"east" : __DIR__"yuan1",
	]));
	create_door("north" ,"竹门", "south", DOOR_CLOSED);
	setup();
}

