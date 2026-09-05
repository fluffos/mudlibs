#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short", MAG"绸缎庄"NOR);
	set("long", 
	HIG"这是一家绸缎庄，出售布匹，绸缎之类的东西。柜台上摆着
  花花绿绿的各式料子，大多都是质量比较粗劣的土布土缎。\n"NOR
	);
	set("objects", ([
                __DIR__"npc/zhao" : 1,
	]));

	set("exits", ([
		"east" : __DIR__"xysouth2",
                
	]));
   	setup();
	replace_program(ROOM);
}

