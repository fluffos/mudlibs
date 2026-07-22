#include <ansi.h>
inherit SSERVER;
inherit F_CLEAN_UP;
 
void remove_effect(object me, int dodge_amount,int attack_amount);

int valid_perform(object me)
{
        if( me->query_level()<30 )
        	return notify_fail("你的人物等级不够。\n");
        if( me->query_skill_mapped("dodge") != "lihuo-dodge" )
		return notify_fail("你还没有施展离火身法呢。\n");
        if(me->query_skill("dodge")<400) 
        	return notify_fail("你身法还不够高明。\n");
        if(me->query_skill("force")<400) 
        	return notify_fail("你的内功修为太差。\n");
	return 1;                
}
 
int perform(object me, object target)
{
        int skill_sword, skill_dodge, dodge_amount,attack_amount;

	if( !target ) 
		target = me;
		
	if( !valid_perform(me) )
		return 0;	

        if( (int)me->query("force") < 50 )      
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") )
                return notify_fail("你已经在运功中了。\n");

        skill_dodge = me->query_skill("dodge");            
        skill_sword = me->query_skill("sword")+me->query_skill("spear")+me->query_skill("blade");
        
        me->add("force", -30);
        message_vision(HIR"$N"HIR"略一提气，只见火花一闪，$N"HIR"背后隐现上古大巫祝融虚影，整个人逐渐幻做一团红雾，满堂滚动。\n" NOR, me);
        attack_amount= skill_sword/2;
        dodge_amount= skill_dodge;
        me->add_temp("apply/attack", attack_amount);  
        me->add_temp("apply/dodge",dodge_amount); 
        me->set_temp("powerup", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, dodge_amount,attack_amount:),120);
	return 1;
}
 
void remove_effect(object me, int dodge_amount,int attack_amount)
{
	if( !me )  return;
        me->add_temp("apply/dodge", -dodge_amount);
        me->add_temp("apply/attack",-attack_amount);
        me->delete_temp("powerup");
        message_vision(HIR"火气渐渐散去，$N"HIR"不得不放慢脚步。\n"NOR,me);
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：火云步
        外功所属：离火身法
        外功效果：2分钟内增强自身的命中率以及闪避率
                  不可叠加
        外功条件：
        	  人物等级30级	
                  内力30点，消耗30点
                  轻功有效等级 400 级
                  内功有效等级 400 级
                  基本轻功激法离火身法
STR;
        me->start_more(str);
        return 1;
}