// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <combat.h>

#define LIU "「" HIY "狂剑" NOR "」"
string query_name() { return "狂剑"; }
inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(LIU "只能在战斗中对对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对，难以施展" LIU "。\n");

        if (me->query_skill("force") < 120)
                return notify_fail("你的内功的修为不够，难以施展" LIU "。\n");

        if (me->query_skill("jinshi-kuangjian", 1) < 120)
                return notify_fail("你的流星剑法修为不够，难以施展" LIU "。\n");

        if (me->query("neili") < 250)
                return notify_fail("你的真气不够，难以施展" LIU "。\n");

        if (me->query_skill_mapped("sword") != "jinshi-kuangjian")
                return notify_fail("你没有激发流星剑法，难以施展" LIU "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIY "$N" HIY "聚集了全身功力，顿时见到一个金色影子，一点剑芒，正在$n" 
              HIR "眼前扩大，快速功向$n。\n" NOR;
              

		ap = me->query_skill("sword");
        dp = target->query_skill("parry");
        if (ap / 2 + random(ap) > dp)
        {
                damage = me->query_skill("sword");
                me->add("neili", -150);
                
                msg += COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 65,
                                           HIR "无坚不摧的剑气，透过" + weapon->name() + HIR "侵来，使$n" 
                                           HIR "呼吸顿止，全身有若刀割，$n" HIR "尚未反应，顿时已受重创，鲜血飞溅！\n" NOR);
                me->start_busy(2);
        } else
        {
                me->add("neili", -60);
                
                msg += CYN "可是$p" CYN "并不慌乱，收敛心神，轻轻格挡开了$P"
                       CYN "的剑招。\n" NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}

