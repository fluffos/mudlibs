// 莲步轻舞 wu.c
// Last updated By 凌惊雪 9-15-2002
#include <ansi.h>
inherit SSERVER;
inherit F_CLEAN_UP;
 
void remove_effect(object me, int dodge_amount,int attack_amount);

int valid_perform(object me)
{
        if( me->query_level()<8 )
        	return notify_fail("你的人物等级不够。\n");
        if( me->query_skill_mapped("dodge") != "moondance" )
		return notify_fail("你还没有施展冷月凝香舞呢。\n");
	if( me->query("family/family_name")!="月宫"
         && me->query("chushi/chushi_moon")!="yes" )
		return notify_fail("你不能使用这项技能！\n");
        if(me->query_skill("dodge")<100) 
        	return notify_fail("你舞技还不够高明。\n");
        if(me->query_skill_mapped("force")!="moonforce")
                return notify_fail("莲步轻舞必须配合圆月心法才能使用。\n");
        if(me->query_skill("force")<100) 
        	return notify_fail("你的圆月心法不够纯熟。\n");
        if(me->query_skill("sword")<100) 
		return notify_fail("你的剑术太差劲了。\n"); 
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
        skill_sword=me->query_skill("sword");
        
        me->add("force", -30);
        message_vision(HIW"$N"HIW"略一提气，运起轻功，拔剑起舞。只见$N足不沾地，手中剑越舞越快，逐渐幻做一团白雾，满堂滚动。\n" NOR, me);
        attack_amount= me->query_skill("moonforce",1)/20;
        dodge_amount= me->query_skill("moondance",1)/10;
        me->add_temp("apply/attack", attack_amount);  
        me->add_temp("apply/dodge",dodge_amount);  //trade offense for defense.  
        me->set_temp("powerup", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, dodge_amount,attack_amount:), skill_dodge/3);
	return 1;
}
 
void remove_effect(object me, int dodge_amount,int attack_amount)
{
	if( !me )  return;
        me->add_temp("apply/dodge", -dodge_amount);
        me->add_temp("apply/attack",-attack_amount);
        me->delete_temp("powerup");
        message_vision(HIW"$N"HIW"渐感气力不支，不得不放慢脚步，放缓剑招。\n"NOR,me);
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：莲步轻舞
        外功所属：冷月凝香舞
        外功效果：一定时间内增强自身的命中率以及闪避率
                  不可叠加
        外功条件：
        	  月宫(出师)弟子
        	  人物等级8级	
        	  内功激发圆月心法
                  内力30点，消耗30点
                  轻功有效等级 100 级
                  剑法有效等级 100 级
                  内功有效等级 100 级
STR;
        me->start_more(str);
        return 1;
}