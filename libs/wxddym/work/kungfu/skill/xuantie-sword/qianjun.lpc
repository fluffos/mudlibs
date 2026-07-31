//Code by Scatter
//modified by Slow
//V. 1.5
// 修改错字
/*
　　○千均一击
      指令：perform qianjun
      条件：玄铁剑法有效等级300，
            玉女心经有效等级300，
            最大内力3000
      特点：重型pfm,极耗内力
*/

#include <ansi.h>

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon;
        int skill, skill1;
        int myskill;
        int damageone;
        int damagesub;
        int damage;
        string msg;
        int ap,dp;
        int status_flag=0;


                
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("千均一击只能对战斗中的对手使用。\n");


        if( !objectp(weapon = me->query_temp("weapon") ) )
                return notify_fail("你未持武器，不能使用千均一击！\n");

        if( me->query_skill("force") < 300 )
                return notify_fail("你的内功火候未到，无法施展千均一击！\n");

        if( me->query_skill("sword") < 300 )
                return notify_fail("你的剑法火候未到，无法施展千均一击！\n");

        if( me->query("max_neili") <= 3000 )
                return notify_fail("你的内力不够施展千均一击！\n");

        if( me->query("neili") <= 1000 )
                return notify_fail("你的内力不够施展千均一击！\n");

        //if( me->query("jingli") <= 1000 )
        //        return notify_fail("你的精力不够施展千均一击！\n");


           msg =HIW"\n\n$N身子左斜，左手抽出背负的"+weapon->query("name")+"，顺手一招「千均一击」!\n"NOR;
         ap=me->query("combat_exp")/2000+me->query_skill("force")+me->query_skill("sword");
         dp=target->query("combat_exp")/1000+target->query_skill("dodge");
               damage=me->query_skill("force")+me->query_skill("sword"); 
                   damage *=2; 
            if ( ap/3 + random(ap*5/3) > dp/3 + random(dp*4/3)) 
        {
msg+=HIB"$N力道使得极猛,挺剑送出。$n早有提防，却万想不到来势竟是如此猛烈，眼见闪避不及，
只听砰的一声猛响，登时连退了五六步，才勉强拿椿站定，等时脸如金纸。\n"NOR;
           target->receive_damage("qi", damage+100,  me);
          target->receive_wound("qi", random(damage/2)+damage/2+100, me);
           me->start_busy(1+random(3));
           status_flag=1;
        }


        else if ( me->query("int") > random(target->query("int")*2) )
        {
msg+=
HIB"$N一剑击出，右手长袖顺势拂去，$n顷刻间只感五脏六腑都似翻转了，站在当地，既不敢运气，
也不敢移动半步，便如僵了一般。\n"NOR;
             if (! target->is_busy())
             target->start_busy(3+random(4));
         me->start_busy(2+random(2));
          status_flag=1;
        }
          else if (ap/3 >random(dp*2))
          {
msg+=
HIC"$N只觉对方冲撞而来的劲力绵绵不绝，越来越强,运出所有内力振臂一击。\n" NOR;
          me->add("neili", -300);
          target->add("neili", -300);
          me->start_busy(1+random(2));
             if (! target->is_busy())
          target->start_busy(1+random(2));
            status_flag=1;
          }
           else
         {
msg += HIG"$n凌空飞跃，身形疾闪，使出本门轻功，身子往回轻轻一侧，$N的发招数尽数落空。\n"NOR;
             me->start_busy(2+random(2));
      }
          me->add("neili", -200);

  message_vision(msg+"\n", me, target);
         if (status_flag==1) COMBAT_D->report_status(target);
  return 1;


}
