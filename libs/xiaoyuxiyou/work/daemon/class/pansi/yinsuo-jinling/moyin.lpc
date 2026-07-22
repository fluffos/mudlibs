#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	string msg,succ_msg;
        int damage;

	if( me->query_level()<15 )
		return notify_fail("你的人物等级不够。\n");	        
	if( me->query("family/family_name")!="盘丝洞"
         && me->query("chushi/chushi_pansidong")!="yes" )
		return notify_fail("你使不出此招。\n");
	if((int)me->query("force") < 500 )
                return notify_fail("你的内力不够！\n");
        if((int)me->query("kee") < 300 )
                return notify_fail("你的气血不足，没法子施用外功！\n");
        if((int)me->query_skill("yinsuo-jinling", 1) < 150)
                return notify_fail("你的银索金铃级别还不够，使用这一招会有困难！\n");
        if(me->query_skill_mapped("whip") != "yinsuo-jinling")
        	return notify_fail("你现在无法使用「万铃魔音」来攻击。\n");
	        	
	if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
		return notify_fail("你要对谁施展这一招「万铃魔音」？\n");
	if( target->is_busy() )
		return notify_fail("对方已经神不守舍，放胆攻击吧。\n");
	
	msg = HIC"\n$N"HIC"运足精神，内力行走了大小周天，突然媚笑一声“"HIR"万铃魔音"NOR+HIC"”！顿时间天昏地暗，电闪雷鸣，地动天摇！\n"NOR;
	succ_msg = HIW"结果$n"HIW"被万铃齐鸣的魔音搅心神不定，七窍五俯震坏了，翻倒在地。\n"NOR;
	me->add("force", -150);
	me->receive_damage("kee",100);
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_CAST,msg,succ_msg);
	me->set_temp("pfm_msg",0);
    	if( damage>0 )
		target->start_busy(3);
	me->start_busy(1);
	return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        外功名称：万铃魔音
        外功所属：银索金玲
        外功效果：
                  用铃声迷惑对方，使之busy 3 秒
                  自身busy 1 秒
        外功条件：
                  盘丝洞(出师)弟子
        	  人物等级15级
                  内力500点，消耗150点
                  气血300点，消耗100点
                  银索金铃150级并激发
STR;
        me->start_more(str);
        return 1;
}