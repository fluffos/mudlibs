// Room: /u/dubei/shaolin/xiaolu
// Date: YZC 96/01/19

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "小径");
	set("long", @LONG
这里是一条寂静的小径，路面一尘不染。两旁是青草，有几只蝴蝶在上面
飞舞。再往前，好象有一所小院。
LONG
	);

	set("exits", ([
		"south" : __DIR__"houyuan",
	]));

	set("outdoors", "shaolin");
	setup();
}

void init()
{
	add_action("do_jump", ({ "jump", "tiao" }));
}

int do_jump(string arg)
{
	object me;
	me = this_player(); 
	if (arg != "out" ) return 0;
	if ( !arg ) return 0;

	if( (int)me->query_skill("dodge",1) < 100 ) {
		message_vision(HIR"$N轻功不够，无法跳出去！\n"NOR, me);
		me->unconcious();
		return 1;     
	}  
	message_vision("$N纵身跃起，一眨眼就消失在窗口 。\n", me);
	me->move(__DIR__"cjlou1");
	tell_room(environment(me), me->name() + "从窗外飞身跃了过来。\n", ({ me }));
	return 1;
}
