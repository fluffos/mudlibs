#include <ansi.h>
#include <combat.h>

#define HUAN "「" HIM "云霞幻生" NOR "」"

inherit F_SSERVER;

string final(object me, object target, int damage);

int perform(object me, object target)
{
        object weapon, weapon2;
        int skill, ap, dp, damage;
        string wn, msg;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(HUAN "只能对战斗中的对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "staff")
                return notify_fail("你使用的武器不对，难以施展" HUAN "。\n");

	if( (int)me->query_skill("hamagong", 1) < 100 )
		return notify_fail("你的蛤蟆功不够娴熟.\n");
		
        skill = me->query_skill("lingshe-zhangfa", 1);

        if (skill < 120)
                return notify_fail("你灵蛇杖法等级不够，难以施展" HUAN "。\n");

        if (me->query_skill("dodge") < 180)
                return notify_fail("你的轻功火候不够，难以施展" HUAN "。\n");
 
        if (me->query_skill_mapped("staff") != "lingshe-zhangfa")
                return notify_fail("你没有激发灵蛇杖法，难以施展" HUAN "。\n");

        if (me->query("neili") < 200)
                return notify_fail("你现在的真气不够，难以施展" HUAN "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        wn = weapon->name();

        message_vision(HIM "\n$N" HIM "蓦地施出「" HIW "云霞幻生\n"
                     HIM "」绝技，手中" + wn + HIM "由一变二，\n"
                     "由二变四，由四变八，由八变十六……竟幻出\n"
                     "无数条灵蛇" + wn + HIM "。杖影层层叠叠朝四周\n"
                     "疾刺而出，企图封锁$n" HIM "的退路。\n" NOR,
                     me, target);

        ap = me->query_skill("staff");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap * 4 / 3) > dp)
        {
                me->add("neili", -80);
                damage = 150 + ap / 6 + random(ap / 6);
        msg = HIR "$p大惊失色之下接连被$P击中数杖"
              "，当即疼痛难当，";
target->add("qi",-damage*2);
target->add("eff_qi",-damage);
target->apply_condition("snake_poison",10);
target->apply_condition("chanchu_poison",10);
target->apply_condition("qx_snake_poison",20);
        if (random(3) >= 1 && ! target->is_busy())
        {
                target->start_busy(5);
                msg += "无暇反击。\n" NOR;
        } else
                msg += "急声长呼。\n" NOR;

                me->start_busy(1);
        } else
        {
                msg = CYN "$n" CYN "大惊之下急忙跃开数步，方才摆脱$N"
                      CYN "棍影的范围。\n" NOR;
                me->add("neili", -50);
                me->start_busy(2);
        }
        message_vision(msg, me, target);

        return 1;
}
