#include <ansi.h>
inherit SSERVER;
inherit F_CLEAN_UP;
 
void remove_effect(object me, int p);

int valid_perform(object me)
{
        if( me->query_level()<35 )
        	return notify_fail("你的人物等级不够。\n");
        if( me->query_skill_mapped("dodge") != "lihuo-dodge" )
		return notify_fail("你还没有施展离火身法呢。\n");
        if(me->query_skill("dodge")<450) 
        	return notify_fail("你身法还不够高明。\n");
        if(me->query_skill("force")<450) 
        	return notify_fail("你的内功修为太差。\n");
	return 1;                
}
 
int perform(object me, object target)
{
        int p;

	if( !target ) 
		target = me;
		
	if( !valid_perform(me) )
		return 0;	

        if( (int)me->query("force") <200 )      
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") )
                return notify_fail("你已经在运功中了。\n");

        p = me->query_skill("spells")/150;
        if( p>10 )
        	p = 10;
        
        me->add("force", -100);
        message_vision(HIR"$N"HIR"略一提气，只见火花一闪，$N"HIR"背后隐现一朵虚化红莲，顿时将$N"HIR"紧紧包裹住。\n" NOR, me);
        me->add_temp("apply/re_spells_effdamage",p/2);
        me->add_temp("apply/re_combat_effdamage",p/2);
        me->add_temp("apply/re_spells_damage",p);
        me->add_temp("apply/re_combat_damage",p);
        me->set_temp("powerup", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, p:),120);
	return 1;
}
 
void remove_effect(object me, int p)
{
	if( !me )  return;
        me->add_temp("apply/re_spells_effdamage",-p/2);
        me->add_temp("apply/re_combat_effdamage",-p/2);
        me->add_temp("apply/re_spells_damage",-p);
        me->add_temp("apply/re_combat_damage",-p);
        me->delete_temp("powerup");
        message_vision(HIR"火光一闪，一朵红莲在$N"HIR"背后消失不见了。\n"NOR,me);
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：火莲裹身
        外功所属：离火身法
        外功效果：2分钟内增强自身的攻击反弹比例
                  不可叠加
        外功条件：
        	  人物等级35级	
                  内力200点，消耗100点
                  轻功有效等级 450 级
                  内功有效等级 450 级
                  基本轻功激发离火身法
STR;
        me->start_more(str);
        return 1;
}