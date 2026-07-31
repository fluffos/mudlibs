// yujiamu-quan xunlei
// liu 2002
/*
霍都却知师父提醒自己，不可一味坚守，须使“狂风迅雷功”与对方抢功，当下
发声长啸，右扇左袖，鼓起一阵疾风，急向朱子柳□去。
    劲风力道凌厉，旁观众人不由自主的渐渐退后，只听他口中不住有似霹雳般吆喝助威，
料想这“狂风迅雷功”除了兵刃拳脚之外，叱诧雷鸣，也是克敌制胜的一门厉害手段。朱子
柳奋袂低昂，高视阔步，和他斗了个旗鼓相当。
*/

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

void checking(object me);

int perform(object me, object target)
{
	int skill;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("你不在战斗中。\n");

	skill = me->query_skill("yujiamu-quan",1);

	if( me->query_skill_mapped("force") != "longxiang-banruo")
		return notify_fail("你现在运使的内功不对。\n");

        if( me->query_skill("cuff") < 200 )
                return notify_fail("你的拳法修为不够。\n");

        if( me->query_skill("force") < 180 )
                return notify_fail("你的内功修为不够。\n");

	if( me->query("neili") <= skill*4 )
		return notify_fail("你的内力不够！\n");

	if( me->query("jingli") <= skill*2 )
		return notify_fail("你的精力不够！\n");

	if( (int)me->query_temp("xunlei") )
		return notify_fail("你已经发动了狂风迅雷功！\n");

	message_vision(MAG"\n$N当下发声长啸，右拳左袖，鼓起一阵疾风，急向$n拂去！\n劲风力道凌厉，只听$N口中不住有似霹雳般吆喝助威，料想这“狂风迅雷功”除了拳劲之外，叱诧雷鸣，也是克敌制胜的一门厉害手段。\n\n"NOR,me,target);

	me->add_temp("apply/damage", skill/4);
	me->set_temp("xunlei", skill/20);

	me->add("neili", -skill*4);
	me->receive_damage("jingli", skill);

	if ( me->query_skill("cuff") < 200 )
	{ 
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	}
	else if ( me->query_skill("cuff") < 300 )
	{
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	}
	else
	{
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	}

	remove_call_out("checking");
	call_out("checking", 1, me);

	return 1;
}

void checking(object me)
{
	int skill = me->query_skill("cuff");

	if(me->query_skill_mapped("cuff") != "yujiamu-quan" || me->query_skill_mapped("force") != "longxiang-banruo" 
	|| !me->is_fighting()  || me->query_temp("xunlei") <= 0 )
	{
        	message_vision(HIG"\n$N将内劲收归丹田，拳劲也渐渐弱了下来。\n"NOR, me);
        	me->delete_temp("xunlei");
        	me->add("neili", skill*2);
		me->add("jingli",-skill);
		me->set_temp("apply/damage",0);

		return ;

	}

	if( !living(me) || me->is_ghost() )
        {
                me->delete_temp("xunlei");
		me->set_temp("apply/damage",0);

                return ;
        }

	me->add_temp("xunlei",-1);
	call_out("checking", 1, me);

	return;
}
