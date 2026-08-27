/*** Reaper Cloak ***/
/*** by Wonderflug **/
/*** Part of the 'Haste' spellquest ***/

inherit "/std/item";

void setup()
{
  set_name("reaper cloak");
  add_alias("cloak");
  set_short("Cloak of the Reaper");
  set_long("\nCloak of the Reaper\n\n"
	"     This cloak is all that remains of the Reaper.  A feeling of "
	"pure evil radiates from it, with a small undercurrent of power.  "
	"It is far too large for you to use, and seems to rustle even "
	"though there is no wind, almost as if it had a mind of its own.\n\n");
  set_weight(100);
  set_value(500);
}

void init()
{
  ::init();
  add_action("do_study", "study");
  add_action("do_wear", "wear");
  add_action("do_wear", "equip");
}

int check_guild()
{
  switch( this_player()->query_guild_name() )
  {
     case "wiz-war":
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
	if ( (int)this_player()->query_level() >= 11 )
	  return 1;
	else return -1;
     case "drow_warrior":
        if ( (int)this_player()->query_level() >= 18 )
          return 2;
        else
          return -1;
     default:
	return 0;
  }
}

int do_wear( string str )
{
  int damage = random(10);

  if ( query_verb() != "equip" && str != "cloak" ) return 0;

  write("\nYou try to put on the Cloak of the Reaper and suddenly it comes "
	"alive in your hands and tries to smother you!\n\nAfter a long "
	"struggle you manage to rip it into shreds, and the shreds fall "
	"apart lifelessly.\n\n");
  this_player()->adjust_hp(-damage, this_object());
  this_object()->dest_me();
  return 1;
}

string enchant_string()
{
  return "\nBeneath the feeling of evil you sense a great weave of power "
	"in the cloak.  This weave definitely needs to be studied.\n";
}

int do_study(string str)
{
string *foo;

  if ( str != "cloak" && str != "weave" )
	return 0;
  switch( check_guild() )
  {
	case 1:
	  write("\nYou study the cloak's weaving intently, probing carefully "
	    "at it.  Eventually you realize that it was this cloak which "
	    "gave the Reaper its extraordinary speed.  The weaving in the "
	    "cloak seems to be specific to the Reaper, so it won't help "
	    "anyone else.  After a time, you see how to reproduce the weave "
	    "on anyone..\n\nYour probing seems to have destroyed the cloak.\n");
	  if ( !this_player()->query_spell("haste") )
		this_player()->add_spell("haste","haste",11);
	  this_object()->dest_me();
	  return 1;
        case 2:
          write("\nYou study the cloak's weaving intently, probing carefully "
            "at it.  Eventually you realize that it was this cloak which "
            "gave the Reaper its extraordinary speed.  The weaving in the "
            "cloak seems to be specific to the Reaper, how it gave it a surge "
            "of adrenaline.  You figure out the secrets of this surge and "
           "now know how to make your own body produce these effect!\n\n"
            "Your probing seems to have destroyed the cloak.\n\n");
          foo = this_player()->query_known_commands();
          if ( member_array("surge", foo) == -1 ) 
                this_player()->add_known_command("surge");
          this_object()->dest_me();
          return 1;

	case -1:
	  write("\nYou study the cloak's weaving intently, probing carefully "
	    "at it, but it seems to be beyond your mastery.\n\n");
	  return 1;
	default:
	  return 0;
  }
  return 1;
}

