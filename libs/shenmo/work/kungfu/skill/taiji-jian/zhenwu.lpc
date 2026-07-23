// zhenwu.c 真武除邪

#include <ansi.h>
#include <combat.h>

#define PFM_NAME        "真武除邪"

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int ap, dp,i,attack_time;
                
        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }
        if (! target || ! me->is_fighting(target))
                return notify_fail("「" + PFM_NAME + "」只能对战斗中的对手使用。\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
                
        if ((int)me->query_skill("taiji-jian", 1) < 290)
                return notify_fail("你的太极剑法不够娴熟，不会使用「" + PFM_NAME + "」。\n");

        if ((int)me->query_skill("raozhi-roujian", 1) < 200)
                return notify_fail("你的绕指柔剑火候太浅。\n");

        if ((int)me->query_skill("yitian-zhang", 1) < 200)
                return notify_fail("你的倚天屠龙掌火候太浅。\n");

        if ((int)me->query_skill("paiyun-shou", 1) < 200)
                return notify_fail("你的排云推手火候太浅。\n");
                
        if ((int)me->query_skill("shenmen-jian", 1) < 200)
                return notify_fail("你的神门十三剑火候太浅。\n");
                                
        if ((int)me->query_skill("force", 1) < 250)
                return notify_fail("你的内功修为不够高，难以运用「" + PFM_NAME + "」。\n");

        if ((int)me->query_skill("taiji-shengong", 1) < 250)
                return notify_fail("你的太极神功修为不够高，难以运用「" + PFM_NAME + "」。\n");


                                    
        if ((int)me->query("neili") < 2000)
                return notify_fail("你现在真气不够，不能使用「" + PFM_NAME + "」。\n");

        if (me->query_skill_mapped("sword") != "taiji-jian")
                return notify_fail("你没有激发太极剑法，不能使用「" + PFM_NAME + "」。\n");

        msg = HIY "$N" HIY "闭目凝神，心如点转，一招充满太极剑意的「" HIW + PFM_NAME +
              HIY "」缓缓使出，剑招返朴归真，看似平淡无奇，\n实则汇集了天地之间的正气，"
              HIY "由手中" + weapon->name()+ "幻化出无数太极剑圈，铺天盖地的压向$n！\n" NOR;

        ap = me->query_skill("sword");
        dp = target->query_skill("parry");
        
        // 增强 ap
        if (me->query("shen") >= 10000) ap += (30 + random(20));
        if (target->is_bad()) ap = ap * 3 / 2;
        // 削弱 ap
        //if (me->is_not_good()) ap = ap / 2;
        if (me->query("shen") <= 0) ap = ap / 3;
        if (target->query("shen") >= 10000) ap = ap * 4 / 5;

        if (wizardp(me) && me->query("env/combat_test"))
        {
                tell_object(me, HIY "AP: " + ap + ". DP: " + dp + ".\n" NOR);
        }
        if (ap * 2 / 3 + random(ap) > dp)
        {
                damage = me->query_skill("sword")*3;

                me->add("neili", -(damage/2+300));
//              tell_object(me, HIC "DAMAGE: " + damage + ".\n" NOR);
       target->add("qi",-damage+500);
		target->add("eff_qi",-damage+500);
                msg += HIR "\n$p" HIR "被$P的正气所慑，竟然吓得顾不上招架，"
                                           "这一剑自胸口向小腹横划而过，\n顿时鲜血飞溅！\n" NOR;
                me->start_busy(3);
        } else 
        {
                msg += WHT "\n然而$p" WHT "竟然丝毫不以为意，轻描淡写的将$P"
                       WHT "的剑招架开。\n" NOR;
                me->add("neili", -50);
                me->start_busy(4);
        }
        message_combatd(msg, me, target, 0, 1);
        //msg="";
        msg = HIW "接跟着，$N" HIW "一声清啸，手中" + weapon->name() +
              HIW "龙吟不定，化出一个个圆圈，把$n" HIW "圈在当"
              "中。\n" NOR;
                        msg += HIY "结果$p" HIY "被$P" HIY
                       "攻了个措手不及，连连后退不暇！\n" NOR;
attack_time = (int)me->query_skill("taiji-jian", 1)/30;
                if (attack_time > 9)
                attack_time = 9;
        msg += HIC "最后 $N" HIC "一声长啸，灵台清明，凝神归元，使出太极剑中的剑轮岚转。\n"
              HIY "手中" + weapon->name() + HIY "招式陡然变得凌厉无比，一转念"
              HIY "间已然攻出" + chinese_number(attack_time) + "招！\n" NOR;
message_combatd(msg, me, target);
                	me->add_temp("apply/attack", 100);
	me->add_temp("apply/damage", 800);

        for (i = 0; i < attack_time; i++)
        {
                 if (random(3)==0) target->start_busy(2);
                COMBAT_D->do_attack(me, target, weapon, 0);
        }
	me->add_temp("apply/attack", -100);
	me->add_temp("apply/damage", -800);

        return 1;
}

