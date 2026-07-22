#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int cast(object me, object target)
{
	string msg,succ_msg;

	if( me->query_level()<40 )
		return notify_fail("你的人物等级不够。\n");
	if( userp(me) && me->query("family/family_name")!="火云洞")
      		return notify_fail("“三昧真火”只有火云洞门人才可以用！\n");
        if((int)me->query_skill("pingtian-dafa", 1) < 350 )
                return notify_fail("你的平天大法火候不够，哪里喷得出真火！\n");
        if((int)me->query("mana") < 600 )
                return notify_fail("你的法力不够，喷出的真火恐怕没有什么用！\n");
        if((int)me->query("sen") < 300 )
                return notify_fail("你现在神智不清，别把自己烧伤了！\n");
	if( time()<me->query_temp("kusong_sanmei")+8 )
		return notify_fail("你不能频繁喷火。\n");
		                
	if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
		return notify_fail("你要对谁喷三昧真火？\n");

	me->add("mana", -300);
	me->receive_damage("sen", 200);

	if( random(me->query("max_mana")) < 50 ) 
	{
		message_vision(HIM"$N口中念念有词。。。但什么也没有发生！\n"NOR,me);
		return 2;
	}
	me->set_temp("kusong_sanmei",time());
	msg = HIC"$N"HIC"伸手在鼻子上砸了两，顿时鲜血直冒，突然红橙黄三道火焰呼！地一声向$n"HIC"卷去！\n" NOR;
	succ_msg = HIR "结果$n"HIR"被烧得焦头烂额！\n" NOR;
	me->set_temp("pfm_color",HIM);
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_CAST,msg,succ_msg,0,me->query_skill("spells")/3);
	me->set_temp("pfm_color",0);
	return 3;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        法术名称：三昧真火
        法术所属：平天大法
        法术效果：给予对方带固定伤害的法术攻击
                  冷却8秒
        法术条件：
                  火云洞弟子
        	  人物等级40级
                  法力600点，消耗300点
                  精神300点，消耗200点
                  平天大法 350 级
                  
STR;
        me->start_more(str);
        return 1;
}