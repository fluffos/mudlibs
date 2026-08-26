#include <priest.h>
inherit SPELL;

object who;
string whoname, whocname, cname, Ccname;

//Needs descriptive work

void create()
{
    ::create();
    set_spell_name("whispers of the grave");
    set_spell_level(([ "warlock" : 1 ]));
    set_spell_sphere("divination");
    //set_heritage("gloom");
    set_syntax("cast CLASS whispers of the grave to TARGET");
    set_description("Calling upon the power of their patron to bridge the barriers between life and death, the warlock is able to establish contact with the recently deceased.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

string query_cast_string()
{
	return "%^RESET%^%^CRST%^%^C144%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C144%^ closes their eyes as they concentrate. The smell of the %^C245%^g%^C243%^r%^C059%^a%^C243%^v%^C245%^e%^RESET%^%^C144%^, of %^C100%^rot %^C144%^and %^C056%^decay%^RESET%^%^C144%^, seems to permeate the air...%^CRST%^";
}

void spell_effect(int prof)
{
    string *ignored, *casterallowed, *targallowed;

    if(!arg)
    {
        TO->remove();
        return;
    }
   
    if (!(who = find_player(caster->realName(lower_case(arg))))) {
      	tell_object(CASTER,capitalize(arg)+" cannot be found within the land of the dead to establish a link.\n");
        TO->remove();
        return;
    }
    cname = CASTER->query_name();
    whoname = who->query_name();
    whocname = who->QCN;
    Ccname = CASTER->QCN;
    if (avatarp(who) && !who->query_disguised())
	{
      	tell_object(CASTER,capitalize(arg)+" cannot be found within the land of the dead to establish a link.\n");
        	TO->remove();
        	return;
    }
   	if(avatarp(who) && arg == (string)who->query_true_name())
	{
      	tell_object(CASTER,capitalize(arg)+" cannot be found within the land of the dead to establish a link.\n");
      	TO->remove();
      	return;
   	}
    if (arg == cname)
	{
      	tell_object(CASTER,"You cannot establish a link with yourself.\n");
        	TO->remove();
        	return;
    	}
    if (who->query_invis() && (int)who->query_level() > (int)CASTER->query_level())
	{
      	tell_object(CASTER,capitalize(arg)+" cannot be found within the land of the dead to establish a link.\n");
        TO->remove();
        return;
    }
    if (who->is_player() && !interactive(who))
	{
      	tell_object(CASTER, who->QCN+" is link-dead and cannot hear you.\n");
        TO->remove();
        return;
    }
	if(!who->query_ghost())
	{
		tell_object(CASTER,capitalize(arg)+" cannot be found within the land of the dead to establish a link.\n");
		TO->remove();
		return;
	}
    if (who->query_blocked("tell"))
	{
      	write(who->QCN+" is currently blocking all tells.");
        	TO->remove();
        	return;
    }
    ignored = who->query_ignored();
    if (!ignored)
	{
      	who->reset_ignored();
        ignored = who->query_ignored();
    }
    if ((member_array(cname, ignored) != -1))
	{
      	tell_object(CASTER, who->QCN+" is ignoring you.\n");
        TO->remove();
        return;
    }
    casterallowed = CASTER->query_property("allowed tell");
    targallowed = who->query_property("allowed tell");
    if (!casterallowed) casterallowed = ({});
    if (!targallowed) targallowed = ({});
    if (member_array(cname,targallowed) != -1
    && member_array(whoname,casterallowed) != -1)
	{
        tell_object(CASTER,"You already have a mental link with "+who->QCN+".\n");
        TO->remove();
        return;
    }
    tell_object(CASTER, "%^RED%^You find "+who->QCN+"%^RED%^ within the land of the dead and establish a connection with "+who->QO+".");

    tell_object(who, "%^RED%^"+CASTER->QCN+" has reached out from the land of the living and established a mental connection with you!");
    addSpellToCaster();
    casterallowed += ({whoname});
    targallowed += ({cname});
    CASTER->set_property("allowed tell",casterallowed);
    CASTER->set_property("spelled", ({TO}) );
    who->set_property("allowed tell",targallowed);
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 4;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect() {
    string *casterallowed, *targallowed;

    casterallowed = ({});
    targallowed = ({});
    if (objectp(CASTER))
    {
        CASTER->remove_property_value("spelled", ({TO}) );
        casterallowed = CASTER->query_property("allowed tell");
        if (pointerp(casterallowed))
        if (member_array(whoname,casterallowed) != -1)
        {
            casterallowed = casterallowed - ({whoname});
            CASTER->remove_property("allowed tell");
            CASTER->set_property("allowed tell",casterallowed);
            tell_object(CASTER,"%^RED%^Your mental link with "+whocname+" has been ended.\n");
        }
    }
    if (objectp(who))
    {
        targallowed = (string *)who->query_property("allowed tell");
        if (member_array(cname,targallowed) != -1)
        {
            targallowed = targallowed - ({cname});
            who->remove_property("allowed tell");
            who->set_property("allowed tell",targallowed);
            tell_object(who,"%^RED%^Your mental link with "+Ccname+" has been ended.\n");
        }
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
