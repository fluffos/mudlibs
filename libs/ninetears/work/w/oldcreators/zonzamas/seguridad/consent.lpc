/* consent.c
 *
 * This mess by Wonderflug, til I convince someone to let
 * me put in a real consent system.
 * Basically properties the player can set himself.
 * Only ones that matters right now are resurrect, determines
 * whether the player wants to be resurrected or not,
 * and drinks, lets another player buy you a drink.
 */

mapping consents;
nosave mixed valid_consents;

string help()
{
  return "Usage: consent <type> <on/off>\n\n"
    "Turns consent for a type of activity on or off. "
    "The current valid types are: \n"
    "resurrection:  If a player tries to resurrect/raise you, you will "
    "attempt to dodge the spell.  Often you do not want to be raised.\n"
    "reincarnation: Same as ressurection but on the spell 'reincarnate'.\n"
      "tag: The means that you are prepared to play one of a number "
      "of silly, but non-lethal games.\n"
    "drinks:  This lets another player buy you a drink. "  
    "Drunkenness often has nasty side-effects.\n";

}  

void create()
{
  consents = ([ ]);
  valid_consents = ({ "resurrection", "follow", "drinks","tag",
                      "reincarnation"});
}

void consent_commands()
{
  add_action("change_consent", "consent");
}

mixed query_consent(string which)
{
  return consents[which];
}

mapping query_consents()
{
  return consents;
}


int change_consent(string str)
{
  string which;
  int value;

  if ( str && sscanf(str, "%s on", which) == 1 )
    value = 1;
  else if ( str && sscanf(str, "%s off", which) == 1 )
    value = 0;
  else
  {
    write("Your current consents are:\n");
    for (int i=0; i<sizeof(valid_consents); i++)
      write("Consent for "+valid_consents[i]+" is currently "+
        (consents[valid_consents[i]]?"on":"off")+".\n");
    write("\nFor usage, see 'help consent'.\n");
    return 1;
  }

  if ( member_array( which, valid_consents ) == -1 )
  {
    notify_fail("Invalid consent type.  Valid arguments are: "+
      implode(valid_consents, ", ")+".\nSee 'help consent' for more "
      "info.\n");
    return 0;
  }

  if ( !consents )
    consents = ([ which : value ]);
  else
    consents += ([ which : value ]); 

  // This looks nasty but just converts 1/0 back to on/off
  tell_object(this_object(), "Ok. Consent for "+which+" changed to "+
    ((value==1)?"on":((value==0)?"off":(sprintf("%d",value))))+".\n");

  return 1;
}
