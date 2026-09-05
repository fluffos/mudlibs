// Room: /biwu/kantai.c
// 比武看台 by all@pkuxkx

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"门派比武看台"NOR);
	set("long", @LONG
这是一座在比武场边上搭的看台，为了让大家看到各位高手的比武情况
而设立的，在这里你可以轻松的看到双方高手的的比武情况。
LONG);

	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");


	set("exits", ([
		"down": __DIR__"gate",
        		    
	]));
	setup();	
}

