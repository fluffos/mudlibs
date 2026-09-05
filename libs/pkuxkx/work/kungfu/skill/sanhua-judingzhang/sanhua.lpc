#include <ansi.h>
#include <char.h>
#include <combat.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

void remove_effect(object me, object target, int extra);

int perform(object me, object target)
{
    object weapon;
    int skill, extra;
    int cdtime = time();
    mapping attack_val = ([
        "base" : ([ "no_weapon" : "strike", ]),//基本功夫类型
        "skill" : ([ "no_weapon" : "sanhua-judingzhang", ]),//高级技能名称
        ]);

    if (!target) target = offensive_target(me);

    if (!target || !target->is_character() || !me->is_fighting(target))
        return notify_fail("[三花聚顶]只能对战斗中的对手使用。\n");

    if ( cdtime < me->query_temp("sanhuapfm") )
        return notify_fail("你刚刚用完[三花聚顶]，内力未曾恢复，无法出招！\n");

    if ((int)me->query("neili") < 500)
        return notify_fail("你的内力不够！\n");

    if ( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) && 
         me->query("family/family_name") != "全真派")
        return notify_fail("全真派真全力找寻你这个叛徒，在江湖上还是别用全真绝技为妙！\n");

    if ((int)me->query_skill("sanhua-judingzhang", 1) < 120)
        return notify_fail("你的[三花聚顶掌法]级别还不够，使用这一招会有困难！\n");

    if (objectp(me->query_temp("weapon")))
        return notify_fail("你手持武器，无法使用[三花聚顶]！\n");


    skill = (int)me->query_skill("sanhua-judingzhang", 1);
    extra = (int)skill / 3;
    me->add_temp("apply/attack", extra);
    me->add_temp("apply/damage", extra);

    message_vision("\n\t$N使出-"HIC"[三花聚顶掌法]"NOR"绝技-"HIY"三花聚顶"NOR"\n", me);
    me->set_temp("attack_val", attack_val);
    COMBAT_D->do_attack(me, target, 0, TYPE_SPECIAL);

    message_vision("\n"HIY"三花聚顶"NOR"-------"HIW"天道\n"NOR, me);
    me->set_temp("attack_val", attack_val);
    COMBAT_D->do_attack(me, target, 0, TYPE_SPECIAL);

    message_vision("\n"HIY"三花聚顶"NOR"-------"HIG"无我\n"NOR, me);
    me->set_temp("attack_val", attack_val);
    COMBAT_D->do_attack(me, target, 0, TYPE_SPECIAL);

    message_vision("\n"HIY"三花聚顶"NOR"-------"HIB"忘情\n"NOR, me);
    me->set_temp("attack_val", attack_val);
    COMBAT_D->do_attack(me, target, 0, TYPE_SPECIAL);

    me->add_temp("apply/attack", -extra);
    me->add_temp("apply/damage", -extra);
    me->add("neili", -100);
    //命中率为F-|C-=C/2+C+/2
    if (!target->query_temp("qz/sanhua") &&
        (F_KUNGFU->hit_rate((int)me->query_skill("sanhua-judingzhang"), (int)target->query_skill("dodge"), 9, me, target) ||
         F_KUNGFU->hit_rate((int)me->query("str"), (int)target->query("dex"), 9, me, target)))
    {
        extra = (int)skill / 10 + random(skill / 10);
        target->set_temp("active_debuff/sanhua-judingzhang.sanhua/name", "三花聚顶");                       //buff名称
        target->set_temp("active_debuff/sanhua-judingzhang.sanhua/last_time", time() + skill / 30 + 1);        //持续时间
        if (random(10) > 4)
        {
            if (target->query_skill("dodge") < extra)
            {
                extra = (int)target->query_skill("dodge") - 10;
            }
            target->add_temp("apply/dodge", -extra);
            target->set_temp("qz/sanhua", 1);
            target->set_temp("active_debuff/sanhua-judingzhang.sanhua/effect1", "轻功技能-" + extra + "级");     //效果描述1
            message_vision("\n\t" + WHT + "$N出招中正平和，却又把$n腾挪躲闪的位置全部计算好了。\n"NOR, me, target);
            target->add_busy(1);
            me->add("neili", -150);
        }
        else
        {
            if (target->query_skill("parry") < extra)
            {
                extra = (int)target->query_skill("parry") - 10;
            }
            target->add_temp("apply/parry", -extra);
            target->set_temp("qz/sanhua", 2);
            target->set_temp("active_debuff/sanhua-judingzhang.sanhua/effect1", "招架技能-" + extra + "级");     //效果描述1
            message_vision("\n\t" + HIM + "$N出招中正平和，却又把$n拆招化解的可能全部弥消于无形。\n"NOR, me, target);
            target->add_busy(1);
            me->add("neili", -150);
        }
        call_out("remove_effect", (int)skill / 30 + 1, me, target, extra);
    }
    me->set_temp("sanhuapfm", time()+6+random(4));
    me->start_busy(2);
    return 1;
}

void remove_effect(object me, object target, int extra)
{
    if (!objectp(target) || target->is_ghost(1)) return;
    tell_object(target, "良久之后，三花聚顶掌的功力才被你完全压制住，你又活动自如了。\n");
    if (me && me->is_fighting(target))
        tell_object(me, target->name() + "似乎从三花聚顶威力下恢复了。\n");
    if ( target->query_temp("qz/sanhua") == 1)
    {
        target->add_temp("apply/dodge", extra);
    }
    if ( target->query_temp("qz/sanhua") == 2)
    {
        target->add_temp("apply/parry", extra);
    }
    target->delete_temp("qz/sanhua");
    target->delete_temp("active_debuff/sanhua-judingzhang.sanhua");
    return;
}

