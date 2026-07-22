// Room: /d/chengdu/zijuefushufang.c
// By Jpei

inherit ROOM;

string look_shelf();

void create()
{
	set("short", "书房");
	set("long", @LONG
这是子爵府的书房，并排列着七个架子(shelf)，上面全是棋谱。
LONG
	);

	set("item_desc", ([
		"shelf" : (: look_shelf :),
	]));

	set("exits", ([
		"east" : __DIR__"zijuefuhall",
	]));

	setup();
}

string look_shelf()
{
	object me = this_player();

	if (!present("ou xie pu", me) && me->query_temp("qipu_guess_win") && !me->query_temp("ouxiepu_got")) {
		new(__DIR__"obj/ouxiepu")->move(me);
		return "你在书架上翻来翻去，忽然发现一张很古旧的棋谱，你偷偷地把它藏到了怀里。\n";
	}
	return "你在书架上翻来翻去，没发现什么有用的东西。\n";
}

