#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
    string msg;
    object weapon, weapon2, target;
    int skill, ap, dp, damage;
    me->clean_up_enemy();
    target = me->select_opponent();
    skill = me->query_skill("riyue-lun",1);
    if( !(me->is_fighting() ))
        return notify_fail("「卡字决」只能对战斗中的对手使用。\n");

if ( (string)me->query("family/family_name") != "雪山寺") 
    return notify_fail("「卡字决」只有雪山弟子才能使用。\n");
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "hammer")
        return notify_fail("你使用的武器不对。\n");  
    if (!objectp(weapon2 = target->query_temp("weapon")))
       return notify_fail("对方没有兵刃，你没办法卡住他。\n");

    if( target->is_busy() )
     return notify_fail("对方已经不能动了。\n");
    if( skill < 200)
        return notify_fail("你的日月轮等级不够, 不能使用「卡字决」！\n"); 
    if( me->query("neili") < 500 )
        return notify_fail("你的内力不够，无法运用「卡字决」！\n"); 
msg = HIW "\n$N纵跃退後，立时"HIY"呜呜、嗡嗡、轰轰"HIW"之声大作，
"HIY"金光闪闪"HIW"，银光烁烁，手中兵器从五个不同方位飞袭出来！\n";
     message_vision(msg, me, target);
 
    damage = 10 + random(skill / 2);
    ap = skill*3;
 dp = target->query_skill("unarmed",1);
    if( dp < 1 )
        dp = 1;
    if( random(ap) > dp )
    {
        if(userp(me))
            me->add("neili",-50);
    msg = "$n顿时觉得眼前一花，手中兵器被"HIY+weapon->name()+HIW"卡住无法动了!\n"NOR;
        target->receive_damage("qi", damage);
        target->start_busy(skill/60);
           }
    else
    {
      if(skill>999)
{
            me->add("neili",-30);
msg = "可是$n及时看破$n的企图，将" HIG+ weapon2->name() + HIW"收了回来\n";
msg += "发出掌气来震退了$N的攻击。\n"NOR;
        weapon2->move(target);
   me->start_busy(2); 
  target->start_busy(random(3));
    }
   if(skill<1000)
{
       me->add("neili",-30);
msg = "可是$n及时看破$n的企图，用" HIG+ weapon2->name() + HIW"用力一挡，撑了过去\n"NOR;
   me->start_busy(2); 
target->start_busy(random(3));
  }
}
      message_vision(msg, me, target);
    return 1;
}

