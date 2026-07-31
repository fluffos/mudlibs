//Cracked by Roath
// powerfade.c
#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target)
{
	int skill;

	if( me->query_level()<15 )
		return notify_fail("你的人物等级不够。\n");
	if(me->query("family/family_name")!="阎罗地府") 
        	return notify_fail("你不是地府弟子，不能使用这项技能！\n");
	if( !target ) target = me;        	
	if( target != me ) 
        	return notify_fail("你只能用反五行摄气诀压制自己的杀气。\n");
	if( (int)me->query("force")<300 )     
        	return notify_fail("你的内力不够。\n");
	if( (int)me->query("sen")<200 )     
        	return notify_fail("你的精神不够。\n");
	if( me->query_temp("powerup") ) 
        	return notify_fail("你已经在运功中了。\n");
	if( (int)me->query("bellicosity") <= 0 )
        	return notify_fail("你现在毫无杀气。\n");

	skill = me->query_skill("tonsillit",1);
	me->add("bellicosity", - 50 - skill/3 );
	me->add("force", -100);
	me->receive_damage("sen", 100);		
	if(me->query("bellicosity") <0) 
		me->set("bellicosity",0);

	message_vision(HIC"$N"HIC"盘膝坐下，双眼微闭，运起反五行摄气诀压制心中的杀气。。。\n" NOR, me);
	if( me->is_fighting() )
        	me->start_busy(3);
	return 1;
}

int help(object me)
{
string str;
if ( !me )      return 0;
str = @LONG
        内功名称：反五行摄气诀
        内功所属：摄 气 诀
        内功效果：运用反五行摄气诀降低自身的杀气
                  战斗中使用自身会busy 3 秒
        内功条件：
         	  人物等级15级
         	  地府弟子
                  内力300点，消耗100点
                  精神200点，消耗100点
               
LONG;
me->start_more(str);
return 1;
}

