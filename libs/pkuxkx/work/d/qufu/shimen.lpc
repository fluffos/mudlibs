
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIC"石门寺"NOR);
	set("long", @LONG
这里是曲阜最大的寺庙——石门寺，庙里最近来了个云游和尚。
LONG );
	//set("outdoors", "qufu");
	set("no_clean_up", 0);
	set("exits", ([
		"out"     : __DIR__"shimenshan",
		//"westdown" : __DIR__"guandaoe",
	]));
    set("objects", ([
		__DIR__"npc/xingzhe" : 1,
        ]));
	setup();
	
}

