inherit ROOM; 
#include <ansi.h>
#include "/d/menggu/entry_migong.h",
string look_bi();
void create() 
{ 
        set("short", "山脚");
        set("long", @LONG
这里是不儿罕山的西边的山脚，再往西是一片大草原。
LONG
        );
        set("exits", ([ "west" :  __DIR__"random_caoyuan2_e",
                        
]));
		set("entry_direction","west");
        set("migong","/d/menggu/caoyuan2");
        set("migong_posi","east");
        set("look_refuse_msg","中央大草原上刮起了大风，你什么都看不清了。\n");
        set("enter_refuse_msg","中央大草原上刮起了大风，这会儿进去太危险了。\n");
        set("objects", ([
        	__DIR__"npc/leader" : 1,
	    ]));
        set("outdoors", "menggu_m");
        setup();
}

void init()
{
    add_action("do_look","look");
    add_action("do_climb","climb");
}

int do_climb(string arg)
{
    object room,me=this_player();
    if (arg=="up")
    {
        if (me->query_skill("dodge")>=800)
        {
            room=load_object(__DIR__"buerhan6");
            tell_object(me,"你小心翼翼地沿着峭壁向上爬去。\n");
            me->move(room);
            tell_room(room,me->name()+"小心翼翼地爬了过来。\n");
        }
        else
        {
            tell_object(me,"爬是爬不上去的！\n");
        }
    }
    else
    {
        tell_object(me,"你四脚着地，学着山间的土狗爬了起来！\n");
    }
    return 1;
}
