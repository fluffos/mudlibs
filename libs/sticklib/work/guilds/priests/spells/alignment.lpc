/* Added new spell 23.10.92 //Hawthorn */

#include "priest_spell.h"

void begin_id(object who, mixed target);
status detect_align(object who, mixed target);

create_spell() {
    lvl = 2;
    cost = 5;
    funs = ({ #'begin_id, #'detect_align });
    skills_used = ({ });
}

void
begin_id(object who, mixed target)
{
    if(!target || !(target = present(target, HERE)) || !living(target)) {
	who->tell_me("There's no such being here!");
	target = 0;
	return;
    }
    if(target==who) {
	who->tell_me("You should know your own mind well enough, so that you \
don't have to use this spell to find what your alignment is.");
	target = 0;
	return;
    }
    HERE->tell_here(":%<me.capname>% utter%<me.ending_s>% a prayer and \
touch%<me.ending_s>% gently %<him.name>%",0,0,0,who,target,0);
}

status
detect_align(object who, mixed target)
{
    int align;
    string al_str;

    if(!objectp(target))
	return 0;
    who->add_sp(-cost);
    inc_skills(who, who->query_guild_object(), 100);
    if(who->query_level() > random(10)) {
	align = (int)target->query_alignment();
	if(align > 2000)
	    al_str="extremely holy";
	else if(align > 1000)
	    al_str="holy";
	else if(align > 200)
	    al_str="pure";
	else if(align > -200)
	    al_str="neutral";
	else if(align > -1000)
	    al_str="evil";
	else if(align > -2000)
	    al_str="devilish";
	else
	    al_str="altogether satanic";

	who->tell_me(sprintf("You slowly get a vision of %s's %s mind.",
	    target->query_name(),al_str));
	HERE->tell_here(":%<me.capname>% finishes %<me.possessive>% prayer."
	  ,0,0,who,who,0,0);
	return 1;
    }
    who->tell_me("You fail to concentrate your mind fully.");
    HERE->tell_here(":%<me.capname>% ends praying, but looks rather \
dissapointed", 0,0,who,who,0,0);
    return 1;
}
