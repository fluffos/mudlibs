// duo.c 空手入白刃
// modified by Zine new明教
#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/shenghuo-lingfa/shenghuo.h"
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    string msg, weapon_name, color, hand;
    object my_weapon, weapon, weapon2, wea;
    int exp;
    mapping attack_val = ([
        "base" : ([ "weapon" : "dagger", ]),//基本功夫类型
        "skill" : ([ "weapon" : "shenghuo-lingfa", ]),//高级技能名称
        ]);

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「夺字诀」只能对战斗中的对手使用。\n");

    if( (int)me->query_temp("duo") )
        return notify_fail("你已经在夺敌人的兵刃了。\n");

    /*if (!present("shenghuo ling",me))
    return notify_fail("没有圣火令，你无法夺取别人的兵器。\n");*/

    if (!objectp(my_weapon = me->query_temp("weapon")) || (string)my_weapon->query("skill_type") != "dagger")
/*    if (!objectp(my_weapon = me->query_temp("secondary_weapon")) || (string)my_weapon->query("skill_type") != "dagger") */
        return notify_fail("你右手没有匕首类武器不能使出圣火令法的「夺字诀」。\n");

    if( (int)me->query_skill("shenghuo-lingfa",1) <100)
          return notify_fail("你的圣火令法不够纯熟,无法夺人兵器！\n");

    if (custom_color(me)==NOR)
        color=BRED;
    else
        color=custom_color(me);

    weapon = target->query_temp("weapon");
    weapon2 = target->query_temp("secondary_weapon");
    if (!objectp(weapon) && !objectp(weapon2))
    {
        if (time()-me->query_temp("mj_duo_attack")<3)
        return notify_fail(target->query("name")+"手中并无兵刃。\n");
        message_vision(color+"$N"+color+"手中并无兵刃格架，$n"+color+"中官直进，招式递了上去。\n"+NOR,target,me);
        me->set_temp("mj_duo_attack",time());
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL);
        return 1;
    }
    msg = color+ "$N"+color+"用"+my_weapon->query("name")+color+"搭住$n"+color+"的兵器，试图夺走$n"+color+"的兵器。\n"+NOR;           
    message_vision(msg, me,target);
    //命中率C-
    exp=me->query("combat_exp");
    if (objectp(me->query_temp("weapon")))
        if (me->query_temp("weapon")->query("is_shenghuoling"))
            exp=exp+exp/10;
    if (objectp(me->query_temp("secondary_weapon")))
        if (me->query_temp("secondary_weapon")->query("is_shenghuoling"))
            exp=exp+exp/10;//圣火令对命中的加成作用。
    if( F_KUNGFU->hit_rate( exp, (int)target->query("combat_exp"), 9, me, target) )
    {
         //msg = HIW"$N使出圣火神功的夺字诀, $n顿时觉得眼前一花，手腕一麻，手中兵刃脱手而出！\n" NOR;
        if (objectp(weapon))
        {
            weapon_name=weapon->query("name");
            weapon->move(environment(target));
            hand = "右手";
        }
        else
        {
            weapon_name=weapon2->query("name");
            weapon2->move(environment(target));
            hand = "左手";
        }
        msg =HIW"岂知$N"+HIW+"忽地放手，那"+my_weapon->query("name")+HIW+"尾端向上弹起，啪的一响，正好打中$n"+HIW+"手腕。\n$n"+ hand +"手指剧痛，再也拿捏不住手中的"+weapon_name+HIW+"，顿时脱手而飞。\n"+NOR;
        me->start_busy(1);
    }
    else
    {
        msg = "可是$n的看破了$N的企图，立刻采取守势，使$N没能夺下兵刃。\n"NOR;
        me->start_busy(3-(int)me->query("mingjiaonewbiejobdone"));
    }

    message_vision(msg, me, target);
    return 1;
}
