#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg,succ_msg;
        int damage,p;

      	if( me->query_level()<5 )
      		return notify_fail("你的人物等级不够。\n");
	if(me->query("family/family_name") != "蜀山派" ) 
        	return notify_fail("你是哪儿偷学来的武功！\n");
        if((int)me->query("force") < 100 )
                return notify_fail("你的内力不足！\n");
 	if((int)me->query_skill("xianfeng-yunti", 1) <50
 	 ||(string)me->query_skill_mapped("force")!="xianfeng-yunti" ) 
          	return notify_fail("你的仙风云体术等级不够，施这招恐怕有困难！\n");
        if((int)me->query_skill("chuanyun-zhang",1) < 50
         ||(string)me->query_skill_mapped("unarmed")!="chuanyun-zhang" ) 
                return notify_fail("你的掌法火候还不到，使用这一招会有困难！\n");
                
	if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
		return notify_fail("你要对谁的施展「穿云裂石」？\n");
	if( time()-(int)me->query_temp("shushan_chuanyun")<3 )
		return notify_fail("绝招用多就不灵了！\n");
	
	p = me->query_skill("unarmed")/10;
	me->add("force",-50);
	me->set_temp("shushan_chuanyun",time());
	msg = "$N运转真气，一股澎湃的仙气汹涌而出，顿时掌风大作，气势磅礴！\n";
	succ_msg = "$n脚下一个不稳，踉跄几步，呕出几口鲜血，面色苍白了许多！\n";
	me->set_temp("pfm_color",HIC);
	me->add_temp("apply/attack",p);
	me->set_temp("perform_CY",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg,({"小腹","后心","头部"})[random(3)]);
	me->delete_temp("pfm_color");
	me->delete_temp("perform_CY");
	me->add_temp("apply/attack",-p);
        return 1;
}

int help(object me)
{
string str;     
if ( !me )      return 0;
str = @LONG
        外功名称：穿云裂石
        外功所属：穿云掌
        外功效果：对敌进行要害攻击
                  冷却时间3秒
        外功条件：
                  蜀山派弟子
        	  人物等级5级	
                  内力100点，消耗50点
                  仙风云体术50级并激发
                  穿云掌50级并激发
LONG;
me->start_more(str);
return 1;
}   
