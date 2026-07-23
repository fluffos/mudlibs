#include <ansi.h>
#include <combat.h>

#define SHEN "「" HIM "五神朝元势" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg, wn;
        object weapon;
        int ap, dp;
                int count;
	int i, attack_time;
        me = this_player();


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(SHEN "只能在战斗中对对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对，难以施展" SHEN "。\n");

	if( (int)me->query_skill("yunlong-shengong", 1) < 150 )
		return notify_fail("你的云龙神功不够高。\n");
	if( (int)me->query_skill("yunlong-jian", 1) < 150 )
		return notify_fail("你的云龙剑法还不够纯熟！\n");
        if (me->query_skill_mapped("sword") != "yunlong-jian")
                return notify_fail("你没有激发云龙剑法，难以施展。\n");

        if ((int)me->query_skill("force", 1) < 220)
                return notify_fail("你的内功火候不够，难以施展" SHEN "。\n");

        if ((int)me->query_skill("dodge", 1) < 200)
                return notify_fail("你的轻功火候不够，难以施展" SHEN "。\n");  

        if ((int)me->query("max_neili") < 5500)
                return notify_fail("你的内力修为不足，难以施展" SHEN "。\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("你现在的真气不够，难以施展" SHEN "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        wn = weapon->name();

        msg = HIM "\n$N" HIM "一声怒喝，内劲暴涨，手中" + wn +
              HIM "变幻万千，霎那间化作红黄蓝绿白五道剑光，纵"
              "横飞扬。\n$P身法蓦地变快，随着剑光同时将『" HIR
              "祝融" HIM "』、『" HIY "紫盖" HIM "』、『" NOR
              WHT "石廪" HIM "』、『" HIG "芙蓉" HIM "』、『"
              HIW "天柱" HIM "』\n五套剑法交替使出，电光火石间"
              "已袭向$n" HIM "全身。" NOR;

//        message_sort(msg, me, target);
        
        ap = me->query_skill("yunlong-jian", 1) +
             me->query_skill("parry", 1);

        dp = target->query_skill("dodge", 1) +
             target->query_skill("parry", 1);

        if (ap * 2 / 3 + random(ap) > random(dp))
        {
                damage = me->query_skill("yunlong-jian", 1) +
                         me->query_skill("force", 1) +
                         me->query_skill("parry", 1);

                damage += random(damage / 2);

                // 五分之一的几率可被招架
                if (random(10) <= 1 && ap / 2 < dp)
                {
                        damage = damage / 3;

                               target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIG "\n$n" HIG "见$N" HIG "五道剑光剑势"
                                                  "惊人，急忙收敛心神奋力招架。\n哪知$P这"
                                                  "招力道非凡，$p一声闷哼，连退几步，喷"
                                                  "出一口鲜血。\n" NOR;
                        me->add("neili", -100);
                        me->start_busy(3);
                } else 
                {
                               target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "\n$n" HIR "见$N" HIR "五道剑光缤纷"
                                                  "洒落，交错纵横，呼啸着向自己袭来。\n心"
                                                  "底不由大惊，登时听得“噗嗤”一声，剑"
                                                  "气透体而过。\n" NOR;

                        me->add("neili", -100);
                        me->start_busy(3);
                }
        } else
        {
                msg = CYN "\n然而$n" CYN "以快对快，飞身一跳"
                      "已然躲过$N" CYN "这一招。\n" NOR;
                me->add("neili", -150);
                me->start_busy(3);
        }
        message_vision(msg, me, target);
count = ap / 3;
                attack_time += random(ap / 40);
        if (attack_time > 7)
                attack_time = 7;

        me->add_temp("apply/attack", 80);
        me->add_temp("apply/damage", count / 2);
        me->add("neili", -attack_time * 30);
	me->start_busy(3);

        me->set_temp("perform_wushenjian/qian", 1);
	for (i = 0; i < attack_time; i++)
	{
		if (! me->is_fighting(target))
		       break;

                if (! target->is_busy() && random(3) == 1)
                       target->start_busy(2);
 
	        COMBAT_D->do_attack(me, target, weapon, 0);
	}
        me->delete_temp("perform_wushenjian/qian");

        me->add_temp("apply/attack", -80);
        me->add_temp("apply/damage", -count / 2);

        return 1;
}
