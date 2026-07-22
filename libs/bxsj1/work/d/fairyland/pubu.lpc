// Room: /u/qingyun/jyzj/pubu.c
// Updated by jpei

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"瀑布"NOR);
	set("long", @LONG
你向西走出两里多路，只见峭壁上有一道大瀑布冲击而下，料想是雪融而
成，阳光照射下犹如一条玉龙，极是壮观美丽。瀑布泻在一个清澈碧绿的深潭
之中，潭水却也不见满，当是另有泄水的去路。潭水中不时的跳起一尾大白鱼，
似乎随手可得。
LONG	);
	set("exits", ([
		"east" : __DIR__"shanlu4",
		"southdown" : __DIR__"tanbian",
	]));

	set("item_desc", ([
		"pool" : "只见碧绿的水中十余条大白鱼来回游动着。\n"
	]));

	set("resource/water", 1);
	set("drink_msg", "$N喝了一口从瀑布边流淌下来的潭水，觉得舒服多了。\n");
	set("outdoors", "昆仑翠谷");
	set("fish_count", 5);
	setup();
}

void reset()
{
	set("fish_count", 5);
}

void init()
{
	add_action("do_catch", ({"catch", "zhua", "zuo"}));
}

int do_catch(string arg)
{
	object me = this_player();
	if (arg == "fish" || arg == "white fish" || arg == "yu") {
		if (query("fish_count")) {
			if (!present("zhi tiao", me))
				message_vision("潭中跃起一尾大白鱼，$N忙伸手去抓，虽然碰到了鱼身，却一滑滑脱了。\n", me);
			else {
				message_vision("一尾大白鱼游上水面，$N用一条树枝使劲疾刺下去，正中鱼身。\n", me);
				add("fish_count", -1);
				new(__DIR__"obj/fish")->move(me);
			}
			return 1;
		}
		else
			return notify_fail("潭里的白鱼都被人抓光了。\n");
	}
	return 0;
}
