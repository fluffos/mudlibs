// 玉女十九式 by Zine new huashan剑宗不许用
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

string *xue_name = ({
    "玉堂穴","大横穴","幽门穴","章门穴","晴明穴","紫宫穴","风池穴","百汇穴","太阳穴","长强穴","灵台穴"
});

int perform(object me, object target)
{
    int skill, damage, bt, buff;
    object weapon = me->query_temp("weapon");

    if ( !me->query("huashan_newskills/qizong") ||
         me->query("family/family_name")!="华山派" )
		{
		return notify_fail("这是华山气宗的秘传绝学，你无法在实战中运用「玉女十九式」。\n");
		}
    if (!target) target = offensive_target(me);

    if (!target || !target->is_character() || !me->is_fighting(target))
        return notify_fail("玉女十九式只能对战斗中的对手使用。\n");

    if (!weapon || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "yunushijiu-jian")
        return notify_fail("你手中无剑怎能使用玉女十九式？！\n");

    if ( (int)me->query_skill("zixia-shengong", 1) < 300 )
        return notify_fail("你的内功火候未到，无法施展玉女十九式！\n");

    if (me->query_skill("sword", 1) < 300 || me->query_skill("yunushijiu-jian", 1) < 300)
        return notify_fail("你剑法未到炉火纯青之境，还不会使用玉女十九式！\n");

    if ( me->query("neili") <= 5000 || 
         me->query("max_neili") <= 10000 )
        return notify_fail("你的内力修为不够使用玉女十九式！\n");

    if (me->query_temp("hs/yn19") == 1)
        return notify_fail("你正在使用玉女十九式。\n");

    if (time() - me->query_temp("hs/yn19") < 12)
        return notify_fail("你刚刚使用过玉女十九式。\n");

    me->set_temp("hs/yn19", 1);
    me->set_temp("hs/yn19_remain", 19);
    message_vision(HIM"\n$N" + HIM + "手中" + weapon->query("name") + HIM + "越出越快，正是玉女十九式，虽只一十九式，但每一式都是变化繁复。\n" + HIW +
                   "十九式主旨在於变幻奇妙，跟华山派著重以气驭剑的法门颇有不同。\n"NOR, me);
    call_out("yn_pfm", 1, me, target, weapon);
    return 1;
}
void attack_target(object me, object target, int times)
{
    int damage, chemical = random(times), buff, xs1=0;
    mapping attack_val = ([
                          "base" : ([ "weapon" : "sword", ]), //基本功夫类型
                          "skill" : ([ "weapon" : "yunushijiu-jian", ]), //高级技能名称
                           ]);

    me->add("neili", -40);
    for (int i = 0; i < times; i++)
    {
        if (i == chemical && !me->query("betrayer")) //化学
        {
            me->add("neili", -120);
            message_vision(MAG"$N" + MAG + "凝神举剑，缓缓向$n" + MAG + "刺去。\n"NOR, me, target);
            if (F_KUNGFU->hit_rate(me->query("combat_exp"), target->query("combat_exp"), 7 + random(3), me, target))
            {
                message_vision(HIR + "$N" + HIR + "一剑化繁为简，取中宫直刺中$n" + HIR + "。\n"NOR, me, target);
                damage = (int)me->query_skill("yunushijiu-jian", 1);
                damage = damage / 2 + random(damage / 2) + random(damage / 2);
                F_KUNGFU->hit_wound("qi", damage, damage / (3 - random(2)), me, target);
                me->add("neili", -(80 + random(20)));
                COMBAT_D->report_status(target);
            }
            else
            {
                message_vision("$N这一招险险落空。\n", me);
            }
        }
        else //物理
        {
            me->add("neili", -(20 + random(20)));
            buff = me->query_skill("yunushijiu-jian", 1) / 15 + random(me->query_skill("sword", 1) / 12);
            me->add_temp("apply/attack", buff);
            me->add_temp("apply/damage", buff);
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
            me->add_temp("apply/attack", -buff);
            me->add_temp("apply/damage", -buff);
        }
    }
}
int end_yn(object me)
{
    tell_object(me, "稍一迟疑，你的玉女十九式无以为继。\n");
    me->set_temp("hs/yn19", time());
    return 0;
}
int yn_pfm(object me, object target, object weapon)
{
    string name, msg, *limbs;
    int remain = me->query_temp("hs/yn19_remain"), times, damage = 10;
    int bt;

    bt = me->query("betrayer");
    if (me->is_busy())
        return end_yn(me);
    if (!me || !target || !weapon)
        return end_yn(me);
    if (!living(me) || !living(target))
        return end_yn(me);
    if (environment(me) != environment(target))
        return end_yn(me);
    if (!me->is_fighting(target))
        return end_yn(me);
    if (me->query_temp("weapon") != weapon)
        return end_yn(me);
    if (remain < 1)
    {
        message_vision(HIG"$N" + HIG + "一套玉女十九式使完了。\n"NOR, me);
        me->set_temp("hs/yn19", time());
        return 1;
    }
    if (remain != 19)
        message_vision(HIM"片刻之间，$N" + HIM + "又是几招连续递出。\n"NOR, me);
    times = random(3) + 3;
    if (remain < times)
        times = remain;
    remain -= times;
    me->set_temp("hs/yn19_remain", remain);
    attack_target(me, target, times);
    me->start_busy(random(3));
    call_out("yn_pfm", 2 + random(3), me, target, weapon);
    return 1;
}

