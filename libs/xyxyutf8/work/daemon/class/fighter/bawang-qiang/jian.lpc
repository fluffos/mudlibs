#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object weapon;
	int damage,p;
	string msg,succ_msg;
	
	if( me->query_level()<10 )
		return notify_fail("你的人物等级不够。\n");
	weapon = me->query_temp("weapon");
	if( !weapon
	 || ( weapon->query("skill_type")!="spear"
	   && weapon->query("use_apply_skill")!="spear" ) )
	   	return notify_fail("你手里没枪。\n");
	if( me->query_skill("wusi-mace")<60
	 && me->query_skill("jinglei-mace")<60 )
	 	return notify_fail("你至少得提高一种锏法。\n");
	if(me->query("family/family_name")!="将军府"  
 	 &&me->query("chushi/chushi_jjf")!="yes")
        	return notify_fail("你不能使用这项技能！\n"); 	
	if( me->query_skill("spear",1)<100
	 || me->query_skill("bawang-qiang",1)<100
	 || me->query_skill_mapped("spear")!= "bawang-qiang" )
		return notify_fail("此乃罗家霸王枪的精髓之技。\n");
	if( me->query_skill_mapped("mace")!= "wusi-mace" 
	 && me->query_skill_mapped("mace")!= "jinglei-mace" )
		return notify_fail("你的锏法只学了点皮毛。\n");
	if( me->query("force")<500 )
		return notify_fail("你内力不足。\n");
      	if( !target ) target = offensive_target(me);
	if( !target
 	|| !target->is_character()
 	|| target->is_corpse()
 	|| target==me
 	|| !me->is_fighting(target) )
 		return notify_fail("你要对谁施展这一招「枪里加锏」？\n");
 	if( time()<me->query_temp("jjf_feijian")+5 )
 		return notify_fail("你刚刚撒过锏。\n");	
	
	me->add_temp("force",-150);
	me->set_temp("jjf_feijian",time());
	msg = HIC"$N"HIC"双手一抖，$w"HIC"抖出三四个枪花，朵朵枪花闪电般扎向$n"HIC"$l！\n"NOR;
	succ_msg = HIR"只听“扑哧”一声，$n"HIR"$l处顿时绽开一朵凄厉的鲜红梅花，鲜血冒出寸许！\n"NOR;
	p = me->query_skill("bawang-qiang",1)/2;
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg,0,p);
	me->set_temp("pfm_msg",0);
	if( damage<1 )
	{
		message_combatd(HIC"结果这一击被$n"HIC"堪堪架住。\n"NOR,me,target);
		msg = HIY"\n$N"HIY"趁$n"HIY"忙于招架，"NOR;
	}
	else	msg = HIY"\n$N"HIY"一招得手，"NOR;
	
	p = (me->query_skill("spear")+me->query_skill("mace"))/5;
	msg+= HIY"顺势倒转枪头，枪作鞭势，一招「枪里加锏」，狠狠砸向$n"HIY"$l！\n"NOR;
	succ_msg = HIR"只听“轰”的一声，$n"HIR"一声惨叫，$l处顿时肿起了老大一块，疼得$p哧哧直咧嘴。\n"NOR,
	weapon = me->query_temp("weapon");
	weapon->set("use_apply_skill","mace");
	me->reset_action();
	me->set_temp("pfm_msg",1);
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg,0,p);
	me->set_temp("pfm_msg",0);
	weapon->delete("use_apply_skill");
	me->reset_action();
	return 1;
}

int help(object me)
{
string str;
if ( !me )      return 0;

str = @LONG
        外功名称：枪里加锏
        外功所属：霸王枪法
        外功效果：以枪法、锏法分别攻击对方
		  冷却时间5秒，不能与「撒手锏」同时使用
        外功条件：
                  将军府(出师)弟子         
                  人物等级10级 
                  内力500点，消耗150点
		  基本枪法60级，并激发霸王枪法
                  霸王枪法60级
                  无私锏法、惊雷锏法任一达60级并激发
LONG;
me->start_more(str);
return 1;
}

