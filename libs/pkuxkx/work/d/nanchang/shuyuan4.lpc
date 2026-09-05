#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "休息室");
	set("long", @LONG
这里岳麓书院的休息室，读书累了的弟子可以在这里小憩(sleep)。
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		
        "west" : __DIR__"shuyuan2",
	]));
    set("sleep_room", "1");
	set("no_fight", "1");
	setup();
	
}

