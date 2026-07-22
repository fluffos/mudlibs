// huacong.c
// By River@SJ 98/08/29

#include <ansi.h>
inherit ROOM;

void delete_hexiu(object me, object arg);

void create()
{
	set("short",HIR"红花丛"NOR);
	set("long", @LONG
这丛红花排开来长达数丈，密密层层，奇香扑鼻，但见花丛有如一座大屏
风，红瓣绿枝，煞是好看，四下里树荫垂盖，便似天然结成的一座花房树屋。
四周都是一片清幽，只闻泉声鸟语，杳无人迹，确是个上好的练功所在。
LONG        );

	set("exits", ([
		"west" : __DIR__"guolin4",
		"south" : __DIR__"guolin5",
	]));

	set("outdoors","古墓");

	set("no_fight", 1);
	setup();
}

void init()
{
	add_action("do_hexiu", "hexiu");
	add_action("do_quit", "quit");
}

int do_hexiu(string arg)
{
	object me = this_player();
	object ob, *inv;
	mapping fam;
	int ynlvl,i;

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	if(!arg)
		return notify_fail("你要与谁和修内功？\n");

	if (!(fam = me->query("family")) || fam["family_name"] != "古墓派")
		return notify_fail("你不是古墓派传人，怎么能练古墓的内功？\n");

	if (me->query("gender") == "无性")
		return notify_fail("你无根无性，阴阳不调，难以领会高深的玉女心经神功。\n");

	if (!(ob = present(arg, this_object())))
		return notify_fail("这人现在不在这里！\n");

	if ( me == ob)
		return notify_fail("你想玩双手互搏吗？\n");

	if (!living(ob))
		return notify_fail("你必须先把" + ob->name() + "弄醒。\n");

	if (!userp(ob))
		return notify_fail("你只能与玩家和修练功！\n");

	if( me->query_temp("weapon"))
		return notify_fail("你手中拿着武器，怎么双掌相对，合修玉女心经？\n");

	ynlvl = me->query_skill("yunu-xinjing",1);
/*
	if ( ynlvl > 130 )
		return notify_fail("你已经不能从和修中得到帮助了！\n"); 
*/
	if ( me->query("potential") < 1 )
		return notify_fail("你的潜能消耗光了，暂时无法合修。\n");

	if( ob->query("potential") < 1)
		return notify_fail( ob->name()+"的潜能消耗光了，暂时无法合修。\n");
/*
	if ( ob->query_skill("yunu-xinjing", 1) < (ynlvl - 25))
		return notify_fail(ob->name() +"功夫与你相差太远，无法助你练功！\n");
*/
	if (me->query("jing") < 30 || me->query("qi") < 30)
		return notify_fail("你太累了，还是先休息一会儿吧！\n");

	if (ob->query("jing") < 30 || ob->query("qi") < 30)
		return notify_fail(ob->name()+"太累了，还是先休息一会儿吧！\n");

	if (me->query_temp("gumu_hexiu")
	 && me->query_temp("gumu_hexiu")!= ob->query("id"))
		return notify_fail("你正欲与别人和修呢！\n");

	inv= all_inventory(me);
	i = sizeof(inv);
	while (i--)
	if( inv[i]->query("equipped") && (! inv[i]->query_autoload() && inv[i]->query("id") != "lingpai"))
		return notify_fail("如果你不除去身上衣衫，练功极有可能会走火入魔。\n"); 

	me->set_temp("gumu_hexiu", ob->query("id"));

	tell_object(ob,"红花丛中，"+me->name()+"端坐于你面前，欲与你和修玉女心经。\n");
	tell_object(me,"红花丛中，你端坐于"+ob->name()+"面前，欲与其和修玉女心经。\n");

	if ( ob->query_temp("gumu_hexiu") 
	 && ob->query_temp("gumu_hexiu") != me->query("id"))
		return notify_fail(ob->name()+"没有要与你和修练功的意思！\n");

	if (!ob->query_temp("gumu_hexiu")) return 1;
	message_vision(HIW"\n$N左臂透过花丛，与$n右掌相抵，二人各处花丛一边，解开衣衫，修习起来。\n"NOR,me, ob);
	me->start_busy(10);
	ob->start_busy(10);
	call_out("delete_hexiu", 2+random(3), me, ob);
	return 1;
}

void delete_hexiu(object me, object ob)
{
	if ( !me || !ob) return;

	me->receive_damage("jing", 20+random(10));
	me->receive_damage("qi",  20+random(5));
	me->add("potential", -1);
	if ( me->query_skill("yunu-xinjing", 1) < 130 )
		me->improve_skill("yunu-xinjing", me->query_int()*( 2 + random(2)));
	me->start_busy(1);
	me->delete_temp("gumu_hexiu");

	ob->receive_damage("jing", 20+random(10));
	ob->receive_damage("qi",  20+random(5));
	ob->add("potential", -1);
	if ( ob->query_skill("yunu-xinjing", 1) < 130 )
		ob->improve_skill("yunu-xinjing", ob->query_int()*( 2 + random(2))); 
	ob->start_busy(1);
	ob->delete_temp("gumu_hexiu");

	message_vision(HIR"\n良久后，$N和$n受到感应，立时运功为助，全身热气蒸腾，收获颇丰。\n\n"NOR,me,ob);
	return;
}

int do_quit()
{
	write("这里不准退出！\n");
	return 1;
}

int valid_leave(object me, string dir)
{
	me->delete_temp("gumu_hexiu");
	return ::valid_leave(me, dir);
}
