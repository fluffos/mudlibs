//bingqiku.c by river

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "兵器库");
        set("long", @LONG
这里是武馆的兵器库，周围的兵器架上放着很多兵器，刀，剑，矛，戟等
十八般兵器排列整齐。一群武馆弟子正站在架前挑选自己合手的兵刃。北面就
是练武场了，里面很多人正练的热火朝天呢。
LONG
        );      	 
	
        set("exits", ([
               "north" : __DIR__"wuchang3",               
        ]));
        
        set("objects", ([
           __DIR__"obj/jia" : 1,
        ]));
	set("no_fight", 1);

        setup();
}
