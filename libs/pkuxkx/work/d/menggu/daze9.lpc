inherit ROOM; 
#include <ansi.h>
#include "/d/menggu/entry_migong.h"
void create() 
{ 
        set("short", "西南角");
        set("long", @LONG
这里是大泽的西南角。
LONG
        );
	
        set("exits", ([ "east" : __DIR__"daze8",
                        "northeast" : __DIR__"daze10",
                        "west" : __DIR__"random_caoyuan3_e",
                        //"east" : __DIR__"angke6",
                        //"south" : __DIR__"daze",
]));
        
		set("entry_direction","west");
        set("migong","/d/menggu/caoyuan3");
        set("migong_posi","east");
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