// hama.c 蛤蟆功

#include <ansi.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
        int damage, p;
        string msg, dodge_skill;

        if( !target ) target = offensive_target(me);
        
        if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("蛤蟆功绝招只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("hamashengong", 1) < 150 )
                return notify_fail("你的蛤蟆神功还不够熟练，不能使用蛤蟆绝招对敌！\n");

        if( me->query_temp("weapon") )
                return notify_fail("你必须空手才能使用「蛤蟆功」！\n");

        if ( me->query_skill_mapped("strike") != "hamashengong")
                return notify_fail("你必须先将蛤蟆功运用于掌法之中才行。\n");

        if( (int)me->query("neili") < 2000 )
                return notify_fail("你现在内力不足，使不出蛤蟆功的绝招！\n");     

        if( (int)me->query("neili") < 400 )
                return notify_fail("你现在内力不足，使不出蛤蟆功的绝招！\n");     

        if( (int)me->query_skill("strike", 1) < 100 )
                return notify_fail("你的掌法不够娴熟，使不出蛤蟆功的绝招！\n");

        if( me->query_temp("hmg_hama") )
                return notify_fail("你刚使完「蛤蟆功」绝招，目前气血翻涌，无法再次运用！\n");
        
        msg = BLU "\n$N身子蹲下，左掌平推而出，使的正是$N生平最得意的「蛤蟆功」绝招，掌风直逼$n而去！\n"NOR;        
        me->set_temp("hmg_hama", 1);
        
        if (random(me->query_skill("force")) > target->query_skill("force") /4 ){                     
                me->start_busy(1);
                target->start_busy(1); 
                me->add("neili", -200);
                me->add("jing", -10);
                damage = (int)me->query_skill("hamashengong", 1);                
                damage = damage*2 + random(damage);
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage/2, me);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                call_out("perform2", 0, me, target, p);    
                } 
        else {
                me->start_busy(2);
                target->start_busy(1);
                me->add("neili", -100);
                tell_object(target, HIY"你但觉一股微风扑面而来，风势虽然不劲，然已逼得自己呼吸不畅，知道不妙，连忙跃开数尺。\n" NOR);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
                call_out("remove_effect", me->query_con()/6, me);
        }
        message_vision(msg, me, target); 
        return 1;
}

int perform2(object me, object target, int p)
{
        int damage;
        string msg, dodge_skill;

        if(!living(target)) 
          return notify_fail("对手已经不能再战斗了。\n");

        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("你待要再发一掌，却发现自己的内力不够了！\n");     

        msg = BLU "\n$N左掌劲力未消，右掌也跟着推出，功力相叠，「蛤蟆功」掌风排山倒海般涌向$n！\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 4 &&
            me->query_skill("hamagong", 1) > 150 ){                
                me->start_busy(1);
                target->start_busy(1);
                me->add("neili", -200);
                me->add("jing", -20);                
                damage = (int)me->query_skill("hamashengong", 1);                
                damage = damage*3 + random(damage)*2;
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage/2, me);
                p = (int)target->query("qi")*100/(int)target->query("eff_qi");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";                
                call_out("perform3", 0, me, target, p);  
        } 
        else 
        {
                me->start_busy(2);
                me->add("neili", -200);
                tell_object(target, HIY"你喘息未定，又觉一股劲风扑面而来，连忙跃开数尺，狼狈地避开。\n" NOR);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
                call_out("remove_effect", me->query_con()/4, me);
        }
        message_vision(msg, me, target); 
        return 1;
}

int perform3(object me, object target, int p)
{
        int damage;
        string msg, dodge_skill;
  
        if(!living(target))
              return notify_fail("对手已经不能再战斗了。\n");

        if( (int)me->query("neili", 1) < 700 )
                return notify_fail("你待要再发一掌，却发现自己的内力不够了！\n");     

        msg = BLU "\n$N双腿一登，双掌相并向前猛力推出，$n连同身前方圆三丈全在「蛤蟆功」劲力笼罩之下！\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 4 &&
            me->query_skill("hamashengong", 1) > 199 )
        {
                me->start_busy(2);
                target->start_busy(random(3));
                me->add("neili", -300);
                me->add("jing", -30);                
                damage = (int)me->query_skill("hamashengong", 1);                
                damage = damage*5 + random(damage)*2;
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage/2, me);
                p = (int)target->query("qi")*100/(int)target->query("eff_qi");
                msg += damage_msg(damage, "瘀伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";     
        } else 
        {
                me->start_busy(4);
                target->start_busy(1);
                me->add("neili", -300);
                target->add("jing", -100);
                tell_object(target, HIY"你用尽全身力量向右一纵一滚，摇摇欲倒地站了起来，但总算躲开了这致命的一击！\n" NOR);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        }
        call_out("remove_effect", me->query_con()/2, me);
        message_vision(msg, me, target); 
        return 1;
}

void remove_effect(object me)
{
        if (!me) return;
        me->delete_temp("hmg_hama");
        tell_object(me, HIC"\n你经过一段时间调气养息，又可以使用「蛤蟆功」绝招了。\n"NOR); 
}


