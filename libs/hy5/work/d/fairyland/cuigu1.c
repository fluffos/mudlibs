// Room: /u/qingyun/jyzj/cuigu1.c
// Updated by jpei

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"翠谷"NOR);
	set("long", @LONG
但见翠谷四周高山环绕，似乎亘古以来从未有人至，四面雪峰插云，险峻
陡峭，决计无法攀登而入，北边一座高峰阻住去路，无法再往前行，草地上有
七八头野山羊低头吃草，见人毫不惊避，树(tree)上十余只猴儿相嬉，看来虎
豹之类巨兽因身子笨重，不能逾险峰而至。
LONG	);
	set("exits", ([
		"south" : __DIR__"cuigu",
	]));
	set("item_desc", ([
		"tree" : "一棵不算高的树，树皮(bark)还很嫩，树上面有许多的枝条(twig)。\n",
		"twig" : "许多小枝生在离地不高的主干上。\n",
		"bark" : "树皮仍旧显出青绿色。\n",
	]) );
	set("objects",([
		__DIR__"npc/shanyang" : 2,
		__DIR__"npc/monkey" : 2,
		__DIR__"npc/xiaohou" : 1,
	]));
	set("outdoors", "kunlun");
	set("no_clean_up", 0);
	set("twig_count", 10);
	set("bark_count", 10);

	setup();
}

void init()
{
	add_action("do_break", ({"break", "zhe", "zheduan", "zhai"}));
	add_action("do_tear", ({"tear", "si", "che"}));
}

void reset_twig()
{
	set("twig_count", 10);
	delete("twig_call_out");
}

void reset_bark()
{
	set("bark_count", 10);
	delete("bark_call_out");
}

int do_break(string arg)
{
	object me = this_player();

	if (arg == "twig" || arg == "zhi" || arg == "zhi tiao") {
		if (query("twig_count")) {
			message_vision("$N踮起脚尖，伸手拉住了一根小树枝，用劲将它折了下来。\n", me);
			add("twig_count", -1);
			new(__DIR__"obj/twig")->move(me);
			return 1;
		}
		else {
			if (!query("twig_call_out")) {
				remove_call_out("reset_twig");
				set("twig_call_out", 1);
				call_out("reset_twig", 600);
			}
			return notify_fail("树上已经没有什么小树枝可供攀折了。\n");
		}
	}
	return 0;
}

int do_tear(string arg)
{
	object me = this_player();

	if (arg == "bark" || arg == "shupi" || arg == "shu pi") {
		if (query("bark_count")) {
			message_vision("$N用力撕下一条树皮来，撮了几下，将它揉成一条细丝。\n", me);
			add("bark_count", -1);
			new(__DIR__"obj/thread")->move(me);
			return 1;
		}
		else {
			if (!query("bark_call_out")) {
				remove_call_out("reset_bark");
				set("bark_call_out", 1);
				call_out("reset_bark", 600);
			}
			return notify_fail("你打算将树皮全扒下来呀？！\n");
		}
	}
	return 0;
}
