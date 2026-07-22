// Room: /d/emei/guanyintang.c
// 暂时对 player 关闭 fen 香

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIW "观音堂" NOR);
	set("long", @LONG
观音堂高踞坡岗，近临危崖，环境幽静，四周树木蓊郁，悦目赏心。传说
入山于此，解脱尘凡；出山于此，解脱险阻，又故名解脱庵。进山的人在此焚
香洗心，入山方可化险为夷，步步平安。这里东下可达伏虎寺，西上行约二里
可到归云阁。
LONG
	);
	set("outdoors", "峨眉山");
	set("objects",([
		__DIR__"npc/xiangke" : 2,
	]));
	set("exits", ([ 
		"east" : __DIR__"guanyinqiao",
		"westup" : __DIR__"guiyunge",
	]));
	set("coor/x",-250);
	set("coor/y",-130);
	set("coor/z",30);
	setup();
}

void init()
{
	add_action("do_fen", "fen");
	add_action("do_fen", "焚");
}

int do_fen(string arg)
{
	object me = this_player();
	int nv, nh, improve1;

	if( !wizardp(me) ) return 0;

	if( me->is_busy() || me->is_fighting() )
		return notify_fail("你正忙着哪！\n");

	if( !arg || arg == "" || arg != "香" )
		return notify_fail("你要焚烧什么？\n");

	if( !present("xiang", me) )
		return notify_fail("你要焚烧什么？\n");
	
	if( arg == "香" ) {
		if( (int)me->query_temp("fen_xiang", 1) >= 1 ) {
			message_vision("$N跪拜在观音堂前，点燃一把香火，虔诚的磕头。\n", me);
			me->add_temp("fen_xiang", 1);
			destruct(present("xiang", me));
			return 1;
		}
		if( !(int)me->query_temp("fen_xiang", 1) ) {
			nv = (int)me->query("kar", 1);
			nh = nv * 250;
			improve1 = 1;
			message_vision("$N跪拜在观音堂前，点燃一把香火，虔诚的磕头。\n", me);
			me->add_temp("fen_xiang", 1);
			destruct(present("xiang",me));
			me->add("kar", improve1);
			me->start_call_out( (: call_other, this_object(), "remove_effect", me, improve1 :), nh );
			return 1;
		}
	}
}

void remove_effect(object me)
{
	if( (int)me->query_temp("fen_xiang",1) >= 1 ) {
		me->add("kar", -1);
		me->delete_temp("fen_xiang");
	}
}
