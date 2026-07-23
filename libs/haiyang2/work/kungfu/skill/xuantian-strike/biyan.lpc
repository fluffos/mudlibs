#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int check_pfm(object me, object target);
int perform(object me, object target)
{
      object ob,weapon;
weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「碧焰」攻击只能对战斗中的对手使用。\n");
      
	if( objectp(me->query_temp("weapon")) 
	&& (string)weapon->query("skill_type") != "staff")
		return notify_fail("你必须空手才能使用「碧焰」！\n");		

//        if(!objectp(ob = present("huo yan", environment(me))))
//                return notify_fail("没有火堆怎么驱动「碧焰」进行攻击？\n");
        if(me->query_temp("pfm_chousui"))
                return notify_fail("你正在驱动火堆进行攻击！\n");
       message_vision(HIC"\n$N右手指向"HIR"火堆"HIC"，默不作声的注视着火焰，左掌按胸，口中喃喃的不知说些什么。。。\n"NOR,me);
       me->start_busy(1);
       me->set_temp("pfm_chousui", 1);
       if(random(me->query_kar()) > 15)
             check_pfm(me, target);
       else call_out("check_pfm", 2, me, target);
       return 1;
}

int check_pfm(object me, object target)
{
        string msg, *limbs;
        int i, neili, ap, dp, damage, p;

        if(!me) return 0;
        if(!target) return 0;
        i = (int)me->query_skill("xuantian-strike", 1);
        neili = (int)me->query("neili");        

        me->delete_temp("pfm_chousui");
        if(!living(me) || me->is_ghost()) return 1;
        if( i < 80 ){
                tell_object(me, "你发现自己的玄天冰蚕掌还不够娴熟，无法使用「碧焰」进行攻击。\n");
                return 1;
                }
        if( (int)me->query_skill("huagong-dafa",1) < 80 ){
                tell_object(me,"你发现自己的化功大法修为不够，无法使用「碧焰」进行攻击。\n");
                return 1;
                }
        if( me->query_skill_mapped("force") != "huagong-dafa"){
                tell_object(me,"你发现自己所用的内功无法进行「碧焰」攻击。\n");
                return 1;
                }
        if( (int)me->query("max_neili") < 500) {
                tell_object(me,"你发现自己内力太弱，无法驱动「碧焰」进行攻击。\n");
                return 1;
                }
        if(neili < 300){
                tell_object(me,"你发现自己现在真气太弱，使不出「碧焰」进行攻击。\n");           
                return 1;
                }     
          
        if(!living(target) || !target || !me->is_fighting(target) || environment(me)->query("no_fight")
           || environment(me)!=environment(target)){
           message_vision(HIY"$N缓缓将右手收回，散开内息，双手下垂而立。\n"NOR,me);
           return 1;
           }
 
        if(target->query_condition("xx_poison") > 100){
                tell_object(me,"对方已经身中无数剧毒，你不用再进行「碧焰」攻击了。\n");           
                return 1;
                }
        ap = me->query("combat_exp")/1000 * i * me->query_str();
        dp = target->query("combat_exp")/1000 * target->query_skill("parry",1) * target->query_dex();
        if (ap < 1) ap = 1;
        if (dp < 1) dp = 1;
        me->add("neili", -100);
        me->add("jing", -10);

        msg = HIC"\n然后$N突然双掌向前平平推出，但见"RED"火焰"HIC"微微颤动了两下，吐出一道"GRN"碧焰"HIC"，射向$n的$l！\n"NOR;        
        if(random(ap) > dp/4){
          damage = random(i)*2+me->query("jiali")*2;
          if(neili > target->query("neili")*2) damage = damage*2;
          if (damage > 700) damage = 700;
          target->receive_damage("qi", damage, me);
          target->receive_wound("qi", damage/2, me);
	 target->apply_condition("x2_sandu",20);
	 target->apply_condition("sanpoison",20);
          target->apply_condition("xx_poison",  (me->query_skill("poison", 1)/2) + target->query_condition("xx_poison"));
          p = (int)target->query("qi")*100/(int)target->query("max_qi");
          msg += damage_msg(damage, "刺伤");
          msg += "( $n"+eff_status_msg(p)+" )\n";
          me->start_busy(1);
          me->add_temp("max_guard",-1);
          target->start_busy(1);
          }
        else{
          me->start_busy(2);
          me->add_temp("max_guard",-1);
          msg += HIY"\n$p全力向后一纵一闪，凶险万分地避开了那急速而来的$w"HIY"！\n" NOR;
          }       
       limbs = target->query("limbs");
       msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
       msg = replace_string(msg, "$w", GRN"碧焰"NOR);
       message_vision(msg, me, target);
       return 1;
}

