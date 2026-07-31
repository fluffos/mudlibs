// riyun.c

#include <ansi.h>

int exert(object me)
{	
	int nb, nx, nh, improve;
	nx = (int)me->query("max_qi", 1);
	nb = (int)me->query("eff_jing", 1);
	nh = (int)me->query_skill("linji-zhuang", 1);

	if ((int)me->query_skill("linji-zhuang", 1) < 300)
		return notify_fail("你的临济十二庄修为还不够。\n");

	if( (int)me->query("neili") < (int)me->query("max_neili")/3 )
		return notify_fail("你的真气不够。\n");

	write(RED"你五心向天，运行日月二庄，益气升阳，益阴潜阳，
升降反正，天地二气交泰于身，并配合峨嵋九阳功。灭绝之间顿时大起!\n"NOR);

	message_vision(HIR"只见$N脸上红光时隐时现。劲气四溢！！\n"NOR, me);
me->set("qi",me->query("max_qi")*3);
me->set("eff_qi",me->query("max_qi")*3);
me->set("jing",me->query("max_jing")*3);
me->set("eff_jing",me->query("max_jing")*3);
me->add("neili",-me->query("neili")/2);
me->start_busy(3);
return 1;
}
