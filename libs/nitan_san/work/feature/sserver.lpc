// sserver.c

// This function selects a random target for offensive spells/functions.
object offensive_target(object me)
{
        me->clean_up_enemy();
        return me->select_opponent();
}

int ap_power(object me, string skill)
{
        return SKILLS_D->attack_power(me, skill);
}

int dp_power(object target, string skill)
{
        return SKILLS_D->defend_power(target, skill);
}

int da_power(object me, string skill)
{    
        return SKILLS_D->damage_power(me, skill);
}                        

