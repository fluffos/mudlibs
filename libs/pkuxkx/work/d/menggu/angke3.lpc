inherit ROOM; 
#include <ansi.h>

#include "/d/menggu/entry_migong.h"
void create() 
{ 
        set("short", "昂可刺河南岸");
        set("long", @LONG
这里是昂可刺河的南岸，河水流向大泽。
LONG
        );
	
        set("exits", ([ //"northeast" : __DIR__"yilan_0",
                        "south" : __DIR__"random_caoyuan3_n",
                        "northwest" : __DIR__"angke2",
                        "east" : __DIR__"angke4",
                        
]));
        
		set("entry_direction","south");
        set("migong","/d/menggu/caoyuan3");
        set("migong_posi","north");
        set("look_refuse_msg","瀚难河草原上刮起了大风，你什么都看不清了。\n");
        set("enter_refuse_msg","瀚难河草原上刮起了大风，这会儿进去太危险了。\n");
        set("objects", ([
        	__DIR__"npc/leader" : 1,
	    ]));
        set("outdoors", "menggu_n");
	setup();
}

void init()
{
    add_action("do_look","look");
}