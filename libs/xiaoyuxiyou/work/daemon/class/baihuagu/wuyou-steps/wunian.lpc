// Wunian.c 无念无忧
// Cracked by 凌惊雪 3-3-2003
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int damage,p;
	string msg,succ_msg;
	if( me->query_level()<10 )
		return notify_fail("你的人物等级不够。\n");
	if(me->query("family/family_name") != "百花谷" )
    		return notify_fail("你是哪儿偷学来的武功！\n"); 
	if( time()-(int)me->query_temp("bhg_wunian") < 6 )
    		return notify_fail("绝招用多就不灵了！\n");
	if( (int)me->query_skill("brightjade-force", 1) < 100 )
        	return notify_fail("你的明玉神功不够级别，无法施展这一招。\n");
	if( (int)me->query_skill("wuyou-steps", 1) < 100 )
        	return notify_fail("你的无忧步法不够高，不能施展这一招。\n");
	if( (int)me->query("force", 1) < 600 )
        	return notify_fail("你现在内力不足。\n");
	if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
		return notify_fail("「无念无忧」只能对战斗中的对手使用。\n");   

	p = me->query_skill("dodge")/50;
    	me->set_temp("bhg_wunian",time());  
	me->add("force", -150);    
	msg = HIC"$N"HIC"运起无忧步法，身形恬静轻柔，飘忽不定！$N"HIC"身形突然旋转，回飞，凝神息气，一道劲飞向$n"HIC"。\n"NOR;
	succ_msg = RED"结果$n"RED"被$N"RED"的明玉神功气劲击中，眼前一黑，象一捆稻草一样飞出去好几丈远！\n"NOR;
	me->add_temp("apply/attack",p);
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg,"腹部",300);
	me->add_temp("apply/attack",-p);	
	me->set_temp("pfm_msg",0);
	if( damage<1 )
	{
		message_combatd(CYN"可是$n"CYN"看破了$P的企图，并没有上当。\n"NOR,me,target);
		me->add_temp("bhg_wunian",3);
	}
	return 1;
}

int help(object me)
{
string str;
if ( !me )      return 0;
str = @LONG     
        外功名称：无念无忧
        外功所属：无忧步法
        外功效果：对敌一次要害攻击，固定伤害300点
                  使用完冷却 6 秒
                  不中增加冷却 3 秒
        外功条件：
        	  百花谷弟子
        	  人物等级10级
                  明玉神功100级
                  无忧步法100级
                  内力600点,消耗150点
LONG;
me->start_more(str);
return 1;
}
