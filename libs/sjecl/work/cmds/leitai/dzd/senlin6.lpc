//ROOM: /d/dzd/senlin6.c

#include <ansi.h>

inherit __DIR__"dzd_room";

int do_tiao(string arg);

void create()
{
	set("short","黑森林");
	set("long",@LONG
这是一片一望无际、阴翳蔽天的原始森林，数人合抱的大树和奇花异草举目皆是。
树木分杂簇在一块，密实的枝叶象一蓬蓬巨伞般伸向天空，把阳光遮得丝毫也无。你一
走进这里便觉得阴阴森林的，似乎谁的眼睛在注视着你，你的感觉告诉你，得赶快离开。
LONG
	);
	set("outdoors","大智岛");
	set("exits",([
		"east" : __DIR__"senlin7",
		"west" : __DIR__"pubu",
		"north" : __DIR__"senlin9",
		"south" : __DIR__"senlin4",
		"northeast" : __DIR__"senlin10",
		"southeast" : __DIR__"mudi",
	]));
	setup();
}

void init()
{
	object room;
	object me = this_player();
	::init();
	add_action("do_tiao","tiao");
	if(!room = find_object(__DIR__"shuding3"))
		room = load_object(__DIR__"shuding3");
	if(!wizardp(this_player()))
		tell_room(room,"透过树叶的缝隙，你看见" + me->name() + "(" + me->parse_command_id_list()[0] + ")来到了树下。\n");
}

int do_tiao(string arg)
{
	object me = this_player();
	if(me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");
	if(!arg || arg != "tree")
		return notify_fail("你要跳到哪儿？\n");
	message_vision(HIY"$N深吸一口气，纵身向树上跳去。\n"NOR,me);
	me->move(__DIR__"shuding3",1);
	message_vision(HIY"$N体内真气流转，已轻轻落在树上。\n"NOR,me);
	return 1;
}

int valid_leave(object me,string dir)
{
	object room;
	int valid;
	
	valid = ::valid_leave(me,dir);
	if(valid && !wizardp(me) && room = find_object(__DIR__"shuding3"))
		tell_room(room,"你透过树叶的缝隙，看到" + me->name() + "(" + me->parse_command_id_list()[0] + ")离开了树下。\n");
	return valid;
}
