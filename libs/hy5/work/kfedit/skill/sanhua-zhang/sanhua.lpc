//sanhua-zhang perform 四季散花(春夏秋冬)
// by beyond
// rewrite by snowman
#include <ansi.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
      string msg;
      int damage, p;                                   

      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) )
      return notify_fail("「四季散花」只能在战斗中对对手使用。\n");
             
      if(me->query_temp("weapon"))
      return notify_fail("你必须空手使用「四季散花」！\n");
      
      if( (int)me->query_skill("sanhua-zhang",1) < 100 )
      return notify_fail("你的散花掌不够娴熟，不能使用「四季散花」！\n");
      
      if( (int)me->query_skill("yijinjing",1) < 100 )
      return notify_fail("你的易筋经内功等级不够，不能使用「四季散花」！\n");  
      
      if( (int)me->query_str() < 30 )
      return notify_fail("你的臂力不够强，不能使用「四季散花」！\n");
      
      if( (int)me->query("neili") < 800 )
      return notify_fail("你的内力太弱，不能使用「四季散花」！\n");
      
                                                                                 
      if (me->query_skill_prepared("strike") != "sanhua-zhang"
          || me->query_skill_mapped("strike") != "sanhua-zhang")
      return notify_fail("你现在无法使用「四季散花」进行攻击。\n");     
     
      damage = (int)me->query_skill("sanhua-zhang", 1);
      damage = (int)me->query_skill("yijinjing", 1)+damage;
      damage = (int)me->query_skill("yijinjing", 1)+damage;
      
        switch(random(4)) {
        case 0:
           { msg = GRN"
$N突然面带微笑，手掌微张，掌中涌出一股劲风，恍忽是一片片嫩绿的"CYN"「芳草」"GRN"，直向$n的面颊飞去！\n"NOR;
                damage = damage/3 + random(damage/3);               
                me->set_temp("nl", -120);} break;
          
        case 1:        
          { msg = MAG"
只听$N“哎呀”一声，身行象前跌去，突然一道蓝光闪现，破空之声中几朵"WHT"「清兰」"MAG"向$n的胸前飞去！\n"NOR;             
                damage = damage/3 + random(damage/2);                
                me->set_temp("nl", -180);} break;

        case 2:        
          { msg = HIY"
突然$N双手莫念经文，$n忽然觉得眼前人影如山，忽而排山倒海，忽而忽而高山流水，
觉得一切都在离$n远去，跟着一股醉人的"GRN"「秋菊」"HIY"清香扑鼻而来。。。\n"NOR;           
                damage = damage/2 + random(damage/3);                                
                me->set_temp("nl", -220);} break;
        
        case 3:
         { msg = HIW"
突然$N大吼一声，顿时把$n瞎了一个激灵，之间$N在眉宇之间布满了一层薄霜，
双目冷冷的瞪着$n，接着僧袍一卷，一朵朵绽开的"MAG"「寒梅」"HIW"向$n满面扑来！\n"NOR;          
                damage = damage/2 + random(damage/2);               
                me->set_temp("nl", -300);} break;
        }
    if (random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/2 &&
        random(10) > 2)
            {
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                me->add("neili", me->query_temp("nl"));
                me->add("jing", -50);
                me->delete_temp("nl");
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";                
                } 
            else 
               {       
                me->start_busy(3);
                me->add("neili", -(100+random(100))); 
                me->add("jing", -25);
                me->delete_temp("nl");
                message_vision(msg, me, target);               
                msg = CYN" 可是$p一个巧云翻身，远远的躲了开去。\n"NOR;
               }
            message_vision(msg, me, target);
           return 1;
       
}
