// shout.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str;
	if (!userp(me)) return 0;
	if (!arg) return notify_fail("你想要大叫什么？\n");
	if (present(arg, environment(me))) return 0;
	if (!wizardp(me) && me->query("max_neili") < 4000 ) {
		write("以你目前的内力状况，无法使用千里传音。\n");
		return 1;
	}
	if (!wizardp(me) && me->query("neili") < 4000) {
		write("以你目前的内力状况，无法使用千里传音。\n");   
		return 1;
	}
	if (me->query_condition("shout_condition")) {
		write("你刚刚纵声长啸过，先休息一会再说吧。\n");
		return 1;
	}
	if (!wizardp(me)){
		if (strlen(arg) > 100)
			arg = arg[0..99];
		str = me->name(1) + "(" + capitalize(me->query("id")) + ")";
		me->add("neili", -2000);
		me->apply_condition("shout_condition", 6);
	} else str = me->name();
	message("channel", "\r" + HIW + str + "纵声长啸：「" + arg + "」\n" NOR, users(), me);
	write(HIW "你纵声长啸：「" + arg + "」\n" NOR);
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : shout <讯息>
 
这个指令让你将 <讯息> 传送出去, 所有正在游戏中的人都会听见你的话。
最低要求：空手最大内力 4000，基本内力 4000
 
see also : tune
HELP
    );
    return 1;
}
