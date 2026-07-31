
#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return "[古秘术]"ZJBR"大化自在"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
        int skill = me->query_skill("force") /3*100 ;

        if (target != me)
                return notify_fail("你只能用上古秘经来提升自己！！！。\n");

        if ((int)me->query("neili") < 10000)
                return notify_fail("你的内力不够。\n");

        if (skill < 1200)
                return notify_fail("你的上古秘经等级不够。\n");

        if ((int)me->query_temp("shou"))
                return notify_fail("你已经在运功中了。\n");

        me->add("neili", -10000);
        me->receive_damage("qi", 0);

        message_vision(HIY "$N" HIY "默运上古秘经，顿觉体内力量汹涌！！！"NOR"\n", me);

        if (me->query("breakup"))
        {
			me->add_temp("apply/dodge", skill);
			me->add_temp("apply/parry", skill);
            me->add_temp("apply/armor", skill);
                    me->add_temp("apply/sword", skill);
					me->add_temp("apply/cuff", skill);
					me->add_temp("apply/blade", skill);
                    me->add_temp("apply/force", skill);
					me->add_temp("apply/club", skill);
                     me->add_temp("apply/claw", skill);
					me->add_temp("apply/hand", skill);
					me->add_temp("apply/strike", skill);
                    me->add_temp("apply/staff", skill);
					me->add_temp("apply/whip", skill);
                     me->add_temp("apply/unarmed", skill);
					me->add_temp("apply/hammer", skill);
					me->add_temp("apply/finger", skill);
 }
        else
        {
			me->add_temp("apply/dodge", skill / 100);
			me->add_temp("apply/parry", skill / 100);
            me->add_temp("apply/armor", skill / 100);
                    me->add_temp("apply/sword", skill / 100);
					me->add_temp("apply/cuff", skill / 100);
					me->add_temp("apply/blade", skill / 100);
                    me->add_temp("apply/force", skill / 100);
					me->add_temp("apply/club", skill / 100);
                     me->add_temp("apply/claw", skill / 100);
					me->add_temp("apply/hand", skill / 100);
					me->add_temp("apply/strike", skill / 100);
                    me->add_temp("apply/staff", skill / 100);
					me->add_temp("apply/whip", skill / 100);
                     me->add_temp("apply/unarmed", skill / 100);
					me->add_temp("apply/hammer", skill / 100);
					me->add_temp("apply/finger", skill / 100);
        }
        me->set_temp("shou", 1);
        me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill :), skill);

        return 1;
}

void remove_effect(object me, int amount)
{
        if (me->query_temp("shou"))
        {
                if (me->query("breakup")) {
                    me->add_temp("apply/armor", -amount);
					me->add_temp("apply/dodge", -amount);
					me->add_temp("apply/parry", -amount);
                    me->add_temp("apply/sword", -amount);
					me->add_temp("apply/cuff", -amount);
					me->add_temp("apply/blade", -amount);
                    me->add_temp("apply/force", -amount);
					me->add_temp("apply/club", -amount);
                      me->add_temp("apply/claw", -amount);
					me->add_temp("apply/hand", -amount);
					me->add_temp("apply/strike", -amount);
                    me->add_temp("apply/staff", -amount);
					me->add_temp("apply/whip", -amount);
                     me->add_temp("apply/unarmed", -amount);
					me->add_temp("apply/hammer", -amount);
 					me->add_temp("apply/finger", -amount);
 }
                else {               
                    me->add_temp("apply/armor", -amount / 100);
					me->add_temp("apply/dodge", -amount / 100);
					me->add_temp("apply/parry", -amount / 100);
                    me->add_temp("apply/sword", -amount / 100);
					me->add_temp("apply/cuff", -amount / 100);
					me->add_temp("apply/blade", -amount / 100);
                    me->add_temp("apply/force", -amount / 100);
					me->add_temp("apply/club", -amount / 100);
                      me->add_temp("apply/claw", -amount / 100);
					me->add_temp("apply/hand", -amount / 100);
					me->add_temp("apply/strike", -amount / 100);
                    me->add_temp("apply/staff", -amount / 100);
					me->add_temp("apply/whip", -amount / 100);
                     me->add_temp("apply/unarmed", -amount / 100);
					me->add_temp("apply/hammer", -amount / 100);
					me->add_temp("apply/finger", -amount / 100);
 }
		    me->delete_temp("shou");
                tell_object(me, "你的上古秘经运行完毕，将内力收回丹田。\n");
        }
       
}
