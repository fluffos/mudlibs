inherit ROOM; 
#include <ansi.h>


void create() 
{ 
        set("short", "山谷");
        set("long", @LONG
这里是不儿罕山南麓深处的一处山谷，人迹罕至。却盖着一处茅草屋。
LONG
        );
	
        set("exits", ([ "enter" : __DIR__"valley2",
                        //"southdown" : __DIR__"buerhan-3",
						//"northwest" : __DIR__"buerhan-1",
                        //"northup": __DIR__"buerhan",
]));
        set("outdoors", "menggu_e");
		set("no_robber",1);
		setup();
}

void init()
{
	add_action("do_climb","climb");
}
int climb(object me,object exit)
{
	string s_banshan=base_name(environment(me));
	if (!me||!living(me))
	{
		return 1;
	}
	if (s_banshan!="/d/menggu/banshan")
	{
		tell_object(me,"你重重地摔回到了原地。\n");
		me->move(this_object());
		return 1;
	}
	tell_room(exit,me->name()+"从谷底爬了上来。\n");
	me->move(exit);
	return 1;
}
int do_climb(string arg)
{
	object me=this_player(),exit;
	if (me->is_busy())
	{
		tell_object(me,"你正忙着呢。\n");
		return 1;
	}
	if (!arg||(arg!="up"&&arg!="Up"&&arg!="UP"&&arg!="u"))
	{
		tell_object(me,"这里只能向上攀爬。\n");
		return 1;
	}
	if (!me->query("mengguquest/yinzhe/path"))
	{
		tell_object(me,"你是怎么混进这里的？既然来了，就别走了。");
		return 1;
	}
	exit=load_object(me->query("mengguquest/yinzhe/path"));
	if (objectp(exit))
	{
		message_vision("$N敏捷地向上攀爬。\n",me);
		call_out("climb",3,me,exit);
		me->move("/d/menggu/banshan");
		return 1;
	}
	else
	{
		tell_object(me,"你是怎么混进这里的？既然来了，就别走了。");
		return 1;
	}
}