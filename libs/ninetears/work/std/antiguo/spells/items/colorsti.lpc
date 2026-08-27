/*** 'ColorStick' ***/
/*** by Wonderflug **/

/* Teaches players how to cast cloudkill if mages, or
 * otherwise is pretty much useless.
 */

inherit "/std/object";

int state;

void setup()
{
  set_name("colorstick");
  add_alias("stick");
  set_short("Colored Stick");
  set_long("\nThis is a curious looking stick, about 2 feet long and " 
	"brightly coloured in several different wild shades, blues and "
	"reds mostly.  On one "
	"end there seem to be some runes and on the other end two little "
	"buttons, one red, and one blue.\n");
  set_value(5000);
  state = 0;
}

void init()
{
  ::init();
  add_action("do_push", "push");
  add_action("do_push", "press");
}

int add_cloudkill_spell()
{
  if (this_player()->query_level() < 16)
  {
	write("\nYou wonder how that happened.  Maybe "
	  "if you were more experienced you'd be able figure it out.\n");
	return 0;
  }

  switch( this_player()->query_guild_name() )
  {
     case "drow_wizard":
     case "wizard":
     case "necromancer":
     case "conjurer":
     case "abjurer":
     case "enchanter":
     case "illusionist":
     case "invoker":
     case "transmuter":
      case "bard":
    case "wizthief":
	if ( !(this_player()->query_spell("cloudkill")) )
	{
	  this_player()->add_spell("cloudkill","kcloud",16);
	  write("Seeing the runes blaze as that happened, you realize "
	    "a spell was just cast.  You sit down and study the runes "
	    "and soon you learn how to cast the spell.\n");
	  tell_room(environment(this_player()), this_player()->query_cap_name()+
	    " studies a Colored stick, then smiles triumphantly.\n",
	    this_player() );
	  return 0;
	}
	write("You activate the stick again, confident in your ability.  "
	  "Overconfident in fact, as you become careless and let the mist "
	  "spray out over you.  You feel weak and withered.\n");
	tell_room(environment(this_player()), this_player()->query_cap_name()+
	  " sprays "+this_player()->query_objective()+"self with the mist, "
	  "collapses weakly to the ground.\n", this_player());
	this_player()->adjust_hp(-10, this_object());
	this_player()->adjust_tmp_str(-3);
	return 0;
    default:
	write("Wasn't that neat?\n");
	return 0;
  }

}

int do_push(string str)
{
  int check;

  check = random(20) - (int)this_player()->query_int();

  if ( str != "red" && str != "blue" && str != "red button" && 
       str != "blue button" && str != "button" )
	return 0;

  if ( check < 0 ) 
  {
	write("\nYou press the button and the colours line up a little, "
	  "the blues bunching together somewhat and the reds coming together "
	  "somewhat.\n");
	state++;
  }
  else 
  {
	write("\nYou press the button and the colours scatter haphazardly.\n");
	state--;
  }

  switch( state )
  {
	case 3..10:
	  write("\nAll lined up now, the colours blur from a deep red into "
	    "lighter and lighter and then into blue shades.  Suddenly a "
	    "faint mist comes out of the end of the stick.  Strangely, "
	    "foliage that comes near the mist shrivels up and dies.\n\n");
	  add_cloudkill_spell();
	  write("\nThe stick seems quite useless now, and you throw it "
	    "away.\n");
	  this_object()->dest_me();
	  return 1;
	case 2:
	  write("\nAlmost all the colours are lined up now, deep red growing "
	    "lighter into light blue growing into a deep blue.\n");
	  return 1;
	case 1:
	  write("\nThe colours are still somewhat scattered about.\n");
	  return 1;
	case 0:
	  write("\nBlues and reds are completely intermixed now.\n");
	  return 1;
	default:
	  write("\nThe rod alternates blue-red-blue-red all along its "
	    "length, looking quite ugly and gaudy.\n");
	  state = -1;  /* so we don't go completely bad. */
	return 1;
  }

  return 1;
}
