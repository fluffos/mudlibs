/*** Poison Fang ***/
/*** by Wonderflug **/

/* Teaches players how to cast poison if they're priests, or
 * otherwise lets them cast it once.
 */
string *allowed = ({ "paladin","hokemj","Cyrcia","Grimbrand","timion","taniwha","antipaladin","ducky","virga"});
int *levels = ({ 17,11,11,11,11,11,17,11,11 });

inherit "/std/object";

void setup()
{
  set_name("poison fang");
  add_alias("fang");
  set_short("Poisoned Fang");
  set_long("\nThis is a poisonous, venomous fang.  Be very careful holding "
	"this thing so you don't accidentally prick yourself with it.  A "
	"little drop of venom drips off the end of it as you look at it.  Too"
	"bad there's not enough to dribble on to a weapon or anything.\n");
  set_value(5000);
}

void init()
{
  ::init();
  add_action("do_drink", "drink");
  add_action("do_drink", "suck");
}

int add_poison_spell()
{
   int i;

   i = member_array(this_player()->query_guild_name(),allowed);
   if( i == -1 || this_player()->query_level() < levels[i] )
  {
	write("\nYou drink in the poison from the fang, but the effects "
	  "happen too quickly for your inexperienced mind to catch on to "
	  "how its done.\n");
         this_player()->add_static_property("poison",20);
	return 0;
  }
	write("\nYou drink in the poison from the fang. \n\n");
	if ( !(this_player()->query_spell("poison")) )
	{
	  this_player()->add_spell("poison","poison",11);
	  write("You feel the poison course through your veins, but "
	    "your faith in your god protects you, and you learn how "
	"to inflict the poison on others.\n");
	tell_room(environment(this_player()), this_player()->query_cap_name()+
	    " sucks on a dripping, venomous fang and cackles madly.\n",
	    this_player() );
	  return 0;
	}
	write("You try to drink in the poison again, but your god "
	  "abandons you, leaving your foolish arrogance to die. "
	  "The poison consumes you, and in seconds you are thrashing on "
	  "the ground; a minute later you die.\n");
	tell_room(environment(this_player()), this_player()->query_cap_name()+
	  " sucks on a dripping venomous fang, then convulses, eyes bulging "
	  "as \nthe poison overtakes "+this_player()->query_objective()+". "
	  "Thrashing on the ground, "+this_player()->query_pronoun()+
	  " is dead within \na minute.\n", this_player());
	this_player()->do_death();
	return 0;

}


int do_drink( string str )
{
  if ( str == "on fang" || str == "fang" || str == "from fang" )
  {
	if ( add_poison_spell() )
	  return 1;
	write("\nYou throw the empty, useless fang away.\n");
	this_object()->dest_me();
	return 1;
  }
  else return 0;
}

