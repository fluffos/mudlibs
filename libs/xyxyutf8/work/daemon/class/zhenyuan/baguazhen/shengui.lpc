// 神机鬼藏 shengui.c
#include <ansi.h>
inherit SSERVER;
inherit F_CLEAN_UP;
 
void remove_effect(object me, int dodge_amount);

int valid_perform(object me)
{
        if( me->query_level()<8 )
        	return notify_fail("你的人物等级不够。\n");
        if( me->query_skill_mapped("dodge") != "baguazhen" )
		return notify_fail("你还没有施展八卦阵法呢。\n");
	if( me->query("family/family_name")!="五庄观"
         && me->query("chushi/chushi_wzg")!="yes" )
		return notify_fail("你不能使用这项技能！\n");
        if(me->query_skill("dodge")<90) 
        	return notify_fail("你八卦阵法还不够高明。\n");
        if(me->query_skill_mapped("force")!="zhenyuan-force")
                return notify_fail("神机鬼藏必须配合镇元神功才能使用。\n");
        if(me->query_skill("force")<90) 
        	return notify_fail("你的内功不够纯熟。\n");
	return 1;                
}
 
int perform(object me, object target)
{
	string *msgs;
        int dodge_amount;

	if( !target ) 
		target = me;
		
	if( !valid_perform(me) )
		return 0;	

        if( (int)me->query("force") < 50 )      
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") )
                return notify_fail("你已经在运功中了。\n");

	msgs = ({
		"开","休","生","死","惊","伤","杜","景",
	});	

        me->add("force", -30);
        message_vision(HIC"$N"HIC"略一提气，脚踏八卦，步行八门。只见$N"HIC"踏"+msgs[random(sizeof(msgs))]+"门，过"+msgs[random(sizeof(msgs))]+"门，越走越快，逐渐幻做千万幻影，乱人心神。\n" NOR, me);
        dodge_amount= me->query_skill("baguazhen",1);
        me->add_temp("apply/dodge",dodge_amount);  //trade offense for defense.  
        me->set_temp("powerup", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, dodge_amount:), me->query_skill("dodge"));
	return 1;
}
 
void remove_effect(object me, int dodge_amount)
{
	if( !me )  return;
        me->add_temp("apply/dodge", -dodge_amount);
        me->delete_temp("powerup");
        message_vision(HIC"$N"HIC"撤去了八卦阵。\n"NOR,me);
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：神机鬼藏
        外功所属：八卦阵法
        外功效果：一定时间内大幅度增强自身的闪避率
                  不可叠加
        外功条件：
        	  五庄观(出师)弟子
        	  人物等级8级	
        	  内功激发镇元神功
                  内力30点，消耗30点
                  轻功有效等级 90 级
                  内功有效等级 90 级
STR;
        me->start_more(str);
        return 1;
}