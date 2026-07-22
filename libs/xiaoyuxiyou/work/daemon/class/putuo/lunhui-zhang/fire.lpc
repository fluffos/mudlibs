#include <ansi.h>
#include <combat.h>
inherit SSERVER;

void remove_eff(object);

int valid_perform(object me)
{
	if( me->query_level()<25 )
		return notify_fail("你的人物等级不够。\n");
	if( (int)me->query("bellicosity")>300 )
    		return notify_fail("你的杀气太重，无法施展佛门绝技。\n");
	if( (string)me->query("family/family_name")!= "南海普陀山" ) 
        	return notify_fail(HIR"你非佛门弟子！\n"NOR); 
	if( me->query_skill("lotusforce",1)<250 
 	 || me->query_skill("force",1)<250 )
        	return notify_fail("你的内功底子不足，无法运杖如风，施展不出"HIR"无妄之火"NOR"。\n");
	if((string)me->query_skill_mapped("force")!="lotusforce")
        	return notify_fail("佛门三渡必须以莲台心法为底子。\n");
	if( me->query_skill("staff",1)<250 
 	 || me->query_skill("lunhui-zhang",1)<250 )
        	return notify_fail("你的杖法底子不足，无法运杖如风，施展不出"HIR"无妄之火"NOR"。\n");
	if( me->query("force")<800 )
	        return notify_fail("你的内力不够了。\n");
	if( me->query_temp("fire_Busy") )
	        return notify_fail(HIR"你兵器上的无妄之火尚未熄灭。\n"NOR);
        if( time()<me->query_temp("putuo_fire")+5 )
        	return notify_fail("你不能频繁使用无妄之火。\n");	
	return 1;
}

int perform(object me,object target)
{
	int damage;
	object m_weapon;
	string msg,succ_msg;

	if( !valid_perform(me) )
		return 0;
	if( !target ) target = offensive_target(me);

	if( !target
   	 || !target->is_character()
   	 || !me->is_fighting(target) )
		return notify_fail(HIR"无妄之火"NOR"只能对战斗中的对手使用。\n");
	m_weapon=me->query_temp("weapon");        

	msg = HIR"$N"HIR"大喝一声，身形爆涨，口中念动不动明王咒，全身渐渐笼罩起一层无妄真火！\n"NOR;
	message_vision(msg,me,target);
	me->add("force",-150);
	me->set_temp("fire_Busy",1);
	me->start_call_out( (: call_other, __FILE__, "remove_eff",me:),me->query_skill("staff"));

	if( wizardp(me) || (me->query_skill("lotusforce",1)>350 && random(me->query_spi())>random(target->query_spi())) )
    	{
    		tell_object(target,HIR"只见红光一卷，你似乎见到"+me->name()+HIR"背后现出一尊不动明王之像，不禁吓的背后飕飕！\n"NOR);
    		if( COMBAT_D->query_message_type(me,target)==0 )
    			message("vision",HIR"但见"+target->name()+HIR"微微一震，面色稍变，似是受了惊吓。\n"NOR,environment(target),target);
		write(HIR"你暗凝心神，捏明王咒一指"+target->name()+HIR"，对方明显受到了惊吓。\n"NOR);
        	damage = me->query_skill("buddhism",1)/10+1;
        	target->receive_wound("sen",damage,me,TYPE_PERFORM);
        	COMBAT_D->report_sen_status(target);
	}

	msg = HIR"但见红光渐渐笼聚在$w"HIR"之上，仿若有生命般在$w"HIR"上跳跃不止。$N"HIR"左手一抽，右手攥住$w"HIR"狠狠向$n"HIR"$l抽去！\n"NOR;
	succ_msg = HIR"$n"HIR"闪避不及，重重挨了一击！\n"NOR;
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg);
	me->set_temp("pfm_msg",0);
	if( damage<1 )
		message_combatd(HIR"$n"HIR"见势不秒，连忙架住$N"HIR"的这一击！\n"NOR,me,target);
		
	msg = HIR"$N"HIR"见招势已老，连忙撤杖换招，倒提$w"HIR"使出一招「"NOR HIM"八方火蜒"NOR HIR"」，杖风暴风骤雨般打向$n"HIR"！\n"NOR;
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,0,0,me->query_skill("staff")/5);
	if( me->query_skill("lunhui-zhang",1)>300 )
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,0,0,0,me->query_skill("staff")/3);
	if( me->query_skill("lunhui-zhang",1)>400 )
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,0,0,0,me->query_skill("staff")/2);
	if( me->query_skill("lunhui-zhang",1)>500 )
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,0,0,0,me->query_skill("staff"));
	if( me->query_skill("lunhui-zhang",1)>800 )
	{
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,0,0,0,me->query_skill("staff"));
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,0,0,0,me->query_skill("staff"));
	}	
	return 1;
}

void remove_eff(object me)
{
	object weapon;
	string name;
	if( !me )
        	return;
	if( !objectp(weapon=me->query_temp("weapon")) )
    		name = "禅杖";
	else	name = weapon->name();

	if( me->query_temp("fire_Busy") )
    	{
    		write(HIR"你缓缓的收回"+name+HIR"上的火焰。\n"NOR);
        	message("vision",HIR+me->name()+HIR"将"+name+"上的"HIB"无妄之火"NOR HIR"缓缓收回。\n"NOR,environment(me),me);
		me->delete_temp("fire_Busy");
		me->set_temp("putuo_fire",time());
	}
}

void fire_attack(object me,object target,object weapon,int damage)
{
	string msg,succ_msg;

	if( !me || !me->query_temp("fire_Busy") )
        	return;
        if( !weapon )
        	weapon = me->query_temp("weapon");
	if( !target )  target = offensive_target(me);
	if( !target
 	 || !target->is_character()
 	 || target->is_corpse()
 	 || target==me 
 	 || !me->is_fighting(target) 
 	 || !living(me) )
		return;         		
	if( weapon )
	{        	
		msg = "\n"HIR"$w"HIR"上冲出一道火焰，带着丝丝的热气直冲$n"HIR"$l！"NOR"\n";
		succ_msg = RED"结果$n"RED"被烧得灰头灰脸，狼狈不堪！"NOR"\n";
		damage = weapon->query("weapon_prop/spells_damage");
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_QUICK,msg,succ_msg,0,damage);
	}
}

int help(object me)
{
string str;
if( !me )      return 0;
str = @LONG
        外功名称：无妄之火
        外功所属：轮回杖法
        外功效果：将明王咒加持在武器之上，对敌人进行攻击
                  使用后冷却5秒
        外功条件：
                  普陀弟子
                  人物等级25  
                  杀气低于300
                  内力800点，消耗150点
                  轮回杖法250级
                  基本杖法250级
                  内功心法250级
                  莲台心法250级
LONG;
me->start_more(str);
return 1;
}