#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "黑牢");
	set("long", @LONG
这里是绿柳山庄的黑牢，用于关押到山庄里来捣乱的各路宵小。四周有人
日夜把守，想越狱基本上是不可能的，你就安心把牢底坐穿吧。
LONG);
	set("no_die",1);
	set("no_fight",1);
	set("no_kill",1);
	set("no_perform",1);
	set("no_steal",1);
	setup();
}

void init()
{
	object me = this_player();
	add_action("do_none","exert");
	add_action("do_none","perform");
	add_action("do_none","kill");
	add_action("do_none","fight");
	add_action("do_none","hit");
	add_action("do_none","steal");
	add_action("do_none","beg");
	add_action("do_none","killall");
	add_action("do_none","hitall");
	add_action("do_none","practice");
	add_action("do_none","quit");
	if (userp(me))
		call_out("kickout", 60, me, 3+random(3)); // 3-5分钟
	else
		call_out("kickout", 1, me, 0);
}

int do_none()
{
	write("你稍有动静，狱卒的目光就转了过来，大声喝道：「做什么？老实一点！」\n");
	return 1;
}

void kickout(object me, int count)
{
	if (!objectp(me)) return;
	if (environment(me) != this_object()) return;
	if (count<=0)
	{
		message_vision("几个狱卒走进来揪住$N一脚踹了出去，吼道：「以后别没事就来山庄捣乱！」\n", me);
		me->move(__DIR__"xiaolu");
		message_vision("$N捂着屁股狼狈不堪地跑了过来！\n",me);
		me->start_busy(1);
		return;
	}
	tell_object(me, "几个狱卒在牢外走来走去，凌厉的目光扫过你的脸上。\n");
	call_out("kickout", 60, me, count - 1);
	return;
}

int prevent_die(object me)
{
	if (!objectp(me) || !userp(me))
		return 0;
	me->set("eff_qi", me->query("max_qi"));
	me->set("qi", 1);
	me->set("eff_jing", me->query("max_jing"));
	me->set("jing", 1);
	me->clear_condition();
	message_vision(HIM"眼看$N就要倒毙在地，一个狱卒过来往$P嘴里塞了一颗丹药，嘟囔道：「要死也别死在这里……」\n"NOR, me);
	return 1;
}

