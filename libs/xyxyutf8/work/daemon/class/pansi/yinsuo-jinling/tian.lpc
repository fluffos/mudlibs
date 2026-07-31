#include <ansi.h>
#include <combat.h> 
inherit F_CLEAN_UP;

void remove_effect(object me,int dodge,int parry,int attack,int re_damage)
{
	if( !me || !me->query_temp("powerup") )
		return;
	me->add_temp("apply/defense",-dodge/10);
    	me->add_temp("apply/parry",-parry);
    	me->add_temp("apply/attack",-attack);
    	me->add_temp("apply/re_combat_damage",-re_damage);
    	me->delete_temp("powerup");
    	message_vision(HIW"$N"HIW"收回了周身紧密防守的鞭影。\n"NOR,me);
}    	

int perform(object me,object target)
{
	object weapon;
    	int skill,dodge,attack,parry,re_damage;
    
    	if( me->query_level()<20 )
		return notify_fail("你的人物等级不够。\n");
    	if(!me->is_fighting() )
        	return notify_fail("「天上人间」只能在战斗中使用。\n");
    	if( (int)me->query_skill("jiuyin-xinjing", 1) < 180 )
        	return notify_fail("你的内功等级不够，不能使用「天上人间」。\n");
        if(me->query("family/family_name")!="盘丝洞"
        && me->query("chushi/chushi_pansidong")!="yes")
                  return notify_fail("你不能使用这项技能！\n");
    	if( (int)me->query_skill("yinsuo-jinling", 1) < 200 )
        	return notify_fail("你的银索金铃不够娴熟，不能真正发挥「天上人间」。\n");
    	weapon = me->query_temp("weapon");  
    	if( !weapon 
    	 || ( weapon->query("skill_type") != "whip" 
    	   && weapon->query("use_apply_skill") != "whip" ) )
		return notify_fail("你的鞭子呢？\n");
	if( me->query_skill_mapped("whip") != "yinsuo-jinling" )
		return notify_fail("你现在无法使用「天上人间」来提高防御力。\n");
    	if( (int)me->query("force") < 500 )
        	return notify_fail("你现在内力太弱，不能使用「天上人间」。\n");
    	if( (int)me->query_temp("powerup") ) 
        	return notify_fail("你已经有增益效果在身，无法使用「天上人间」。\n");
    	if(me->query_skill_mapped("force") != "jiuyin-xinjing")
		return notify_fail("你的内功有误，无法使用「天上人间」。\n");

    	message_vision(HIW "$N"HIW"这时一声高喝，脸上"NOR RED"殷红如血"NOR HIW"，衣袍都鼓了起来，手中"+weapon->name()+HIW"急速转动，渐渐收短，守御相当严密。"+weapon->name()+HIW"似有无穷弹力，似真似幻，无论敌人怎么变招抢攻，总是被弹了出去。\n"NOR, me);
	me->start_busy(2);
    	me->add("force", -300);          
    
    	skill = me->query_skill("yinsuo-jinling");
    	dodge = parry = skill;
    	attack = skill/10;
    	re_damage = skill/20;
    	
    	me->add_temp("apply/defense",dodge/10);
    	me->add_temp("apply/parry",parry);
    	me->add_temp("apply/attack",attack);
    	me->add_temp("apply/re_combat_damage",re_damage);
    	me->set_temp("powerup", 1);

    	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, dodge,parry,attack,re_damage:),skill/2);
    	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：天外飞音
        外功所属：银索金玲
        外功效果：一定时间内增加自身的闪避、招架、命中以及物理伤害反弹
		  不能与其他增益类状态叠加
                  自身busy 2 秒
        外功条件：
                  盘丝洞(出师)弟子
        	  人物等级20级
                  内力500点，消耗300点
                  银索金铃200级并激发
                  九阴心经180级并激发
STR;
        me->start_more(str);
        return 1;
}