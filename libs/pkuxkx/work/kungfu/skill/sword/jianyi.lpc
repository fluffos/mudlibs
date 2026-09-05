//剑意 created by Zine 2011.3.19

#include <ansi.h>

void remove_effect(object me, int a_amount, int d_amount);

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage,target_lv;
        string msg=WHT"剑意随心，运转自如，$N"+WHT+"手中剑吞吐不定。\n"+NOR;
        if( !target ) target = offensive_target(me);
        if( !target
	    ||	!target->is_character()
	    ||	!me->is_fighting(target) )
		return notify_fail("剑意只能在战斗中使用！\n");
        if (!objectp(weapon = me->query_temp("weapon"))
            &&(int)me->query("adv_weapon/class/sword/lv") !=12)
            {
                return notify_fail("你手中无剑，也想使用剑意？\n");
            }
        
        if ((string)weapon->query("skill_type") != "sword")
        {
            return notify_fail("你手中无剑，也想使用剑意？\n");
        }

        if( (int)me->query("adv_weapon/class/sword/lv") < 4 )
                return notify_fail("你对剑意的掌握还不够娴熟。\n");

        if( (int)me->query_temp("adv_weapon/sword") ) 
                return notify_fail("你已经在运功中了。\n");
        me->delete_temp("adv_weapon/swordextra");
        message_vision(msg, me);
        if (me->query("adv_weapon/class/sword/lv")==12)
        {
            if (me->query("adv_weapon/class/sword/lv")>target->query("adv_weapon/maxlv"))
            {
                if (!weapon)
                {
                    weapon=new(__DIR__"wujian");
                    weapon->move(me);
                    weapon->equip();
                    message_vision(HIR"$N早已领悟了无招胜有招的境界，天兵实在神威莫测！\n"NOR,me);
                }
            }
        }
        if (me->query("adv_weapon/class/sword/lv")>=4)
        {
            me->set_temp("adv_weapon/class/sword/prac_eff",1); //增加25%练习效率，参悟点及家有效
        }
        if (me->query("adv_weapon/class/sword/lv")>=6)
        {
            i=weapon->query("weapon_prop/damage")/20;
            me->add_temp("apply/damage",i);
            me->add_temp("adv_weapon/swordextra",i);
        }
        if (me->query("adv_weapon/class/sword/lv")>=8)
        {
            me->set_temp("adv_weapon/class/sword/lingwu_eff",1); //增加25%领悟效率
        }
        if (me->query("adv_weapon/class/sword/lv")>=9)
        {
            i=weapon->query("weapon_prop/damage")/10;
            me->add_temp("apply/damage",i);
            me->add_temp("adv_weapon/swordextra",i);
        }
        if (me->query("adv_weapon/class/sword/lv")>=10)
        {
            me->set_temp("adv_weapon/class/sword/prac_eff",2);//增加到30%练习效率，达摩院及参悟点，家有效
        }
        if (me->query("adv_weapon/class/sword/lv")>=11)
        {
            me->set_temp("adv_weapon/class/sword/lingwu_eff",2);//增加到50%领悟效率
        }
        
        me->set_temp("adv_weapon/sword", 1);
        call_out("check_fight",1,me,weapon);
	    me->add("neili", -300);
	    if( me->is_fighting() ) me->start_busy(2);

        return 1;
}

void check_fight(object me, object weapon) 
{ 
	if(!me
	|| !living(me)
	|| !me->is_fighting()
	|| !me->query_temp("weapon")
	||  me->query_temp("weapon") != weapon) 
	{
		remove_effect(me);
		return;
	}
    call_out("check_fight", 1, me, weapon); 
} 


void remove_effect(object me)
{
	int eff;
    if(!objectp(me))
        return;
    eff=(int)me->query_temp("adv_weapon/swordextra");
    me->add_temp("apply/damage",-eff);
    me->delete_temp("adv_weapon/sword");
    me->delete_temp("adv_weapon/swordextra");
    tell_object(me, "你静下心来，纵横剑意消散在天地间。\n");
    return;
}

