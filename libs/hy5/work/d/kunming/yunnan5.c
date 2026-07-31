// /d/kunming/pubu
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN "原始森林" NOR);
        set("long", @LONG
来到这里，只听得流水声越来越大，你感觉到一阵阵雾气向你袭
来，树木渐渐稀少，花草却多了起来，西北方向穿过花丛(huacong)
似乎有条小路能走过去。
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "east" : __DIR__"yunnan4", 
                
        ]));

             
        setup();
       
}


void init()
{
        add_action("do_enter", "poke");
	UPDATE_D->check_user(this_player());
}


int do_enter(string arg)
{
	object me;
	me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="huacong" ) 
	{
		message("vinson", HIY "你拔开花丛走了进去\n\n" NOR, this_player());

                me->move(__DIR__"pubu");
                
		return 1;
	}
}	


