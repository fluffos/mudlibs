#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg,*n1,*n2,*n3,succ_msg;
      	int dodge,damage;
      	
      	if( me->query_level()<30 )
      		return notify_fail("你的人物等级不够。\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me
        || !me->is_fighting(target) )
                return notify_fail("你要对谁施展这一招「万毒噬体」？\n");
        if( me->query_skill("wudu-shenzhang",1) < 300)
                return notify_fail("你的五毒神掌等级不够, 不能使用「万毒噬体」！\n");
        if( me->query("force") < 500 )
                return notify_fail("你的内力不够，无法运用「"+HIR"万毒噬体"+HIY"」！\n");
   	
    	me->add("force", -150);
	dodge = me->query_skill("unarmed")/50;
	me->add_temp("apply/attack",dodge);
	me->set_temp("pfm_color","HIB");
	n1 = ({
		MAG"$n"MAG"脸色一黑，",MAG"$n"MAG"面上黑气一闪，",
		MAG"$N"MAG"双掌黑气一闪，",MAG"$N"MAG"双掌传来一股腥气，",
	});
    	n2 = ({
    		"$n"MAG"只觉一阵头昏，","$n"MAG"眼前一黑，",
		"$n"MAG"只觉$l一麻，",	
	});
    	n3 = ({
    		"立刻站立不稳，摇摇晃晃。\n"NOR,
    		"「嘿」地一声退了两步。\n"NOR,
    		"$l有如受到一记重击，连退了五六步！\n"NOR,
    		"眼前一黑，身子立刻摇摇欲坠！\n"NOR,
    		"立刻吐出一口黑血，身子象断了线的风筝向後飞去！\n"NOR,
    		"不由大叫：毒毒毒！连忙慌忙后退。\n"NOR,
	});
    	succ_msg = n1[random(sizeof(n1))]+n2[random(sizeof(n2))]+n3[random(sizeof(n3))];			
    	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,0,succ_msg);
    	if( damage>1 )
    		target->apply_condition("wudu",target->query_condition("wudu")+15);	
    	me->delete_temp("pfm_color");
    	me->add_temp("apply/attack",-dodge);
	me->start_busy(3);
    	return 1;
}

int help(object me)
{ 
string str; 
if ( !me )      return 0; 
str = @LONG 
              外功名称：万毒噬体
              外功所属：五毒神掌
              外功效果：攻击对方一次，命中则使对方身中五毒15秒
              	        中毒状态可以连续叠加
              		自身busy 3 秒
              外功条件：
              		人物等级30级
                        五毒神掌300级
                        内力500点，消耗150点
LONG; 
me->start_more(str); 
return 1; 
} 