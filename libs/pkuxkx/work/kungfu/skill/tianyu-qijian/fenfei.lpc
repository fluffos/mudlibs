//天羽纷飞
#include <ansi.h>
#include <char.h>
#include <combat.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
    object weapon;
    string str;
    int sword, force, dodge, times, damage;
    int sword_level;
    int delays = time();
    mapping attack_val = ([
                           "base" : ([ "weapon" : "sword", ]), //基本功夫类型
                           "skill" : ([ "weapon" : "tianyu-qijian", ]), //高级技能名称
                          ]);

    sword = (int)me->query_skill("tianyu-qijian", 1);
    force = (int)me->query_skill("bahuang-gong", 1);
    dodge = (int)me->query_skill("yueying-wubu", 1);

    if (!target) target = offensive_target(me);

    if (!target || !target->is_character() || !me->is_fighting(target))
        return notify_fail(HIR"天羽纷飞要对战斗中的对手使用！\n"NOR);

    if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
        if (!objectp(weapon = me->query_temp("secondary_weapon")) || (string)weapon->query("skill_type") != "sword")
            return notify_fail("你双手没拿剑,还想使剑法的绝招?别作梦了!\n");

    sword_level = (int)(sword / 50);
    if (sword < 180) return notify_fail(HIR"你的天羽奇剑级别还不够，使用这一招会有困难！\n"NOR);

    if ( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) && 
         (me->query("family/family_name") != "灵鹫宫" && me->query("chushi/last_family") != "灵鹫宫"))
        return notify_fail(HIR"天羽纷飞是灵鹫宫不传之密，你现在不是灵鹫宫弟子，不能使用这一招！\n"NOR);

    if (force < 180)
        return notify_fail(HIR"你的八荒六合唯我独尊功修为不够，使用这一招会有困难！\n"NOR);

    if (dodge < 180)
        return notify_fail("你的月影舞步级别还不够，使用这一招会有困难！\n");

    if (me->query("neili") < 300 || me->query("max_neili") < 300)
        return notify_fail("你的内力不够，无法施展「天羽纷飞」。");

    // 暂时做一下修改，延迟好像太长了一些，chui
    if ((delays - me->query_temp("fenfei_end")) < 10)
        return notify_fail("绝招用多就不灵了！\n");

    message_vision(HIW"\n$N轻叱一声，脚尖一点，身体急速上旋，在半空中一个折腰。同时手腕轻抖，剑光闪动，一招天羽纷飞，层层剑光卷向$n。\n"NOR, me, target);

    //前三剑
    message_vision(HIC"\n$N同时使出三招天羽奇剑，在半空中压向$n。\n"NOR, me, target);

    me->add_temp("apply/damage", 50);
    me->add_temp("apply/attack", sword / 5);
    me->set_temp("attack_val", attack_val);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);

    me->add_temp("apply/damage", 50);
    me->set_temp("attack_val", attack_val);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);

    me->add_temp("apply/damage", 50);
    me->set_temp("attack_val", attack_val);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);

    damage = 150;

    //再三剑
    if (sword >= 360 && force >= 360 && dodge >= 360)
    {
        message_vision(HIC"\n$N一咬银牙，反手又刺出三招！\n"NOR, me);

        me->add_temp("apply/damage", 100);
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);

        me->add_temp("apply/damage", 100);
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);

        me->add_temp("apply/damage", 100);
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);

        damage += 300;
    }

    //最后三剑
    if (sword >= 540 && force >= 540 && dodge >= 540)
    {
        message_vision(HIC"\n$N一个翻身跃起半空，似乎全身化作一把长剑，滚滚三招刺向$n\n"NOR, me, target);

        me->add_temp("apply/damage", 150);
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);

        me->add_temp("apply/damage", 150);
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);

        me->add_temp("apply/damage", 150);
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);

        damage += 450;
    }

    me->add_temp("apply/damage", -damage);
    me->add_temp("apply/attack", -sword / 5);
    me->set_temp("fenfei_end", time());
    me->add("neili", -300);
    me->start_busy(2);

    return 1;
}

