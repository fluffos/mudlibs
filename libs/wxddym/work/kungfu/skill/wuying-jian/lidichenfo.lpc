// hama.c 少林无影剑

#include <ansi.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
        int damage, p;
        string msg, dodge_skill;
        object weapon;
        if( !target ) target = offensive_target(me);
        
        if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("立地成佛只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("wuying-jian", 1) < 100 )
                return notify_fail("你的少林无影剑还不够熟练，不能使用立地成佛对敌！\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"装备剑才能使用「立地成佛」!\n"NOR);

//        if (me->query_skill_mapped("force") != "yijinjing")
//                return notify_fail("你的内功中无易筋经。\n");

	if( (int)me->query_skill("yijinjing", 1) < 150 )
		return notify_fail("你的易筋经不够娴熟。\n");

        if( (int)me->query("max_neili") < 1500 )
                return notify_fail("你现在内力不足，使不出少林无影剑的绝招！\n");     

        if( (int)me->query("neili") < 400 )
                return notify_fail("你现在内力不足，使不出少林无影剑的绝招！\n");     

        if( (int)me->query_skill("force", 1) < 150 )
                return notify_fail("你的内力不够娴熟，使不出少林无影剑的绝招！\n");

        if (me->query_str() < 28 )
                return notify_fail("你的力量太小，使不出用立地成佛！\n");

        if( me->query_temp("sl_wuying") )
                return notify_fail("你刚使完「少林无影剑」绝招，目前气血翻涌，无法再次运用！\n");
        
        msg = RED "\n$N扔掉手上的武嚣，喃喃说道：放下屠刀，立地成佛，一股强大之极掌风直逼$n而去！\n"NOR;        
weapon->unequip();
//        weapon->move(environment(me));

        
        if (random(me->query_skill("force")) > target->query_skill("force") /4 ){                     
                me->start_busy(1);
                target->start_busy(2); 
                me->add("neili", -200);
                me->add("jing", -20);
                damage = (int)me->query_skill("wuying-jian", 1);                
                damage = damage*2 + random(damage);
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                call_out("perform2", 0, me, target, p);    
                } 
        else {
                me->start_busy(2);
//                target->start_busy(1);
                me->add("neili", -100);
                tell_object(target, HIY"你但觉一股微风扑面而来，风势虽然不劲，然已逼得自己呼吸不畅，知道不妙，连忙跃开数尺。\n" NOR);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        }
        message_vision(msg, me, target); 
        return 1;
}

int perform2(object me, object target, int p)
{
        int damage;
        string msg, dodge_skill;

if (!target)
{
        me->delete_temp("sl_wuying");
          return notify_fail("对手已经不能再战斗了。\n");
}
        if(!living(target)) 
{
        me->delete_temp("sl_wuying");
          return notify_fail("对手已经不能再战斗了。\n");
}
        if( (int)me->query("neili", 1) < 500 )
{
        me->delete_temp("sl_wuying");
                return notify_fail("你待要再发一掌，却发现自己的内力不够了！\n");     
}
        msg = HIC "\n$N左掌劲力未消，右掌也跟着推出，功力相叠，「立地成佛」掌风排山倒海般涌向$n！\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 3 &&
            me->query_skill("wuying-jian", 1) > 199 ){                
                me->start_busy(1);
                target->start_busy(2);
                me->add("neili", -300);
                me->add("jing", -30);                
                damage = (int)me->query_skill("wuying-jian", 1);                
                damage = damage*3 + random(damage)*2;
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
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
        }
        message_vision(msg, me, target); 
        return 1;
}

int perform3(object me, object target, int p)
{
        int damage;
        string msg, dodge_skill;
if (!target)
{
        me->delete_temp("sl_wuying");
          return notify_fail("对手已经不能再战斗了。\n");
}  
        if(!living(target))
{
        me->delete_temp("sl_wuying");
              return notify_fail("对手已经不能再战斗了。\n");
}
        if( (int)me->query("neili", 1) < 700 )
{
        me->delete_temp("sl_wuying");
                return notify_fail("你待要再发一掌，却发现自己的内力不够了！\n");     
}
        msg = HIG "\n$N微微一笑，双掌相并向前推出，看不出有什么力量，但$n连同身前方圆三丈全在「立地成佛」劲力笼罩之下！\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 3 &&
            me->query_skill("wuying-jian", 1) > 249 )
        {
                me->start_busy(2);
                target->start_busy(random(3));
                me->add("neili", -400);
                me->add("jing", -40);                
                damage = (int)me->query_skill("wuying-jian", 1);                
                damage = damage*5 + random(damage)*2;
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "瘀伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";     
        } else 
        {
                me->start_busy(2);
//                target->start_busy(1);
                me->add("neili", -300);
                target->add("jing", -100);
                tell_object(target, HIY"你用尽全身力量向右一纵一滚，摇摇欲倒地站了起来，但总算躲开了这致命的一击！\n" NOR);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        }

        message_vision(msg, me, target); 
        return 1;
}

