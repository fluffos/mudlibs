//万安寺 
//by picewolf
//2009-5-7

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"讲经台"NOR);
        set("long", @LONG
这里是万安寺主持方丈讲经说法的地方，自从番僧住进寺里之后，寺内僧人们的功课
就渐渐少了，来这里的人也越来越少。

LONG
			);

        set("exits", ([     
               "south" : __DIR__"wanansi-wofodian",  
			"northdown" : __DIR__"wanansi-houyuan",  
			"west" : __DIR__"wanansi-chanfangw1",
			"east" : __DIR__"wanansi-chanfange1",  
        ]));

		set("outdoors", "luoyang");
		setup();
		replace_program(ROOM);
}