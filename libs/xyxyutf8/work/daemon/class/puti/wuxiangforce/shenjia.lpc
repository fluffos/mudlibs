//shenjia.c 神甲诀
#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill,p;

	if( me->query_level()<15 )
		return notify_fail("你的人物等级不够。\n");
	if( !target ) target = me;        
	if(me->query("family/family_name")!="方寸山三星洞" 
        && me->query("chushi/chushi_fangcun")!="yes")
                  return notify_fail("此乃方寸秘技！\n");
        if( target != me ) 
                return notify_fail("你只能用小无相功保护自己。\n");
	if( me->query_skill("wuxiangforce",1)<100 )
		return notify_fail("你的小无相功等级不够。\n");
        if( (int)me->query("force") < 100 )     
                return notify_fail("你的内力不够。\n");
	if( (int)me->query("kee") < 50 )
		return notify_fail("你的气血不足。\n");
	if( (int)me->query("sen") < 50 )
		return notify_fail("你的精神不足。\n");
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force");
        me->add("force", -80);
        me->receive_damage("kee", 30,me);
	me->receive_damage("sen", 30,me);
        message_vision(HIR"$N"HIR"微一凝神，运起小无相功,顿时身上像穿了神甲一般!\n" NOR, me);
	
	p = (skill-100)/5;
	p+= 50;
	
        me->add_temp("apply/combat_def",p);
        me->add_temp("apply/spells_def",p);
        me->set_temp("powerup", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, p :), skill);
        if( me->is_fighting() ) 
        	me->start_busy(3);
        return 1;
}

void remove_effect(object me, int amount)
{
	if( me )
	{
	        me->add_temp("apply/combat_def",-amount);
        	me->add_temp("apply/spells_def",-amount);
        	me->delete_temp("powerup");
        	tell_object(me, "你的小无相功运行一周天完毕，神甲渐渐消去了。\n");
	}
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        内功名称：神甲诀
        内功所属：小无相功 
        内功效果：一定时间内增加自身的物理与法术防御
        	  战斗中使用busy 3 秒
        内功条件：
        	  方寸(出师)弟子
        	  人物等级 15 级
                  内力100点，消耗80点
                  精神50点，消耗30点
                  气血50点，消耗30点
STR;
        me->start_more(str);
        return 1;
}
