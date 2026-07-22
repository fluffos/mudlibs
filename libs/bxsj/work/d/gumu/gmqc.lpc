// Room: /u/xdd/gumu/gmqiecuo.c
// Modify by river 98/08/29
#include <ansi.h>
inherit ROOM;

void delete_qiecuo(object me, object arg);

void create()
{
	set("short",HIR"切磋室"NOR);
	set("long", @LONG
这是古墓派弟子切磋武技的地方，空旷的一间石室，没有任何摆设。四周
点亮不少火把，倒也灯火通明，石壁上留有几个骇人的掌印，入石数分，显见
是高手相交所为。
LONG        );

	set("no_fight", 1);

	set("exits", ([
		"north" : __DIR__"gmqt",
	]));

	setup();
}

void init()
{
	add_action("do_qiecuo", "qiecuo");
	add_action("do_qiecuo", "chaizhao");
}

int do_qiecuo(object arg)
{
	object me = this_player();
	object ob;
	mapping fam;
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");
	if (!arg)
		return notify_fail("你要和谁切磋武艺？\n");
	if (!(fam = me->query("family")) || fam["family_name"] != "古墓派")
		return notify_fail("你不是古墓派传人。\n");
	if (me->query("combat_exp") > 2000000)
		return notify_fail("去做一些有危险的任务好吗？\n");
	if (!(ob = present(arg, this_object())))
		return notify_fail("这人现在不在这里！\n");
	if (me == ob)
		return notify_fail("你想玩双手互搏吗？\n");
	if (!living(ob))
		return notify_fail("你必须先把" + arg->name() + "弄醒。\n");
	if (!userp(ob))
		return notify_fail("你只能和玩家切磋武艺！\n");
	if (ob->query("combat_exp") < me->query("combat_exp")/4*5 )
		return notify_fail("这人功夫与你相差太远，无法助你练功！\n");
	if (me->query("jing") < 45 || me->query("qi") < 45)
		return notify_fail("你太累了，还是先休息一会儿吧！\n");
	if ( me->query("potential") < 1 )
		return notify_fail("你的潜能消耗光了，暂时无法切磋武艺。\n");
	if( ob->query("potential") < 1)
		return notify_fail( ob->name()+"的潜能消耗光了，暂时无法切磋武艺。\n");
	if (me->query_temp("gumu_qiecuo"))
		return notify_fail("你现在正在和别人拆招！\n");
	if (me->query("gender") == "无性" )
		return notify_fail("无性之人不能从切磋中得到帮助！\n"); 
	if (me->query("gender") != ob->query("gender") )
		return notify_fail("同性之人不能在切磋中得到帮助！\n");

	me->set_temp("gumu_qiecuo", ob->query("id"));

	tell_object(ob,me->name()+"端坐于你面前，欲与你切磋武艺。\n");
	tell_object(me,"你端坐于"+ob->name()+"面前，欲与其切磋武艺。\n");

	if ( ob->query_temp("gumu_qiecuo") 
	 && ob->query_temp("gumu_qiecuo") != me->query("id"))
		return notify_fail("对方似乎并没有要和你切磋武艺的意思！\n");

	if (!ob->query_temp("gumu_qiecuo")) return 1;
	message_vision("$N和$n拉开架式，拆起招来。\n", me, ob);
	me->start_busy((: delete_qiecuo :));
	ob->start_busy((: delete_qiecuo :));
	call_out("delete_qiecuo", 20 + random(20), me, ob);
	return 1;
}

void delete_qiecuo(object me, object ob)
{
	mapping my;
	int i ,j ;
	if (!me || !ob) return;
	my = me->query_entire_dbase();

	me->delete_temp("gumu_qiecuo");
	ob->delete_temp("gumu_qiecuo");
	message_vision("$N和$n你攻我守，身形变幻，转眼便已拆了十余招.....\n",me, ob);
	message_vision("$N和$n只觉得此番练习，收获颇丰，功夫掌握的更加娴熟了！\n",me,ob);
	me->add("potential", -1);
	me->receive_damage("jing", 25 + random(20));
	me->receive_damage("qi",  25 + random(20));
	i = 5+random((my["max_pot"]-100)/3) ;
	if ( i > 40 ) i = 20 + random(20);
	me->add("combat_exp", i);
	ob->add("potential", -1);
	ob->receive_damage("jing", 25+random(20));
	ob->receive_damage("qi",  25+random(20));
	j = 5+random((ob->query("max_pot")-100)/3) ;
	if ( j > 40 ) j = 20 + random(20);
	ob->add("combat_exp", j); 
	log_file("job/qiecuo", sprintf("%8s%-10s和%8s%-10s切磋，分别得到经验：%2d 和 %2d 。", 
		me->name(), "("+me->query("id")+")", ob->name(), "("+ob->query("id")+")",
		i , j ), me);
	return;
}
