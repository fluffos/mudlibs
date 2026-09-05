//万安寺 
//by picewolf
//2009-5-7

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"客房"NOR);
        set("long", @LONG
这里是万安寺的客房，自从番僧来了以后，便由番僧居住。
LONG
			);

        set("exits", ([     
			"east" : __DIR__"wanansi-chanfangw", 
        ]));

		set("outdoors", "luoyang");
		setup();
		replace_program(ROOM);
}