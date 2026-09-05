// 寻瑕抵隙
// created by Zine new明教
#include <ansi.h>
#include "/kungfu/skill/shenghuo-lingfa/shenghuo.h"
inherit F_SSERVER;

string* valid_weapon()
{
    return ({ "all" });
}

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int remove_effect_me(object me)
{
    if (me) me->delete_temp("danuoyi/use_xunxia");
}

int remove_effect(object me, int point)
{
    if (me)
    {
        me->delete_temp("danuoyi/xunxia");
        me->add_temp("apply/dodge", point);
        me->add_temp("apply/parry", point);
        me->delete_temp("active_force_buffer/qiankun-danuoyi.xunxia");
        message_vision("$N渐渐适应了对手的大挪移武功，招式上的破绽渐少。\n", me);
    }
}

int perform(object me, object target)
{
    int exp, hit_rate, pure = pure_degree(me), skill;
    string color, msg;

    if ( !target ) target = offensive_target(me);

    if ( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「寻瑕抵隙」只能对战斗中的对手使用。\n");

    if (me->query_skill("qiankun-danuoyi", 1) < 100)
        return notify_fail("你的乾坤大挪移级别太低，无法使用「寻瑕抵隙」。\n");

    if (me->query("jing") < 300)
        return notify_fail("你的精血太低，无法使用「寻瑕抵隙」。\n");

    if (me->query_temp("danuoyi/use_xunxia"))
        return notify_fail("你刚刚使用过「寻瑕抵隙」，过于耗神，暂时不能再用。\n");

    if (target->query_temp("danuoyi/xunxia"))
        return notify_fail("你刚刚对" + target->query("name") + "使用过「寻瑕抵隙」，他不会再次上当的。\n");

    if (pure > 100) //纯门派
        hit_rate = 1;
    else if (pure < 100)
        hit_rate = 9;
    else
        hit_rate = 5;

    color = custom_color_dny(me);
    msg = color + "$N" + color + "对照大挪移心法凝神寻找$n" + color + "招式中的破绽。\n" + NOR;
    message_vision(msg, me, target);
    me->add("jing", -200);
    exp = me->query("combat_exp");
    me->set_temp("danuoyi/use_xunxia", 1);
    call_out("remove_effect_me", 15 - me->query("mingjiao/skill/danuoyi/level"), me);
    if (F_KUNGFU->hit_rate(exp, (int)target->query("combat_exp"), hit_rate, me, target))
    {
        skill = me->query_skill("qiankun-danuoyi", 1);
        skill = skill / 10 + random(skill / 10);
        skill = skill * (7 + me->query("mingjiao/skill/danuoyi/level")) / 9;
        target->add_temp("apply/dodge", -skill);
        target->add_temp("apply/parry", -skill);
        target->set_temp("active_force_buffer/qiankun-danuoyi.xunxia/name", "寻瑕抵隙");                              //buff名称
        target->set_temp("active_force_buffer/qiankun-danuoyi.xunxia/last_time", time() + 15 + me->query("mingjiao/skill/danuoyi/level") * 4);                //持续时间
        target->set_temp("active_force_buffer/qiankun-danuoyi.xunxia/effect1", "轻功技能+" + (-skill) + "级");       //效果描述1
        target->set_temp("active_force_buffer/qiankun-danuoyi.xunxia/effect2", "招架技能+" + (-skill) + "级");       //效果描述2
        target->set_temp("danuoyi/xunxia", 1);
        call_out("remove_effect", 15 + me->query("mingjiao/skill/danuoyi/level") * 4, target, skill);
        msg = color + "这乾坤大挪移心法最擅于寻瑕抵隙，对方百计防护，尚且不稳，何况自呈虚弱？$N" + color + "手指上五股劲气，登时丝丝作响，疾攻过去。\n" + NOR;
        if (!target->is_busy())
            me->start_busy(1);
    }
    else
    {
        msg = color + "$N" + color + "一觉$n" + color + "破绽大露，实是$n" + color + "故意露出的破绽，反而弄得自己手忙脚乱。\n"NOR;
        if (!target->is_busy())
            me->start_busy(3 - (int)me->query("mingjiaonewbiejobdone"));
    }
    message_vision(msg, me, target);
    return 1;
}

