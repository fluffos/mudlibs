#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int damage;
        object weapon;

	if( me->query_level()<25 )
		return notify_fail("你的人物等级不够。\n");
	if( !target ) target = offensive_target(me);
	if( !target
 	|| !target->is_character()
 	|| target->is_corpse()
 	|| target==me 
 	|| !me->is_fighting(target) ) 
		return notify_fail("你要对谁施展雷霆一击？\n");
		 	
	if(me->query("family/family_name") != "方寸山三星洞" )
        	return notify_fail("你是哪儿偷学来的武功，也想用「雷霆一击」?\n");

        weapon = me->query_temp("weapon");
        if( !weapon
	 || ( weapon->query("skill_type")!="stick"
	   && weapon->query("use_apply_skill")!="stick" ) )
                return notify_fail("你必须在使用兵器时才能使「雷霆一击」！\n");
        if( me->query_skill("qianjun-bang",1) < 250 )
		return notify_fail("你的千钧棒级别不够使用「雷霆一击」。\n");
        if( me->query_skill("stick",1) < 250 )
		return notify_fail("你的棍法底子不够熟练。\n");
	if( me->query("force")<500 )
		return notify_fail("你的内力不足。\n");
		
	msg = HIY"$N"HIY"朝手中$w"HIY"猛吐一口乙木之气，顿时$w"HIY"迎风一挥，幻出万千虚影，带着“噼噼啪啪”的玄雷之声对准$n"HIY"的脑门就砸了下去！\n"NOR;

	damage = me->query_combat_damage();
	damage = damage*9/10+random(damage/10);
	damage = damage*me->query_str()/60;
	damage+= (me->query_skill("stick",1)-(target->query_skill("parry",1)+target->query("dodge",1))/2)/5;
	damage-= me->query_combat_damage()*target->query_combat_def()/(target->query_combat_def()+target->query_level()*50+360);
	damage+= me->query("force_factor")/5+random(me->query("force_factor")/5);
	if( damage<1 )
		damage = 1;					
	if( damage<target->query_maxkee()/100 )
		damage = target->query_maxkee()/100;

	me->add("force",-300);
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,0,"头部",damage);		
        me->start_busy(2);
	return 1;
}

int help(object me)
{
	string str;
	if( !me )      
		return 0;
str = @LONG
        外功名称：雷霆一击
        外功所属：千钧棒
        外功效果：对敌进行进行强力一击，带最少对方最大气血1%的固定伤害
		  自身busy 2 秒
        外功条件：
        	  方寸弟子
        	  人物等级25级
        	  千钧棒法250级
        	  基本棍法250级
 		  内力修为十八年     	  	
                  内力500点，消耗300点
LONG;
	me->start_more(str);
	return 1;
}