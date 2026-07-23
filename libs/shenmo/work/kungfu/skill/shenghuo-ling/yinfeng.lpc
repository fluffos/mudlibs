// yinfeng.c 阴风刀
// by snowman

#include <ansi.h>
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{        
           object weapon;
// mapping fam
        int damage, p;
        string msg;
        weapon = me->query_temp("weapon");

        if( !target) target = offensive_target(me);
        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) )
                return notify_fail("「阴风刀」只能对战斗中的对手使用。\n");
       
//        if (me->query_skill_mapped("sword") != "shenghuo-lingfa")
//                return notify_fail("你必须先将圣火令法功和圣火神功相互配合。\n");
        if(!weapon)
                return notify_fail("你必须使用武器来传递阴风刀内劲！\n");   
//        if(!(weapon->id("shenghuo ling") || weapon->id("tieyan ling") || weapon->id("tie ling")))
//                return notify_fail("你必须使用圣火令或铁焰令来传递阴风刀内劲！\n");     
        if( (int)me->query_skill("shenghuo-shengong",1) < 130 )
                return notify_fail("你的圣火神功等级不够，不能施展阴风刀内劲！\n");
        if( (int)me->query_skill("shenghuo-ling",1) < 130 )
                return notify_fail("你的圣火令法等级不够，不能施展阴风刀内劲！\n");
        if( (int)me->query_skill("force", 1) < 130 )
                return notify_fail("你的基本内功等级不够，不能施展阴风刀内劲！\n");
        if( (int)me->query("neili") < 500 )
                return notify_fail("你的真气不足，不能施展阴风刀内劲！\n");
        if( (int)me->query("max_neili") < 1200 )
                return notify_fail("你的内力不足，不能施展阴风刀内劲！\n");
        if( (int)me->query("jing") < 100 )
                return notify_fail("你的精力不足，不能施展阴风刀内劲！\n");

        tell_object(me, HIW"\n你悄悄使出"BLU"阴风刀"HIW"，运起一股无形无质的阴寒之气，直插"+target->name()+"胸口玉堂穴要穴！\n"NOR); 
      if(random(me->query_skill("force"))*(me->query_temp("yinfeng")+1) > 
         random(target->query_skill("force")/3)){                
           damage = me->query_skill("force");
           damage = damage + random(damage);
           if(target->query_skill("force")-50 > me->query_skill("force")/2)
             damage = damage/2;                  
           if(target->query_skill("force") > me->query_skill("force"))
             damage = random(50);
           if(me->query_skill("force") > target->query_skill("force"))
             damage = damage+random(damage);
           if(me->query_temp("yinfeng"))
             damage = damage*(me->query_temp("yinfeng")+1);
           if(damage > 1000){
              tell_object(target, HIB"\n突然之间，一股无形无质、利如钢刃的阴寒之气直插入你胸口的“玉堂穴”中！
"HIR"你霎时之间闭气窒息，全身动弹不得！\n"NOR);
              target->start_busy(3);
              }
           else if(damage <= 50){
              damage = 10;
              tell_object(target, HIY"\n突然之间，一股利如钢刃般的阴寒之气直插你胸口的玉堂穴！
幸好你护体神功遍护全身，这股阴风刀虽利，却也伤你不得！\n"NOR);
              tell_object(me, HIY"你连运阴风刀的内劲，但见对方竟是毫不费力的抵挡了下来！\n"NOR);
              }
           else{
              tell_object(target, HIB"\n突然之间，一股阴劲如刀、如剑、如匕、如凿，直插入你胸口的“玉堂穴”中！
"HIR"你霎时之间闭气窒息，全身动弹不得！\n"NOR);
              target->start_busy(2);
              }
           target->receive_damage("qi", damage);
           target->receive_wound("qi", damage/2);
           target->add("neili", -damage/2); 
           p = (int)target->query("qi")*100/(int)target->query("max_qi");
           tell_room(environment(target), HIR + target->name()+"突然全身猛地一震，面如金纸，震退了数步，彷佛被什么人在胸口处猛击了一下似的！\n" NOR, ({ target })); 
           msg = damage_msg(damage, "内伤");
           msg += "( $n"+eff_status_msg(p)+" )\n"; 
           message_vision(msg, me, target);          
//           if(!target->is_killing(me->query("id"))) target->kill_ob(me);      
           me->start_busy(2);
           me->add("neili", -200);
           return 1;
           }
         
     else {       
          me->add("neili", -100);
           me->start_busy(2);
          tell_object(me, HIY"结果阴风刀内劲还没触到"+target->name()+"的身体便已经散了。\n"NOR);
          }
        return 1;
}
