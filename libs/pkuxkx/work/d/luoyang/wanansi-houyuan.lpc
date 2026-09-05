//万安寺 
//by picewolf
//2009-5-7

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"万安寺后院"NOR);
        set("long", @LONG
这里是万安寺的后院，只有时一两个番僧经过，颇为冷清。

LONG
			);

        set("exits", ([     
               "southup" : __DIR__"wanansi-jiangjingtai",  
			"northwest" : __DIR__"wanansi-xiaolu1",
			"northeast" : __DIR__"wanansi-xiaolu2",  
        ]));

		set("outdoors", "luoyang");
		setup();
		replace_program(ROOM);
}