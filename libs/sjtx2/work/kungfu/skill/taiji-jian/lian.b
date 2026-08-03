// lian.c 「连」字诀

#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";
inherit F_SSERVER;

string *name1 = ({"胸口「膻中穴」", "背心「灵台穴」","项颈「大椎穴」", "胸下「巨阙穴」","双臂「清冷渊穴」", "肋下「渊液穴」","胸口「玉枕穴」"});

int perform(object me, object target)
{
      object wep;
      me = this_player();
      wep = me->query_temp("weapon");
      if( !target ) target = offensive_target(me);
      
      if( !target || !me->is_fighting(target) )
                 return notify_fail("「连」字诀只能在战斗中对对手使用。\n");
if((int)me->query_temp("tjj/chan"))
return notify_fail(WHT"你现在正在使用「缠」字诀。\n"NOR);
      if(!living(target))
                 return notify_fail("「连」字诀只能在战斗中对对手使用。\n");
      if(!wep || wep->query("skill_type") != "sword" )
                 return notify_fail("你手中无剑，如何使得「连」字诀？\n");
      if(me->query_skill_mapped("sword") != "taiji-jian")
                 return notify_fail("你现在无法使用「连」字诀。\n");
      if(me->query_skill_mapped("parry") != "taiji-jian")
                 return notify_fail("你现在无法使用「连」字诀。\n");  
      if( (int)me->query_temp("tjj/lian") )
return notify_fail(WHT"你现在正在使用「连」字诀。\n"NOR);
      if( (int)me->query_skill("taiji-jian", 1) <120)
                 return notify_fail("你的太极剑法修为尚不纯熟,无法使用「连」字诀！\n");             
      if( (int)me->query_skill("yinyun-ziqi",1) < 120 )
                 return notify_fail("你的氤氲紫气修为尚浅，不能使用「连」字诀！\n");
      if( (int)me->query_skill("sword",1) < 120 )
                 return notify_fail("你基本剑法修为尚不纯熟,不能使用「连」字诀！\n");  
      if( (int)me->query("max_neili") < 1500 )
                 return notify_fail("你的内力修为太弱，不能使用「连」字诀！\n");
      if( (int)me->query("neili") < 800 )
                 return notify_fail("你的真气太少了，不能使用「连」字诀！\n");  

      message_vision(CYN
"$N微微一笑，使出太极剑中「连」字诀，当下身子缓缓右转,左手持剑向上提起，剑身横于胸前，左右掌心相\n"
"对，如抱圆球，手中"+wep->name()+"未出，已然蓄势无穷。\n"NOR,me,target);
                me->set_temp("tjj/lian",1);
                call_out("perform1", 0, me);
                return 1;
}

int perform1(object me, object target)        
{
      string msg;
      object wep;
      int i, cost, ap, dp, damage,p;
      me = this_player();
      if( !target ) target = offensive_target(me);
      p = (int)target->query("qi")*100/(int)target->query("max_qi");
      wep = me->query_temp("weapon");
      i = (int)me->query_skill("taiji-jian", 1) +(int)me->query_skill("sword", 1);
      cost = me->query_skill("taiji-jian", 1)/2;
if(!objectp(wep = me->query_temp("weapon")) || wep->query("skill_type") != "sword"){ 
                if(!wep) msg = HIY"$N手中武器既失，圆转的太极剑幕也随之消散。\n"NOR;
else if(!target)
msg = HIY"$N将手中"+wep->name()+HIY"向后一摆，抱圆守一，撤回了散开的太极剑意．\n"NOR;
else msg = HIY"$N亮出"+wep->name()+HIY"而撤回太极剑意，$n身边密布的剑幕也随之消散，压力骤然减轻！\n"NOR;
me->start_busy(1);}
      msg = CYN"$N左手"+wep->name()+"缓缓向前划出，成一弧形，一股森森寒气，直逼向$n，突然之间，$N剑交右手，寒光一闪，向$n划去。\n"NOR;
      ap = me->query("combat_exp")/1000 + me->query("max_neili")/10 + me->query_con()*10;
      dp = target->query("combat_exp")/1000 + target->query("neili")/10 + target->query_con()*10;
      if (ap < 1) ap = 1;
      if (dp < 1) dp = 1;

      if (random(ap)>dp/3)
               {         
                damage = i + random(i)/2;
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                me->add("neili", -cost/2);
                me->add("jingli", -cost/10);
                msg +=HIR"结果只听见$n一声惨嚎，"+wep->name()+"已在$n的身上划出一道深可见骨的可怕伤口，鲜血溅得满地！！\n"NOR;
                msg += "( $n"+eff_status_msg(p)+" )\n\n";
                if( (int)me->query("neili") > 500
                &&  present(target->query("id"), environment(me)) 
                &&  me->is_fighting(target) 
                &&  living(target)
                &&  living(me)
                &&  me->is_fighting()
                &&  target->is_fighting()
                &&  !target->is_ghost()
                &&  !me->is_ghost()
                &&  me->query_skill_mapped("sword") == "taiji-jian"
                &&  me->query_skill_mapped("parry") == "taiji-jian"
                &&  (string)wep->query("skill_type") == "sword" ) 
                    { me->start_busy(1);
                      target->start_busy(1);
                      call_out("perform2", 0, me);    
                    }
                else                 
                    { me->start_busy(1);
                      target->start_busy(1);                      
                      me->delete_temp("tjj/lian");
                      msg += HIY"$N「连」字诀运行完毕，剑交左手，收剑而立，笼罩在全身上下的大小光圈随即不见踪影。\n"NOR;
                    }
               }
            else
               {         
                me->add("neili", -cost/2);
                me->add("jingli", -cost/10);
                msg += HIY"\n$p大叫一声不好，全身用力一纵，顺势跳了开去。\n\n" NOR;
                if( (int)me->query("neili") > 500
                &&  present(target->query("id"), environment(me)) 
                &&  me->is_fighting(target) 
                &&  living(target)
                &&  living(me)
                &&  me->is_fighting()
                &&  target->is_fighting()
                &&  !target->is_ghost()
                &&  !me->is_ghost()
                &&  me->query_skill_mapped("sword") == "taiji-jian"
                &&  me->query_skill_mapped("parry") == "taiji-jian"
                &&  (string)wep->query("skill_type") == "sword" ) 
                    { me->start_busy(1);
                      target->start_busy(1);
                      call_out("perform2", 0, me);    
                    }
                else                 
                    { me->start_busy(1);
                      target->start_busy(1);
                      me->delete_temp("tjj/lian");
                      msg += HIY"$N「连」字诀运行完毕，剑交左手，收剑而立，笼罩在全身上下的大小光圈随即不见踪影。\n"NOR;
                    }
                }
      message_vision(msg, me, target);
      return 1;
}
              
int perform2(object me, object target)
{
      string msg, name;
      int i, cost, ap, dp, damage,p;
      object wep;
      me = this_player();
      if( !target ) target = offensive_target(me);
      p = (int)target->query("qi")*100/(int)target->query("max_qi");
      wep = me->query_temp("weapon");
      name = name1[random(sizeof(name1))]; 
      i = (int)me->query_skill("taiji-jian", 1) + (int)me->query_skill ("sword", 1);
      cost = me->query_skill("taiji-jian", 1)/2;
      ap = me->query("combat_exp")/1000 + me->query("max_neili")/10 + me->query_con()*10;
      dp = target->query("combat_exp")/1000 + target->query("neili")/10 + target->query_con()*10;
      if (ap < 1) ap = 1;
      if (dp < 1) dp = 1;
msg =CYN"$N又是剑交左手，在身前划了两个圆圈，剑劲连绵护住全身，竟无半分空隙，右手捏着剑诀，左手剑不住的抖\n"
"动，罩向$n上盘七大要穴，剑尖急颤，看不出攻向何处。\n"NOR;
"罩向$n上盘七大要穴，剑尖急颤，看不出攻向何处。\n"NOR;
      
      if (random(ap) > dp/2)
               {         
                damage = i*2 + random(i);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage*5/12);
                me->add("neili", -cost);
                me->add("jingli", -cost/5);
                if( damage < 500 ){
                msg += HIR"结果「噗嗤」地一声，"+wep->name()+"已在$n"+name+"刺出一个血肉模糊的血窟窿！\n"NOR;
                msg += "( $n"+eff_status_msg(p)+" )\n\n";}

                else {
                msg += HIR"结果只听见$n一声惨嚎，"+wep->name()+"已在$n的"+name+"对穿而出，鲜血溅得满地！！\n"NOR;
                msg += "( $n"+eff_status_msg(p)+" )\n\n";}

                if( (int)me->query("neili") > 500
                &&  present(target->query("id"), environment(me)) 
                &&  me->is_fighting(target) 
                &&  living(target)
                &&  living(me)
                &&  me->is_fighting()
                &&  target->is_fighting()
                &&  !target->is_ghost()
                &&  !me->is_ghost()
                &&  me->query_skill_mapped("sword") == "taiji-jian"
                &&  me->query_skill_mapped("parry") == "taiji-jian"
                &&  (string)wep->query("skill_type") == "sword" ) 
                    { me->start_busy(1);
                      target->start_busy(1);
                      call_out("perform3", 0, me);    
                    }
                else                 
                    { me->start_busy(1);
                      target->start_busy(1);                      
                      me->delete_temp("tjj/lian");
msg += HIY"\n$N「连」字诀运行完毕，剑交左手，收剑而立，笼罩在全身上下的大小光圈随即不见踪影。\n\n"NOR;
                    }
                }
      else
               {         
                me->add("neili", -cost);
                me->add("jingli", -cost/5);
                msg += HIY"可是$p一个巧云翻身，远远的躲了开去。\n\n"NOR;
                if( (int)me->query("neili") > 500
                &&  present(target->query("id"), environment(me)) 
                &&  me->is_fighting(target) 
                &&  living(target)
                &&  living(me)
                &&  me->is_fighting()
                &&  target->is_fighting()
                &&  !target->is_ghost()
                &&  !me->is_ghost()
                &&  me->query_skill_mapped("sword") == "taiji-jian"
                &&  me->query_skill_mapped("parry") == "taiji-jian"
                &&  (string)wep->query("skill_type") == "sword" ) 
                    { me->start_busy(1);
                      target->start_busy(1);
                      call_out("perform3", 0, me);    
                     }
                else                 
                    { me->start_busy(1);
                      target->start_busy(1);
                      me->delete_temp("tjj/lian");
msg += HIY"\n$N「连」字诀运行完毕，剑交左手，收剑而立，笼罩在全身上下的大小光圈随即不见踪影。\n\n"NOR;
                     }
                }                
      message_vision(msg, me, target);
      return 1;
}

int perform3(object me, object target)
{
      string msg;
      int i, cost, ap, dp, damage,p;
      object wep;
      me = this_player();
      if( !target ) target = offensive_target(me);
      p = (int)target->query("qi")*100/(int)target->query("max_qi");
      wep = me->query_temp("weapon");
      i = (int)me->query_skill("taiji-jian", 1) +(int)me->query_skill ("sword", 1);
      cost = me->query_skill("taiji-jian", 1)/2;
      ap = me->query("combat_exp")/1000 + me->query("max_neili")/10 + me->query_con()*10;
      dp = target->query("combat_exp")/1000 + target->query("neili")/10 + target->query_con()*10;
      if (ap < 1) ap = 1;
      if (dp < 1) dp = 1;

msg = CYN"$N剑上所幻的光圈越来越多，过不多时，全身已隐在无数光圈之中，光圈一个未消，另一个再生，手中"+wep->name()+"\n"
"虽使得极快，却丝毫听不到金刃劈风之声，足见剑劲之柔韧已达于化境。\n"
HIW"$n凝视剑光所幻无数光圈绞向自己，见无可退避，只得冒险一击，当下手臂一伸，向光圈的中心挥刃直入。\n"NOR;
            "手中"+wep->name()+"虽使得极快，却丝毫听不到金刃劈风之声，足见剑劲之柔韧已达于化境。\n"
            WHT"$n凝视剑光所幻无数光圈绞向自己，见无可退避，只得冒险一击，当下手臂一伸，向光圈的中心挥刃直入。\n"NOR;
      
      if (random(ap+dp) > dp)
              {         
                call_out("check_fight", 1, me, target);                                 
                me->start_busy(1);
                target->start_busy(random(2)+1);
                damage = i*3 + random(i*2);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                me->add("neili", -cost*2);
                me->add("jingli", -cost/3);
                msg += HIR"只听喀嚓喀嚓几声轻响，$n的手臂被光圈这么一套，登时绞断，整个身体亦被罩入剑光圈中。\n"NOR;
                msg += "( $n"+eff_status_msg(p)+" )\n\n"; 
             }
      else
               {         
                me->start_busy(random(2)+1);
                target->start_busy(1);
                me->add("neili", -cost);
                me->add("jingli", -cost/5);
                msg += HIR"当的一声大响，$n只感胸口剧烈一震，气血翻涌，一只手臂却仍然完好，无数光圈瞬时消失。\n"NOR;
                msg += "( $n"+eff_status_msg(p)+" )\n\n";          
                me->delete_temp("tjj/lian");
                }
      message_vision(msg, me, target);
      return 1;
} 

int check_fight(object me, object target) 
{
      string msg;
      object wep;
      me = this_player();
      if( !target ) target = offensive_target(me);
      wep = me->query_temp("weapon");
      if(!target) 
msg += HIY"\n$N「连」字诀运行完毕，剑交左手，收剑而立，笼罩在全身上下的大小光圈随即不见踪影。\n\n"NOR;
        
      else if(environment(me) != environment(target))
msg += HIY"\n$N「连」字诀运行完毕，剑交左手，收剑而立，笼罩在全身上下的大小光圈随即不见踪影。\n\n"NOR;

      else if ( !target->is_busy()   &&   me->is_fighting(target) )
         {
          me->delete_temp("tjj/lian");
          msg = HIY"$N「连」字诀运行完毕，剑交左手，收剑而立，笼罩在全身上下的大小光圈随即不见踪影。\n"NOR;
         }                                                

      else if ( !present(target->query("id"), environment(me)) 
      &&   me->is_fighting(target) ) 
          { 
           me->delete_temp("tjj/lian");                
msg += HIY"\n$N「连」字诀运行完毕，剑交左手，收剑而立，笼罩在全身上下的大小光圈随即不见踪影。\n\n"NOR;
           }                                                
        
      else if( !living(target) || !present(target->query("id"),environment(me)) ) 
          { 
           me->delete_temp("tjj/lian");                
msg += HIY"\n$N「连」字诀运行完毕，剑交左手，收剑而立，笼罩在全身上下的大小光圈随即不见踪影。\n\n"NOR;
           } 
        
      else if( !me->is_fighting() || !living(me) || me->is_ghost() ) 
          { 
           me->delete_temp("tjj/lian");                
msg += HIY"\n$N「连」字诀运行完毕，剑交左手，收剑而立，笼罩在全身上下的大小光圈随即不见踪影。\n\n"NOR;
          } 
      

      else if( !objectp(wep) || me->query_skill_mapped("sword") != "taiji-jian"
      || (string)wep->query("skill_type") != "sword" ) 
          { 
           me->delete_temp("tjj/lian");
msg += HIY"\n$N「连」字诀运行完毕，剑交左手，收剑而立，笼罩在全身上下的大小光圈随即不见踪影。\n\n"NOR;
          }
      else {call_out("check_fight", 1, me, target);return 1;}
      message_vision(msg, me, target);
      return 1;
}
