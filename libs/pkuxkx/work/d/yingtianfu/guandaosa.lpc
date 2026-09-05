// Room: /d/suzhou/road1.c
// Date: May 31, 98  Java

inherit ROOM;
string look_tian();
void create()
{
	set("short", "青石官道");
	set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人
骑着马匆匆而过。大道两旁有一些小货摊，似乎是一处集市。
北面就是应天府了。西面有一大片田垄(tian)。
LONG );
	set("outdoors", "yingtianfu");
	set("no_clean_up", 0);
	set("exits", ([
		"southeast"     : __DIR__"guandaosb",
		"north" : __DIR__"zhengyang",
	]));
	set("item_desc", ([
		"tian" : (:look_tian:),
	]));
	setup();
}

string look_tian()
{
	object me=this_player();
	if (me->query_temp("mingtasks/gongbu/task")==2)
	{
		return "那边是一片皇家的田庄，你快过去(west)吧。\n";
	}
	else
	{
		return "那边是一片皇家的田庄。\n";
	}
}

void init()
{
	add_action("do_west","west");
}

int do_west()
{
	object me=this_player();
	if (me->query_temp("mingtasks/gongbu/task")==2)
	{
		message_vision("$N向西面走了过去。\n",me);
		me->move(__DIR__"tuntian");
		return 1;
	}
	return 0;
}