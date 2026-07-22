#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg,succ_msg;
        int damage,p;

      	if( me->query_level()<20 )
      		return notify_fail("你的人物等级不够。\n");
        if((int)me->query("force") < 600 )
                return notify_fail("你的内力不足！\n");
 	if((int)me->query_skill("xianfeng-yunti", 1) <200
 	 ||(string)me->query_skill_mapped("force")!="xianfeng-yunti" ) 
          	return notify_fail("你的仙风云体术等级不够，施这招恐怕有困难！\n");
        if((int)me->query_skill("chuanyun-zhang",1) < 200
         ||(string)me->query_skill_mapped("unarmed")!="chuanyun-zhang" ) 
                return notify_fail("你的掌法火候还不到，使用这一招会有困难！\n");
                
	if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
		return notify_fail("你要对谁的施展「云起龙骧」？\n");
	
	p = me->query_skill("unarmed")/5;
	me->add("force",-150);
	msg = "$N呵斥一声，浑身真气运转，挥掌间渐现龙形氤氲之气，暗合两仪，呼啸着直扑$n！\n";
	succ_msg = "$n闪避不及，被劲气贯穿全身，顿时神色有些萎靡。\n"NOR;
	me->set_temp("pfm_color",HIY);
	me->add_temp("apply/attack",p);
	me->set_temp("perform_YQ",1);
	damage = me->query_skill("unarmed")/5;
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg,0,damage,"both");
	me->delete_temp("pfm_color");
	me->delete_temp("perform_YQ");
	me->delete_temp("pfm_msg");
	me->add_temp("apply/attack",-p);
	me->start_busy(2);
        return 1;
}

int help(object me)
{
string str;     
if ( !me )      return 0;
str = @LONG
        外功名称：云起龙骧
        外功所属：穿云掌
        外功效果：对敌进行固定伤害攻击
        	  会伤害对方的精神 	
                  自身busy 2 秒
        外功条件：
        	  人物等级20级	
                  内力600点，消耗150点
                  仙风云体术200级并激发
                  穿云掌200级并激发
LONG;
me->start_more(str);
return 1;
}   
