// tuwu.c

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int skill;
	int damage;
	string msg;
	object weapon;
	 if( !target ) target = offensive_target(me);

        if(me->query("family/master_id") != "feng qingyang")
           return notify_fail("你不是风清扬的弟子，不能使用绝招！\n");

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("以招破招只能在战斗中使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("你使用的武器不对。\n");

	if( (int)me->query_skill("lonely-sword", 1) < 200 )
		return notify_fail("你的独孤九剑不够娴熟，不会使用以招破招。\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("你内力不够了。\n");

	skill = me->query_skill("lonely-sword", 1);

	me->add("neili", -200);
	target->receive_damage("qi", (int)skill/ 3, me);
	message_combatd(HIC "$N随手几招向$n刺来,一看只下尽全是刺向$n武功的弱点
$n心中一慌.....不由的发出的怪叫声。\n"NOR,me,target);
    if (random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
    {
	message_combatd(
        HIR "$N手中的剑发出无数道的剑气,一道一道的剑气向$n刺去
$n两眼一黑，$n啥也看不见了！\n" NOR, me, target);
	target->start_busy(1);
	target->set_temp("block_msg/all",1);
	damage = (int)me->query_skill("lonely-sword", 1);
	damage = damage + random(damage);
	target->receive_damage("qi", damage, me);
	call_out("tuwu_end", (int) skill/30, me, target);
	target->start_busy(me->query_skill("lonely-sword",1)/40 + 2);
        me->start_busy(2);
        //	return 1;
    } else
    {
        me->start_busy(2);
        msg = HIY"$p情急智生，向后一跳...逃出了剑气的范围。\n"NOR;
        message_combatd(msg, me, target);
    }
    if(!target->is_fighting(me)) target->fight_ob(me);
//    if(userp(target)) target->fight_ob(me);
//    else if( !target->is_killing(me->query("id")) ) target->kill_ob(me);
    return 1;
}
void tuwu_end(object me, object target)
{
	target->enable_player();
	message_combatd("$N抹了抹满脸的"HIR"鲜血"NOR"，终于睁开了眼。\n", target);
	target->set_temp("block_msg/all", 0);
	write(HIR"你终于抹掉了满脸的鲜血，看到了周围的情景。\n"NOR);
	return;
}
