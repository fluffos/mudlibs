//ji.c 
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
inherit F_CLEAN_UP;

void remove_effect(object me)
{
	if( me )
	{
		me->delete_temp("hyd_jiqiang");
		me->delete_temp("pfm_action");
		me->set_temp("kusong_ji",time());
		message_vision(HIR"$N"HIR"吹了口气，枪上的火焰渐渐熄灭了。\n"NOR,me);	
	}
}

int perform(object me, object target)
{
	object weapon;
	string msg,succ_msg;
	int damage,t;

	if( me->query_level()<15 )
		return notify_fail("你的人物等级不够。\n");
        if( me->query("family/family_name")!="火云洞" )
		return notify_fail("“祭枪”只有火云洞门人才可以用！\n");
	if( me->query("force")<300 )
        	return notify_fail("你的内力不足以祭枪！\n");
	if( me->query("sen") < 200 )
        	return notify_fail("你的精神不足以祭枪！\n");
	if( me->query_skill_mapped("force")!="huomoforce" )
        	return notify_fail("祭枪必须配合火魔心法才能使用。\n");
	if( me->query_skill_mapped("spells")!="pingtian-dafa" )
        	return notify_fail("祭枪必须配合平天大法才能使用。\n");
	if( time()<me->query_temp("kusong_ji")+5 )
		return notify_fail("你刚刚祭过枪。\n");
		        	
	if( me->query_skill("huoyun-qiang",1)<150
	 || me->query_skill("huomoforce",1)<150 
	 || me->query_skill("pingtian-dafa",1)<150 )
		return notify_fail("你有些技能不熟，祭不了枪。\n");
	if( me->query_temp("hyd_jiqiang") )
		return notify_fail("你现在正祭着枪呢。\n");
	weapon=me->query_temp("weapon");
	if( !weapon 
	 || ( weapon->query("skill_type")!="spear" && weapon->query("use_apply_skill")!="spear" ) )
		return notify_fail("你没枪，怎么祭？\n");
	if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
		return notify_fail("你要对谁施展这一招「祭枪」？\n");

	t = me->query_skill("huoyun-qiang",1)/15;
	if( t>120 ) 
		t = 120;		
	message_vision(HIR"只见$N"HIR"向"+weapon->query("name")+HIR"上吐了口鲜血,大喝一声：“祭枪”！\n"NOR,me);
	me->add("force",-150);
	me->receive_damage("sen",100,me);
	me->set_temp("hyd_jiqiang",1);

	message_combatd(HIR"但见"+weapon->name()+HIR"上忽地燃起一团诡异的火焰，焰光招摇之中，仿佛有道长影在黑暗中划过！\n"NOR,me);
	msg = HIR"只见摇熠的火光之中，窜出一道枪影，如毒蛇吐信般朝$n"HIR"$l刺去！\n"NOR;
	if( random(2) )
		succ_msg = HIR"$n"HIR"毫不知情，结果被刺了个正着！\n"NOR;
	else	succ_msg = HIR"$n"HIR"虽然已看到了这一杆焰中炎枪，怎耐$w"HIR"急如闪电，还是给$N"HIR"刺中了$l\n"NOR;
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg);
	me->set_temp("pfm_msg",0);
	if( damage<1 )
		message_combatd(HIC"$n"HIC"虽然毫不知情，但枪到跟前，还是及时的闪开了！\n"NOR,me,target);
	
	me->set_temp("pfm_action", "hyd_fire");
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me:), t);	
	return 1;
}

varargs void fire(object me,object target,object weapon,int damage)
{
	string succ_msg,msg;
	if( !me || !living(me) )
		return;
	if( !weapon || weapon!=me->query_temp("weapon") )
		weapon = me->query_temp("weapon");
	if( !weapon 
    	 || ( weapon->query("skill_type") != "spear" 
    	   && weapon->query("use_apply_skill") != "spear" ) )
	{
		remove_effect(me);
		return;
	}
	if( !target )  target = offensive_target(me);
	if( !target
 	 || !target->is_character()
 	 || target->is_corpse()
 	 || target==me 
 	 || !me->is_fighting(target) 
 	 || !living(me) )
		return; 
	if( random(me->query_int())<20 )
		return;         	
	msg = HIR"\n$w"HIR"上火光一卷，一道残影如毒蛇出洞般刺向$n"HIR"$l！\n"NOR;
	me->set_temp("pfm_msg",1);
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_QUICK,msg,succ_msg);
	me->set_temp("pfm_msg",0);
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：火灵祭枪
        外功所属：火云枪
        外功效果：一定时期内使攻击有加成
                  不支持非枪类型的武器
                  状态结束后冷却5秒
        外功条件：
        	  火云洞弟子
        	  人物等级15级	
        	  内力300点，消耗150点
        	  精神200点，消耗100点
                  火云枪 150 级
                  火魔心法 150 级
                  平天大法 150 级
STR;
        me->start_more(str);
        return 1;
}