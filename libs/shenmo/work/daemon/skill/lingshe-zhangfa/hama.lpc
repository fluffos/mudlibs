#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int perform(object me, object target)
{
        string msg;
	int extra;
	object weapon,ob;
        int damage, p;
        string dodge_skill;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	extra = me->query_skill("lingshe-zhangfa",1);
        if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
            return notify_fail("你使用的武器不对。\n");

	if(me->is_busy())
		return notify_fail("你现在没空！！\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

       if( !wizardp(me) &&(int)me->query_skill("hamashengong", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("lingshe-zhangfa", 1) < 500 )
		return notify_fail("你的本门外功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("hamagong", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "hamagong")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");


        msg = HBWHT "$N贯通白驼武学，使出了白驼的绝学之精髓！\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);               


	me->add_temp("apply/attack",(extra/3));
	me->add_temp("apply/damage",(extra));
	weapon = me->query_temp("weapon");
if (random(2)==0) target->start_busy(3);
        msg = HIY "$N跳出数丈外，突然一声暴喝：“------ 狂 ----- 风 ----- 扫 ----- 落 ----- 叶 ----- ！！！”" NOR;
	         message_vision(msg, me, target);                
	 msg =  YEL  "$N身形加快，所到之处，狂风四起！" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("hamagong",1)));
	msg =  YEL  "$N突如起来的从狂风中闪出，对着$n胸前就是一杖！" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "$N御杖回身，立于$n身侧，反手一劈！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("hamagong",1)));
        msg = YEL  "$N借力打力，一个纵身，居高临下，当头又是一杖！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "人在半空，$N化虚为掌，化实为杖，朝$n点刺过去！" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("hamagong",1)));
        msg = YEL "$N持杖乱舞，密不透风，使$n渐渐感到透不过气来！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("hamagong",1)));
	 msg = YEL "$N见有机可乘，一杖接着一杖，招招致命！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("hamagong",1)));
	 msg = YEL "$N聚起天地之灵气，手中的"+ weapon->name() +"卷起千层大浪朝$n挥去！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("hamagong",1)));
        me->add_temp("apply/attack",-(extra/3));
	 me->add_temp("apply/damage",-(extra));
if (extra > 250
&&  random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
{
	 msg = RED "蛇毒" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	target->apply_condition("snake_poison",10);
	 msg = RED "蟾蜍毒" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	target->apply_condition("chanchu_poison",10);
	 msg = RED "七修蛇毒" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	target->apply_condition("qx_snake_poison",20);
}

        msg = BLU "\n$N身子蹲下，左掌平推而出，使的正是$N生平最得意的「蛤蟆功」绝招，掌风直逼$n而去！\n"NOR;        
//        me->set_temp("hmg_hama", 1);
        
        if (random(me->query_skill("force")) > target->query_skill("force") /3
         || random(me->query("combat_exp")) > target->query("combat_exp")/3){                     
                target->start_busy(1); 
                me->add("neili", -100);
                me->add("jing", -10);
                damage = (int)me->query_skill("hamashengong", 1);                
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
        me->start_busy(4);

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
        me->delete_temp("hmg_hama");
         return notify_fail("敌人已经不在了。\n");
}

        if(!living(target)) 
          return notify_fail("对手已经不能再战斗了。\n");

        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("你待要再发一掌，却发现自己的内力不够了！\n");     

        msg = BLU "\n$N左掌劲力未消，右掌也跟着推出，功力相叠，「蛤蟆功」掌风排山倒海般涌向$n！\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 3 &&
            me->query_skill("hamagong", 1) > 199 ){                
                target->start_busy(1);
                me->add("neili", -100);
                me->add("jing", -20);                
                damage = (int)me->query_skill("hamashengong", 1);                
                damage = damage*5 + random(damage)*2;
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
  
        if (!me)
{
 return notify_fail("你已经断线了。\n");
}

        if (!target)
{
        me->delete_temp("hmg_hama");
         return notify_fail("敌人已经不在了。\n");
}

        if(!living(target))
              return notify_fail("对手已经不能再战斗了。\n");

        if( (int)me->query("neili", 1) < 700 )
                return notify_fail("你待要再发一掌，却发现自己的内力不够了！\n");     

        msg = BLU "\n$N双腿一登，双掌相并向前猛力推出，$n连同身前方圆三丈全在「蛤蟆功」劲力笼罩之下！\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 3 &&
            me->query_skill("hamashengong", 1) > 249 )
        {

                target->start_busy(random(3));
                me->add("jing", -30);                
                damage = (int)me->query_skill("hamashengong", 1);                
                damage = damage*6 + random(damage)*2;
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
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
        message_vision(msg, me, target); 
        return 1;
}
