// gonggui.c 全真剑法 同归剑法

#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

void remove_effect(object me, int a_amount, int d_amount);


int perform(object me, object target)
{
    object weapon;
    int skill;
    int extra;
    string msg;

    if ( !target ) target = offensive_target(me);

    if ( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「同归于尽」只能在战斗中使用。\n");

    if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你手中无剑，怎能运用「同归于尽」？！\n");

    if ((int)me->query_skill("quanzhen-jian", 1) < 135)
        return notify_fail("你的全真剑法不够娴熟，不会使用「同归于尽」。\n");

    if ((int)me->query_skill("xiantian-gong", 1) < 100)
        return notify_fail("你的先天神功火候不够，不能使用「同归于尽」。\n");

//                if(!( me->query("eff_qi")<1||(int)(me->query("max_qi")/me->query("eff_qi"))>=2.5))
//                return notify_fail("你还没受重伤，不要使用此剑法。\n");

    if ((int)me->query("neili") < 300)
        return notify_fail("你的内力不够。\n");

    if ((int)me->query_temp("qzj_tong"))
        return notify_fail("你已经在运功中了。\n");

    msg = HIB"$N"HIB"左手捏一个剑决，右手握起" + weapon->name() + HIB"，拼着最后的力气，一式「同归剑法」，\n";
    msg += "驭剑猛烈绝伦地冲向$n" + HIB",意图与$n" + HIB"同归一尽！\n"NOR;
    message_vision(msg, me, target);
    target->kill_ob(me);

    extra = (int)me->query_skill("quanzhen-jian", 1) / 10;
    me->add_temp("apply/attack", extra);
    me->add_temp("apply/damage", extra);
    me->add_temp("apply/dexerity", extra);
    me->add_temp("apply/strength", extra);
    me->add_temp("apply/qi_recover", -extra);
    me->set_temp("qzj_tong", 1);
    me->set_temp("active_buffer/family", "全真派");
    me->set_temp("active_buffer/quanzhen-jian.tonggui/name", "同归剑法");                  //buff名称
    me->set_temp("active_buffer/quanzhen-jian.tonggui/last_time", time() + extra * 5);       //持续时间
    me->set_temp("active_buffer/quanzhen-jian.tonggui/effect1", "攻击命中+" + extra + "级");    //效果描述1
    me->set_temp("active_buffer/quanzhen-jian.tonggui/effect2", "攻击伤害+" + extra + "点");    //效果描述2
    me->set_temp("active_buffer/quanzhen-jian.tonggui/effect3", "后天身法+" + extra + "点");    //效果描述3
    me->set_temp("active_buffer/quanzhen-jian.tonggui/effect4", "后天膂力+" + extra + "点");    //效果描述4
    me->set_temp("active_buffer/quanzhen-jian.tonggui/effect5", "气血恢复-" + extra + "点/秒"); //效果描述5
    call_out("remove_effect", extra * 5, me, extra, extra);
    me->add("neili", -300);
    me->start_busy(2);

    return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
    int extra;
    if (!objectp(me)) return;
//        extra = me->query_skill("quanzhen-jian",1)/10;
    extra = a_amount;
    me->add_temp("apply/attack", -extra);
    me->add_temp("apply/damage", -extra);
    me->add_temp("apply/dexerity", -extra);
//	me->add_temp("apply/dodge",-extra);
    me->add_temp("apply/strength", -extra);
    me->add_temp("apply/qi_recover", extra);
    me->delete_temp("active_buffer/quanzhen-jian.tonggui");
    if (sizeof(me->query_temp("active_buffer")) == 1)
        me->delete_temp("active_buffer");
    me->delete_temp("qzj_tong");
    tell_object(me, "你心境渐趋平和，已经没有了刚才的拼死之心。\n");
}
