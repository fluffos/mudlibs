#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;
    int busy;
    busy=(int)me->query("zjb_dj/dj")/2+1; 
    if (busy > 20 ) busy=20;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
        return notify_fail("「破」字诀只能对战斗中的对手使用。\n");

 if ( (string)me->query("family/family_name") != "华山派") 
      return notify_fail("「破字决」只有华山派弟子才能使用。\n");

        if( target->is_busy() )
        return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");
                
        if( (int)me->query_skill("poyu-quan") < 500 )
        return notify_fail("你的破玉拳不够娴熟，不会使用「破」字诀。\n");

        if( (int)me->query_skill("force") < 100 )
        return notify_fail("你的内功不够深厚，不会使用「破」字诀。\n");

msg = HIM "$N使出"HIY"劈石破玉拳「破」"HIM"字诀，全力向$n打出一拳,\n";

 if( random(me->query_skill("unarmed",1)+me->query_skill("poyu-quan",1)) > (int)target->query_skill("unarmed",1) ) {
msg += HIM 
   "结果$p被$P的拳打中，$P的"HIR"拳劲"HIM"一到了$p体内马上化\n" NOR;
msg += HIM  
     "成"HIG"千万条气劲"HIM"，封锁住了$N的各个穴道!!!\n" NOR;
              target->start_busy( busy );
        } else {
       me->start_busy(2);
                msg += HIY"可是$p看破了$P的企图，镇定解招，一丝不乱。\n" NOR;

        }
        message_vision(msg, me, target);

        if(!target->is_fighting(me)) target->fight_ob(me);
        return 1;
}
