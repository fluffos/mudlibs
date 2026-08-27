/*** Titan Hammer ***/
/*** by Wonderflug **/
/*** Part of the 'Power Word: Stun' spellquest ***/

inherit "/std/item";

void setup()
{
  set_name("hammer of the apocalypse");
  add_alias("hammer");
  set_short("Hammer of the Apocalypse");
  set_long("\nHammer of the Apocalypse"
	"     This hammer is huge.  The head is about 6 feet across, "
	"a huge monolithic piece of obsidian.  The handle must have come "
	"from a large tree trunk, carved and polished into a haft about "
	"a foot and a half thick and 20 feet long.  Cold blue runes are "
	"etched along the handle, and the whole thing gives off an aura of "
	"power.\n\n");
  set_weight(10000);
  set_value(0);
  reset_drop();
  reset_get();
}

void init()
{
  ::init();
  add_action("do_fix", "fix");
}

int check_guild()
{
  switch( this_player()->query_guild_name() )
  {
     case "wizard":
      case "wiz-war":
     case "drow_wizard":
     case "necromancer":
     case "conjurer":
     case "abjurer":
     case "enchanter":
     case "illusionist":
     case "invoker":
     case "transmuter":
	if ( (int)this_player()->query_level() >= 15 )
	  return 1;
	else return -1;
   case "wizthief":
   case "bard":
      if( (int)this_player()->query_level() >= 20) return 1;
      else return -1;
     default:
	return 0;
  }
}

string enchant_string()
{
  return "\nAn immense aura of power surrounds the Hammer.  The aura "
	"apparently is meant to incapacitate whoever gets hit by the "
	"Hammer, but age seems to have worn the strength of the weave, "
	"and actually torn it apart.  If it was fixed and whole, you're "
	"sure whoever was holding this Hammer would still be alive.\n";
}

int do_fix(string str)
{
  if ( str != "hammer" && str != "weave" )
	return 0;
  switch( check_guild() )
  {
	case 1:
	  if ( !this_player()->query_spell("power word stun") )
		this_player()->add_spell("power word stun","pw_stun",15);
	  write("You channel some magic into the Hammer and try to mend the "
	    "broken weave.  Eventually you get a good idea of how it was "
	    "done, but unfortunately you can't quite fix it.\n\nYour probing "
	    "has destroyed the Hammer of the Apocalypse.\n\nYou feel tired "
	    "and exhausted from all that.\n");
	  tell_room(environment(this_object()), this_player()->query_cap_name()+
	    " stares intently at the Hammer waving "+
	    this_player()->query_possessive()+" hands at it and such.\n\n"
	    "The Hammer slowly fades into nothingness as if it had never "
	    "been.\n", this_player() );
	  this_player()->set_gp(0);
	  this_object()->dest_me();
	  return 1;
	case -1:
	  write("\nYou try to mend the broken weave, but it seems to evade "
	    "your rudimentary understanding and all you succeed at doing "
	    "is destroying it completely.\n");
	  tell_room(environment(this_object()), this_player()->query_cap_name()+
	    " stares intently at the Hammer of the Apocalypse.\n\nThe Hammer "
	    "suddenly fades and disappears as if it had never been.\n\n"+
	    this_player()->query_cap_name()+" starts cursing sulferously.\n",
	    this_player() );
	  this_player()->set_gp(0);
	  this_object()->dest_me();
	  return 1;
	default:
	  write("It looks in perfect condition (if a bit big) to you!\n");
	  return 0;
  }
  return 1;
}

