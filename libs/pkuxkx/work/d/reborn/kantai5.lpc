// Room: /reborn/kantai.c
// --by hubo-- 

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"第五关看台"NOR);
	set("long", @LONG
这是一座在昆仑山边上搭坐的一个看台，为了让大家看到各位高手的过劫难情况
而设立的，在这里你可以轻松的看到第五关场内的比武情况。
LONG);

	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");


	set("exits", ([
		"north": __DIR__"kantai6",
		"south": __DIR__"kantai4",
        		    
	]));
	setup();	
}

