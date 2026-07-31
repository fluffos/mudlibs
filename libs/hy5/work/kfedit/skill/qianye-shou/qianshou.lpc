// qianshou 千手如来
// bren

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
void back(object target, int skill);
int perform(object me, object target)
{
        string msg;
        int skill;
        skill = (int)me->query_skill("qianye-shou", 1)/3;;
         skill = 1;;

        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("「千手如来」只能在战斗中对对手使用。\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("使用「千手如来」时双手必须空着！\n");

        if( (int)me->query_skill("qianye-shou", 1) < 150 )
                return notify_fail("你的如来千叶手不够娴熟，不会使用「千手如来」。\n");

        if( (int)me->query_skill("yijinjing", 1) < 150 )
                return notify_fail("你的易筋经内功等级不够，不能使用「千手如来」。\n");

        if( (int)me->query_dex() < 25 )
                return notify_fail("你的身法不够强，不能使用「千手如来」。\n");

        if (me->query_skill_prepared("hand") != "qianye-shou"
        || me->query_skill_mapped("hand") != "qianye-shou")
                return notify_fail("你现在无法使用「千手如来」进行攻击。\n");                                                                                 
      

        if( (int)me->query("neili") < 500 )
                return notify_fail("你现在内力太弱，不能使用「千手如来」。\n");

        if( target->query_temp("qianshou")   )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。！\n");

        msg = HIY "$N双手合十互击，陡然向外一分，双掌顿时变得轻灵飘逸，灵动异常，霎时幻起漫天的掌影。\n" NOR;
        message_vision(msg, me, target);

        msg = HIR "$n只觉得四周都是$N的身影，不由得慌乱起来。\n" NOR;
        message_vision(msg, me, target);

        target->add_temp("apply/attack", -skill);
        target->add_temp("apply/dodge", -skill);
        target->add_temp("apply/parry", -skill); 
        target->set_temp("qianshou",1);   
        me->add("neili", -300);
        target->start_call_out( (: call_other, __FILE__, "back", target, skill :),skill/10);

        if( me->is_fighting() ) me->start_busy(2);

                              
        return 1;
}

void back(object target, int skill)
{
        target->add_temp("apply/attack", skill);
        target->add_temp("apply/dodge", skill);
        target->add_temp("apply/parry", skill);
        target->delete_temp("qianshou");
        tell_object(target, HIB"你渐渐适应了这种变化，状态又恢复如常。\n"NOR);
}

        

