//tulong.c 屠龙
// By Spiderii@ty
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
#define MAX_HITS    24
 
string perform_name() {return HIC"屠龙诀"NOR;}

int perform(object me, object target)
{
        string weapon;
        int i,k;

        if( !target ) target = offensive_target(me);

        if( !objectp(target)
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("屠龙诀只能对战斗中的对手使用。\n");
    
        
      if((int)me->query_skill("yitian-tulong",1) < 200 )
         return notify_fail("你的倚天屠龙功还不够熟练，使不出屠龙诀！\n");
      
      if((int)me->query_skill("literate",1) < 200 )
         return notify_fail("你的读书写字等级不够，使不出屠龙诀！\n");  

      if((int)me->query_skill("sword",1) < 200 )
         return notify_fail("你的基本剑法还不够熟练！\n");

        if( me->query("neili") <= 3000 )
                return notify_fail("你的内力不够使用屠龙诀！\n");

        if( me->query("jingli") <= 1000 )
                return notify_fail("你的精力不够使用屠龙诀！\n");

        if( me->query_temp("yttlg/tulong"))
                return notify_fail("你正在运用屠龙诀！\n");

        if( !me->query_temp("weapon") || (me->query_temp("weapon"))->query("skill_type") != "sword" )
                return notify_fail("你手中无剑怎能使用屠龙诀？！\n");
              
        weapon = (me->query_temp("weapon"))->query("name");
              
       message_vision(HIY "\n$N忽然间剑法又变，以手中" + weapon + HIY"做笔，使出了倚天屠龙功的屠龙一诀！笔划多的不觉其繁,\n" +
        "笔划少的不见其陋，其缩也凝重，似尺蠖之屈，其纵也险劲，如狡兔之脱。攻式若扬波搏击，雁飞雕振，延颈协翼，状似凌云。\n" NOR, me, target);
		k=me->query("int")/10;
        me->set_temp("yttlg/tulong",1);
        me->add_temp("apply/attack",me->query_skill("sword",1));
        me->add_temp("apply/damage",me->query_skill("sword")*k);
 
    for( i = 0; i < 10; i ++ ) {
       if (! me->is_fighting(target))
			break;
             COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
          me->add("neili",-100);
         
        }
    
        me->add("neili", -500);
        me->add_temp("apply/attack",-me->query_skill("sword",1));
        me->add_temp("apply/damage",-me->query_skill("sword")*k);
        me->add("jingli", -300);
        me->delete_temp("yttlg/tulong");
        me->start_busy(3+random(2));

        return 1;
}