// y_shihui.c
#include <ansi.h>
#include <condition.h>
int update_condition(object me, int duration)
{
	object weapon;
	int attack,defense;
	mapping prepare;
	string attack_skill;
	weapon = me->query_temp("weapon");
		prepare = me->query_skill_prepare();
		if (!prepare) prepare = ([]);
		if( objectp(weapon) )	attack_skill = weapon->query("skill_type");
		else if ( sizeof(prepare) == 0)	attack_skill = "unarmed";
		else if ( sizeof(prepare) == 1)	attack_skill = (keys(prepare))[0];
		else if ( sizeof(prepare) == 2)	attack_skill = (keys(prepare))[me->query_temp("action_flag")];
		attack = me->query_skill(attack_skill)*3/4;
		defense = me->query_skill("dodge")*3/4;
		me->set_temp("apply/attack",-attack);
		me->set_temp("apply/defense",-defense);
      me->set_temp("blind",1);
      tell_object(me, HIB "你的双眼被石灰弄瞎了，疼痛难忍，而且目不见物。\n" NOR );
      message("vision", me->name() + "的眼睛似乎睁不开，走起路来一摇一晃。\n",environment(me), me);
   me->apply_condition("x_shihui", duration - 1);
   if( duration < 1 )
   {
        me->delete_temp("blind");
        me->delete_temp("apply/attack");
      me->delete_temp("apply/defense");
    return 0;
   }
   return CND_CONTINUE;
}
