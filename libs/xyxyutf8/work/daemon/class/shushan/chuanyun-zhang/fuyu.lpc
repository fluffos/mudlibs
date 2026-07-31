#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object *enemy;
	int i;
        string msg,succ_msg;
        int damage,p;

      	if( me->query_level()<10 )
      		return notify_fail("你的人物等级不够。\n");
	if(me->query("family/family_name") != "蜀山派" ) 
        	return notify_fail("你是哪儿偷学来的武功！\n");
        if((int)me->query("force") < 200 )
                return notify_fail("你的内力不足！\n");
 	if((int)me->query_skill("xianfeng-yunti", 1) <100
 	 ||(string)me->query_skill_mapped("force")!="xianfeng-yunti" ) 
          	return notify_fail("你的仙风云体术等级不够，施这招恐怕有困难！\n");
        if((int)me->query_skill("chuanyun-zhang",1) < 100
         ||(string)me->query_skill_mapped("unarmed")!="chuanyun-zhang" ) 
                return notify_fail("你的掌法火候还不到，使用这一招会有困难！\n");
                
	me->clean_up_enemy();                
        if( !me->is_fighting() )
        	return notify_fail("「覆雨翻云」只能战斗中使用。\n");
	enemy = me->query_enemy();
	if( !intp(i=sizeof(enemy)) 
	 || i<1 )
		return notify_fail("「覆雨翻云」只能战斗中使用。\n");
	
	msg = HIY"$N"HIY"暗念剑咒，体内真气运转，凌空一指，顿时半空中异象大作，聚起层层密云，指化剑风，如暴雨般倒泻而下！\n"NOR;
	message_vision(msg,me);
	me->add("force",-60);
	p = me->query_skill("unarmed")/10;
	me->add_temp("apply/attack",p);
	me->set_temp("perform_FY",1);
	me->set_temp("pfm_color",HIR);
	me->set_temp("pfm_msg",1);
	while(i--)
	{
		target = enemy[i];
		if( !target || !target->is_character()
         	  || target->is_corpse()
         	  || target==me
         	  || !me->is_fighting(target) )
			continue;
		succ_msg = "$n闪避不及，$l被剑风穿体而过，顿时脸色一白！\n";
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,0,succ_msg,0,500);
	}	
	me->delete_temp("pfm_color");
	me->delete_temp("pfm_msg");
	me->delete_temp("perform_FY");
	me->add_temp("apply/attack",-p);
	me->start_busy(2);
        return 1;
}

int help(object me)
{
string str;     
if ( !me )      return 0;
str = @LONG
        外功名称：覆雨翻云
        外功所属：穿云掌
        外功效果：对当前所有敌人进行攻击
                  自身busy 2 秒
        外功条件：
                  蜀山派弟子
        	  人物等级10级	
                  内力200点，消耗60点
                  仙风云体术100级并激发
                  穿云掌100级并激发
LONG;
me->start_more(str);
return 1;
}   
