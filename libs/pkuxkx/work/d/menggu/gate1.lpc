inherit ROOM; 
#include <ansi.h>
#include "/d/menggu/entry_migong.h",

void create() 
{ 
        set("short", "部落大门");
        set("long", @LONG
这里是益兰州牧民部落的大门，东南面是一片大草原。
LONG
        );
	
        set("exits", ([ "southeast" : __DIR__"random_caoyuan2_n",
                        "northwest" : __DIR__"yilan_3",
]));
        set("entry_direction","southeast");
        set("migong","/d/menggu/caoyuan2");
        set("migong_posi","north");
        set("look_refuse_msg","中央大草原上刮起了大风，你什么都看不清了。\n");
        set("enter_refuse_msg","中央大草原上刮起了大风，这会儿进去太危险了。\n");
        set("objects", ([
        	__DIR__"npc/leader" : 1,
	    ]));
        set("outdoors", "menggu_n");
		setup();
}
