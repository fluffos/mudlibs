
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"海边草原"NOR);
	set("long", GRN @LONG
 这起伏不大的丘陵上长满了嫩绿的鲜草，而点缀其上的小白花，使这
里令人觉得精神愉快，站在这儿可以看到远方的大海，这是因为这里都没
有高大的植物。一阵风吹来你觉的身上力量的性质发身了变化!
LONG NOR);
set("magicroom",1);
set("magicset",1);
	set("exits", ([
		"east" : __DIR__"dong12",
		"south" : __DIR__"dong13",
                "west" : __DIR__"dong14",
                "north" : __DIR__"dong11",
                "down" : __DIR__"dong10",
	]));
set("no_npc",1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
void init()
{
        object me = this_player();
        me->start_busy(1);
        me->set("magicgift",1);
        return;
}
