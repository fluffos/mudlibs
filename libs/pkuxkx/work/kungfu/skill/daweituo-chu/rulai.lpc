//我佛如来 rulai.c
// by godzilla 99.03.06

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;

void remove_effect(object me, int a_amount, int d_amount);

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    object weapon,ob;
    int skill;
    int extra;
    string msg;
    object obj;//对方兵器
    mapping attack_val = ([
    "base" : ([ "weapon" : "staff", ]),//基本功夫类型
    "skill" : ([ "weapon" : "daweituo-chu", ]),//高级技能名称
    ]);

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("[「我佛如来」只能对战斗中的对手使用。\n");

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "staff")
        return notify_fail("「我佛如来」必须用禅杖才能施展。\n");

    if( (int)me->query_skill("daweituo-chu", 1) < 150 )
        return notify_fail("你的「大韦陀杵」不够娴熟，不会使用「我佛如来」。\n");

    if( (int)me->query("neili") < 300  )
        return notify_fail("你的内力不够。\n");

    if (me->query_temp("ryb_fumo"))
            return notify_fail("你现在正在使用「金刚伏魔」神功。\n");

    if (me->query_temp("ranmu"))
            return notify_fail("你现在正在使用「天火焚心」绝技。\n");

    skill = me->query_skill("daweituo-chu", 1);
    extra = me->query_skill("daweituo-chu",1) / 5;
    extra += me->query_skill("daweituo-chu",1) / 3;
    me->add_temp("apply/attack", extra);
    me->add_temp("apply/damage", extra);
    //显示perform具体情况
    //me->set_temp("combat_env",me->query("env/skip_combat"));
    //me->set("env/skip_combat",0);
    //target->set_temp("combat_env",target->query("env/skip_combat"));
    //target->set("env/skip_combat",0);

    msg = HIG"$N突然收势凝立，双手合十，口宣佛号\n"NOR;
    message_vision(msg, me, target);

    me->add("neili", -extra);

    msg = "$N一声大吼：「"+HIW"南无大日如来佛！"NOR+"」------"+BNK+HIW"法界体性!!!\n"NOR;;
    msg += "$N手中$w连连舞动，如万道佛光，铺天盖地地砸向$n！\n";
    me->set_temp("attack_val", attack_val);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, msg);

    if( objectp(me->query_temp("weapon")) )
    {
        msg = "$N二声大吼：「"+HIB"南无不动如来佛！"NOR+"」------"+BNK+HIB"大圆鉴!!!\n"NOR;
        msg +="$N面色威严，作金刚状，手中$w裹挟雷霆万钧之势劈头砸下！\n";
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, msg);
    }

    if( objectp(me->query_temp("weapon")) )
    {
        msg = "$N三声大吼：「"+HIY"南无宝生如来佛！"NOR+"」------"+BNK+HIY"平等性!!!\n"NOR;
        msg +="$N面色重归祥和，$n警惕稍懈中，$N手中$w似慢实快地点向$n！\n";
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, msg);
    }

    if( objectp(me->query_temp("weapon")) )
    {
        msg = "$N四声大吼：「"+HIR"南无阿弥陀佛！"NOR+"」------"+BNK+HIR"妙观察!!!\n"NOR;
        msg +="$N眸中利芒闪过，$w径直点向对方攻击的死角，逼得$n不得不收手招架！\n";
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, msg);
    }

    if( objectp(me->query_temp("weapon")) )
    {
        msg = "$N五声大吼：「"+HIG"南无不空成就如来佛！"NOR+"」------"+BNK+HIG"成所作!!!\n"NOR;
        msg +="$N在$n不可思议的目光中，已攻至外门的$w突然收回当胸，中宫直入！\n";
        me->set_temp("attack_val", attack_val);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_SPECIAL, msg);
    }

    me->add_temp("apply/attack", -extra);
    me->add_temp("apply/damage", -extra);

    if (skill< 800 )me->start_busy(3+random(2));
    else me->start_busy(2+random(2));
    //增加特效，砍兵器
    if ( F_KUNGFU->hit_rate(me->query("combat_exp"), target->query("combat_exp"), 9, me, target)
    && F_KUNGFU->hit_rate(me->query_skill("staff"), target->query_skill("dodge"), 9, me, target)
    && me->query_skill("daweituo-chu",1)>500
    && me->query_skill("yijin-jing",1)>500
    && objectp(obj = target->query_temp("weapon")) )
    {
        obj->unequip();
        message_vision(HIW "\n$N"HIW"大韦陀杵使得兴起，罡气纵横捭阖，$n"HIW"顿感无法招架！" NOR, me,target);
        message_vision(HIW "\n只听见「当」地一声巨响，$N"HIW"手中的" + obj->name()+ HIW"已被生生震成两段！\n" NOR, target);
        if ( obj->query("no_get") )
            obj->move(environment(target));
        else
        {
            obj->set("name", "断掉的" + obj->query("name"));
            obj->set("value", 0);
            obj->set("weapon_prop", 0);
            obj->move(environment(target));
        }
        if (!target->is_busy()) target->start_busy(2);
        call_out("remove_broken_cloth",15,obj);
    }
    //恢复combat设置
    //me->set("env/skip_combat",me->query_temp("combat_env"));
    //target->set("env/skip_combat",target->query_temp("combat_env"));
    return 1;
}


void remove_broken_cloth(object obj)
{
        if(obj && environment(obj)) {
                tell_object(environment(obj),"一阵微风吹过，"+obj->name()+"化为片片尘土，消失不见了。\n");
                destruct(obj);
        }
}
