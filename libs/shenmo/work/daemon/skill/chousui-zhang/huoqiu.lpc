#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int check_pfm(object me, object target);
int perform(object me, object target)
{
      object ob,weapon;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「火球」攻击只能对战斗中的对手使用。\n");
      
	weapon = me->query_temp("weapon");
	if( objectp(me->query_temp("weapon")) 
	&& (string)weapon->query("skill_type") != "staff")
		return notify_fail("你必须空手才能使用这个绝技！\n");		
//        if(!objectp(ob = present("huo yan", environment(me))))
//                return notify_fail("没有火堆怎么驱动「火球」进行攻击？\n");
        if(me->query_temp("pfm_chousui"))
                return notify_fail("你正在驱动火堆进行攻击！\n");

       message_vision(HIR"\n$N厉声大喝，掌力加盛，火焰中突然生出一个斗大的"RED"火球"HIR"，在空中骨碌碌的迅速转动！\n\n"NOR,me);

       me->start_busy(2);
       me->add_temp("max_guard",-1);
       me->set_temp("pfm_chousui", 1);
       if(random(me->query_kar()) > 15)
             check_pfm(me, target);
       else call_out("check_pfm", 6, me, target);
       return 1;
}

int check_armor(object target)
{
       object *inv;
       int i, j;
       inv = all_inventory(target);
       j=0;
          for(i=0; i<sizeof(inv); i++)
            if( (string)inv[i]->query("equipped")=="worn" ) j++;
       return j;
}
int check_pfm(object me, object target)
{
        string msg, *limbs;
        int i, neili, ap, dp, damage, p;
        object *inv;
        if(!me) return 0;
        if(!target) return 0;
        i = (int)me->query_skill("chousui-zhang", 1);
        neili = (int)me->query("neili");
        damage = (i+me->query("jiali"))*2;

        me->delete_temp("pfm_chousui");
        me->start_busy(1);
        if(!living(me) || me->is_ghost()) return 1;
        if( i < 180 ){
                tell_object(me, "你发现自己的星宿毒掌还不够娴熟，无法使用「火球」进行攻击。\n");
                return 1;
                }
        if( (int)me->query_skill("huagong-dafa",1) < 180 ){
                tell_object(me,"你发现自己的化功大法修为不够，无法使用「火球」进行攻击。\n");
                return 1;
                }
        if( me->query_skill_mapped("force") != "huagong-dafa"){
                tell_object(me,"你发现自己所用的内功无法进行「火球」攻击。\n");
                return 1;
                }
        if( (int)me->query("max_neili") < 1500) {
                tell_object(me,"你发现自己内力太弱，无法驱动「火球」进行攻击。\n");
                return 1;
                }
        if(neili < 1500){
                tell_object(me,"你发现自己现在真气太弱，使不出「火球」进行攻击。\n");           
                return 1;
                }           
        if(!target || !me->is_fighting(target) || environment(me)->query("no_fight")
           || environment(me)!=environment(target)){
           message_vision(HIY"$N衣袖再拂，将升起的"RED"火球"HIY"压回火焰之中。\n"NOR,me);
           return 1;
           }


        ap = me->query("combat_exp")/1000 * i * me->query_str();
        dp = target->query("combat_exp")/1000 * target->query_skill("parry",1) * target->query_con();
        if (ap < 1) ap = 1;
        if (dp < 1) dp = 1;
        me->add("neili", -600);
        me->add("jing", -10);

        msg = WHT"\n此时$N脸上已无半点血色，一口口鲜血不住向"RED"火球"WHT"中吐去，"HIR"火势一盛，嗤嗤两声轻响，
爆出几朵火花，"RED"火球"HIR"陡然变大向$n疾冲过来！\n"NOR;

       
       if(random(ap) > dp/4){
          inv = all_inventory(target);
          if(check_armor(target) >= 1){     
            if(me->query("neili") > target->query("neili")*2){
               if(me->query_str() > random(target->query_str())){
                  me->start_busy(2);
                  target->start_busy(2);
                  msg += HIY"猛烈间火球温度飙升，火花迸射，炸开了$p的护具！\n" NOR;
                  for(i=0; i<sizeof(inv); i++)
                     if((string)inv[i]->query("equipped")=="worn" && !inv[i]->query("unique")){
                         inv[i]->unequip();
                         inv[i]->move(environment(target));
                         inv[i]->set("name", "粉碎的" + inv[i]->query("name"));
                         inv[i]->delete("value");
                         inv[i]->set("armor_prop", 0);
                         }
                  target->reset_action();
                  damage = damage * 3;
                  if (damage > 2000) damage = 2000;
                  damage = damage - target->query_temp("apply/armor");
                  target->receive_damage("qi", damage, me);   
                  target->receive_wound("qi", damage/4, me);             
                          target->apply_condition("xx_poison",20);
	 target->apply_condition("x2_sandu",20);
	 target->apply_condition("sanpoison",20);
target->apply_condition("fire_poison",60);
                  target->apply_condition("xx_poison", random(15) + (me->query_skill("poison", 1)/10) + target->query_condition("xx_poison"));
                  p = (int)target->query("qi")*100/(int)target->query("max_qi");
                  msg += damage_msg(damage, "砸伤");
                  msg += "( $n"+eff_status_msg(p)+" )\n";
                  me->start_busy(1);
                  target->start_busy(1);               
                  }                   
            else {
                  me->start_busy(2);
                  target->start_busy(2);
                  msg += HIY"只见火球猛然升温，火花四溅，热力直透$p的护具！\n" NOR;
                  for(i=0; i<sizeof(inv); i++)
                     if((string)inv[i]->query("equipped")=="worn" && !inv[i]->query("unique")){
                         inv[i]->set("name", "碎裂的" + inv[i]->query("name"));
                         inv[i]->set("value", 49);
                         if(inv[i]->query("armor_prop/armor"))
                             inv[i]->set("armor_prop/armor", inv[i]->query("armor_prop/armor")/2);
                         }
                  target->reset_action();
                  damage = damage * 3;
                  if (damage > 1800) damage = 1800;
                  damage = damage - target->query_temp("apply/armor");
                  target->receive_damage("qi", damage, me); 
                  target->receive_wound("qi", damage/4, me);            
                  target->apply_condition("xx_poison", random(5) + (me->query_skill("poison", 1)/10) + target->query_condition("xx_poison"));
                  p = (int)target->query("qi")*100/(int)target->query("max_qi");
                  msg += damage_msg(damage, "砸伤");
                  msg += "( $n"+eff_status_msg(p)+" )\n";
                  me->start_busy(2);
                  target->start_busy(1);
                  }
               }
           else {
                  me->start_busy(3);
                  target->start_busy(3);
                  msg += HIY"火球急速滚动，火光四溅，掀起阵阵火焰撞向$p怀里！\n" NOR;                  
                  damage = damage * 2;
                  if (damage > 1800) damage = 1800;
                  target->receive_damage("qi", damage, me);
                  target->receive_wound("qi", damage/6, me);                
                  target->apply_condition("xx_poison", 30 + target->query_condition("xx_poison"));
                  p = (int)target->query("qi")*100/(int)target->query("max_qi");
                  msg += damage_msg(damage, "砸伤");
                  msg += "( $n"+eff_status_msg(p)+" )\n";
                  me->start_busy(2);
                  target->start_busy(1);
                  }
            }
        else{
                //target has no armor, so, hehe...
                damage = damage*2 + random(damage);
                if(neili > target->query("neili")*2) damage = damage*2;
                if (damage > 2800) damage = 2800;
                target->receive_damage("qi", damage, me);   
                target->receive_wound("qi", damage/2, me);             
                target->apply_condition("xx_poison", 30 + target->query_condition("xx_poison"));
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "砸伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                me->start_busy(2);
                target->start_busy(1);
                }
        }
     else{
          me->add_temp("max_guard",-1);
        me->start_busy(4);
        msg += HIY"\n$p眼看就要被打中，冒死一个“铁板桥”，全身自膝盖处向后倒去，堪堪避过$w"HIY"！\n" NOR;
        }
       limbs = target->query("limbs");
       msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
       msg = replace_string(msg, "$w", RED"火球"NOR);       
       message_vision(msg, me, target);
//me->kill_ob(target);
//       if(!target->is_killing(me->query("id"))) target->kill_ob(me);
       return 1;
} 

