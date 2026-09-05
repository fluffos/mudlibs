// Room: /hangzhou/nandajie1.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";

void create()
{
	set("short", "城隍庙");
	set("long", @LONG
城隍庙共有大殿五间，侧殿三间，早年大门上额“招信城隍庙”，正殿上额
“忠祜王府”。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"east" : __DIR__"nandajie1",
		//"south" : __DIR__"chenghuang",
		//"west" : __DIR__"qingbo",
		"north" : __DIR__"xijie",
	]));

	setup();
}

void init()
{
	add_action("do_scoop","scoop");
}
int do_scoop()
{
	object me=this_player(),ob;
	if (!me->query_temp("allow_scoop_sunzizhu"))
	return 0;
	me->delete_temp("allow_scoop_sunzizhu");
	message_vision("$N在城隍庙前按雄武营官的提示崛起了一层土，片刻就找到了一本书。\n",me);
	ob=new(__DIR__"obj/books/book_strategy_1");
	ob->move(me);
	return 1;
}