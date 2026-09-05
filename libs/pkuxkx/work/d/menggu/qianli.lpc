inherit ROOM; 
#include <ansi.h>
#include "/d/menggu/entry_migong.h"
void create() 
{ 
        set("short", "谦利河畔");
        set("long", @LONG
这里是谦利河的北岸河畔。
LONG
        );
	
        set("exits", ([ "east" : __DIR__"random_caoyuan3_w",
                        //"southwest" : __DIR__"zaoze1",
                        "southwest" : __DIR__"qianli2n",
                        
]));
        set("outdoors", "menggu_n");
		set("entry_direction","east");
        set("migong","/d/menggu/caoyuan3");
        set("migong_posi","west");
        set("look_refuse_msg","瀚难河草原上刮起了大风，你什么都看不清了。\n");
        set("enter_refuse_msg","瀚难河草原上刮起了大风，这会儿进去太危险了。\n");
        set("objects", ([
        	__DIR__"npc/leader" : 1,
	    ]));
	setup();
}

void init()
{
    add_action("do_look","look");
}