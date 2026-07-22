// Room: /d/jinghai/wm2.c

inherit ROOM;

void create()
{
	set("short", "无名堡前吊桥");
	set("long", @LONG
出现在你面前是一条阔达二十步的护城河，有两丈多深，河
上面架设有一双车对行木悬桥，由粗铁链吊紧。再往西望去，有
一座城楼高筑，旌旗飘扬。巍峨宽阔的拱行城门上方镂着“无名
堡”三个金漆大字。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "east" : __DIR__"wm12",
]));
        set("outdoors","jinghai");

	setup();
}

void init()
{
	add_action("do_han", "yell");
}

int do_han(string arg)
{
	object me, key, nroom;
	string passwd;

	me = this_player();

	if( !arg
	|| !(passwd = me->query_temp("jinghai_wm_passwd"))
	|| (arg != passwd))
		return notify_fail("你扯着脖子喊了几嗓子，周围好像没有任何反映。\n");

	if( !(key = present("bai ling", me))
	|| (key->query("master") != me->query("id")))
		return notify_fail("城上探出了个脑袋看了看你又缩了回去。\n");

	if( !(nroom = find_object(__DIR__"wm3")) )
		nroom= load_object(__DIR__"wm3");

	set("exits/westup", __DIR__"wm3");

	message_vision("城上探出了个脑袋看了看$N，$N赶紧把手中的令牌拿出来晃了晃。\n", me);
	message_vision("只听城上有人喊了些什么，吊桥慢慢放下。\n", me );

	me->delete_temp("jinghai_have_ling/bai");
	destruct(key);

	me->delete_temp("jinghai_wm_passwd");
/*
	me->set_temp("used_bailing", 1);
*/
	call_out("open",10,me);
	return 1;
}

void open()
{
	message("vision", "只听城上有人喊道:关门...升桥。\n", this_object() );
	delete("exits/westup");
}
