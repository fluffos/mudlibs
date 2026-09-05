#include <ansi.h>
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
    int myexp,yourexp,mystr,yourstr,lvl,lv;
    object weapon,weapon1;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("［雷霆一破］只能对战斗中的对手使用。\n");

    weapon1 = me->query_temp("weapon");
    if (!weapon1 || weapon1->query("skill_type") != "hammer"  )
        return notify_fail("你必须在使用锤类兵器时才能使[雷霆一击」！\n");

    if( me->query_skill("shandian-chui",1) < 80 )
        return notify_fail("你的日月闪电锤级别太低，不够使用［雷霆一破］\n");

    weapon = target->query_temp("weapon");
    if( !objectp(weapon) ) return notify_fail("你的对手没有用兵器！\n");

    myexp = (int) me->query("combat_exp")/10000;
    mystr = (int) me->query("str");
    yourexp = (int) target->query("combat_exp")/10000;
    yourstr = (int) target->query("str");

    lv  = (int) me->query_skill("dodge") ;
    lvl = (int) target->query_skill("dodge")+1;
    msg = HIY "$N双手抡起"+weapon1->name()+HIY"往下一砸，$n手中的"+weapon->name()+HIY"断成两截落在了地下！ \n" NOR;

    if( objectp(weapon) )
    {
        //A-
        if( F_KUNGFU->hit_rate( myexp * lv/10 * mystr/3, yourexp * lvl/10 * yourstr/3, 3, me, target) )                
        {
            weapon->unequip();
            weapon->move(environment(target));
            if ( !weapon->is_gems() )
            {
                weapon->set("name","断成两截的"+weapon->query("name"));
                weapon->set("rigidity",1);
                weapon->set("no_get",1);
                //                weapon->set("long","一件"+weapon->query("name"))
                weapon->set("value",0);
                call_out("remove_broken_weapon", random(30)+60,weapon);
            }
            message_vision(msg, me, target);
            if ( !target->is_busy() ) target->start_busy(2);
        }
        else
        {
            msg=HIY"$N双手抡起"+weapon1->name()+HIY"往下一砸，企图砸断$n的兵器。\n"+HIW"结果$n看破了$N的企图，轻巧地躲过，而$N用力过度，闹了个手忙脚乱。\n"NOR;
            message_vision(msg, me, target);
            COMBAT_D->do_attack(target, me, weapon, TYPE_SPECIAL);
        }
        me->start_busy(2);
    }
    return 1;
}

void remove_broken_weapon(object ob)
{
    if( objectp(ob) && environment(ob) ) 
    {
        tell_object(environment(ob), "一阵微风吹过，"+ob->name()+"化为片片尘土，消失不见了。\n");
        destruct(ob);
    }
}
