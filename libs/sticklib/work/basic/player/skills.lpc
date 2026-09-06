#include <skills_defs.h>
#include "skills.h"
#ifndef PLAYER_C
varargs int tell_me(string s, int tell_type);
#endif

mapping Skills = ([ ]);



mapping	query_skills()		{	return Skills;		}


void	set_skills(mapping sk) {
    Skills = sk;
}

int	add_skill(string name, float value)	{
    int size, i;
    if(member(m_indices(Skills), name) != -1)
	return SKILL_EXISTS;
    i = (size = sizeof(Skills));
    if(size >= SKILL_LIMIT)
	while(i--)
	    if(Skills[m_indices(Skills)[i], SKILL_POS_LEV] > 1)
		size--;
    if(size >= SKILL_LIMIT)
	return SKILLS_FULL;
    Skills += ([ name : value;1;0 ]);
    return SKILL_ADDED;
}


float	query_skill(string name)	{
    if(member(m_indices(Skills), name) == -1)
	return (float)SKILL_NO_EXIST;
    return Skills[name];
}


void	set_skill(string name, float val)	{
    if(member(m_indices(Skills), name) == -1)
	return;
    Skills[name] = val;
}

void	set_skill_lev(string name, int lev) {
    if(member(m_indices(Skills), name) == -1)	return;
    Skills[name, SKILL_POS_LEV] = lev;
}

int	query_skill_lev(string name) {
    if(member(m_indices(Skills), name) == -1)
	return SKILL_NO_EXIST;
    return Skills[name, SKILL_POS_LEV];
}

mixed	use_skill(string name, float fac, mixed *data)	{
    float uses, old;
    mixed ret, rtotal;
    int resolv, i;
    if(member(m_indices(Skills), name) == -1)
	return (float)SKILL_NO_EXIST;
    if( i  = sizeof(Skills[name, SKILL_POS_HOOK])) {
	while(i -- ) {
	    ret = funcall(Skills[name, SKILL_POS_HOOK],
	      this_object(), Skills[name, SKILL_POS_VAL],
	      Skills[name, SKILL_POS_LEV], name);
	    switch(ret) {
	    case HOOK_RESOLVED_NT:	rtotal = ret;
		break;
	    case HOOK_RESOLVED:	if(rtotal != HOOK_RESOLVED_NT)
		    rtotal = HOOK_RESOLVED;
		break;
	    default:
		rtotal += ret;
	    }
	}
    }
    if(rtotal == HOOK_RESOLVED_NT) return rtotal;
    uses = exp(old = to_float(Skills[name]));
    uses += (fac * SKILL_TRAIN_RATE);
    if(log(uses) <= to_float(TOP_RANK))
	Skills[name] = log(uses);
    /* Not going to work with multi-skill commands
	    if(to_int(Skills[name]) > to_int(old))
		    tell_me(sprintf("\nYou feel more experienced in %s.\n",
		    name));
    */
    if(to_int(Skills[name]) >= TOP_RANK && fac < 0.0)
	// this is a cheat we use for multi-skill commands
	return;
    if(rtotal == HOOK_RESOLVED) return rtotal;
    if(!rtotal)
	return Skills[name];
    return rtotal;
}

int	add_skill_hook(string name, closure cl) {
    if(member(m_indices(Skills), name) == -1)
	return SKILL_NO_EXIST;
    if(Skills[name, SKILL_POS_HOOK] == 0)
	Skills[name, SKILL_POS_HOOK] = ({ cl });
    else {
	if(member(Skills[name, SKILL_POS_HOOK], cl) != -1)
	    return ALREADY_HOOKED;
	else
	    Skills[name, SKILL_POS_HOOK] += ({ cl });
    }
    return HOOKED;
}

mixed	query_skill_hook(string name, closure cl) {
    if(member(m_indices(Skills), name) == -1)
	return SKILL_NO_EXIST;
    if(!Skills[name, SKILL_POS_HOOK])
	return HOOK_NOT_IN_USE;
    if(!cl) return Skills[name, SKILL_POS_HOOK];
    if(member(Skills[name, SKILL_POS_HOOK], cl) != -1)
	return HOOKED;
}

int	remove_skill_hook(string name, closure cl) {
    if(member(m_indices(Skills), name) == -1)
	return SKILL_NO_EXIST;
    if(!Skills[name, SKILL_POS_HOOK])
	return HOOK_NOT_IN_USE;
    if(member(Skills[name, SKILL_POS_HOOK], cl) == -1)
	return NOT_HOOKED;
    else {
	Skills[name, SKILL_POS_HOOK] -= ({ cl });
	if(!sizeof(Skills[name, SKILL_POS_HOOK]))
	    Skills[name, SKILL_POS_HOOK] = 0;
	return HOOK_REMOVED;
    }
}

void	remove_skill(string str) {
    Skills = m_delete(Skills, str);
}
