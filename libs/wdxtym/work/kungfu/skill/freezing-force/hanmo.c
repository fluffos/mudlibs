// This program is a part of NT MudLIB

#include <ansi.h>
inherit F_CLEAN_UP;
string query_name() { return "寒魔"ZJBR"玄力"; }
int exert(object me, object target)
{
        mapping buff, data;
        string msg;
        int skill;
        int time;

/*         if( !query("yuanshen", me) )
                return notify_fail("你尚未悟道，无法使用寒魔玄力！\n"); */

        if( target != me )
                return notify_fail("你只能用冰蚕寒功来激发寒魔玄力。\n");

        if( (skill = me->query_skill("freezing-force", 1)) < 250 )
                return notify_fail("你的冰蚕寒功修为不够，无法使用寒魔玄力！\n");

        if( me->query_skill("huagong-dafa", 1) < 150 )
                return notify_fail("你的化功大法修为不够，无法使用寒魔玄力！\n");

        if( me->query_skill("poison", 1) < 250 )
                return notify_fail("你对基本毒功的参悟还不够，无法使用寒魔玄力！\n");

        if( me->query_skill("force", 1) < 150 )
                return notify_fail("你对基本内功的修为还不够，无法使用寒魔玄力！\n");

        if( (int)me->query_temp("protectshield") )
                return notify_fail("你已经在运起寒魔玄力了。\n");

        if( me->query("jingli")<2000 )
                return notify_fail("你的真气不够。\n");

        if( me->query("neili")<5000 )
                return notify_fail("你的内力不够。\n");

       
        
        skill = me->query_skill("freezing-force", 1);
        me->addn("neili", -1000);
        me->receive_damage("qi", 0);


	message_combatd(HIB "$N" HIB "神色凝重，深吸一口气，体表瞬间变为靛蓝色，$N" HIB "随之摆出各种奇特的造型舞动着。\n"
                       "随着那些诡异的舞姿，蓝色烟气四起，在空中竟似显现无数异样蚕虫，在$N身周绕行不止，\n"
                       "四周温度骤降，只刹那间功夫，空气似乎都凝结了。\n" NOR, me);
        
        msg = HIB "这瞬间，$N" HIB "如同毒神附体，使人周身颤栗。\n" NOR;

	me->add_temp("apply/unarmed_damage", skill *3);
	me->add_temp("apply/shield_amount", skill * 3);
//	me->add_temp("apply/dodge", skill / 3);
	me->set_temp("protectshield", 1);

	me->start_call_out((: call_other, __FILE__, "remove_effect",
			   me, skill :), skill);

	if (me->is_fighting()) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
	if ((int)me->query_temp("protectshield"))
	{
		me->add_temp("apply/unarmed_damage", -(amount*3));
		me->add_temp("apply/shield_amount", -(amount*3));
	//	me->add_temp("apply/dodge", -amount);
		me->delete_temp("protectshield");
		tell_object(me, "你的寒魔玄力运行完毕，将内力收回丹田。\n");
	}
}