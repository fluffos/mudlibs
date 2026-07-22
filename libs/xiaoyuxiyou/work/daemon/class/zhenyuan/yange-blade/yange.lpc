//yange.c 
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
	
	if( me->query_level()<10 )
		return notify_fail("你的人物等级不够。\n");
	if((int)me->query("force") < 500 )
		return notify_fail("你的内力不足！\n");
        if((int)me->query("kee") < 200 )
                return notify_fail("你的气血不足，没法子施用外功！\n");
	if((int)me->query_skill("yange-blade", 1) < 100)
                return notify_fail("你的雁歌刀法级别还不够，使用这一招会有困难！\n");
	if( time()<me->query_temp("wzg_yange")+5 )
		return notify_fail("绝招滥使就不灵了！\n");
     	if( me->query("family/family_name") != "五庄观"
         && me->query("chushi/chushi_wzg")!="yes" )
		return notify_fail("你是哪儿偷学来的武功，也想用「大漠雁歌」?\n");
	weapon = me->query_temp("weapon");
        if( !weapon 
	 || (weapon->query("skill_type")!="blade"
	  && weapon->query("use_apply_skill")!="blade") )
		return notify_fail("你需要驾驭雁歌刀法！\n");
		
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
                return notify_fail("你要对谁施展这一招「大漠雁歌」？\n");

	message_vision(HIR"\n$N大喝一声,只见飞沙走石,大雁南行,「大漠雁歌」一招一气呵成!!!\n"NOR,me,target);
        me->receive_damage("kee", 100,me);
        me->add("force", -100);
        me->set_temp("wzg_yange",time());
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_PERFORM);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_PERFORM); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),TYPE_PERFORM);
	return 1;
}

int help(object me)
{
        string str;     
        if( !me )      
                return 0;
        str = @LONG
        外功名称：大漠雁歌
        外功所属：雁歌刀法
        外功效果：向对方连续攻击三下
                  冷却时间 5 秒
        外功条件：
                  五庄观(出师)弟子
        	  人物等级10级	
                  内力500点,消耗100点
                  气血200点，消耗100点
                  雁歌刀法100级并激发
LONG;
        me->start_more(str);
        return 1;
}
