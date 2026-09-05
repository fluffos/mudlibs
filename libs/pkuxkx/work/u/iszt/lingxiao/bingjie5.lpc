// File		: bingjie5.c
// Created By	: iszt@pkuxkx, 2006-08-15

#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", WHT"冰街广场"NOR);
	set("long", @LONG
石级以上，是青石铺就的平整的广场。由此向山下望去，凌霄外城尽在眼中，
而远方层峦叠嶂，亦有一番气势。前方是一座构制宏伟的殿堂，中央一块匾道：        
                                                                      
                      城    霄    凌                                  
                                                                      
这就是凌霄城迎接客人的大厅了。左右两边各是一条石板路。
LONG);
	
	set("outdoors", "凌霄城");
	set("no_sleep_room", 1);
	set("exits", ([
		"west" : __DIR__"bingwest5",
		"east" : __DIR__"bingeast5",
		"southdown" : __DIR__"bingjie4",
		"north" : __DIR__"dating",
	]));
	set("objects", ([
		__DIR__"npc/dizixl" : 1,
	]));

	setup();
	replace_program(ROOM);
}

