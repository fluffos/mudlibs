#include <ansi.h>
#include <combat.h>

#define AOJUE "「" HIR "中华傲诀" NOR "」"

inherit F_SSERVER;

string final(object me, object target, int damage);

int perform(object me, object target)
{
        object weapon;
        string wn, msg;       
        int ap, dp, damage, lvl, idle, i, count;

        if (userp(me) && ! me->query("can_perform/china-aojue/aojue"))
                return notify_fail("你所使用的外功中没有这种功能。\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(AOJUE "只能对战斗中的对手使用。\n");

        if ( me->query("int") < 15 ) 
                return notify_fail("你的先天悟性不足，无法使用此招。\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对，难以施展" AOJUE "。\n");

        if ((int)me->query_skill("force") < 450)
                return notify_fail("你的内功修为不够，难以施展" AOJUE "。\n");

        if ((int)me->query("max_neili") < 6000)
                return notify_fail("你的内力修为不够，难以施展" AOJUE "。\n");

        if ((int)me->query_skill("china-aojue", 1) < 300)
                return notify_fail("你中华傲诀火候不够，难以施展" AOJUE "。\n");

        if ((int)me->query_skill("idle-force", 1) < 300)
                return notify_fail("你发呆神功等级不够，难以施展" AOJUE "。\n");

        if (me->query_skill_mapped("sword") != "china-aojue")
                return notify_fail("你没有激发中华傲诀为剑法，难以施展" AOJUE "。\n");

        if (me->query_skill_mapped("force") != "china-aojue")
                return notify_fail("你没有激发中华傲诀为内功，难以施展" AOJUE "。\n");

        if ((int)me->query("neili") < 800)
                return notify_fail("你现在真气不够，难以施展" AOJUE "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        wn = weapon->name();

        message_combatd(HIM "$N" HIM "微微一笑，轻挥手中" + wn +
                        HIM "，进而剑随音转，口中低吟道：\n" NOR, me, target);
      
       lvl = (int)me->query_skill("china-aojue", 1);
       idle = (int)me->query_skill("idle-force", 1);

        // 第一招，空手攻击一个单招
       if ( me->query_skill_mapped("strike") == "china-aojue" &&
            me->query_skill_prepared("strike") == "china-aojue" )
       {
           ap = me->query_skill("strike") + me->query_skill("martial-cognize");
           damage = ap + random(ap);
           dp = target->query_skill("parry") + target->query_skill("dodge");        
 
           message_vision(HIG "\n  去年今日此门中\n\n" NOR, me, target); 

           if (ap * 4/ 5 + random(ap) > dp)
           {
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 
                120 + random(10));        

            } else
            {
                msg = CYN "可是$n" CYN "收敛心神，奋力招"
                      "架，将剑招卸于无形。\n" NOR;
             }
            message_vision(msg, me, target);
        }

        // 第二招，兵器攻击九剑

        ap = me->query_skill("sword") + me->query_skill("martial-cognize");
        damage = ap + random(ap);
        dp = target->query_skill("parry") + target->query_skill("dodge");        

        message_vision(HIM "\n    人面桃花相映红\n\n" NOR, me, target);

        count = lvl / 9;

        if (count > 60 ) count = 60;

        me->add_temp("apply/attack", count);
        for (i = 0; i < 9; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(2) == 1 && ! target->is_busy())
                        target->start_busy(1);

                COMBAT_D->do_attack(me, target, 0, i * 4 );
        }
        me->add_temp("apply/attack", -count);


        // 第三招，兵器一个单招，判断发呆神功
        ap = me->query_skill("sword") + me->query_skill("martial-cognize", 1);
        damage = ap + random(ap);
        dp = target->query_skill("parry") + target->query_skill("dodge");        
        message_vision(HIY "\n      人面不知何处去\n\n" NOR, me, target); 
  
        if (ap * 4 / 5 + random(ap) > dp)
        {
                msg = COMBAT_D->do_damage(me, target, WEAPON_ATTACK, damage, 
                90 + random(10),(: final, me, target, damage, weapon, lvl :));              

        } else
        {
                msg = CYN "可是$n" CYN "收敛心神，奋力招"
                      "架，将剑招卸于无形。\n" NOR;
        }
        message_vision(msg, me, target);


        me->start_busy(3 + random(2));
        me->add("neili", -600 - random(200));
        return 1;
}


string final(object me, object target, int damage)
{
        return  HIR "$n" HIR "身法稍慢，已被$N剑招刺中，惨不堪言！\n" NOR;
}

