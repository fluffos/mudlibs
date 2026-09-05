// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
    string msg;
    int damage;
    mapping attack_val = ([
                          "base" : ([ "no_weapon" : "hand", ]), //基本功夫类型
                           "skill" : ([ "no_weapon" : "zhemei-shou", ]), //高级技能名称
                           ]);

    if (!target) target = offensive_target(me);

    if ( !target || !target->is_character() || !me->is_fighting(target))
        return notify_fail("【弹梅.落雪.散花香】只能对战斗中的对手使用。\n");

    damage = (int)me->query_skill("zhemei-shou", 1) / 4;
    if ((int)me->query_skill("zhemei-shou", 1) < 150)
        return notify_fail("你的天山折梅手不够娴熟，不会使用【弹梅.落雪.散花香】。\n");

    if ( me->query_skill("bahuang-gong", 1) < 150 )
        return notify_fail("你的唯我独尊功等级不够，不能使用【弹梅.落雪.散花香】。\n");

    if ( me->query_skill("xiaowuxiang-gong", 1) < 150 )
        return notify_fail("你的小无相功等级不够，不能使用【弹梅.落雪.散花香】。\n");

    if (me->query_skill_prepared("hand") != "zhemei-shou" || me->query_skill_mapped("hand") != "zhemei-shou")
        return notify_fail("你现在没有激发或者没有备天山折梅手,不能使用【弹梅.落雪.散花香】。\n");

    if ((int)me->query("neili") < 500)
        return notify_fail("你的内力不够。\n");

    if ((int)me->query("max_neili") < 2000)
        return notify_fail("你的内力修为太差。\n");

    if ((int)me->query("jing") < 500)
        return notify_fail("你的精力不够。\n");

    me->add_temp("apply/damage", damage);
    me->add_temp("apply/strength", damage);
    me->add_temp("apply/attack", damage);

    msg = HIY "$n"HIY"正凝神与$N"HIY"放对，不成想眼前一花$N"HIY"的身形已不可辨，所见分明是个天外飞仙在无尽的\n"
       "雪影之中伸指弹梅。$n"HIY"见到这般绮丽场景正自失神，直至察觉三道凌厉之极的掌风纷至而来，\n"
       "兀自不信世间竟有如此美妙的武功！"NOR;
    me->set_temp("attack_val", attack_val);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, msg);
    message_vision(HIW"                【弹  梅】\n"NOR, me, target);

    msg = HIY "$N双手急挥，左右摇摆，幻出漫天梅花，飞雪似的向$n落来！" NOR;
    me->set_temp("attack_val", attack_val);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, msg);
    message_vision(HIW"                【落  雪】\n"NOR, me, target);

    msg = HIY "$n突然闻到一股若有若无的香味，心猿意马之中$N的双手已向$p胸口拍来！" NOR;
    me->set_temp("attack_val", attack_val);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, msg);
    message_vision(HIW"                【散花香】\n"NOR, me, target);

    me->add_temp("apply/damage", -damage);
    me->add_temp("apply/strength", -damage);
    me->add_temp("apply/attack", -damage);
    me->add("neili", -150);
    me->add("jing", -150);

    //命中率C-&C-=E
    if (F_KUNGFU->hit_rate(me->query("combat_exp"), (int)target->query("combat_exp"), 9, me, target)
        && F_KUNGFU->hit_rate(me->query_int(), target->query_int(), 9, me, target))
    {
        msg = HIR "\n$N双手幻出漫天手影，宛若朵朵梅花，将$n笼罩在一片梅海之中！" NOR;
        message_vision(msg + "\n", me, target);
        msg = HIY"结果$n被$N攻了个手忙脚乱！\n"NOR;
        message_vision(msg, me, target);
        F_KUNGFU->hit_busy("confuse", 2 + random(me->query_skill("zhemei-shou") / 15), target);
        me->add("neili", -100);
        me->start_busy(2);
    }
    else
    {
        me->start_busy(2 + random(3));
    }

    return 1;
}

