// lianhuan.c 夺命连环三仙剑
// 新增华山剑宗武功Zine
#include <ansi.h>
#include <combat.h>
inherit F_DBASE;
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int Calcu_rate(object me, int flag)
{
    int *buffs;
    if (me->query("env/lianhuan") == "rise")
    {
        buffs = ({6,4,3});
        return buffs[flag];
    }
    else if (me->query("env/lianhuan") == "fall")
    {
        buffs = ({3,4,6});
        return buffs[flag];
    }
    else
    {
        buffs = ({5,4,3+random(2)});
        return buffs[flag];
    }
}
int target_dodge(object target)
{
    message_vision(WHT"$N险险避过这一招。\n"NOR, target);
}
int perform(object me, object target)
{
    int skill, damage, bt, buff, bf2, xs1=0;
    object weapon = me->query_temp("weapon");
    mapping attack_val = ([
                          "base" : ([ "weapon" : "sword", ]), //基本功夫类型
                          "skill" : ([ "weapon" : "kuangfeng-kuaijian", ]), //高级技能名称
                           ]);
    if (!me->query("huashan_newskills/jianzong") ||
         me->query("family/family_name")!="华山派") 
		{
				return notify_fail("这是华山剑宗的秘传绝学，你无法在实战中运用「夺命连环三仙剑」。\n");

		}
    if (!target) target = offensive_target(me);

    if (!target || !target->is_character() || !me->is_fighting(target))
        return notify_fail("夺命连环三仙剑只能对战斗中的对手使用。\n");

    if (!weapon || weapon->query("skill_type") != "sword" )
        return notify_fail("你手中无剑怎能使用夺命连环三仙剑？！\n");

    if ( (int)me->query_skill("huashan-neigong", 1) < 120 )
        return notify_fail("你的华山内功火候未到，无法施展夺命连环三仙剑！\n");

    if (me->query_skill("dodge") < 120)
        return notify_fail("夺命连环三仙剑需要超绝的轻功配合，方能有效施展！\n");

    if (me->query_skill("sword", "kuangfeng-kuaijian") < 120)
        return notify_fail("你剑法未到炉火纯青之境，还不会使用夺命连环三仙剑！\n");

    if (me->query("neili") <= 500)
        return notify_fail("你的内力不够使用夺命连环三仙剑！\n");

    if (me->query("max_neili") <= 1000)
        return notify_fail("你的内力修为不够使用夺命连环三仙剑！\n");

    message_vision(RED"\n$N怒吼一声，使出了华山剑宗绝技『夺命连环三仙剑』！\n"NOR, me);
    message_vision(HIR "\n$N" + HIR + "凝神潜运功力，" + weapon->name() + HIR "向$n" + HIR + "当头直劈！\n" NOR, me, target);
    //起始当头直劈；若对方斜身闪开，则圈转长剑，拦腰横削；如果对方还能避开，势必纵身从剑上跃过，则长剑反撩，疾刺对方后心，若对方背//后不生眼睛，势难躲避。

    me->add("neili", -100);
    skill = me->query_skill("kuangfeng-kuaijian", 1);
    buff = Calcu_rate(me, 0);
    bt = me->query("betrayer");
    if (F_KUNGFU->hit_rate(me->query_skill("sword", "kuangfeng-kuaijian"), target->query_skill("parry"), buff, me, target))
    {
        message_vision("$N逼无可避，被这一招正中肩头。\n", target);
        damage = (int)me->query_skill("kuangfeng-kuaijian", 1) + (int)me->query_skill("huashan-jianfa", 1) / 2;
        damage = damage + random(damage) * (3 - bt) / 2;
        if (damage < 0)
          damage = 1; //判师多可能变负伤害。
        F_KUNGFU->hit_wound("qi", damage, damage / 2, me, target);
        me->add("neili", -100);
        COMBAT_D->report_status(target);
    }
    else if ( !me->query("env/no_lianhuan_annex") && !bt && !me->query("chushi/done") )
    {
        bf2 = me->query_skill("kuangfeng-kuaijian", 1) / 8 + random(me->query_skill("kuangfeng-kuaijian", 1) / 10);
        me->add_temp("apply/attack", bf2);
        me->add_temp("apply/damage", bf2);
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
        me->add_temp("apply/attack", -bf2);
        me->add_temp("apply/damage", -bf2);
    }
    else
        target_dodge(target);
    
    buff = Calcu_rate(me, 1);
    message_vision(HIR + "\n$N" + HIR + "圈转长剑，拦腰向$n" + HIR + "横削。\n"NOR, me, target);
    if (F_KUNGFU->hit_rate(me->query_skill("dodge"), target->query_skill("parry"), buff, me, target))
    {
        message_vision("$N被剑锋扫过腰间。\n", target);
        damage = (int)me->query_skill("kuangfeng-kuaijian", 1) + (int)me->query_skill("huashen-shenfa", 1) / 2;
        damage = damage + random(damage) * (4 - bt) / 2;
        if (damage < 0)
            damage = 1; //判师多可能变负伤害。
        F_KUNGFU->hit_wound("qi", damage, damage / (3 - random(2)), me, target);
        me->add("neili", -100);
        COMBAT_D->report_status(target);
    }
    else if ( !me->query("env/no_lianhuan_annex") && !bt && !me->query("chushi/done") )
    {
        bf2 = me->query_skill("kuangfeng-kuaijian", 1) / 10 + random(me->query_skill("kuangfeng-kuaijian", 1) / 10);
        me->add_temp("apply/attack", bf2);
        me->add_temp("apply/damage", bf2);
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
        me->add_temp("apply/attack", -bf2);
        me->add_temp("apply/damage", -bf2);
    }
    else
        target_dodge(target);
        
    buff = Calcu_rate(me, 2);
    message_vision(HIR + "\n$N" + HIR + "长剑反撩，疾刺$n" + HIR + "后心。\n"NOR, me, target);
    if (F_KUNGFU->hit_rate(me->query_skill("force"), target->query_skill("parry"), buff, me, target))
    {
        message_vision("$N躲避不及，被刺中后心。\n", target);
        damage = (int)me->query_skill("kuangfeng-kuaijian", 1) + (int)me->query_skill("huashan-neigong", 1) *2/ 3;
        damage = damage + random(damage) * (2 - bt);

        if (damage < 0)
            damage = 1; //判师多可能变负伤害。
        F_KUNGFU->hit_wound("qi", damage, damage / (3 - random(2)), me, target);
        me->add("neili", -100);
        COMBAT_D->report_status(target);
    }
    else if ( !me->query("env/no_lianhuan_annex") && !bt && !me->query("chushi/done") )
    {
        bf2 = me->query_skill("kuangfeng-kuaijian", 1) / 10 + random(me->query_skill("kuangfeng-kuaijian", 1) / 10);
        me->add_temp("apply/attack", bf2);
        me->add_temp("apply/damage", bf2);
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
        me->add_temp("apply/attack", -bf2);
        me->add_temp("apply/damage", -bf2);
    }
    else
        target_dodge(target);
        
    if ((int)me->query("neili") < 0)
        me->set("neili", 0);
    me->start_busy(3);

    return 1;
}

