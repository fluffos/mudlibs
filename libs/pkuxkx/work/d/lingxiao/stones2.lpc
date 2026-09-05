// File		: stones2.c
// Created By	: iszt@pkuxkx, 2006-09-04

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
一条平整宽阔的石板路，路边稀稀疏疏的长着几根草茎。北边是凌霄城中最
大的练武场，有数十名弟子专心致志的练习师授武功。南面的屋檐下倒挂着不少
冰柱(ice)，锋利尖锐，看来如果能用作武器也是不错的选择。
LONG);

	set("outdoors", "凌霄城");
	set("exits", ([
		"west" : __DIR__"stones1",
		"east" : __DIR__"stones3",
		"north" : __DIR__"lianwuchang",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	]));
	set("item_desc", ([
		"ice" : "这是一条晶莹剔透的冰柱，你可以试着扳(pick)下来看看。\n",
	]) );
	set("ice_count", 5);

	setup();
}

void init()
{
	add_action("do_pick", "pick");
	add_action("do_pick", "ban");
}

void reset()
{
	::reset();
	set("ice_count", 5);
}

int do_pick(string arg)
{
	object me = this_player();

	if(arg != "ice")
		return notify_fail("你要摘什么？\n");
	if(!query("ice_count"))
		return notify_fail("冰柱已经被扳完了。\n");

	message_vision(HIW"$N小心翼翼地从屋檐上扳了一条冰柱下来。\n"NOR, me);
	add("ice_count", -1);
	new(__DIR__"obj/ice")->move(me);
	return 1;
}