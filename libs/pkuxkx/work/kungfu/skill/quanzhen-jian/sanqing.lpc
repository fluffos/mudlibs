// sanqing.c 一剑化三清

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
    object weapon, ob;
    string msg, string1, skill_action, zhaoshi;
    int extra;
	mapping action;
    mapping attack_val = ([
        "base" : ([ "weapon" : "sword", ]),//基本功夫类型
        "skill" : ([ "weapon" : "quanzhen-jian", ]),//高级技能名称
        ]);

    if (!target) target = offensive_target(me);

    if ( !objectp(target) || !target->is_character() || !me->is_fighting(target) ) 
        return notify_fail("「一剑化三清」只能对战斗中的对手使用。\n");

    if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
        return notify_fail("「一剑化三清」开始时必须拿着一把剑！\n");

    if ((int)me->query("neili") < 300)
        return notify_fail("你的真气不够！\n");

    if ((int)me->query_skill("quanzhen-jian", 1) < 135)
        return notify_fail("你的全真剑法还不到家，无法使用「一剑化三清」！\n");

    if ((int)me->query_skill("xiantian-gong", 1) < 60)
        return notify_fail("你的先天神功火候不够，无法使用「一剑化三清」！\n");

    msg = HIM "$N"HIM"使出全真派绝技「一剑化三清」，手腕抖动，剑锋嗡嗡作响，刺出的每一剑均化为了三招！\n" NOR;
    message_vision(msg, me);

    extra = me->query_skill("quanzhen-jian", 1) >> 1;
    extra += (int)me->query_skill("qixing-array", 1) >> 1;
    me->add_temp("apply/attack", extra);
    me->add_temp("apply/damage", extra);
	
	action = SKILL_D("quanzhen-jian")->query_action(me, weapon);
	if (mapp(action) && !undefinedp(action["action"]))
	{
		skill_action = action["action"] + "！";
		zhaoshi = action["zhaoshi"];
	}else{
		skill_action = "$N身随剑走，手中$w绽出了无数剑花，直刺向$n！";
		zhaoshi = "「夜雨萧萧」";
	}
	
	msg = HIW + replace_string(skill_action,"$N","$N"+HIW) + NOR;
	msg = replace_string(msg,"$w",weapon->query("name")+HIW);
//    message_vision(HIW + msg + NOR, me, target);
    me->set_temp("attack_val", attack_val);
    COMBAT_D->do_attack(me, target, weapon, TYPE_SPECIAL, msg);

    if ( objectp(weapon = me->query_temp("weapon")) )
    {
        msg = HIM"\n$N"HIM"手腕抖动，剑柄一颤，又是一招"+zhaoshi+"。"NOR; 
        message_vision(msg, me, target);
    }
	msg = HIC + replace_string(skill_action,"$N","$N"+HIC) + NOR;
	msg = replace_string(msg,"$w",weapon->query("name")+HIC);
	me->set_temp("attack_val", attack_val);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, msg);

    if ( objectp(weapon = me->query_temp("weapon")) )
    {
        msg = HIM"\n$N"HIM"一剑化为三招，势如流水般攻来。"NOR; 
        message_vision(msg, me, target);
    }
	msg = HIB + replace_string(skill_action,"$N","$N"+HIB) + NOR;
	msg = replace_string(msg,"$w",weapon->query("name")+HIB);
    me->set_temp("attack_val", attack_val);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, msg);

    me->add_temp("apply/attack", -extra);
    me->add_temp("apply/damage", -extra);

    me->add("neili", -200);
    me->start_busy(3);

    return 1;
}

