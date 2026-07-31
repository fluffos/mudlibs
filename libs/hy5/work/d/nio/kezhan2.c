// Room: /u/jpei/thd/kezhan2.c

#include <room.h>
inherit ROOM;

int do_unlock();
string look_men();

void create()
{
	set("short", "二楼");
	set("long", @LONG
这是客栈的二楼，竟然只有两间房子。东厢房的门敞开着，而西厢房的门
(men)却是关着的。
LONG
	);
	set("no_clean_up", 0);

	set("item_desc", ([
		"men" : (: look_men :),
	]));

	set("exits", ([
		"east": __DIR__"kezhan3.c",
		"down": __DIR__"kezhan.c",
	]) );

	setup();
}

void init()
{
	add_action("do_unlock", "unlock");
	add_action("do_unlock", "kai");
}

int do_unlock()
{
	object ob;
	object me = this_player();

	if (me->is_busy() || me->is_fighting())	return notify_fail("你正忙着呢！\n");
	if (__DIR__"kezhan4.c"->query_temp("busy")) 
		return notify_fail("这扇门已经被人从里面反锁了。\n");
	if (!(ob = present("kezhan key", me)))
		return notify_fail("你不会撬锁。\n");
	message_vision("$N用一把钥匙打开了西厢房门。\n", me);
	destruct(ob);
	this_player()->move(__DIR__"kezhan4");
	return 1;
}

string look_men()
{
	if (__DIR__"kezhan4.c"->query_temp("busy")) 
		return "这扇门已经被人从里面反锁了。\n";
	else
		return "这扇门上挂着一把大铁锁。\n";
}
