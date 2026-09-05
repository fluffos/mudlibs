//万安寺 
//by picewolf
//2009-5-7

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"寺内小路"NOR);
        set("long", @LONG
这时寺内人烟稀少，一个人走在小路上，更觉得冷冷清清。
LONG
			);

        set("exits", ([     
			"northwest" : __DIR__"wananta", 
			"southeast" : __DIR__"wanansi-houyuan", 
        ]));

		set("outdoors", "luoyang");
		setup();
		replace_program(ROOM);
}