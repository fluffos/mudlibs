// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

string look_pubu();

void create()
{
	set("short", "山谷瀑布");
	set("long", @LONG
空山寂寂，水声在山谷间激荡回响，轰轰汹汹，愈走水声愈大，待得走上
岭顶，只见一道白龙似的大瀑布(pubu)从对面双峰之间奔腾而下，声势甚是惊
人。从岭上望下去，瀑布旁边有一间草屋。只见瀑布旁柳树下坐着一人，头戴
斗笠，坐在一块石上，正自垂钓。
LONG
	);
	set("outdoors", "桃源县");
	set("exits", ([
		"north" : __DIR__"xiaolu2",
		"west" : __DIR__"caowu",
	]));
	set("item_desc", ([
		"pubu" : (: look_pubu :),
	]));
	set("yideng_boat", 1);

	set("objects", ([
		__DIR__"npc/yuren" : 1,
	]));

	setup();
}

void init()
{
	add_action("do_jump", ({ "jump", "tiao" }));
}

string look_pubu()
{
	object room, me = this_player();

	if(!( room = find_object(__DIR__"pubu1")))
		room = load_object(__DIR__"pubu1");

	if ( room->query("ppl"))
		return "那瀑布奔腾而去，水沫四溅，只见"+room->query("ppl")+"稳稳站定水底，一任瀑布狂冲猛击，身子竟未摇晃。\n";

	if ( ! me->query_temp("yideng/yuren") || me->query_temp("yideng/yuren_done"))
		return "只见那瀑布奔腾而去，水沫四溅，你不由看得目眩心惊。\n";

	if ( !me->query_temp("yideng/pubu"))
		me->set_temp("yideng/pubu", 1);

	return "\n你目光顺着瀑布往下流动，突然眼前金光闪烁，水底有物游动，定睛瞧去，只\n"+
		"见一对金娃娃钻在山石之中，两条尾巴却在外面乱晃。\n\n";
}

int do_jump(string arg)
{
	object room, *ob, me = this_player();
	int i;

	if ( !me->query_temp("yideng/pubu")) return 0;

	if( ! arg || arg != "pubu") return 0;

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	if ( me->query("combat_exp", 1) < 100000 ) {
		write("你的武功太差，跳下去太危险了！\n");
		return 1;
	}

	if ( me->query_dex(1) < 30 ) {
		write("你的身法不够，跳下去太危险了！\n");
		return 1;
	}

	if ( me->query_skill("dodge") < 200) {
		write("你的轻功不够，跳下去太危险了！\n");
		return 1;
	}

	ob = deep_inventory(me);
	i = sizeof(ob);
	while (i--)
	if (ob[i]->is_character()){
		write("你身上背负一个人，看来无法轻松地跳入瀑布中。\n");
		return 1;
	}

	if(!( room = find_object(__DIR__"pubu1")))
		room = load_object(__DIR__"pubu1");

	if ( room->query("ppl")){
		write("瀑布中已经有人了，你再下去太危险了。\n");
		return 1;
	}

	message_vision(HIY"$N当下一语不发，也不除衣裤鞋袜，涌身就往瀑布中跳落。\n"NOR, me);
	room->set("ppl", me->name(1));
	me->move(__DIR__"pubu1");
	message_vision(HIY"$N双足使劲，以千斤坠功夫牢牢站稳石上，恰以中流砥柱，屹立不动，闭气凝息。\n"NOR, me);
	return 1;
}
