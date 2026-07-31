// junji.c
// by snowman@SJ 13/05/99

#include <ansi.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
  string msg, dodge_skill;
  int damage, p, jiali, skill, neili, neili2;

  if( !target ) target = offensive_target(me);

  if( !target || !target->is_character() ||  !me->is_fighting(target) 
      || environment(target)!=environment(me) || !living(target))
         return notify_fail("「峻极神掌」只能在战斗中用。\n");

  if( me->query_temp("weapon")) 
         return notify_fail("你手握武器，如何使得出「峻极神掌」？\n");
         
  if( me->query_temp("combat_yield") )
         return notify_fail("你不出手，如何使得出「峻极神掌」？\n");

  if( (int)me->query_temp("ss_junji") )
         return notify_fail("你刚施展完「峻极神掌」，先调息一下吧！\n");
         
  if( (skill = (int)me->query_skill("songyang-zhang", 1)) < 140 )
         return notify_fail("你的大嵩阳神掌不够娴熟，不会使「峻极神掌」！\n");

  if( (int)me->query_skill("hanbing-zhenqi", 1) < 100 )
         if( (int)me->query_skill("songshan-qigong", 1) < 140 )
                return notify_fail("你的内功火候不够，不会使用「峻极神掌」！\n");

  if( me->query_skill_mapped("force") != "hanbing-zhenqi"
   && me->query_skill_mapped("force") != "songshan-qigong" )
         return notify_fail("你所用的内功和「峻极神掌」相互冲突！\n");

  if (me->query_skill_prepared("strike") != "songyang-zhang" ||
      me->query_skill_mapped("strike") != "songyang-zhang")
         return notify_fail("你必须先将大嵩阳神掌运用于掌法之中才行。\n");

  if( (jiali = (int)me->query("jiali")) < 50 )
         return notify_fail("你掌上不带内力，怎么使得出「峻极神掌」来？\n");

  if( (neili = (int)me->query("neili")) < 500 )
         return notify_fail("你的真气不足，不能施展「峻极神掌」！\n");
  if( (int)me->query("max_neili") < 1500 )
         return notify_fail("你的内力不足，不能施展「峻极神掌」！\n");
  if( (int)me->query("jingli") < 300 )
         return notify_fail("你的精力不足，不能施展「峻极神掌」！\n");

  me->start_busy(2+random(2));
  me->receive_damage("neili", me->query_skill("force") );
  me->receive_damage("jingli", 50);
  msg = CYN "\n只听“啪”的一声响，$N"CYN"抢上前，对着$n"CYN"迅速击出一掌，";

  if( random( me->query("combat_exp") ) < target->query("combat_exp")/2) {
         dodge_skill = target->query_skill_mapped("dodge");
         if( !dodge_skill ) dodge_skill = "dodge";
         msg += "掌风凛冽，不可小视！\n"NOR + SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
         message_vision(msg, me, target);
         return 1;
         }
  
  msg += "$p慌忙出手，双掌随即相交！\n"NOR;
  neili = me->query("neili");
  neili2 = target->query("neili");
  
  if( me->query_skill("force") < target->query_skill("force")/2
     || neili < neili2/2){
         msg += "结果相拼之下，$n立占上风，将$N一下子震了开来！\n";
         damage = target->query_skill("force") * 2;
         me->receive_damage("qi", damage,  target);
         me->receive_wound("qi", random(damage/2), target);
         p = (int)me->query("qi")*100/(int)me->query("max_qi");
         msg += damage_msg(damage, "内伤") + "( $N"+eff_status_msg(p)+" )\n";     
         }
  else if( me->query_skill("force") < target->query_skill("force")/3*2
         || neili < neili2/3*2)        
         msg += "结果相拼之下，两人都晃了一晃，谁也没有占到好处！\n";
            
  else {
         damage = me->query_skill("force") + jiali * (3+random(5));
         if(neili > neili2*2) damage *= 2;
         if(damage > 3000) damage = 3000;
         if(damage < 10) damage = 10;         
           
         if(!target->is_busy())
                 target->start_busy(1);
         target->receive_damage("qi", damage,  me);
         target->receive_wound("qi", random(damage/3), me);
         p = (int)target->query("qi")*100/(int)target->query("max_qi");
         msg += damage_msg(damage, "内伤") + "( $n"+eff_status_msg(p)+" )\n"; 
         if(target->is_killing(me->query("id"))
            || me->is_killing(target->query("id")))
                 call_out("perform2", 0, me, target, p, damage);
                 
         p = 30 - skill/10;
         if(p < 7) p = 7;
         call_out("remove_effect", p, me);
         }
  message_vision(msg, me, target);
  return 1;
}

int perform2(object me, object target, int p, int damage)
{
        string msg, dodge_skill;

        if( !target || !target->is_character() ||  !me->is_fighting(target) 
           || environment(target)!=environment(me) || !living(target))
                return notify_fail("对手已经不能再战斗了。\n");

        if( (int)me->query("neili") < me->query_skill("force")*2 )
                return notify_fail("你待要再发一掌，却发现自己的内力不够了！\n");     

        msg = CYN "\n$N"CYN"微微一笑，双掌陡然相交，$n"CYN"欲待再催内力，已然不及，$P的掌力如排山倒海般压到！\n"NOR;        
        if ( me->query("neili") > target->query("neili") / 2 
          && random( me->query("combat_exp") ) > target->query("combat_exp")/2){
                me->start_busy(2);
                me->receive_damage("neili", me->query_skill("force")*2);
                me->receive_damage("jingli", 20);                              
                damage = damage*2;
                if(me->query("neili") > target->query("neili")*2 ) 
                       damage += random(damage);
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage/3, me);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "内伤") + "( $n"+eff_status_msg(p)+" )\n"; 
        } 
        else 
        {
                me->start_busy(3);
                me->add("neili", -200);
                dodge_skill = target->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        }
        message_vision(msg, me, target); 
        return 1;
}

void remove_effect(object me)
{
        if (!me) return;
        me->delete_temp("ss_junji");
        if(living(me))
            tell_object(me, "\n你经过一段时间调气养息，又可以使用「峻极神掌」了。\n"); 
}