// /u/dubei/苗疆

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
这里灌木丛生，前面好象已经没有路了。旁边是一座山崖，下面好象有一座
山洞(shandong)，洞口处有几具野兽的骨骸。
LONG
        );

	set("exits", ([
		"west" : __DIR__"slu8",
		"enter" : __DIR__"shandong",
	]));
	set("item_desc", ([
		"shandong" : HIY "黑呦呦的，也不知道有多深。\n"NOR,
	]));
 
	set("outdoors", "苗疆");

        setup();
}

void init()
{
	add_action("do_look", "look");
	add_action("do_pa", ({ "zuan", "zuan" }));
} 

int do_look(string arg)
{
	if( !arg || arg == "" || arg !=  "guanmu") return 0;

	write("你仔细查看着灌木丛，发现似乎可以钻过去。\n");
	this_player()->set_temp("marks/灌木", 1);
	return 1;
}

int do_pa(string arg)
{
	object me;
	me = this_player(); 
	if (arg != "guanmu" ) return 0;
	if ( !arg ) return 0;

	if (!me->query_temp("marks/灌木"))
		return notify_fail("你要做什麽？\n");
 
	message_vision("$N拔开灌木，一弯身钻了进去。\n", me);
	me->move(__DIR__"shangu1");
	tell_room(environment(me), me->name() + "从灌木丛中钻了出来。\n", ({ me }));
	me->delete_temp("marks/灌木");
	return 1;
}
