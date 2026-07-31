// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "瀑布中");
	set("long", @LONG
抬头仰视，只见那山峰穿云插天，较之铁掌山的中指峰尤高数倍，山石滑
溜，寸草不生，那片大瀑布恰如从空而降，那瀑布奔腾而去，水沫四溅，使人
看得不由目眩心惊。一对金娃娃钻在山石之中，两条尾巴却在外面乱晃。
LONG
	);
	set("outdoors", "桃源县");
	set("no_fight", 1);
	set("no_save", 1);
	setup();
}

void init()
{
	add_action("do_jump", ({ "jump", "tiao" }));
	add_action("do_zhua", ({ "zhua", "qin" }));
	remove_call_out("check_ppl");
	call_out("check_ppl", 1, this_player(), 300);
}

void check_ppl(object me, int count)
{
	if ( ! me || environment(me) != this_object()) {
		delete("ppl");
		return;
	}
	if ( me->query("qi") > 500 ) {
		me->add("qi", -500 );
		me->add_busy(1);
		write(HIB"你站在瀑布中，水流湍急，压迫着你感到呼吸都有些困难了。\n"NOR);
	}
	else {
		write("你实在支撑不下去了，纵身跳回了瀑布岸边。\n");
		me->move(__DIR__"pubu");
		tell_room(environment(me), me->name() + "踉踉跄跄地跃回了岸边。\n", ({ me }));
		delete("ppl");
		return;
	}
	if ( count < 1 ){
		write("你实在支撑不下去了，纵身跳回了瀑布岸边。\n");
		me->move(__DIR__"pubu");
		tell_room(environment(me), me->name() + "踉踉跄跄地跃回了岸边。\n", ({ me }));
		delete("ppl");
		return;
	}
	call_out("check_ppl", 5, me, count-5 );
}

int do_zhua(string arg)
{
	object me = this_player();
	object ob, weapon;

	if ( ! arg || arg != "yu")
		return notify_fail("你要抓什么？\n");

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	if ( me->query_str(1) < 30 )
		return notify_fail("你的膂力不够，看起来无法抓住金娃娃了。\n");

	if ( me->query_temp("yideng/yuren_done"))
		return notify_fail("你不是已经抓到金娃娃了么？\n");

	if ( weapon = me->query_temp("weapon"))
		return notify_fail("你用"+weapon->name()+"来抓金娃娃么？\n");

	if ( me->query_temp("yideng/zhua") < 5 || (!random(30) && me->query_temp("yideng/zhua"))){
		message_vision(HIW"$N慢慢弯腰去捉那对金娃娃，一手一条，握住了金娃娃的尾巴轻轻向外拉扯，\n"+
				"只恐弄伤了怪鱼，不敢使力。岂知那金娃娃身上全是粘液，滑腻异常，几下扭\n"+
				"动，挣脱了$N掌握，先后窜入石底。\n"NOR, me);
		me->add_temp("yideng/zhua", 1);
		me->add_busy(2);
		return 1;
	}
	else {
		message_vision(HIW"\n$N伸手到怪鱼遁入的那大石底下用力一抬，只感那石微微摇动，双掌向上猛举，\n"+
				"水声响处，那巨石竟被$P抬了起来，$P变招奇速，巨石一起，立时一招横推过\n"+
				"去，那巨石受水力与掌力夹击，擦过$P身旁，蓬蓬隆隆，滚落下面深渊中去了，\n"
				"响声在山谷间激荡发出回音，轰轰然良久不绝，$N趁势抓住了这对金娃娃。\n\n"NOR, me);
		me->delete_temp("yideng/zhua");
		me->set_temp("yideng/yuren_done", 1);
		ob = new(__DIR__"obj/wawa");
		ob->set_temp("owner", me->query("id"));
		ob->move(me);
		return 1;
	}
}

int do_jump(string arg)
{
	object me = this_player();

	if ( ! arg || arg != "anbian")	return 0;

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	if ( me->query_temp("yideng/yuren_done"))
		message_vision(HIY"\n$N手中握着怪鱼，只怕一松手又被滑脱逃去，当下在水底凝神提气，右足一点，\n"+
				"身子斗然间从瀑布中钻出，紧跟着左足在深沟边上横里一撑，借力跃到岸上！\n\n"NOR,me);
	else
		message_vision(HIY"\n$N在水底凝神提气，右足一点，身子斗然间从瀑布中钻出，紧跟着左足在深沟\n"+
				"边上横里一撑，人已借力跃到岸上！\n\n"NOR,me);
	delete("ppl");
	me->move(__DIR__"pubu");
	tell_room(environment(me), me->name() + "纵身跃回了岸边。\n", ({ me }));
	return 1;
}
