// back.c// Modify by Jingxue for XYCQ 2.11.2004
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        int i,k,t;
        mapping *style;
        
        if( me->query_level()<15 )
        	return notify_fail("你的人物等级不够。\n");
        if((int)me->query("force") < 200 )
		return notify_fail("你内力不足！\n"); 		
	if((int)me->query_skill("dali-bang",1) < 150)
		return notify_fail("你的『大 力 棍』等级不够！\n");
        if((int)me->query_skill("stick",1) < 150)
		return notify_fail("你的『基本棍法』等级不够！\n");
        if((int)me->query_skill("huomoforce",1) < 150)
		return notify_fail("你的『火魔心法』等级不够！\n");
	weapon=me->query_temp("weapon");
	if( !weapon 
	 || ( weapon->query("skill_type")!="stick" && weapon->query("use_apply_skill")!="stick" )
	 || me->query_skill_mapped("stick") != "dali-bang" )
		return notify_fail("你不施展大力棒就没法「魔王回首」。\n");
				
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
                return notify_fail("你要对谁施展这一招「魔王回首」？\n");

	if( me->query_skill("dali-bang",1)<180 )
		i = 2;
	else if( me->query_skill("dali-bang",1)<240 )
		i = 3;
	else if( me->query_skill("dali-bang",1)<300 )
		i = 4;
	else	i = 5;	

	style = ({
		([
                	"action" : HIY"$N"HIY"发出一声厉叫，手中$w"HIY"以一招"HIG"「六丁开山」"HIY"，带着呼呼风声向$n"HIY"的$l砸去！\n"NOR,
                	"dodge"  : -10,
                	"parry"	 : -20,
                	"damage" : 70,
                	"damage_type": "砸伤"                
                ]),
        	([
                	"action" : HIY"$N"HIY"舞动$w"HIY"，使出"HIG"「八方风雨」"HIY"，幻出了无数$w"HIY"向$n"HIY"砸去！\n"NOR,
                	"dodge"  : -15,
                	"parry"  : -10,                
                	"damage" : 80,
                	"damage_type" : "砸伤" 
		]),
        	([
                	"action" : HIY"$N"HIY"舞动$w"HIY"，一式"HIG"「翻江搅海」"HIY"，劈头盖脸的向$n"HIY"的$l砸去！\n"NOR,
                	"dodge"  : -10,
                	"parry"  : -30,
                	"damage" : 90,
                	"damage_type": "砸伤",
		]),
        	([
                	"action" : HIY"$N"HIY"身形一转，一招"HIG"「飞砂走石」"HIY"使出，周围丈内土石乱飞，$w"HIY"狠狠"HIY"已砸向$n"HIY"的$l！\n"NOR,
                	"dodge"  : -30,
                	"parry"  : -30,
                	"damage" : 100,
                	"damage_type": "砸伤"                
		]),
        	([
                	"action" : HIY"$N"HIY"一招"HIG"「混沌初破」"HIY"使出，霹雳间$w"HIY"已砸向$n"HIY"的$l，躲也躲不开了。\n"NOR,
                	"dodge"  : -30,
                	"parry"  : -40,
                	"damage" : 120,
                	"damage_type": "砸伤"
                ]),
        	([
                	"action" : HIG"$N"HIG"仰天长啸，看也不看，一招"HIY"「魔王回首」"HIG"，闪电霹雳般一棒向$n"HIG"当头砸下！\n"NOR,
                	"dodge"  : -50,
                	"parry"  : -60,
                	"damage" : 150,
                	"damage_type" : "砸伤"                
		]),
	});
        message_vision(HIB"$N"HIB"侧走一步，转身仰天咆哮，举棒力劈数招。！\n"NOR,me,target);
        me->add("force", -60);
        t = 2;
        for(k=0;k<i;k++)
        {
        	if( me && living(me) && target && me->is_fighting(target) )
		{
			me->set("actions",style[k]);
			COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM);
        	}
        }
        me->set("actions",style[5]);
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM);
        me->reset_action();		
        me->start_busy(2);
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：魔王回首
        外功所属：大力棒
        外功效果：连续对敌进行攻击
                  至多六击，最少三击
                  随着大力棒等级提高而增加攻击次数
                  自身 busy 2 秒
        外功条件：
        	  火云洞(出师)弟子
        	  人物等级15级	
        	  内力200点，消耗60点
                  大力棒 150 级
                  火魔心法 150 级
STR;
        me->start_more(str);
        return 1;
}