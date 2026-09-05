// chan.c 太极剑法「缠」字诀
//seagate@pkuxkx 2010/11/02
//判师降低成功率，而不是以前提高成功率
//成功率计算使用combat_ratio函数进行拟合。

#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
    string msg;
    object weapon;
    object tweapon;
    int bt, pflv, rt;
    int tj_level, busy_time = 1;

    if (!target) target = offensive_target(me);

    if (!objectp(target) || !target->is_character() || !me->is_fighting(target))
        return notify_fail("牵制攻击只能对战斗中的对手使用。\n");

    tweapon = target->query_temp("weapon");
    tj_level = (int)me->query_skill("taiji-shengong", 1) / 150;
    bt = me->query("betrayer");
    if (bt < 0) bt = 0;
    
    if (target->is_busy())
        return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        if (!objectp(weapon = me->query_temp("secondary_weapon"))
            || (string)weapon->query("skill_type") != "sword")
            return notify_fail("你没拿剑,还想使剑法的绝招?别作梦了!\n");

    if ((int)me->query_skill("taiji-jian", 1) < 40)
        return notify_fail("你的太剑法极不够娴熟，不会使用「缠」字诀。\n");

    if ((int)me->query_skill("taiji-shengong", 1) < 40)
        return notify_fail("你的太剑神功等级不够，不能发挥「缠」字诀。\n");

    if ((int)me->query("neili") < 400)
        return notify_fail("你的内力不够。\n");

	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "武当派")
		pflv = 0;

    msg = HIG "$N"HIG"手腕灵动运剑成圈，顷刻只见圆转剑意不绝，$n"HIG"只觉得处处虚招处处实，根本无从下手。\n"NOR;

//命中率B-级，每判一次师下调两个大级别，直到命中率下调到F-级最低级。
    if (F_KUNGFU->hit_rate(me->query("combat_exp"), target->query("combat_exp"), 6 + bt * 6, me, target))
    {
        msg += RED "$p"RED"只觉剑势连绵不绝，旧力未尽，新力便生，简直无有穷尽，\n只能见招拆招，疲于应对，不觉已深陷太极剑意之中，无法出招。\n"NOR;
        F_KUNGFU->hit_busy("confuse", (int)me->query_skill("taiji-jian") / (8 * (bt + 1)), target);
        if (tweapon && (string)me->query_skill_mapped("force") == "taiji-shengong" && random(tj_level + 1) > 1 && bt < 1)
        {
            msg += HIB"$N"HIB"默运太极神功，心中竟无半点渣滓，以意运剑，网住了$n"HIB"手中的" + tweapon->name() +
               HIB"。\n$n"HIB"一个把持不住，手中" + tweapon->name() + HIB"卷入剑圈之中，脱手而飞！\n"NOR;
            //如果是no_get的兵器，则直接掉目标自己身上，以免捡不回来
            if (tweapon->unequip())
            {
                if (tweapon->query("no_get"))
                    tweapon->move(target);
                else
                    tweapon->move(environment(target));
            }
        }
		if (pflv>=4 && random(2))
			busy_time = 0;
    }
    else
    {
		if (pflv>=3)
		{
			switch (pflv)
			{
				case 3: rt=7; break;
				case 4: rt=17; break;
				default: rt=22; break;
			}
			if (random(100)<(33+rt))
				busy_time = 0;
			else
				busy_time = 1+random(2);
		}
		else 
			busy_time = random(100) % 3;
        msg += HIW "$p"HIW"暗自凝神，以不变应万变，招数直来直往，中宫直入，向剑圈中直捣过去。\n只听得「铮」一声清响，剧烈碰撞之下$P"HIW"剑诀为敌所破，无以为继，被迫撤剑收招。\n"NOR;
    }
    if (busy_time>0) me->start_busy(busy_time);
    me->add("neili", -100);
	message_vision(msg, me, target);
    return 1;
}

