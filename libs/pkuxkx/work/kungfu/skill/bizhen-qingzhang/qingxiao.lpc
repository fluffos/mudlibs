// File         : qingxiao.c
// Created By   : iszt@pkuxkx, 2006-09-19

#include <ansi.h>
inherit F_SSERVER;

string perform_name(){ return HIG"碧针清啸"NOR; }

int perform(object me, object target)
{
        object weapon;
        string msg;
        
        if( !target ) target = offensive_target(me);

        if( !target
        || !target->is_character()
        || !me->is_fighting(target) 
        || !living(target))
                return notify_fail("「碧针清啸」只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("bizhen-qingzhang", 1) < 200 )
                return notify_fail("你的碧针清掌功力太浅。\n");
        if( me->query_skill_prepared("strike") != "bizhen-qingzhang" )
                return notify_fail("你没有使用碧针清掌，不能使用「碧针清啸」。\n");
        if( (int)me->query_skill("force", 1) < 200 )
                return notify_fail("你的基本内功修为不够，难以驾驭真气。\n");
        if( (int)me->query("max_neili") < 5000 )
                return notify_fail("你的内力修为太浅，使不出「碧针清啸」。\n");
        if( (int)me->query("neili") < 4000 )
                return notify_fail("你的真气不够，使不出「碧针清啸」。\n");
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("你手里拿着武器，无法全力施展「碧针清啸」。\n");

        if( me->query_temp("qingxiao") )
                return notify_fail("你正在使用「碧针清啸」！\n");
                
        me->set_temp("qingxiao",1);
        me->add("neili", - 100 - me->query_skill("bizhen-qingzhang",1));

        me->add_temp("apply/attack",me->query_skill("bizhen-qingzhang",1)/2);
        msg = HIR"\n$N"HIR"一声清啸，身法骤然加快，内力疾吐，一路"HIG"「碧针清掌」"HIR"更是威力大增！\n"NOR;
        message_vision(msg,me,target);

        call_out("remove_effect", 1, me);
        return 1;
}

void remove_effect(object me)
{
        if( ( me->query_temp("weapon")
        || me->query_temp("secondary_weapon")
        || me->query_skill_prepared("strike") != "bizhen-qingzhang"
        || !me->is_fighting()
        || me->query("neili") < 1000)
        && me->query_temp("qingxiao") ){
                me->delete_temp("qingxiao");
                me->add_temp("apply/attack",-me->query_skill("bizhen-qingzhang",1)/2);
                message_vision(RED"\n$N内力不济，不再使用「碧针清啸」。\n" NOR,me);
                return;
        }
        if( me->query_temp("qingxiao"))
                call_out("remove_effect", 1, me);
}

int help(object me)
{
        write(HIG"\n碧针清掌之「碧针清啸」："NOR"\n");
        write(DASH_LINE_LF);
        write(@HELP
            「碧针清啸」一出，将这一套掌法的威力大幅提升，包括命中与伤
        害均较正常为高。掌力击中对手后有相当大的机会使对手无暇反击。
            相应的，每一掌需消耗更多的内力。
        使用要求：
                内力 4000 以上；
                最大内力 5000 以上；
                基本内功等级 200 以上；
                碧针清掌等级 200 以上；
                且使用碧针清掌。
HELP
        );
        return 1;
}
