// Room: /d/shaolin/shijie9.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "菜地");
	set("long", @LONG
这里是少林的菜地，少林寺里和尚吃的东西，大多都产自这里。
菜地的边上是一个大草垛(caoduo).
LONG
	);

	set("item_desc", ([
		"caoduo" : "草垛里可以藏东西,搜索(search)一下?\n",
	]));

	set("exits", ([
		"west"    : __DIR__"shijie9",
	]));

	set("outdoors", "shaolin");
	setup();
}

void init()
{
	add_action("do_search","search");
}

int do_search()
{
	object me=this_player();
	write("你在草堆里摸索起来,希望可以找到什么。\n");
	call_out("search_hulu",random(5),me);
	return 1;
}

int search_hulu()
{
	object ob;
	object me=this_player();
	if (me->query_temp("bingcan/findcan"))
	{
		ob=new("/d/shaolin/npc/obj/hulu1");
		ob->move(me);
		write("你在草堆里找到一个葫芦！！\n");
		me->delete_temp("bingcan/findcan"); 
		return 1;
	}
	write("你累了半天，什么也没找到....\n");
	return 1;
}