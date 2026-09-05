inherit ROOM; 
#include <ansi.h>
#include "/d/menggu/entry_migong.h",

void create() 
{ 
        set("short", "绿洲");
        set("long", @LONG
这里是大漠中的一片绿洲，据说是一群凶悍的盗贼的据点。
LONG
        );
	    set("valid_startroom", 1);

        set("exits", ([ "eastup" : __DIR__"random_shaomo1_w",
                        "northwest" : __DIR__"antai3",
                        "west": __DIR__"yeriver1",
]));
        set("entry_direction","eastup");
        set("migong","/d/menggu/shamo1");
        set("look_refuse_msg","库布齐沙漠里起了沙尘暴，你什么都看不清了。\n");
        set("enter_refuse_msg","库布齐沙漠里此时正刮起了沙尘暴，这会儿进去太危险了。\n");
		set("outdoors", "menggu_w");
		set("objects", ([
        	__DIR__"npc/alucar" : 1,
		]));
        setup();
}
void init()
{
    add_action("do_look","look");
}