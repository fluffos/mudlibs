//by greenwc 2000.11
#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me, int def,int rebuf)
{
	if( !me )
		return;
        me->add_temp("apply/combat_def",-def);
	me->add_temp("apply/spells_def",def);
	me->add_temp("apply/re_combat_damage",-rebuf);
	me->delete_temp("powerup");
	message_vision(HIY"$N"HIY"周身盘旋的金戈剑影渐渐淡去。\n"NOR,me);
}			

int exert(object me, object target)
{
	int i,def,rebuf,skill;
	if( me->query_level()<30 )
		return notify_fail("你的人物等级不够。\n");      
        if(me->query("family/family_name")!="蜀山派")
      		return notify_fail("你不是蜀山弟子，不能使用这项技能！\n");
      	if( me->query_skill("xianfeng-yunti",1)<300 )
      		return notify_fail("你的内功修为太差。\n");	
        if( (int)me->query("force") < 500 )     
                return notify_fail("你的内力不够。\n");
        if( (int)me->query("kee") < 100 )
                return notify_fail("你的气血不足。\n");
        if( (int)me->query("sen") < 100 )
                return notify_fail("你的精神不足。\n");
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("你已有增益型状态，不能使用「真元护体」。\n");
        skill = me->query_skill("force");
        me->add("force", -200);
        me->receive_damage("kee", 50);
        me->receive_damage("sen", 50);
	i = skill/10+1;
	def = skill/3;
	if( def>me->query_spells_def()/2 )
		def = me->query_spells_def()/2;
	rebuf = skill/15;
	message_vision(HIY"$N"HIY"左手掐咒，运起仙风云体术，顿时浑身剑气凌厉，周身隐约有"+chinese_number(i)+HIY"把剑影盘旋！\n" NOR, me);
        me->add_temp("apply/combat_def",def);
	me->add_temp("apply/spells_def",-def);
	me->add_temp("apply/re_combat_damage",rebuf);
	me->set_temp("powerup", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, def,rebuf :), skill);
        if( me->is_fighting() ) 
        	me->start_busy(2);
        return 1;
}

int help(object me)
{
string str;     
if ( !me )      return 0;
str = @LONG
        内功名称：真元护体
        内功所属：仙风云体术
        内功效果：一定时间内牺牲自身的法术防御来增加自身的物理防御
        	  并提高物理伤害反弹系数
                  战斗中使用自身busy 2 秒
        内功条件：
                  蜀山派弟子
        	  人物等级30级	
                  内力500点，消耗200点
                  精神100点，消耗50点
                  气血100点，消耗50点
                  仙风云体术300级
LONG;
me->start_more(str);
return 1;
} 