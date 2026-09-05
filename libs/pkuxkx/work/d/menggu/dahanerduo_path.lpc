inherit ROOM; 
#include <ansi.h>
#include "/d/menggu/entry_migong.h",

void create() 
{ 
        set("short", "草地");
        set("long", @LONG
这里是一片草地，不远处是大翰耳朵，居住着一个草原部落。
LONG
        );
	
        set("exits", ([ "west" : __DIR__"dahanerduo",
                        "southeast" : __DIR__"random_caoyuan1_n",
]));
        set("entry_direction","southeast");
        set("migong","/d/menggu/caoyuan1");
        set("migong_posi","north");
        set("look_refuse_msg","科尔沁草原上刮起了大风，你什么都看不清了。\n");
        set("enter_refuse_msg","科尔沁草原上刮起了大风，这会儿进去太危险了。\n");
        set("objects", ([
        	__DIR__"npc/leader" : 1,
	    ]));
        set("outdoors", "menggu_e");
		setup();
}
void init()
{
    add_action("do_look","look");
}