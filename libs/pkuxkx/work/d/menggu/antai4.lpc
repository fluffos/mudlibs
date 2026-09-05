inherit ROOM; 
#include <ansi.h>
#include "/d/menggu/entry_migong.h",
string look_song();
void create() 
{ 
        set("short", "按台山北麓");
        set("long", @LONG
这里是按台山北麓，西北不远是一片大草原。
LONG
        );
        set("exits", ([ 
                        "northeast" : __DIR__"random_caoyuan2_w",
                        "southup": __DIR__"antai",
]));
		set("entry_direction","northeast");
        set("migong","/d/menggu/caoyuan2");
        set("migong_posi","west");
        set("look_refuse_msg","中央大草原上刮起了大风，你什么都看不清了。\n");
        set("enter_refuse_msg","中央大草原上刮起了大风，这会儿进去太危险了。\n");
        set("objects", ([
        	__DIR__"npc/leader" : 1,
	    ]));
        set("outdoors", "menggu_w");
        setup();
}

void init()
{
    add_action("do_look","look");
}