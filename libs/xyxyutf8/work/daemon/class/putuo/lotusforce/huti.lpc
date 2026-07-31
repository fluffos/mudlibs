#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me, int combat_def,int spells_def,int re_spells_damage,int re_combat_damage,int re_spells_effdamage,int re_combat_effdamage);

int valid_exert(object me)
{
	if(me->query("family/family_name")!="南海普陀山")
        	return notify_fail("你不是佛门弟子，用不了佛门心法！\n");
        if( me->query_level()<6 )
        	return notify_fail("你的人物等级不够。\n");
	if( me->query_skill("lotusforce",1)<50 )	
		return notify_fail("你的莲台心法等级不够。\n");
	if( (int)me->query("force") < 500 )     
        	return notify_fail("你的内力不够。\n");
	return 1;
}

int exert(object me, object target)
{
	int combat_def,spells_def,re_spells_damage,re_combat_damage,re_spells_effdamage,re_combat_effdamage;
	int time,skill,cost;

	if( !valid_exert(me) )
		return 0;
	if( !target ) target = me;	
	skill = me->query_skill("lotusforce",1);
        if( target!= me ) 
        {	
        	if( me->query_level()<40 )
	       		return notify_fail("你只能用佛光护体来保护自己。\n");
        	else
        	{
        		if( me->is_fighting(target) || target->is_fighting(me) 
        	 	|| !living(target) )
        			return notify_fail("有这个必要吗？\n");
			if( (int)target->query_temp("powerup") ) 
        			return notify_fail("对方有其他增益，你暂时不能对其使用「佛光护体」。\n");
        	}
        }
        else	target = me;
	if( (int)me->query_temp("powerup") ) 
        	return notify_fail("你已经在运功中了。\n");
	
	message_vision(HIY"$N"HIY"念着佛号，一阵佛光从头而降，笼罩住了$n"HIY"。\n" NOR,me,target);
	target->set_temp("powerup", 1);
	time = skill*2;
	if( time>900 )
		time = 900;
	cost = 30;	
	combat_def = spells_def = re_spells_damage = re_combat_damage = re_spells_effdamage = re_combat_effdamage = 0;
	if( me->query_level()>=6 )
	{
		combat_def+= skill/3;
		spells_def+= skill/3;
		cost+= 20;
	}
	if( me->query_level()>=40 && skill>=350 )
	{
		re_spells_damage+= skill/50;
		re_combat_damage+= skill/50;
		cost+= 20;
	}
	if( me->query_level()>=60 && skill>=500 )
	{
		re_spells_damage+= skill/100;
		re_combat_damage+= skill/100;
		cost+= 20;
	}	
	me->add("force",-cost);
	
	target->add_temp("apply/combat_def",combat_def);
	target->add_temp("apply/spells_def",spells_def);
	target->add_temp("apply/re_spells_damage",re_spells_damage);
	target->add_temp("apply/re_combat_damage",re_combat_damage);	
	target->add_temp("apply/re_spells_effdamage",re_spells_effdamage);	
	target->add_temp("apply/re_combat_effdamage",re_combat_effdamage);	

	target->start_call_out( (: call_other, __FILE__, "remove_effect", me, combat_def,spells_def,re_spells_damage,re_combat_damage,re_spells_effdamage,re_combat_effdamage :), time);
	return 1;
}

void remove_effect(object target, int combat_def,int spells_def,int re_spells_damage,int re_combat_damage,int re_spells_effdamage,int re_combat_effdamage)
{
	if ( target )
        {       
		target->add_temp("apply/combat_def",-combat_def);
		target->add_temp("apply/spells_def",-spells_def);
		target->add_temp("apply/re_spells_damage",-re_spells_damage);
		target->add_temp("apply/re_combat_damage",-re_combat_damage);	
		target->add_temp("apply/re_spells_effdamage",-re_spells_effdamage);	
		target->add_temp("apply/re_combat_effdamage",-re_combat_effdamage);	
        	target->delete_temp("powerup");
        	tell_object(target, HIY"你的护体佛光渐渐淡了下去。\n"NOR);
        }
}

int help(object me)
{
string str;
if ( !me )      return 0;
str = @LONG
        内功名称：佛光护体
        内功所属：莲台心法
        内功效果：一定时间内提升对象的物理与法术防御
        	  人物等级小于40级，则只能对自身使用
        	  人物等级到达40级，莲台心法达到350级，追加提升自身伤害反弹系数的效果，内力消耗增加20点
        	  人物等级到达60级，莲台心法达到500级，追加提升自身损失反弹系数的效果，内力消耗增加20点
                  不能与其他增益类状态叠加
        内功条件：
                  普陀弟子
                  人物等级6级
                  莲台心法50级
                  内力500点，消耗50点
LONG;
me->start_more(str);
return 1;
}

