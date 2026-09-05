// Room: /city/kantai.c
// --by hubo-- 

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"第一关看台"NOR);
	set("long", @LONG
这是一座在昆仑山边上搭坐的一个看台，为了让大家看到各位高手的过劫难情况
而设立的，本看台面对的是劫难第一关。
LONG);

	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");


	set("exits", ([
		"out": __DIR__"wizard_room_haiv",
        		    
	]));
	setup();	
}

