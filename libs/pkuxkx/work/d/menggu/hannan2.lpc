inherit ROOM; 
#include <ansi.h>
#include "/d/menggu/entry_migong.h"
#include "/d/menggu/check_point.h"
string look_song();
void create() 
{ 
        set("short", "斡难河");
        set("long", @LONG
这里是斡难河的源头。
LONG
        );
        set("exits", ([ "south" : __DIR__"hannan1",
                        "northwest": __DIR__"random_caoyuan3_s",
]));
		set("entry_direction","northwest");
        set("migong","/d/menggu/caoyuan3");
        set("migong_posi","south");
        set("look_refuse_msg","瀚难河草原上刮起了大风，你什么都看不清了。\n");
        set("enter_refuse_msg","瀚难河草原上刮起了大风，这会儿进去太危险了。\n");
        set("objects", ([
        	__DIR__"npc/leader" : 1,
			__DIR__"npc/mumin" : 1,
	    ]));
        set("outdoors", "menggu_n");
	setup();
}

void init()
{
    object me=this_player(),ob=this_object();
    add_action("do_look","look");
    if (me->query_temp("shediaoquest/jdfm/gogogo"))
    {check_point(me,ob);}
}