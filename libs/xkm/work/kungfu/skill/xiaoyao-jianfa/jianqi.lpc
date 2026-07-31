// jianqi.c

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
void check_fight(object me, object target, int amount);
private int remove_effect(object me, int amount);

string *name1 = ({ "玉堂穴", "大横穴", "幽门穴", "章门穴", "晴明穴", "紫宫穴",                   
		   "风池穴", "太阳穴", "会阴穴", "长强穴", "灵台穴" });

int perform(object me)
{                   
	int damage;        

	object target;        
	object weapon = me->query_temp("weapon");        

	if( !target ) target = offensive_target(me);        
	if( me->is_busy())                
		return notify_fail("你现在正忙着呢。\n"); 
	if( !me->is_fighting() )                
		return notify_fail("「剑气」只能在战斗中使用。\n");

	if( !target || !target->is_character() ||!me->is_fighting(target) )                
		return notify_fail("「剑气」只能在战斗中对对手使用。\n");

	if( target->query("qi") <= 50 && me->is_fighting(target) )                
		return notify_fail("对手已经伤痕累累，你现在没有必要用「剑气」攻击敌人了。\n");        

	if (!weapon || weapon->query("skill_type") != "sword"        
		|| me->query_skill_mapped("sword") != "xiaoyao-jianfa")             
		return notify_fail("你现在无法使用「剑气」攻击敌人。\n");
        
	if(  me->query_temp("jianqi"))                  
		return notify_fail("你现在正在运用「剑气」攻击对手。\n"); 
       
	if( (int)me->query_skill("xiaoyao-jianfa", 1) < 150 ||            
	(int)me->query_skill("sword", 1) < 150 ||            
	(int)me->query_str() < 25   ||            
	(int)me->query_dex() < 30)                  
		return notify_fail("你有的功夫还不够娴熟，不会催动剑气伤敌。\n");         

	if((int)me->query_skill("shenghuo-xuanming", 1) < 100)            
		return notify_fail("你的圣火玄冥功修为不够，无法领悟以剑御气的精髓。\n");        

	if( (int)me->query("max_neili") < 1500 )                
		return notify_fail("你的内力太弱，无法使用出「剑气」！\n");
                
	if( (int)me->query("neili") < 1200 )                
		return notify_fail("你的真气不够！\n");    

        if( (int)me->query("jingli", 1) < 300 )
                return notify_fail("你现在的体力太弱，不够使用「剑气」！\n");

	damage = me->query_skill("force") + me->query_skill("xiaoyao-jianfa",1);
	damage = damage/5;

	if ( damage > 400)
		damage = 400;

		call_out("check_fight", 1, me, target);
                me->add_temp("apply/attack", damage/5);                
		me->add_temp("apply/dodge",  damage/3);                
		me->add_temp("apply/parry",  damage/5);     
		me->add("neili", - ( 100 + me->query_skill("shenghuo-shengong") ) );
		me->add("jingli", -50);
		me->set_temp("jianqi_1", 1); 
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		me->delete_temp("jianqi_1"); 
		me->set_temp("jianqi", 1);                

		if( (int)me->query_skill("xiaoyao-jianfa", 1) > 180                
		&&  (int)me->query("neili") > 1000                
		&&  present(target->query("id"), environment(me))
		&&  me->is_fighting(target)
		&&  living(target)
		&&  living(me)
		&&  me->is_fighting()
		&&  target->is_fighting()
		&&  !target->is_ghost() 
		&&  !me->is_ghost()
		&&  me->query_skill_mapped("sword") == "xiaoyao-jianfa" 
		&&  (string)weapon->query("skill_type") == "sword" )
		{                        
			call_out("perform2", 0, me);
		}
		else
		{                        
//			me->delete_temp("jianqi");
		} 
	return 1;
}

int perform2(object me)
{  
	object target;        
	object weapon = me->query_temp("weapon");              

	if( !target ) target = offensive_target(me);           
     
		me->add("neili", - ( 200 + me->query_skill("shenghuo-shengong") ));
		me->add("jingli", -50);
		me->set_temp("jianqi_2", 1); 
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		me->delete_temp("jianqi_2"); 

		if(  (int)me->query_skill("xiaoyao-jianfa", 1) > 250                
		&& (int)me->query("neili", 1) > 1000                
		&&  present(target->query("id"), environment(me))                 
		&&  me->is_fighting(target)                 
		&&  living(target)                
		&&  living(me)                
		&&  me->is_fighting()                
		&&  target->is_fighting()                
		&&  !target->is_ghost()                
		&&  !me->is_ghost()                
		&&  me->query_skill_mapped("sword") == "xiaoyao-jianfa"                
		&&  (string)weapon->query("skill_type") == "sword")                                
		{
			call_out("perform3", 1, me);
		}                
		else                 
		{                        
//			me->delete_temp("jianqi");                                      
		}        
		return 1;
}                                                       

int perform3(object me)
{              
	object weapon = me->query_temp("weapon");        
	object target;        
       
	if( !target ) target = offensive_target(me);        
           
		me->add("neili", - ( 300 + me->query_skill("shenghuo-shengong") ));
		me->add("jingli", -50);
		me->set_temp("jianqi_3", 1); 
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		me->delete_temp("jianqi_3"); 
		target->start_busy(1);                
		me->start_busy(4);                
		return 1;
}

void check_fight(object me, object target, int amount) 
{         
	object weapon;     

	if( !living(me) || me->is_ghost() )
	{
		remove_effect(me, amount);    
		return ;
	}
	if( !me->is_fighting() )
	{
		remove_effect(me, amount);    
		message_vision("\n$N见战局已毕，便即收起了施展剑气的内力。\n", me);
	}
	else if( !objectp(weapon = me->query_temp("weapon"))         
	|| me->query_skill_mapped("sword") != "xiaoyao-jianfa"     
	|| me->query_skill_mapped("force") != "shenghuo-xuanming"   
	|| (string)weapon->query("skill_type") != "sword" )         
	{
		remove_effect(me, amount);    
		message_vision(HIY"\n$n中途改换了使剑的套路，剑气弥失，$N攻守自如多了。\n"NOR, target,me);      
		return ;
	}
		else call_out("check_fight", 1, me, target, amount);         
		return; 
}

private int remove_effect(object me, int amount)
{
	amount = me->query_skill("force") + me->query_skill("xiaoyao-jianfa",1);
	amount = amount/5;

	if ( amount > 400)
		amount = 400;

	me->add_temp("apply/attack", -amount/5);      
	me->add_temp("apply/dodge",  -amount/3);      
	me->add_temp("apply/parry",  -amount/5);        
	me->delete_temp("jianqi");                          
	me->delete_temp("jianqi_1");             
	me->delete_temp("jianqi_2");                               
	me->delete_temp("jianqi_3");                                                            
}