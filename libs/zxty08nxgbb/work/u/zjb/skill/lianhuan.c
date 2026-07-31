#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;

void do_attack(object me,object target,object weapon,int attack_time)
{
    int i;
    if (!me) return;
    me->delete_temp("perform");
    if (!living(me) || !target ) return;
    if (weapon == me->query_temp("secondary_weapon") )
    me->set_temp("secondly_weapon",1);
    if (!weapon->query("equipped")){ me->start_busy(1); return; }
    if (environment(me)!=environment(target)) return;
        for(i = 0; i < attack_time; i++)
            if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
            COMBAT_D->do_attack(me, target, weapon, 1);
              me->start_busy(1);
            }else break;
    me->delete_temp("secondly_weapon");
    if (i) message_vision(HIM " $p被$P攻的破绽百出！\n" NOR, me, target);
}

int perform(object me, object target)
{
    object weapon;
    string msg;
    int attack_time;
    if( !target ) target = offensive_target(me);
    if( !target
    ||  !target->is_character()
    ||  !me->is_fighting(target) )
        return notify_fail("「连环神龙」只能对战斗中的对手使用。\n"); 
 if ( (string)me->query("family/family_name") != "五毒教") 
       return notify_fail("「"HIR"连环神龙"NOR"」只有五毒教弟子才能使用。\n");
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你使用的武器不对。\n");
   if (me->query_skill_mapped("sword")!="wudu-goufa") {me->start_busy(random(3)); return notify_fail("你必须要激发到剑法上才能使用该pfm。\n");
 }


    if( (int)me->query_skill("wudu-goufa", 1) < 300 )
        return notify_fail("你的五毒钩法等级不够娴熟，不会使用「连环神龙」。\n");
     if (me->query_temp("perform"))  return notify_fail("你上一个招式还没完成!\n");
    if ( me->query("neili")<100 )   return notify_fail("你的内力不足!\n");
    if( me->is_busy()) return notify_fail("你现在正忙着。\n");
msg = HIG "$N邪恶的一笑，手中"BLINK HIW + weapon->name() + NOR HIG"如万蛇出洞般卷向$n,使的正是五毒钩法之终极必杀技「"BLINK HIR"连环神龙"NOR HIG"」。\n" NOR;
    if( random(10*(me->query_skill("wudu-goufa",1)+me->query_skill("unarmed",1)) ) > (me->query_skill("unarmed",1)*2)/3 ) 
    {
  attack_time = (int)me->query_skill("wudu-goufa", 1) / 50;
if (attack_time> 30) attack_time=30;
        if(attack_time < 1)
            attack_time = 1;
    me->start_call_out( (: call_other, __FILE__, "do_attack", me, target,weapon,attack_time :), 1);
    if (me->query("neili")<150)
        me->set("neili",0);
    else
        me->add("neili", -150);
    me->set_temp("perform",1);
    }
    else
    {
        msg += HIC  "可是$p经验老到随手一挡，就挡去了$P的攻击。\n" NOR;
          me->start_busy(random(3));
    }
    message_vision(msg, me, target);
    return 1;
}


