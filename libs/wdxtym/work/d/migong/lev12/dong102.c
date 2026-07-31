#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{      
       set("short", YEL"岩洞入口"NOR);
	set("long", YEL @LONG
    周围都是黄褐色的岩石，感觉上已经在地下很深的地方了,
左面有条狭窄的小道通往地下更深处
。 
LONG NOR);
	set("exits", ([
		"south" : __DIR__"dong101",
                "down" : "/d/migong/lev13/dong21"
                	]));
 set("objects", ([
             "/d/migong/obj/npc1" : random(3),             
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
