#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon,ob;
        int skill,dodge,attack;
        string msg;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「独孤九剑」只能对战斗中的对手使用。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("独孤九剑必须用剑才能施展。\n");
         if( (int)me->query_skill("dugu-jiujian", 1) < 151 )
                return notify_fail("你的独孤九剑练得不够熟练，不会使用绝招。\n");
            if( (int)me->query_skill("zixia-gong", 1) < 101 )
                   return notify_fail("你的内功心法不到家不能使用独孤九剑！\n");
            if( (int)me->query_skill("huashan-shenfa", 1) < 101 )
                   return notify_fail("你的身法不到家恐怕使不出独孤九剑！\n");
            if( (int)me->query_skill("pishi-poyu", 1) < 101 )
                   return notify_fail("你的拳脚本领都没练到家怎能使用独孤九剑？\n");
        if( (int)me->query("shen") < 5000  ) 
                return notify_fail("[独孤九剑]讲究的是凌云正气，你？......\n");
        if( (int)me->query("neili") < 200  ) 
                return notify_fail("你的内力不够。\n");
// 不是feng 弟子，不能 enable sword dugu-jiujian,所以没必要在这里限制 /program add
      dodge = target->query_skill("dodge")*2;
      attack = target->query_skill("sword")*2;
      msg = HIW "$N使出「"HIG"独孤九剑"HIW"」绝技，身法陡然加快，猛地连出9招！\n"NOR;
        message_vision(msg, me, target);
        me->add("neili", -200);
        me->clean_up_enemy();
        ob = me->select_opponent();
        msg = HIC"\n第一剑！「"HIG"独孤九剑"HIY"飞星式"HIC"」\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        msg = HIW"\n第二剑！「"HIG"独孤九剑"HIC"落沙式"HIW"」\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        msg = HIY"\n第三剑！「"HIG"独孤九剑"HIW"奔流式"HIY"」\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        msg = HIR"\n第四剑！「"HIG"独孤九剑"BBLU+HIW"行空式"NOR+HIR"」\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        msg = BLU"\n第五剑！"HIB"「"HIG"独孤九剑"HIR"横扫式"BLU"」\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        msg = HIG"\n第六剑！「"HIG"独孤九剑"RED"直刺式"HIG"」\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        msg = CYN"\n第七剑！「"HIG"独孤九剑"HIY"绝情式"NOR+CYN"」\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        msg = HIW+BLK"\n第八剑！「"HIG"独孤九剑"HIB"斜劈式"HIW+BLK"」\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        msg = MAG"\n第九剑！"HIR"「"HIG"独孤九剑"HIY"之"U+HIG"九"HIW"天"HIY"御"HIW+BLK"剑"HIR"术"NOR+HIR"」\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
           msg = HIW"\n结果$n被$N攻了个措手不及。\n"NOR;
           message_vision(msg, me, target);
        if (me->query("family/family_name") != "华山派")
        {
        if( me->is_fighting() ) me->start_busy(2+random(2));
        }
        else
        {
        if( me->is_fighting() ) me->start_busy(1+random(2));
        }
        return 1;
}
