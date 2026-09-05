// qianshou 千手如来
// bren
// modify by notme 2004/3/17

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

void back(object target, int skill);

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
        string msg;
        int skill;

        skill = (int)me->query_skill("qianye-shou", 1)/3;;

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !me->is_fighting(target) )
                return notify_fail("「千手如来」只能在战斗中对对手使用。\n");

        if( me->check_hand() >= 1 )
                return notify_fail("使用「千手如来」时双手必须空着！\n");

        if( (int)me->query_skill("qianye-shou", 1) < 150 )
                return notify_fail("你的如来千叶手不够娴熟，不会使用「千手如来」。\n");

        if( (int)me->query_skill("hunyuan-yiqi", 1) < 150 )
                  return notify_fail("你的混元一气等级不够，不能使用「千手如来」。\n");

        if( (int)me->query_dex() < 25 )
                return notify_fail("你的身法不够强，不能使用「千手如来」。\n");

/*          if (me->query_skill_mapped("hand") != "qianye-shou")
             return notify_fail("你现在无法使用「千手如来」进行攻击。\n"); */

        if( (int)me->query("neili") < 1000 )
                return notify_fail("你现在内力太弱，不能使用「千手如来」。\n");

        if( target->query_temp("qianshou")   )
                  return notify_fail("你正在使用「千手如来」进行攻击。！\n");

        msg = HIY "$N双手合十互击，陡然向外一分，双掌顿时变得轻灵飘逸，灵动异常，霎时幻起漫天的掌影。\n" NOR;
        message_vision(msg, me, target);

        msg = HIR "$n只觉得四周都是$N的身影，不由得慌乱起来。\n" NOR;
        message_vision(msg, me, target);

        target->add_temp("apply/attack", -skill);
        target->add_temp("apply/dodge", -skill);
        target->add_temp("apply/parry", -skill);
        target->set_temp("qianshou",1);
        target->set_temp("active_debuff/qianye-shou.qianshou/name", "千手如来");                      //buff名称
        target->set_temp("active_debuff/qianye-shou.qianshou/last_time", time() + skill/10 );         //持续时间
        target->set_temp("active_debuff/qianye-shou.qianshou/effect1", "轻功技能-"+skill+"级");       //效果描述1
        target->set_temp("active_debuff/qianye-shou.qianshou/effect2", "攻击命中-"+skill+"级");       //效果描述2
        target->set_temp("active_debuff/qianye-shou.qianshou/effect3", "招架技能-"+skill+"级");       //效果描述3
        target->add("neili", -500);
        call_out("back", skill/10, target, skill);

        if( me->is_fighting() ) me->start_busy(2);


        return 1;
}

void back(object target, int skill)
{
       if ( !objectp(target) ) return;
       if ( !environment(target) ) return;
        target->add_temp("apply/attack", skill);
        target->add_temp("apply/dodge", skill);
        target->add_temp("apply/parry", skill);
        target->delete_temp("qianshou");
        target->delete_temp("active_debuff/qianye-shou.qianshou");
        tell_object(target, HIB"你渐渐适应了这种变化，状态又恢复如常。\n"NOR);
}



