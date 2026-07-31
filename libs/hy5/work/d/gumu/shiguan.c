// shiguan.c
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "石棺内");
        set("long", 
"棺盖内侧似乎写得有字，凝目瞧去，果见是十六个大字：「"HIR"玉女心经，技
压全真。重阳一生，不弱於人。"NOR"」这十六个字以浓墨所书，笔力苍劲，字体甚
大。其时棺盖只推开了一半，但斜眼看去，仍是清清楚楚。\n"
        );

        set("exits", ([
                "out" : __DIR__"lingshi",
        ]));

        setup();
//        replace_program(ROOM);
}

void init()
{
	add_action("do_tang",  ({ "tang" }));
	add_action("do_search",  ({ "search" }));
	add_action("do_turn",  ({ "turn" }));
}

int do_tang (string arg)
{
	object me = this_player();
	
	if( !arg || arg!="shiguan" )
		return notify_fail("你要躺在哪里？\n");
	message_vision(HIY"$N躺进了石棺，棺内已无转侧馀地，\n", me);
	if (!present("fire", me)) {
		message_vision("里面漆黑一团，$N什么也看不见。\n"NOR, me);
		return 1;
	}
	message_vision("只听见“呲 ---”的一声，$N点亮了手中的火折。\n"NOR, me);
	write("\n再看那十六个字时，只见其后还写得有许多小字：破解玉女心经之法，吾置之\n于此室之下，后人有缘，一观便知 .....重阳真人 ....\n\n");
	me->set_temp("jiuyin/gumu", 1);
	return 1;
}

int do_search()
{
	object me = this_player();

	if (me->query_temp("jiuyin/gumu") < 1)
		return 0;
	message_vision("$N点亮火折，仔细地在石棺内四下摸索。\n", me);
	if (random(10) == 0) {
		message_vision("$N觉得手下一沉，果然摸到个可容一手的凹(ao)处。\n", me);
		me->set_temp("jiuyin/gumu", 2);
	}
	return 1;
}

int do_turn (string arg)
{
	object me = this_player();
	
	if (me->query_temp("jiuyin/gumu") < 2)
		return 0;
	if( !arg || (arg!="left" && arg!="right"))
		return notify_fail("你想往什么方向转？\n");
	if (arg == "right")
		return notify_fail("你将凹处往右转动几下，可是什么也没有发生。\n");
	message_vision("$N将凹处往左转动几下，果然有些松动。\n", me);
	message_vision(HIY"\n$N紧紧握住了凹处向上一提,只听喀喇一响，棺底石板应手而起，\n$N猝不及防，翻身跌入下层石室。\n"NOR, me);
	me->set_temp("jiuyin/gumu", 3);
	me->move(__DIR__"shishi");
	return 1;
}
