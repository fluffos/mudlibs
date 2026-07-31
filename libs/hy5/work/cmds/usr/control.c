// 遥控随从 (by xbd)

#include <ansi.h>

inherit SKILL;

string *cmds = ({"give", "wield", "unwield", "wear", "remove", "enable", "jifa", "prepare", "bei", "exert",
"yun", "perform", "yong", "enforce", "jiali", "ask", "drop", "l", "look", "go","say"});

void do_control(object me, object ob, string cmd);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object ob;
	string type, cmd;
	int i, flag = 0;

	if (!me->query("guard/flag"))
		return notify_fail("凭你现在的条件，还没有资格拥有随从呢！\n");
	
	if (!me->query("guard/active"))
		return notify_fail("你现在还没有收过随从，如果需要的话，可以到无名居士那里去要一个！\n");

	if (!(ob = me->query_temp("guard_ob")))
		return notify_fail("你现在还没有召唤随从呢！\n");

	if (!arg || arg == "")
		return notify_fail("你想遥控她做什么？\n");

	if ((sscanf(arg, "%s %s", type, cmd) < 2 ))
		type = arg;
	
	for (i = 0; i < sizeof(cmds); i++)
		if (cmds[i] == type) {
			flag = 1;
			break;
		}
	if (!flag)
		return notify_fail("你想遥控她做什么？\n");

	if (me->is_busy())
		return notify_fail("你正忙着呢！\n");

	if (me->query("neili") < 500)
		return notify_fail("以你现在的内力，无法施展天心通！\n");
	if (me->query("jing") < 200)
		return notify_fail("以你现在的精气，无法施展天心通！\n");
	if (ob->query("neili") < 500)
		return notify_fail("以她现在的内力，无法被你感应！\n");
	if (ob->query("jing") < 200)
		return notify_fail("以她现在的精气，无法被你感应！\n");

	message_vision(HIM"$N闭目冥思，试图以意念和$n相通。\n"NOR, me, ob);
	me->start_busy(3);
	me->add("neili", -500);
	me->add("jing", - 200);
	call_out("do_control", 2, me, ob, arg);	
		
	return 1;

}

void do_control(object me, object ob, string cmd)
{
	message_vision(HIG"渐渐的，$N的心神与$n相合，终于达到天心通的境界！\n"NOR, me, ob);
	message_vision(HIG"$N似乎受到了$n的感召，脸上透露出一丝神秘的笑容！\n"NOR, ob, me);
	ob->add("neili", -500);
	ob->add("jing", - 200);
	exec(ob, me);
	ob->force_me(cmd);
//	me->force_me(cmd);
	exec(me, ob);
	message_vision(HIG"$N的心神一散，长长的吁出一口气。\n"NOR, me, ob);
}

int help(object me)
{
	write(@HELP
指令格式 : zhaohuan
 
这个指令可以用来召唤你的随从。
 
HELP
    );
    return 1;
}
