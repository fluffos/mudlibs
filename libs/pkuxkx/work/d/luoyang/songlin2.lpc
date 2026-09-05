//万安寺 
//by picewolf
//2009-5-7

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"松林"NOR);
        set("long", @LONG
这是一片松林，苍松翠柏，郁郁葱葱，清风吹过，涛声阵阵，从这里
可以看见远处的市镇有袅袅的炊烟升起，向北，万安寺的山门就在眼前。

LONG
			);

        set("exits", ([     
               "southeast" : __DIR__"songlin1", 
			"northwest" : __DIR__"wanansi1",   
        ]));

		set("outdoors", "luoyang");
		setup();
		replace_program(ROOM);
}