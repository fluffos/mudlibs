#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object ob;
        object weapon;
        string msg;
        ob=me->query_temp("weapon");
        if( !target ) target = offensive_target(me); 

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(HIC"「风"HIW"雪"HIC"回剑」"NOR+"只能对战斗中的对手使用。\n"); 
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("你使用的武器不对。\n"); 

         if((int)me->query_skill("bingxue-xinfa",1) < 150)
                return notify_fail("你的冰雪心法修为不够，还不能运用"+HIC"「风"HIW"雪"HIC"回剑」"NOR+"。\n");

        if((int)me->query_skill("xueshan-sword",1) < 150)
                return notify_fail("你的雪山剑法不够娴熟，使不出"+HIC"「风"HIW"雪"HIC"回剑」"NOR+"！\n");

        if((int)me->query("neili") < 220)
                return notify_fail("你内力还现在不够。 \n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");

        msg = HIC "$N回剑旋舞，剑势不断加快，剑气呼啸四散，如片片雪花遇风，飘然而出。\n形成一个雪花形旋涡，将$n裹在内里。\n";
        if(random(me->query_skill("sword",1)+me->query_skill("xueshan-sword",1)+me->query_skill("dodge",1)) > ((int)target->query_skill("dodge",1))) {
                msg +=HIG "$n只觉得四周压力越来越大，道道暗流缠绕周身，几乎动弹不得。\n" NOR;
                target->start_busy( (int)me->query_skill("xueshan-sword",1) / 50+2);
                me->add("neili", -100);
        } else {
                msg +=HIR "可是$n运足内力，雪花顿时全部溶解，一片不剩，脱出重围。\n" NOR;
                me->start_busy(2);
        }
        message_vision(msg, me, target);
        if(!target->is_fighting(me)) target->fight_ob(me);
        return 1;
}

