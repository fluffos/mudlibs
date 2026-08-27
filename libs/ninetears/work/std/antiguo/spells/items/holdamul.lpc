/*** Hold Amulet ***/
/*** by Wonderflug **/
/*** Part of the 'Hold Person' spellquest ***/

inherit "/obj/armour";

void setup()
{
  set_name("red amulet");
  add_alias("amulet");
  set_short("Red Amulet");
  set_long("\nRed Amulet\n\n"
	"     This is a small disc made out of some strange, metallic red "
	"substance, though it seems brittle enough to break.  As you hold "
	"it, it seems to pulse with warmth, almost like a heart beat. "
	"The pulses start to race somewhat, almost angrily.\n\n");
  set_base_armour("amulet");
  set_weight(50);
  set_value(500);
}

void init()
{
  ::init();
  add_action("do_break", "break");
}

int check_guild()
{
  switch( this_player()->query_guild_name() )
  {
   case "virga":
     case "Cyrcia":
     case "timion":
     case "hokemj":
      case "Grimbrand":
     case "taniwha":
	if ( (int)this_player()->query_level() >= 11 )
	  return 1;
	else return -1;
     default:
	return 0;
  }
}

int do_break(string str)
{
  if ( str != "amulet" && str != "red amulet" )
	return 0;
  switch( check_guild() )
  {
	case 1:
	  write("\nYou break the amulet apart.  Suddenly, an awareness "
	    "fills your head, reverberating with ancient words..\n\n"
	    "  'Thou hast freed mine soul from the accursed prison of the "
	    "dread Mind Flayers.  Guard thee well that I be a Greater "
	    "Servant of "+capitalize(this_player()->query_guild_name())+
	    ", and for thine deeds I reward thee with a new prayer, the "
	    "instrument of mine bondage.  Use thy newfound power well.'\n\n"
	    "The awareness fades.\n\n");
	  if ( !this_player()->query_spell("hold person") )
		this_player()->add_spell("hold person", "hold_person", 11);
	  this_object()->dest_me();
	  return 1;
	case -1:
	  write("\nYou feel an opposing power thwarting you from breaking "
	    "the amulet.  You feel helpless and can think of no way to "
	    "get around the power.  You give up and vow to try again another "
	    "day.\n\n");
	  return 1;
	default:
	  write("\nYou break the amulet in apart, destroying any use it "
	    "might have had.  A hollow laughter echoes in your head and "
	    "is gone as suddenly as it came.\n\n");
	  this_object()->dest_me();
	  return 1;
  }
  return 1;
}

