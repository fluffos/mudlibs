// Room: /d/mr/jushi.c
// this is made by beyond
// update 1997.6.20
// rebuild by Lklv 2001.9.20

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",HIW"局室"NOR);
	set ("long",@long
这是大家平时休闲起居的地方，里面放着一具古筝，一张棋桌，上面的棋
局(qiju)错综复杂，令人百思不得其解。局室的东面是大厅，西面是一条长廊，
南面是一间厢房。
long);
	set("item_desc",([
		"qiju" : "一盘杀的难解难纷的棋，不知你是否想研究一下？\n",
	]));

	set("exits",([
		"east" : __DIR__"dating",
		"west" : __DIR__"cl6-0",
		"south" : __DIR__"xiangfang3",
	]));

	setup();
}

void init()
{
	add_action("do_yanjiu", "kan");
	add_action("do_yanjiu", "yanjiu");
}

int do_yanjiu(string arg)
{
	object me;

	me = this_player();
	if ( !living(this_player()) || !arg || arg != "qiju" )
		return 0;
	if ( me->is_busy() && !wizardp(me) ) return notify_fail(HIG"你正在着思考中。\n"NOR);
	if ((int)me->query_int() < 50 || me->query_temp("qiju_over")){
		me->start_busy(1);
		return notify_fail("你废尽心思观察棋局，不一会感觉头昏脑涨。\n");
	}
	if ((int)me->query("jing") < 60 ) {
		write("你太累了，已经没有力气来研读棋局了！\n");
		me->set_temp("qiju_over",1);
		return 1;
	}
	me->receive_damage("jing", 50);
	me->receive_wound("jing", 20);
	message_vision("$N正专心研究桌上的「棋局」。\n", me);

	if ((int)me->query_skill("art", 1) < 31){
		if ( random(4) == 0 )
		me->improve_skill("art", me->query("int"));
		if ( random(2) == 0 )
		write("你对着桌子上的「棋局」琢磨了一回儿，似乎略有所得。\n");
		me->start_busy(1);
		return 1;
	}
	write("你对着棋局研究了一会，但是你已经研究透彻，对你来说已毫无意义了。\n");
	return 1;
}
