/*** Teleport to Player Spell   ***/
/*** Coded by:  Eerevann Tokani ***/
/*** Fixed by:  Slinger :)      ***/


#define SP_NAME "Teleport"
#define GP_COST 1
#define DIVISOR 1


mixed spell(string str,int skill, int cast);

/*** Help file here ***/
string help() {
       return
       "\n\n"
       "Spell Name: "+SP_NAME+"\n"
       "Skill Used:  Magic.Spells.Misc\n"
       "Gp Cost: "+GP_COST+"\n"
       "Description: \n"
       "     This spell instantly teleports you to another person.  The person "
       "can't be an immortal.\n"
       "\n";
}

int cast_spell(string str)

{
  int skill;
  mixed ret;

  skill = (int)this_player()->query_skill_bonus("int.spells");

  if(!str)
   return 0;
  ret = spell(str, skill, 1);
   if (stringp(ret))
     {
        notify_fail(ret);
        return 0;
     }

  write("You begin to cast "+SP_NAME+".\n");
  return 1;
}

mixed spell(string str, int skill, int cast)

{
  object ob;
  if ((int)this_player()->query_spell_effect("misc"))
    return "You are already casting an misc spell.\n";
  this_player()->add_spell_effect(1, "misc", "SP_NAME", this_object(),
    "hb_spell", ({ skill/DIVISOR,str,cast }));
  return 1;
}

int hb_spell(object attacker, mixed *params) {

  object ob;


   if ((ob=find_player(params[1])) == 0)
   {
  tell_object(previous_object(), "There is no one of that name to teleport to.\n");
  return 0;
   }


   if (params[2] && (int)previous_object()->adjust_gp(-GP_COST)<0)
   {
  tell_object(previous_object(), "You are currently too mentally drained to cast.\n");
  return 0;
   }


if (ob->query_creator() ) {
      write("You cannot teleport to an immortal.\n");
      return 0;
   }

/*   if (environment(this_player()) == environment(ob))){
      write("Your already in the same room!\n");
      return 0;
   }*/
 
   tell_object(ob, this_player()->query_cap_name()+
      " summons the powers of magic to warp "
      "space, creating a temporary rift between you and "+
      this_player()->query_pronoun()+".\n");
 
  tell_room(environment(ob), "There is a sharp crack, "
      "and a pinpoint of light appears "
      "in mid air.\nThe light slowly expands into "+this_player()->query_cap_name()+".\n");


   tell_room(environment(this_player()), "There is a sharp crack "
      "then a flash of light "
      "as "+this_player()->query_cap_name()+" disappears.\n");



   this_player()->move(environment(ob));



   return GP_COST;
}
