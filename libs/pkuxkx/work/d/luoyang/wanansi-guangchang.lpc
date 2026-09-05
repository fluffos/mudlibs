//万安寺 
//by picewolf
//2009-5-7

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"寺内广场"NOR);
        set("long", @LONG
进了万安寺的山门，是一个小广场，一个大香炉被放在广场中央，不时
有寺内的和尚、番僧走来走去，但香客很少，和这么大的寺庙很不相称。

LONG
			);

        set("exits", ([     
               "south" : __DIR__"wanansi1",   
			"north" : __DIR__"wanansi-tianwangdian", 
        ]));

		set("outdoors", "luoyang");
		setup();
		replace_program(ROOM);
}