// 山间平台
// edit: by zine Sep 2 2010

inherit __DIR__"skfroom1";
#include <ansi.h>
void create()
{
	set("short", "山间平台");
	set("long", @LONG
这里是一处很大的平台，似乎是樵夫和猎人歇脚的地方，也许能找(zhao)到一些他们遗落的东西。
LONG
	);
	set("exits", ([ 
		"northeast" : __DIR__"grass",
	]));
	set("no_task",1);
	setup();
	::create();
}

void init()
{
	add_action("do_find", "find");
	add_action("do_find", "zhao");
	::init();
}

int do_find()
{
	object me = this_player();
	string* obj = ({__DIR__"obj/axe",__DIR__"obj/masheng",});
	object ob;
	if (me->is_busy() || me->is_fighting())
	return notify_fail("你正忙着哪！\n");
	if(random(10)>5)
	{
		if (!present("gang fu",me))
		ob= new( obj[random(sizeof(obj))] );
		else
		ob=new(__DIR__"obj/masheng");
		ob->move(me);
		message_vision("$N找了半天，终于找到了$n。\n", me,ob);
	}
    else 
	{   
		message_vision("$N疯狂地找了半天，可什么也没找到。\n", me);
	}
	me->add_busy(random(3));
	return 1; 
}

