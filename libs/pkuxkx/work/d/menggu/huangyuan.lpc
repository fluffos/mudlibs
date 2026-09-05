inherit ROOM; 
#include <ansi.h>
#include "/d/menggu/entry_migong.h",

void create() 
{ 
        set("short", "荒原");
        set("long", @LONG
西面就是库布齐沙漠，塞外大漠别称的来由。
LONG
        );
	
        set("exits", ([ "east" : __DIR__"entry_1",
                        "west" : __DIR__"random_shaomo1_e",
]));
        set("entry_direction","west");
        set("migong","/d/menggu/shamo1");
        set("look_refuse_msg","库布齐沙漠里起了沙尘暴，你什么都看不清了。\n");
        set("enter_refuse_msg","库布齐沙漠里此时正刮起了沙尘暴，这会儿进去太危险了。\n");
		set("outdoors", "menggu_e");
        setup();
}
void init()
{
    add_action("do_look","look");
}