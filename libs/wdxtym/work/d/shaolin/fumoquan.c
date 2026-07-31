// Room: /d/shaolin/fumoquan.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "金刚伏魔圈");
	set("long", @LONG
三棵大松树的树干上各挖了个可容身一人的大洞，有个洞口
露出黑色僧袍一角，似乎住得有人。中央是一片大草坪，中心处
光秃秃的，似乎经常受大力击打，以致寸草不生。
LONG );
	set("exits", ([
		"out" : __DIR__"qyping",
	]));

	set("objects",([
		CLASS_D("shaolin") + "/du-nan" : 1,
		CLASS_D("shaolin") + "/du-e" : 1,
		CLASS_D("shaolin") + "/du-jie" : 1,
	]));
	setup();
}

void init()
{	
	mapping mine;
	object me;
	object ob1, ob2, ob3;

	me = this_player();
	mine = me->query("family");

	if (me->query_temp("valid_in_fumoquan"))
		return;

	if (mapp(mine) &&
	    mine["family_name"] == "少林派" &&
	    mine["generation"] <= 37)
	{
		me->set_temp("valid_in_fumoquan", 1);
		return;
	}

	if (! objectp(ob1 = present("du nan", this_object())) ||
	    ! living(ob1) ||
	    ! objectp(ob2 = present("du e", this_object())) ||
	    ! living(ob2) ||
	    ! objectp(ob3 = present("du jie", this_object())) ||
	    ! living(ob3) ||
	    ! interactive(me))
	{
		me->set_temp("valid_in_fumoquan", 2);
		return;
	}

	if (ultrap(me))
	{
		message_vision(HIG "三位老僧各自坐在树洞下，竟然纹丝不动，镇定不若，恍若不
知道你的到来。"NOR"\n", me);
		CHANNEL_D->do_channel(this_object(), "rumor", "大宗师" +
				      me->name(1) + "进入金刚伏魔圈。");
		me->set_temp("valid_in_fumoquan", 1);
		return;
	}

	message_vision(HIR "突然间劲气纵横，三根黑索如三条黑蟒般就地滚来，瞬间近身，
化成一条笔直的兵刃，如长矛，如杆棒，如利剑，分别向$N的头，
胸，腹三处要害疾刺而至。$N一瞥间，看到三个老僧分居三个树
洞之中，正全力持鞭向$N攻来！$N已陷身于少林寺之蕴含无上降
魔大法的金刚伏魔圈！"NOR"\n", me);

	if (me->query("family/family_name") == "少林派" &&
	    me->query("combat_exp") < 200000)
	{
		message_vision(HIR "$N被一道排山倒海般的劲气击中，顿时飞了出去 !"NOR"\n", this_player());
		me->unconcious();
		me->move("/d/shaolin/qyping");
		return;
	}
/*
	if (me->query("family/family_name") == "少林派" &&
	    me->query("combat_exp") > 200000)
	{
		message_vision("三位老僧看着$N，面露慈祥的微笑。"NOR"\n", this_player());
		me->set_temp("valid_in_fumoquan", 1);
		return;
	}
*/
	COMBAT_D->do_attack(ob1, me, ob1->query_temp("weapon"));
	COMBAT_D->do_attack(ob2, me, ob2->query_temp("weapon"));
	COMBAT_D->do_attack(ob3, me, ob3->query_temp("weapon"));
	if (me->query("qi") < 0)
	{
		me->unconcious();
		me->move("/d/shaolin/qyping");
		return;
	}

	me->set_temp("valid_in_fumoquan", 1);
	message_vision("三位老僧收回鞭子，哼了一声。\n\n", me);
	CHANNEL_D->do_channel(this_object(), "rumor", (mapp(mine) ? mine["family_name"] : "") +
			      me->name(1) + "闯入金刚伏魔圈。");
}

int valid_leave(object me, string dir)
{
	me->delete_temp("valid_in_fumoquan");
	return ::valid_leave(me, dir);
}

