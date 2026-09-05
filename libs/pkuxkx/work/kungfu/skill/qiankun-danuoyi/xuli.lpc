// 蓄力
// created by Zine new明教
#include <ansi.h>
#include "/kungfu/skill/shenghuo-lingfa/shenghuo.h"
#define XULI_LIMIT 14
#define XULI_HIT 8
inherit F_SSERVER;
inherit YIZHAOYUN;

string* valid_weapon()
{
    return ({ "all" });
}

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform_cd(object me)
{
    int time = time() - me->query_temp("danuoyi/use_xuli");
    if (me->query("mingjiao/skill/danuoyi/level") < 6)
    {
        if (time >= (6 - me->query("mingjiao/skill/danuoyi/level")) * 3600)
            return 1;
    }
    else
    {
        if (time >= (8 - me->query("mingjiao/skill/danuoyi/level")) * 30)
            return 2;
    }
    return 0;
}

int cost_me(object me, int flag)
{
    if (flag == 2)
    {
        if (me->query("mingjiao/skill/danuoyi/level") >= 7)
            me->add("neili", -200);
        else if (me->query("mingjiao/skill/danuoyi/level") == 6)
            me->add("neili", -300);
        else
            me->add("max_neili", (me->query("mingjiao/skill/danuoyi/level") - 6) * 3);
    }
    if (flag == 1)
    {
        if (me->query("mingjiao/skill/danuoyi/level") >= 7)
            me->add("neili", -800);
        else if (me->query("mingjiao/skill/danuoyi/level") == 6)
            me->add("neili", -1000);
        else
            me->add("max_neili", (me->query("mingjiao/skill/danuoyi/level") - 6) * 8);
    }
}

int result(object me, object target)
{
    int times, flag = 0;
	int exp1,exp2;
	int add_t;
	string msg, color;
    if (!me || !target || environment(me) != environment(target) || !environment(me) || !me->is_fighting(target))
    {
        return 1;
    }
    times = me->query_temp("danuoyi/user_xuli_time");
    times += 1;
    color = custom_color_dny(me);
	exp1=me->query("combat_exp");
	exp2=target->query("combat_exp");
	exp2/=3;
	add_t=random(XULI_LIMIT);
    if (times > add_t && random(exp1)>random(exp2))
    {
        if ((times > XULI_HIT)&&random(exp1)>random(exp2)) //晕或死
        {
            msg = color + "$N" + color + "突然间大喝一声，反震出去，便如一座大湖在山洪爆发时储满了洪水，猛地里湖堤崩决，洪水急冲而出，将$n" + color + "送来的掌力尽数倒回。\n" + NOR;
            msg += color + "$n" + color + "立时腕骨、臂骨、肩骨、肋骨一齐折断，连血也喷不出来，";

            if (random(10))
            {
                msg += "当场昏死过去。\n" + NOR;
                // target->set_temp("last_damage_from", me);
                // target->unconcious();
                message_vision(msg, me, target);
                yizhaoyun(target, me, 1);
            }
            else
            {
                msg += "当场成为一团血肉模糊，死得惨不可言。\n" + NOR;
                message_vision(msg, me, target);
                target->receive_damage("qi", 0, me);
                target->die();
            }
            flag = 1;
        }
        else
        {
            msg = color + "$N" + color + "虽然蓄力未足充分，依然打得$n" + color + "身受重伤。\n" + NOR;
            message_vision(msg, me, target);
            F_KUNGFU->hit_wound("qi", target->query("max_qi", 1) * times / 14, 0, me, target);
            COMBAT_D->report_status(target);
            flag = 2;
        }
		me->add_temp("danuoyi/user_xuli_time",-add_t*2/3);
        cost_me(me, flag);
        //命中
    }
    else
    {
        me->add_temp("danuoyi/user_xuli_time", 1);
        call_out("result", 2, me, target);
        msg = color + "$N" + color + "继续将$n" + color + "的劲力积蓄在一起。。。\n" + NOR;
        message_vision(msg, me, target);
    }
    return 1;
}

int perform(object me, object target)
{
    int exp, hit_rate, skill;
    string color, msg;

    if (!target) target = offensive_target(me);

    if ( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「蓄力」绝技只能对战斗中的对手使用。\n");

    if (me->query_skill("qiankun-danuoyi", 1) < 200)
        return notify_fail("你的乾坤大挪移级别太低，无法使用乾坤大挪移的「蓄力」绝技。\n");

    if (me->query("max_neili") < 5000)
        return notify_fail("你的最大内力太低，无法使用「蓄力」绝技。\n");

    if (me->query("neili") < 5000)
        return notify_fail("你的内力太低，无法使用「蓄力」绝技。\n");

    if (me->query("mingjiao/skill/danuoyi/level") < 4 && pure_degree(me) <= 100)
        return notify_fail("你的乾坤大挪移层级太低，无法使用乾坤大挪移的「蓄力」绝技。\n");

    if (me->query("mingjiao/skill/danuoyi/level") < 3)
        return notify_fail("你的乾坤大挪移层级太低，无法使用乾坤大挪移的「蓄力」绝技。\n");

    if (!perform_cd(me))
        return notify_fail("你刚刚使用过「蓄力」绝技，暂时不能再用。\n");

    color = custom_color_dny(me);
    if (me->query("mingjiao/skill/danuoyi/level") < 6)
        msg = color + "$N" + color + "强行运起乾坤大挪移心法中第七层功夫，将$n" + color + "劲力渐渐积蓄。。。\n" + NOR;
    else
        msg = color + "$N" + color + "运起乾坤大挪移心法中第七层功夫，将$n" + color + "劲力渐渐积蓄。。。\n" + NOR;

    message_vision(msg, me, target);
    me->set_temp("danuoyi/use_xuli", time());
    call_out("result", 1, me, target);
    return 1;
}
