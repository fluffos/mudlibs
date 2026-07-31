//by ÇØÊ¼»Ê qsh ednpc tools.
// xiaolu11.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","ĞéÄâ¿Õ¼ä");
	set("long","ĞéÄâ¿Õ¼ä¡£");
	set("exits", ([
		"south" : __DIR__"xiaolu12",
		"west" : __DIR__"xiaolu10",
	]));
	set("fuben2", 1);
	set("objects", ([
		__DIR__"npc/mitan":2+random(2),
	]));
	setup();
}

