#define HIDE "dest_hide_shadow"
#define MAGICAL "dispell_me"
#define ADJ_COST 1

inherit "/std/spells/base";

/*** Faerie Fire Spell ***/
/*** Coded by:  Taniwha ***/

#define SP_NAME "faerie fire"
#define GP_COST 10
#define TYPE "magical"
#define save_type "magical"

void setup()
{
    set_spell_name("Faerie fire");
    set_spell_level(2);
    set_school("invocation");

    set_target_type("many");
    set_range(0);
    set_line_of_sight_needed(0);

    set_help_extras(
      "Damage Type: No direct damage\n"
      "Saving Throw: magical");
    set_help_desc(
      "     This spell is unusual in that is envelopes a group of enemies "+
      " in faerie fire. "+
      "This in itself does no damage, but it really messes up things like "+
      "invisibility and mirror image. Because the targets are outlined "+
      "with faerie fire they take a hit to their defensive capabilities. "+
      "Note that this spell takes GP for every round of casting and persists "+
      "for up to 10 rounds. Other than the effects on targets "+
      "it will make everything in the room other than the caster "+
      "sparkle every casting round. "+
      "Note the effects on targets persist until casting finishes. "+
      ".\n");

    set_gp_cost(GP_COST);
    set_casting_time(10);
    set_rounds( ({ "round2","round2","round2","round2","round2","round2","round2","round2","round2", "round2"}) );
}



int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
    int i;
    object *olist;
    string str;

    tell_room(environment(caster),"Small points of light flash into existance.\n",({ }));
    if( (int)caster->adjust_gp(-ADJ_COST)<0)
    {
	tell_object(caster, "You are currently too "+
	  "mentally drained to continue the spell.\n");
	return 0;
    }
    olist = all_inventory(environment(caster));
    str ="The faerie fire illuminates the room revealing ";
    for(i = 0; i < sizeof(olist); i++)
    {
	if(olist[i] != caster && !olist[i]->query_property(save_type) && olist[i]->query_name() ) str = str + " "+ (string)olist[i]->query_name();
//    tell_object(caster,str+"\n");
    }
   str = str + ".\n";
   tell_room(environment(caster),str,({ }));

    for(i= 0 ; i<sizeof(target);i++)
    {
	if(target[i] )
	{
	    if( function_exists(MAGICAL,target[i]) )
	    {
		call_other(target[i],MAGICAL,0);
		tell_object(target[i],"The faerie fire outlines you, defeating your magical protections.\n");
		tell_object(caster,"You strip "+target[i]->query_cap_name()+"'s magical protections.\n");
	    }
	    else if( function_exists(HIDE,target[i]) )
	    {
		call_other(target[i],HIDE,0);
		tell_object(target[i],"The faerie fire outlines you.\n");
		tell_object(caster,"Your spell reveals "+target[i]->query_cap_name()+".\n");
	    }

	}
	return 0;
    }
}


