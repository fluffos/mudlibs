// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

string query_name() { return "白首"ZJBR"太玄"; }

#define JING "「" HIW "白首太玄经" NOR "」"

inherit F_SSERVER;

string final1(object me, object target, int damage, int lvl);
string final2(object me, object target, int damage);
string final3(object me, object target, int damage, int lvl, string msg);

int perform(object me, object target)
{
        int damage;
        string msg, sub_msg;
        int ap, dp;
        int flag = 0;
        int lvl;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(JING "只能对战斗中的对手使用。\n");

        if ((int)me->query_skill("force", 1) < 380)
                return notify_fail("你内功修为不够，难以施展" JING "。\n");

        if ((int)me->query("max_neili") < 5000)
                return notify_fail("你内力修为不够，难以施展" JING "。\n");

        lvl = (int)me->query_skill("taixuan-gong", 1);
        if (lvl < 380)
            return notify_fail("你太玄功火候不够，难以施展" JING "。\n");

        if (me->query_skill_mapped("force") != "taixuan-gong")
                return notify_fail("你现在没有激发太玄功为内功，难以施展" JING "。\n");

     //   if (me->query_skill_prepared("unarmed") != "taixuan-gong")
       //         return notify_fail("你现在没有准备使用太玄功，难以施展" JING "。\n");

        if ((int)me->query("neili") < 850)
                return notify_fail("你现在真气不够，难以施展" JING "。\n");

        if (me->query_skill("martial-cognize", 1) < 100)
                return notify_fail("你武学修养不足，难以施展" JING "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        message_combatd(HIM "\n$N" HIM "情不自禁的纵声长啸，霎时之间，千百种招式纷至沓来，涌"
                     "向心头。$N" HIM "随手挥舞，已是不按次序，但觉无论何种招式皆能随心所欲"
                     "，既不必存想内息，亦不须记忆招数，石壁上的千百种招式，自然而然的从心"
                     "中传向手足，尽数袭向$n" HIM "。\n" NOR, me, target);

        damage = me->query_skill("unarmed"); 
        ap = me->query_skill("unarmed") + me->query_str() * 20;

        // 第一招，判断对方臂力
        dp = target->query_skill("parry") + target->query_str() * 20;

        message_combatd(HIW "\n$N" HIW "突然间只觉得右肋下‘渊液穴’上一动，一道热线沿着‘足少"
                     "阳胆经’，向着‘日月’、‘京门’二穴行去，一招‘十步杀一人’的" + sub_msg + 
                     "法已随意使出，各种招式源源而出，将$n" HIW "笼罩。\n" NOR, me, target);

        if (ap / 2 + random(ap) > dp)
        {
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 30 + random(10),
                                         (: final1, me, target, damage, lvl :));
        } else
        {
                msg = HIC "$n" HIC "气贯双臂，凝神以对，竟将$N" HIC "之力卸去。\n" NOR;
        }
        message_combatd(msg, me, target);

        ap = me->query_skill("unarmed") + target->query("int") * 20;
        // 第二招，判断对方悟性
        dp = target->query_skill("parry") + target->query("int") * 20;

        message_combatd(HIW "\n$N" HIW "肌肤如欲胀裂，内息不由自主的依着‘赵客缦胡缨’那套经脉运"
                     "行图谱转动，同时手舞足蹈，似是大欢喜，又似大苦恼。\n" NOR, me);

        if (ap / 2 + random(ap) > dp)
        {
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 30 + random(10),
                                     HIY "$n" HIY "冷笑一声，觉得$N" HIY "此招肤浅之极，于"
                                     "是随意招架，猛然间，「噗嗤」！一声，一道真气已穿透$n" HIY "的胸膛，鲜血不断涌出。\n" NOR, me , target);
        } else
        {
                msg = HIC "$n" HIC "会心一笑，看出$N" HIC "这招中的破绽，随意施招竟将这招化去。\n" NOR;
        }
        message_combatd(msg, me, target);

        ap = me->query_skill("unarmed") + target->query_con() * 20;
        // 第三招，判断对方根骨
        dp = target->query_skill("force") + target->query_con() * 20;

        message_combatd(HIW "\n‘赵客缦胡缨’既毕，接下去便是‘吴钩霜雪明’，$N" HIW "更"
                    "不思索，石壁上的图谱一幅幅在脑海中自然涌出，自‘银鞍照白马’直到‘谁能书阁下’，"
                    "一气呵成的使了出来。\n" NOR, me);

        if (ap / 2 + random(ap) > dp)
        {
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 25 + random(10),
                                           (: final2, me, target, damage :));
        } else
        {
                msg = HIC "$n" HIC "默运内功，内劲贯于全身，奋力抵挡住$N" HIC "这招。\n" NOR;
        }
        message_combatd(msg, me, target);

        // 第四招，判断对方身法

        ap = me->query_skill("unarmed") + target->query_dex() * 20;        
        dp = target->query_skill("dodge") + target->query_dex() * 20;

        message_combatd(HIW "\n待得‘谁能书阁下’这套功夫演完，$N" HIW "只觉气息逆转"
                     "，‘不惭世上英’倒使上去。\n" NOR, me);

        if (ap / 2 + random(ap) > dp)
        {
                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 30 + random(10),
                                          (: final3, me, target, damage, lvl, sub_msg :));
        } else
        {
                msg = HIC "$n" HIC "见这招来势凶猛，身形疾退，瞬间飘出三"
                      "丈，方才躲过$N" HIC "这招。\n" NOR;
        }
        message_combatd(msg, me, target);

        me->start_busy(3 + random(3));
        me->add("neili", -800);
        return 1;
}

string final1(object me, object target, int damage, int lvl)
{
        target->add("neili", -(lvl + random(lvl)));

        return  HIY "$n" HIY "却觉$N" HIY "这招气势恢弘，于是运力奋力抵挡。但是无奈这"
                "招威力惊人，$n" HIY "闷哼一声，倒退几步，顿觉内息涣散！\n" NOR;
}

string final2(object me, object target, int damage)
{
        target->receive_damage("jing", damage / 2, me);
        target->receive_wound("jing", damage / 4, me);
        return  HIY "$n" HIY "心中一惊，但见$N" HIY "这几招奇异无比，招式变化莫测，"
                "但威力却依然不减，正犹豫间，$n" HIY "却已中招，顿感精力不济，浑"
                "身无力。\n" NOR;
}

string final3(object me, object target, int damage, int lvl, string msg)
{
        target->start_busy(4 + random(lvl / 50));
  
        return  HIY "$N" HIY + msg + "法奇妙无比，时而宛若游龙，时而"
                "宛若惊鸿，霎那间$n" HIY "已遍体鳞伤，$N" HIY "猛然将招式一"
                "转，陡然加快，将$n" HIY "团团围住，竟无一丝空隙！\n" NOR;

}

