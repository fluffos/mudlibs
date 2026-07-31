// zhong.c 种生死符
// by Lonely

#include <ansi.h>

inherit F_SSERVER;
#include <balance.h>

int perform(object me, object target)
{
        int ap, dp, lvl;
        object obj;
        string msg;

        if (! target) target = offensive_target(me);

        if (userp(me) && ! me->query("can_perform/liuyang-zhang/zhong"))
                return notify_fail("你虽听过生死符的名字，但是不懂得如何催动内力种符。\n");

        if (! objectp(target) || target == me 
        ||  target->query("id") == "mu ren")
                return notify_fail("你要往谁身上种生死符？\n");
                
        lvl  = me->query_skill("liuyang-zhang", 1); 

        if (! me->is_fighting() || ! target->is_fighting() || ! living(target))
                return notify_fail("你必须在战斗中才能种生死符！\n");

        if (! objectp(obj=present("jiudai", me)))
                return notify_fail("你身上没有酒袋，不能化水为冰。\n");

        if ((int)me->query_skill("bahuang-gong", 1) < 150
                && (int)me->query_skill("beiming-shengong", 1) < 150)
                return notify_fail("你的逍遥派内功功力不够，不能种生死符！\n");

        if (me->query_skill_mapped("force") != "bahuang-gong"
        &&  me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("你没有运用逍遥派内功！\n"); 

        if ((int)me->query_skill("liuyang-zhang", 1) < 150)
                return notify_fail("你的天山六阳掌功力不够，不能种生死符！n");

        if ((int)me->query("neili", 1) < 1000)
                return notify_fail("你的内力不够，不能种生死符。\n");

        message_combatd(
                WHT "$N突然从背后掏出一个酒袋，往自己掌心倒了些酒水。"
                "$N左掌掌心中暗运内功，逆转真气，\n不多时已将掌中酒水化成七八片寒冰，右掌"
                "蕴出一缕白线，猛地向$n的胸口射了过去！\n\n" NOR,
                me, target );

        ap = ap_power(me, "strike") + me->query("str") * 20; 
        dp = dp_power(target, "force") + target->query("con") * 20; 
             
        if (ap / 2 + random(ap) > dp)
        {
                msg = HIR "$n" HIR "只觉胸口一闷，一丝凉意直入肺腑，脑中一片空白茫然不知所措！\n" NOR;
         
                target->affect_by("ss_poison",
                                  ([ "level" : lvl, 
                                     "id"    : me->query("id"), 
                                     // "remain": -1, 
                                     "duration" : lvl / 100 + random(lvl / 10) ,
                                  ])); 
                
                if (! target->is_busy())
                                target->start_busy(1);
                me->start_busy(2);
        } else
        {
                me->start_busy(2);
                msg = CYN "可是$n" CYN "见势不妙，猛一运力把白线逼了回去。\n" NOR;
                tell_object(me, HIG "你觉得手指一阵冰凉，暗叫一声不好，赶经运功抵抗！\n" NOR); 
        }
        message_combatd(msg, me, target);
        
        me->want_kill(target);
        if (! target->is_killing(me)) target->kill_ob(me);

        return 1;
}



