#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me,int p,int pp)
{
	if( me )
	{
		me->add_temp("apply/re_spells_damage",-p);
		me->add_temp("apply/re_combat_damage",-p);
		me->add_temp("apply/re_spells_effdamage",-p/2);
		me->add_temp("apply/re_combat_effdamage",-p/2);
        	me->delete_temp("powerup");
        	message_vision(HIR"$N"HIR"周身的火焰渐渐熄灭。\n"NOR,me);
	}
}

int exert(object me, object target)
{
        int p,t;
	
	if( me->query_level()<10 )
		return notify_fail("你的人物等级不够。\n");
	if(me->query("family/family_name")!="火云洞")
		return notify_fail("「离体真火」只有火云洞门人才可以用！\n");
	if( me->query_skill("huomoforce",1)<100 )
		return notify_fail("你的火魔心法不够娴熟。\n");	
        if( me->is_fighting() )
                return notify_fail("战斗中不能使用。\n");
        if( (int)me->query("force") < 200 )
                return notify_fail("你的内力不够。\n");
	if( (int)me->query("kee") < 100)
		return notify_fail("你气血不足，难以施展。\n");
	if( me->query_temp("powerup") )
		return notify_fail("你已经被祝福了，不能再施展「离体真火」了。\n");
     
        me->add("force", -100);
        me->receive_damage("kee", 50,me);
	message_vision(HIR "$N"HIR"退后两步，拳头在鼻子上砸了两下，顿时鲜血直冒！忽然从$P口中冲出红橙黄三道火焰，化作道道火圈，围在身体周围。\n"NOR,me);
	p = me->query_skill("huomoforce",1)/30;
	if( p<2 )
		p = 2;
	if( p>50 )
		p = 50;	
	me->add_temp("apply/re_spells_damage",p);
	me->add_temp("apply/re_combat_damage",p);
	me->add_temp("apply/re_spells_effdamage",p/2);
	me->add_temp("apply/re_combat_effdamage",p/2);
	me->set_temp("powerup",1);
	t = me->query_skill("spells")/10;
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, p:), t);
        return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        内功名称：离体真火
        内功所属：火魔心法
        内功效果：一定时间内提高自身的物理、法术伤害反弹
                  战斗中不能使用
                  不能和其他增益类的状态叠加
        内功条件：
                  火云洞弟子 
        	  人物等级 10 级
                  内力200点，消耗100点
                  气血100点，消耗50点
                  火魔心法 100 级
STR;
        me->start_more(str);
        return 1;
}
