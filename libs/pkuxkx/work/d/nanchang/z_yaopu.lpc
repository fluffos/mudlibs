
// edit: by zine Aug 21 2010


#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW+"壮族"+HIR+"医馆"NOR);
	set("long", @LONG
这里是壮族巫医的医馆，族人有个头疼脑热，都来这里求医问药。
LONG
	);
	set("exits", ([ 		
        "west" : __DIR__"z_guangchang",
        
		
    ]));
     set("objects", ([
        __DIR__"npc/huoji": 1,
		__DIR__"npc/zhuang_man": random(2),
        
        
        ]));
	set("no_task",1);
	setup();
	
}


