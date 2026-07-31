// Room: /u/jpei/thd/kezhan4.c

#include <room.h>
inherit ROOM;

int do_open(string arg);
int do_quit();
int do_goto();
int do_home();
int do_gg();

void create()
{
	set("short", "西厢房");
	set("long", @LONG
你一走进西厢房，就把门反锁了。环顾四周，只有一张床和一张残破的桌
子(zhuozi)。
LONG
	);
	set("no_clean_up", 0);

	set("item_desc", ([
		"zhuozi" : "一张残破的书桌，抽屉(chouti)露出一道缝隙。桌子上放着一本发黄的日记(riji)。\n",
		"chouti" : "透过缝隙往里看，黑乎乎地什么也看不清！\n",
		"riji" : "日记上用奇怪的符号画着这样的图案：\nThere are so many jewels...If I can remember the location, but I think the\nsailer will remember...\n",
	]));

	set("exits", ([
		"east": __DIR__"kezhan2.c",
	]) );

	setup();
}

void init()
{
	add_action("do_open", "open");
	add_action("do_quit", "quit");
	add_action("do_goto", "goto");
	add_action("do_gg", "gg");
	add_action("do_home", "home");
	set_temp("busy", 1);
}

void delete_got()
{
	delete_temp("jing_got");
}

int do_open(string arg)
{
	object me = this_player();

	if (me->is_busy() || me->is_fighting())	return notify_fail("你正忙着呢！\n");
	if (arg == "chouti") {
		if (!query_temp("jing_got") && !present("wangyuan jing", me)) {
			write("你轻轻地打开抽屉，发现了一个奇怪的东西，它有两个圆桶，用眼睛凑上去看，竟然能看到远处。\n");
			set_temp("jing_got",1);
			new(__DIR__"obj/wangyuan")->move(me);
			remove_call_out("delete_got");
			call_out("delete_got", 300);
		}
		else 
			write("你轻轻地打开了抽屉，却发现里面是空的。\n");
		return 1;
	}
	return notify_fail("你要打开什么？\n");
}

int do_quit()
{
	write("这里不准退出！\n");
	return 1;
}

int do_goto()
{
	if (wiz_level(this_player()) > 0)
		delete_temp("busy");
	return 0;
}

int do_home()
{
	if (wiz_level(this_player()) > 1)
		delete_temp("busy");
	return 0;
}

int do_gg()
{
	if (wiz_level(this_player()) > 2)
		delete_temp("busy");
	return 0;
}

int valid_leave(object me, string dir)
{
	delete_temp("busy");

	return ::valid_leave(me, dir);
}
