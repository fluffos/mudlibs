//绝情谷
// By Zine 

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "山洞口");
        set("long", 
"这里是一座不知名的山洞的洞口，依稀一点光亮指向外面，在这里你只能摸黑\n前行(move)。\n"

        );
        
        set("exits", ([
                "out" : __DIR__"xiaolu",	
        ]));
		set("real_dark",1);
        set("no_sleep_room",1);
        //set("outdoors", "jueqinggu");
        setup();
   
}
void init()
{
	add_action("do_move","move");
}
int do_move(string arg)
{
	object me=this_player();
	if (me->is_busy()||me->is_fighting())
	{
		write("你正忙着呢。\n");
		return 1;
	}
	me->set_temp("jueqinggu/maze/laststep",time());
	write("你向山洞深处离去。\n");
	if (me->query("jueqinggu/maze"))
		tell_object(me,"你之前走过这条路，努力回想一下吧。\n");
	me->move(__DIR__"maze");
	tell_room(this_object(),"只见一道人影闪过，你并没有看清什么。\n");
	return 1;
}

