// Room: /d/xiangyang/caodi1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "高台");
	set("long", @LONG
这是襄阳城外的高台，台下堆满了木材和引火之物。
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"down"  : __DIR__"caodi1",
	]));
	set("objects", ([
		
		__DIR__"npc/guoxiang"   : 1,

	]));
	setup();
	//replace_program(ROOM);
}

