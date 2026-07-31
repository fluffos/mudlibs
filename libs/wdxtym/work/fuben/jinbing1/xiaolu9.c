//by ÇØÊ¼»Ê qsh ednpc tools.
// xiaolu9.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","ĞéÄâ¿Õ¼ä");
	set("long","ĞéÄâ¿Õ¼ä¡£");
	set("exits", ([
		"east" : __DIR__"xiaolu8",
	]));
	set("fuben2", 1);
	set("objects", ([
		__DIR__"npc/mitan":random(2),
	]));
	setup();
}

