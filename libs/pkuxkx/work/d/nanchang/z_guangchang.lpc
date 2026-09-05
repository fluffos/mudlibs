
// edit: by zine Aug 21 2010


#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "广场");
	set("long", @LONG
这里是一个大广场，壮族头领在这里议事，很多壮人在这里活动。
LONG
	);
	set("exits", ([ 		
		"southdown" : __DIR__"z_xiaolu2",	
        "northup" : __DIR__"z_toulingshi",
        "west" : __DIR__"z_biwu",
        "east" : __DIR__"z_yaopu",
        "northeast" : __DIR__"z_dangpu",
        "northwest" : __DIR__"z_caodi",
        "southeast" : __DIR__"z_well",
        "southwest" : __DIR__"z_jiuguan",
		
    ]));
	set("no_task",1);
    set("outdoors", "nanchang");
	setup();
	
}


