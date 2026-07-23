#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int myexp,yourexp,mystr,yourstr,lvl;
        object weapon;

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［风起云涌］只能对战斗中的对手使用。\n");

	//if(!objectp(weapon)) return notify_fail("你的对手没有用兵器！\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("你的内力不够。\n");
        me->add("neili",-200);
        weapon = target->query_temp("weapon");
        myexp = (int) me->query("combat_exp");
	mystr = (int) me->query_str();
        yourexp = (int) target->query("combat_exp");
	yourstr = (int) target->query_str();
        lvl = (int) me->query_skill("sword",1) / 10 + 1;
	msg = YEL "$N双手一挥，连出三剑［风起云涌］$n的兵器不知怎么就收入了怀中！ \n" NOR;
if(objectp(weapon) )
{
        if( random(myexp ) > (yourexp)/2 )
        {
                weapon->unequip();              
		//weapon->move(environment(target));
		message_vision(msg, me, target);

                target->start_busy(2);
                COMBAT_D->do_attack(target,me, weapon, TYPE_REGULAR);
                COMBAT_D->do_attack(target,me, weapon, TYPE_REGULAR);
                COMBAT_D->do_attack(target,me, weapon, TYPE_REGULAR);

	        me->start_busy(2);
        }
        else 
	{
	msg = YEL "$N连出三剑，［风起云涌］！ \n" NOR;		
message_vision(msg, me, target);
                COMBAT_D->do_attack(target,me, weapon, TYPE_REGULAR);
                COMBAT_D->do_attack(target,me, weapon, TYPE_REGULAR);
                COMBAT_D->do_attack(target,me, weapon, TYPE_REGULAR);
        }
	        me->start_busy(2);
}
        return 1;
}
