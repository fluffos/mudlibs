// by whuan 2007-6-22 刀影连环
// 群攻pfm
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    string msg;
    int extra, lvl, lvla, lvlb;
    int i, j, menggu;
    object *enemy; //对手
    int count; //对手的数量
    object weapon;
    mapping attack_val = ([
                          "base" : ([ "weapon" : "blade", ]), //基本功夫类型
                           "skill" : ([ "weapon" : "hujia-daofa", ]), //高级技能名称
                           ]);

    if (!target) target = offensive_target(me);

    /*
    if( !me->query("daoying"))
            return notify_fail("你的外功中没有这种功能。\n");       
    */

    if ( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「刀影连环」只能对战斗中的对手使用。\n");

/*    if (me->query_skill_mapped("parry") != "hujia-daofa")
        return notify_fail("你的招架必须激发成胡家刀法方可使用「刀影连环」！\n"); */

    if ( !objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade" )
        return notify_fail("你手上无刀，不能使用「刀影连环」！\n");

    if ((int)me->query("neili") <= 1500)
        return notify_fail("你内力不够，不能使用「刀影连环」！\n");

    if ((int)me->query_skill("hujia-daofa", 1) < 500)
        return notify_fail("你的胡家刀法不够熟练，不能使用「刀影连环」！\n");

    //计算对手的数量
    enemy = me->query_enemy();
    count = sizeof(enemy);

    if (!count)
        return notify_fail("「刀影连环」只能对战斗中的对手使用。\n");

    //extra = me->query_skill("hujia-daofa",1) / 3; 以胡家刀法的次数来判断
//        extra = me->query("yidao/times") / 2;

    extra = (me->query("yidao/times") <= me->query_skill("hujia-daofa", 1)) ?
       me->query("yidao/times") : me->query_skill("hujia-daofa", 1);
    extra = extra / 2;

    me->add_temp("apply/attack", extra);
    me->add_temp("apply/damage", extra);
    msg = HIR  "$N使出胡家刀法的「刀影连环」，手中的" + weapon->name() + HIR"斜斜劈出三刀，$n顿觉呼吸一窒！\n" NOR;
    message_vision(msg, me, enemy[0]);
	me->set_temp("pfm_skip",1);
    for (i = 0; i < 3; i++)
    {
        if (!objectp(weapon)) break;
        if (environment(enemy[0]) != environment(me))
            continue;
        msg = HIY "$N一刀劈向$n！\n" NOR;
        message_vision(msg, me, enemy[0]);
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, enemy[0], weapon, TYPE_SPECIAL);
        //message_vision(msg,me,enemy[0])
    }
    //增加如果武器丢失的处理
    if (objectp(weapon))
    {
        msg =  HIW "\n$N"+HIW+"大喝一声，气聚丹田，手中" + weapon->name() + HIW + "连环递出数招，刀意绵绵不绝，抹！钩！剁！砍！劈！\n" NOR;
        message_vision(msg, me);
    }

    lvla = to_int(me->query("yidao/times") / 100); //以胡家刀法的次数来判断NPC个数
    lvlb = to_int(pow(me->query("level") * 1.0, 0.5));

    lvl = (lvla >= lvlb) ? lvlb : lvla; //取较小的那个

    if (count > lvl)
        count = lvl;

    if (enemy[0]->query("menggu"))
        menggu = 1;
    else if (count > 1 && enemy[1]->query("menggu"))
        menggu = 1;

    for (j = 0; j < count; j++)
    {
        if (!objectp(weapon)) break;
        if (environment(enemy[j]) != environment(me))
            continue;
        if (!menggu && j >= 5)
            continue;
        if (menggu)
        {
            msg = HIY "$N一刀劈向$n！\n" NOR;
            message_vision(msg, me, enemy[j]);
            me->set_temp("attack_val", attack_val);
            COMBAT_D->do_attack(me, enemy[j], weapon, TYPE_SPECIAL);
        }
        msg = HIY "$N一刀劈向$n！\n" NOR;
        message_vision(msg, me, enemy[j]);
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, enemy[j], weapon, TYPE_SPECIAL);
    }

    me->add_temp("apply/attack", -extra);
    me->add_temp("apply/damage", -extra);
	me->delete_temp("pfm_skip");

    if (!menggu)
        me->add("neili", -500);
    me->add("neili", -125 * lvl);
    me->start_busy(2 + random(2));

    if (wizardp(me))
        tell_object(me, "lvla：" + lvla + ",lvlb:" + lvlb + "lvl：" + lvl + "。\n");

    return 1;
}

