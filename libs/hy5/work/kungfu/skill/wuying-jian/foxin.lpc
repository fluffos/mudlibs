// foxing 示佛心
// campsun
//2000.9.17

#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

inherit F_SSERVER;
int perform(object me, object target)
{
  object weapon;
string msg;
int damage,p;        
int extra;
        string dodge_skill;

        if( !target ) target = offensive_target(me);

	if(me->is_busy())
		return notify_fail("你现在没空！！\n");

        if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("只能对战斗中的对手使用。\n");
                
//	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
//		return notify_fail("这个绝技只能空手使用。\n");		
	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

       if( !wizardp(me) &&(int)me->query_skill("wuying-jian", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("yijinjing", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("hunyuan-yiqi", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");

//	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
//		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "yijinjing")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");

//        if( !wizardp(me) && me->query_temp("weapon") )
//              return notify_fail("你必须空手才能使用本门绝学!\n");


        msg = HBWHT "$N贯通少林武学，使出了少林的绝学之精髓！\n" NOR;
message_vision(msg, me, target);               



        msg = HIY "\n$N忽然跃起，左脚一勾一弹，霎时之间踢出一招「如」字诀的穿心腿，直袭$n前胸！\n" NOR;
	            damage = (int)me->query_skill("wuying-jian", 1);
                damage = (int)me->query_skill("yijinjing", 1) +damage;
                damage = damage+350;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage/2,me);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                   
 msg += damage_msg(damage, "内伤");
 msg += "( $n"+eff_status_msg(p)+" )\n";
message_vision(msg, me, target);               
        msg = HIY "\n紧接着$N左腿勾回，将腰身一扭，那右腿的一招「影」字诀便紧随而至，飞向$n！\n" NOR;
//me->add("neili",-100);
damage = (int)me->query_skill("wuying-jian", 1);
                damage = (int)me->query_skill("yijinjing", 1) +damage;
                damage = damage+100;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage/2,me);

        
     msg += damage_msg(damage, "内伤");
 msg += "( $n"+eff_status_msg(p)+" )\n";
message_vision(msg, me, target);                  
        
         if( (int)me->query_skill("yijinjing", 1) >150  ){

        msg = HIY "\n只见$N右脚劲力未消，便凌空一转，左腿顺势扫出一招「随」字诀，如影而至！\n" NOR;
//me->add("neili",-100);
damage = (int)me->query_skill("wuying-jian", 1);
                damage = (int)me->query_skill("yijinjing", 1) +damage;
                damage = damage+200;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage/2,me);

        
     msg += damage_msg(damage, "内伤");
 msg += "( $n"+eff_status_msg(p)+" )\n";
message_vision(msg, me, target);                  

}
if( (int)me->query_skill("yijinjing", 1) >180  ){

        msg = HIY "\n半空中$N脚未后撤，已经运起「形」字诀，内劲直透脚尖，在$n胸腹处连点了数十下！\n" NOR;
//me->add("neili",-100);
damage = (int)me->query_skill("wuying-jian", 1);
                damage = (int)me->query_skill("yijinjing", 1) +damage;
                damage = damage+350;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage/2,me);

        
     msg += damage_msg(damage, "内伤");
 msg += "( $n"+eff_status_msg(p)+" )\n";
message_vision(msg, me, target);                  

}

 if( random((int)me->query_skill("yijinjing", 1)) >180  ){

        msg = RED "\n这时$N双臂展动，带起一股强烈的旋风，双腿霎时齐并，「如影随形」一击重炮轰在$n胸堂之上！\n" NOR;
//me->add("neili",-100);
        target->start_busy(1+random(2));

damage = (int)me->query_skill("wuying-jian", 1);
                damage = (int)me->query_skill("yijinjing", 1) +damage;
                damage = damage+450;
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage/2,me);

        
     msg += damage_msg(damage, "内伤");
 msg += "( $n"+eff_status_msg(p)+" )\n";
message_vision(msg, me, target);                  

 }
extra = me->query_skill("wuying-jian",1) / 10;
if ((int)me->query_skill("yijinjing",1) >250
&&(int)me->query_skill("wuying-jian",1) >250
&& me->query("neili") >500)
{

if (random(3)==0) target->start_busy(3);
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", 2800);
	msg = HIR  "眼看招式要完，突然间$N又施展出［迷踪幻影连环脚］，身形极度旋转，一丛人影中突然向$n飞出一腿！" NOR;
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
//	COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"瘀伤");
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -2800);
	extra *=2;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", 2800);
        msg = HIR  "人影中又飞出一腿！" NOR;
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
//        COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"瘀伤");
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -2800);
        extra *=2;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", 2800);
        msg = HIR  "$N身形渐稳，反身又是一腿！" NOR;
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
//        COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"瘀伤");
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -2800);
//me->add("neili",-350);
}
msg =YEL "\n$N连环飞腿使完，全身一转，稳稳落在地上。\n";
message_vision(msg, me, target);                  
me->start_busy(4);
//me->start_busy(3+random(3));
	if (me->query("hyvip")==4) 
	{me->add("neili",-500);}
	else
	{me->add("neili", -me->query("max_neili")/7);}
        msg = RED "\n$N扔掉手上的武嚣，喃喃说道：放下屠刀，立地成佛，一股强大之极掌风直逼$n而去！\n"NOR;        
//weapon->unequip();
//        weapon->move(environment(me));

//        me->set_temp("sl_wuying", 1);
        
        if (random(me->query_skill("force")) > target->query_skill("force") /3 || random(3)==0){                     
//                me->start_busy(1);
                target->start_busy(2); 
                //me->add("neili", -100);
                me->add("jing", -20);
                damage = (int)me->query_skill("wuying-jian", 1);                
		//damage = (int)me->query_skill("wushen-jian", 1);
		
	target->receive_damage("qi",damage*8,me);
	target->receive_wound("qi",damage*8,me);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                call_out("perform2", 0, me, target, p);    
                } 
        else {
//                me->start_busy(2);
//                target->start_busy(1);
                //me->add("neili", -100);
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

        if(!living(target)) 
          return notify_fail("对手已经不能再战斗了。\n");

        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("你待要再发一掌，却发现自己的内力不够了！\n");     

        msg = HIC "\n$N左掌劲力未消，右掌也跟着推出，功力相叠，「立地成佛」掌风排山倒海般涌向$n！\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 3 &&
            me->query_skill("wuying-jian", 1) > 199 || random(3)==0){                
//                me->start_busy(1);
                target->start_busy(2);
                //me->add("neili", -100);
                //me->add("jing", -30);                
                damage = (int)me->query_skill("wuying-jian", 1);                

		
	target->receive_damage("qi",damage*8,me);
	target->receive_wound("qi",damage*8,me);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";                
                call_out("perform3", 0, me, target, p);  
        } 
        else 
        {
//                me->start_busy(2);
                //me->add("neili", -100);
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
  
        if(!living(target))
              return notify_fail("对手已经不能再战斗了。\n");

        if( (int)me->query("neili", 1) < 700 )
                return notify_fail("你待要再发一掌，却发现自己的内力不够了！\n");     

        msg = HIG "\n$N微微一笑，双掌相并向前推出，看不出有什么力量，但$n连同身前方圆三丈全在「立地成佛」劲力笼罩之下！\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 3 &&
            me->query_skill("wuying-jian", 1) > 249 || random(3)==0)
        {
//                me->start_busy(2);
                target->start_busy(random(5)+2);
                //me->add("neili", -200);
                //me->add("jing", -40);                
                damage = (int)me->query_skill("wuying-jian", 1);                
                damage = damage*5 + random(damage)*2;
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage,me);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "瘀伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";     
        } else 
        {
//                me->start_busy(2);
//                target->start_busy(1);
                //me->add("neili", -200);
                target->add("jing", -100);
                tell_object(target, HIY"你用尽全身力量向右一纵一滚，摇摇欲倒地站了起来，但总算躲开了这致命的一击！\n" NOR);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        }
        message_vision(msg, me, target); 
        return 1;
}

