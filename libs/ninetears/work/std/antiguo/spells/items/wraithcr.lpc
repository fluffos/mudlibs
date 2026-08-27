/*** Wraith CrowN ***/
/*** by Wonderflug **/

/* Teaches players how to cast wraithform if they're general mages, or
 * other mage-type guilds. 
 */

inherit "/obj/armour";

void setup()
{
  set_name("wraith crown");
  add_alias("crown");
  set_short("Armas' Crown");
  set_long("\nArmas' Crown\n\n"
        "     A simple ring of beaten gold, with small gems inset into it. "
        "Runes are inscribed on the inner rim, glowing faintly with a cold "
        "blue light.  As you look closer at them, they seem to be pulsing "
        "softly.  It seems incredibly heavy.\n\n");
  set_base_armour("slippers");
  set_weight(150);
  set_value(5000);
}

void init()
{
  ::init();
  add_action("do_look", "look");
  add_action("do_look", "l");
  add_action("do_look", "read");
  add_action("do_open", "open");
}

int check_guild()
{
  switch( this_player()->query_guild_name() )
  {
      case "bard":
      case "wizthief":
     case "wizard":
     case "drow_wizard":
     case "necromancer":
     case "conjurer":
     case "abjurer":
     case "enchanter":
     case "illusionist":
     case "invoker":
     case "transmuter":
        if ( (int)this_player()->query_level() >= 20 )
          return 1;
        else return -1;
     default:
        return 0;
  }
}

int do_look(string str)
{
  if ( str != "runes" )
        return 0;
  switch( check_guild() )
  {
        case 1:
          write("\nYou read the magical runes... \n\n"
            "'Wear me and open your mind to absorb my power.'\n");
          return 1;
        case -1:
          write("\nYou try to read the magical runes, but they swirl and "
            "weave before your eyes.  Deciphering them seems to be beyond "
            "your meager ability.\n");
        default:
          write("\nYou cannot read the magical runes.\n");
          return 1;
  }
  return 1;
}

int do_open( string str )
{
  if ( str != "mind" && str != "my mind" )
        return 0;

  if ( !(this_object()->query_in_use()) )
        return 0;

  if ( check_guild() > 0 ) 
  {
	if ( !(this_player()->query_spell("wraithform")) )
        this_player()->add_spell("wraithform","wraithform",20);
        write("\nYou open your mind to Armas' Crown and you feel a.. "
          "presence.. enter you.  You scramble for control over it, and "
          "force it to the back of your mind.  You feel you can leash it "
          "there and keep control over it.. and even let it take control of "
          "your body for a time if you wish.....\n\n");
        write("The crown seems to have faded away.\n");
        this_object()->dest_me();
        return 1;
  }
  return 0;
}

