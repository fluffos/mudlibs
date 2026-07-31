#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG "偏厅" NOR);
	set("long","这是客店的偏厅，只有一个蒙古女子和一些蒙古士兵在此。\n");

	set("objects", ([
		__DIR__"hebw": 1,
		__DIR__"luzk": 1,
		__DIR__"zhao": 1,
	]));

	set("exits", ([
		"west" : "/d/city/kedian",
//		"east":	__DIR__"bonus_room",
	]));

	setup();
	"/clone/board/skill_b"->foo();
}

void init()
{
	object me = this_player();
	if (me->query("zhao_job")){
		me->add("job_time/赵敏", me->query("zhao_job"));
		me->delete("zhao_job");
	}
}

int valid_leave(object me, string dir)
{
	object *inv;

	inv = filter_array(deep_inventory(me), (: userp :));
	if ( dir != "west")
	if( me->query("bxsj_bonus/exp") || me->query("bxsj_bonus/oldsj") || sizeof(inv) || me->query("registered") != 3 )
		return notify_fail(HIR"您现在的状态，无法进入该房间。\n"NOR);
	return ::valid_leave(me, dir);
}
