// 喧哗流拳法.三重劲sanchong

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
                return notify_fail("三重劲只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("xuanhualiu-quanfa", 1) < 200 )
                return notify_fail("你的喧哗流拳法还不够熟练，不能使用三重劲！\n");

        if( me->query_temp("weapon") )
                return notify_fail("你必须空手才能使用「三重劲」！\n");

        if ( me->query_skill_mapped("unarmed") != "xuanhualiu-quanfa")
                return notify_fail("你必须先将喧哗流拳法运用于招架之中才行。\n");

	if ((int)me->query_skill("shayi-xinfa", 1) < 100)
		return notify_fail("你的本门内功火候不够。\n");

        if( (int)me->query("neili") < 2000 )
                return notify_fail("你现在内力不足，使不出蛤蟆功的绝招！\n");     

        if( (int)me->query("neili") < 400 )
                return notify_fail("你现在内力不足，使不出蛤蟆功的绝招！\n");     

        if( (int)me->query_skill("cuff", 1) < 170 )
                return notify_fail("你的拳法不够娴熟，使不出蛤蟆功的绝招！\n");

        if( me->query_temp("sc_hama") )
                return notify_fail("你刚使完「三重劲」绝招，目前气血翻涌，无法再次运用！\n");

    if ((int)me->query_skill("shayi-xinfa", 1) < 80)
   return notify_fail("你的杀意心法火候不够。\n");
        
        msg = HIW "\n$N突然全身骨骼作响打出一拳，脸上一阵红色，全身好象有使不完的力量一样！\n   一拳打出，拳风直逼$n而去！\n"NOR;        
        me->set_temp("sc_hama", 1);
        
        if (random(me->query_skill("force")) > target->query_skill("force") /3
         || random(me->query("combat_exp")) > target->query("combat_exp")/2){                     
                me->start_busy(1);
                target->start_busy(1); 
                me->add("neili", -200);
                me->add("jing", -10);
                damage = (int)me->query_skill("xuanhualiu-quanfa", 1);                
                damage = damage*2 + random(damage);
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                call_out("perform2", 0, me, target, p);    
                } 
        else {
                me->start_busy(2);
                target->start_busy(1);
                me->add("neili", -100);
                tell_object(target, HIG"你但觉一股强大至极的力道扑面而来，你知道不妙，连忙跃开数尺。\n" NOR);
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

        if (!me)
{
 return notify_fail("你已经断线了。\n");
}

        if (!target)
{
        me->delete_temp("sc_hama");
         return notify_fail("敌人已经不在了。\n");
}

        if(!living(target)) 
          return notify_fail("对手已经不能再战斗了。\n");

        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("你待要再发一拳，却发现自己的内力不够了！\n");     

        msg = RED "\n「二重劲!」$N左拳劲力未消，右拳也跟着打出。\n   在$n没有产生抵抗力时给予第二击,拳风排山倒海般涌向$n！\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 3 &&
            me->query_skill("shayi-xinfa", 1) > 199 ){                
                me->start_busy(1);
                target->start_busy(1);
                me->add("neili", -200);
                me->add("jing", -20);                
                damage = (int)me->query_skill("xuanhualiu-quanfa", 1);                
                damage = damage*3 + random(damage)*2;
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                p = (int)target->query("qi")*100/(int)target->query("eff_qi");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";                
                call_out("perform3", 0, me, target, p);  
        } 
        else 
        {
                me->start_busy(1);
                me->add("neili", -200);
                tell_object(target, HIG"你喘息未定，抵抗力还未产生，只好跃开数尺，狼狈地避开。\n" NOR);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
                call_out("remove_effect", me->query_con()/6, me);
        }
        message_vision(msg, me, target); 
        return 1;
}

int perform3(object me, object target, int p)
{
        int damage;
        string msg, dodge_skill;
  
        if (!me)
{
 return notify_fail("你已经断线了。\n");
}

        if (!target)
{
        me->delete_temp("sc_hama");
         return notify_fail("敌人已经不在了。\n");
}

        if(!living(target))
              return notify_fail("对手已经不能再战斗了。\n");

        if( (int)me->query("neili", 1) < 700 )
                return notify_fail("你待要再发一拳，却发现自己的内力不够了！\n");     

        msg = HIR "\n「三重劲!」$N全身骨骼一阵爆响,拼尽毕生功力使出了喧哗流拳法的终极绝技。\n   $n连同身前方圆三丈全在「三重劲!」劲力笼罩之下！\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 3 &&
            me->query_skill("xuanhualiu-quanfa", 1) > 249 )
        {
                me->start_busy(2);
                target->start_busy(random(3));
                me->add("neili", -300);
                me->add("jing", -30);                
                damage = (int)me->query_skill("xuanhualiu-quanfa", 1);                
                damage = damage*5 + random(damage)*2;
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                target->receive_damage("qi", damage*2);
                target->receive_wound("qi", damage);
                p = (int)target->query("qi")*100/(int)target->query("eff_qi");
                msg += damage_msg(damage, "瘀伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";     
        } else 
        {
                me->start_busy(4);
                target->start_busy(1);
                me->add("neili", -300);
                target->add("jing", -100);
                tell_object(target, HIG"你用尽全身力量向右一纵一滚，摇摇欲倒地站了起来，但总算躲开了这致命的一击！\n" NOR);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        }
        call_out("remove_effect", me->query_con()/6, me);
        message_vision(msg, me, target); 
        return 1;
}

void remove_effect(object me)
{
        if (!me) return;
        me->delete_temp("sc_hama");
        tell_object(me, HIC"\n你经过一段时间调气养息，又可以使用「三重劲」绝招了。\n"NOR); 
}


