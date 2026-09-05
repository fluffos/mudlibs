inherit ROOM; 
#include <ansi.h>


void create() 
{ 
        set("short", YEL"茅草屋"NOR);
        set("long", @LONG
这里是间茅草屋，住着一个隐士。
LONG
        );
	
        set("exits", ([ "out" : __DIR__"valley",
                        //"southdown" : __DIR__"buerhan-3",
						//"northwest" : __DIR__"buerhan-1",
                        //"northup": __DIR__"buerhan",
]));
        //set("outdoors", "menggu_e");
		set("objects", ([
        	__DIR__"npc/yinzhe" : 1,
		]));
		set("no_robber",1);
		setup();
}

