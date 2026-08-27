inherit "/obj/monster";
string	owner_name;

int	abandon( string item );
int	follow( string person );
void	heart_beat();
int	help( string subject );
void	init();
int	open( string item );
int	query_auto_load();
int	write_message(int dam,object him,object me,string type,string attack);

void
  /* This is the old setup. Forget it for now.
   * Keep it to get the special stuff later. */
  /*
{
 set_name( "luggage" );
 set_main_plural( "luggages" );
 add_adjective( "sapient" );
 add_adjective( "pearwood" );
 add_plural( "sapient luggages" );
 add_plural( "sapient pearwood luggages" );
 add_plural( "pearwood luggages" );
 set_short( "luggage" );
 set_long( "The luggage is made of sapient pearwood.  It is just like any "
  + "ordinary trunk although it has numerous legs sprouting from "
  + "its base.  The most unusual thing about it is that is seems "
  + "to be staring at you.  You wonder what makes you think that "
  + "as it does not have any discernable face.\n" );
 reset_get();
 set_max_weight( 5000 );
/*
		set_closed();
		set_stuck( 0 );
*/
  set_weight( 150 );
 adjust_money( 5 , "platinum" );
 set_heart_beat( 1 );
 owner = 0;
 set_level( 1 );
 set_al( 100 );
 set_race( "luggage" );
 set_aggressive( 0 );
 add_attack( "snap" , 0 , 20 , 30 , 0 , 0 , "slash" );
 add_attack( "bump" , 0 , 20 , 25 , 0 , 0 , "blunt" );
}
  */
  /* This is the new setup. It has no real armor setup stuff,
   * just object stuff such as names..etc. No money either. */

  void setup()
    {
    set_name("luggage");
    set_main_plural("luggages");
    add_adjective("sapient");
    add_adjective("pearwood");
    add_plural("sapient luggages");
    add_plural("sapient pearwood luggages");
    add_plural("pearwood luggages");
    set_short("luggage");
    set_long("The luggage is made of sapient pearwood. It is just like any "+
             "ordinary trunk although it has numerous legs sprouting from "+
             "its base. The most unusual thing about it is that it seems "+
             "to be staring at you. You wonder what makes you think that "+
             "as it does not have any discernable face.\n");
  }
int abandon( string item )
{
 if ( owner && ( item == "luggage" ) )
 {
  owner = 0;
  set_short( "luggage" );
  write( "The luggage looks hurt.  How could you abandon such a loyal "
   + "servant?\n" );
  return 1;
 }
 return 0;
}

int follow( string person )
{
 if ( !owner && ( person == "me" ) )
 {
  owner = this_player();
  owner_name = (string) ( owner->query_cap_name() );
  set_short( owner_name + "'s luggage" );
  write( "The luggage sizes you up to see if you are worthy of its "
   + "loyality.  Not being sure, it decides it will give you a "
   + "change to prove yourself.\n" );
  return 1;
 }
 return 0;
}

void
heart_beat()
{
 object	luggage;
 object	lug_env;
 object	own_env;

 if ( !owner ) return;

 luggage = this_object();
 lug_env = environment( luggage );
 own_env = environment( owner );

 if ( lug_env == own_env )  return;

 luggage->move( own_env );

 if ( lug_env ) tell_room( lug_env , owner_name + "'s luggage patters "
  + "along off after " + owner->query_possessive()+".\n");
 if ( own_env ) tell_room( own_env , owner_name + "'s luggage patters "
  + "into the room on its many legs.\n" );
}

int help( string subject )
{
 if ( !subject || ( subject != "luggage" ) )  return 0;

 write( "To get the luggage to follow you, just enter 'follow me'.\n"
	 + "To get the luggage to stop following, enter 'abandon luggage'.\n"
	 + "Beyond that, it works just like an ordinary container.\n");
 return 1;
}

void init()
{
		::init();

		add_action( "abandon" , "abandon" );
		add_action( "follow"  , "follow"  );
		add_action( "help"    , "help"    );
		add_action( "open"    , "open"    );
}

int open( string item )
{
		if ( !item )  return 0;

		if ( ( item != "luggage" )
			&& ( item != "pearwood luggage" )
			&& ( item != "sapient luggage" )
			&& ( item != "sapient pearwood luggage" )
			&& ( item != owner_name + "'s luggage" )
			 )  return 0;

		if ( owner != this_player() )
		{
	write( "The luggage glares at you when you attempt to open it.\n" );
	return 1;
		}
		return 0;
}

int
query_auto_load() { return 1; }

int
write_message( int dam , object him , object me , string type , string attack )
{
 switch ( attack )
 {
  case "snap" :
   say( owner_name + "'s luggage snaps at " + him->query_cap_name()
    + ".\n" , him );
   tell_object( him , owner_name + "'s luggage snaps at you.\n" );
   break;

  case "bump" :
   say( owner_name + "'s luggage bumps into "
	 + him->query_cap_name() + ".\n" , him );
   tell_object( him , owner_name + "'s luggage bumps into you.\n" );
   break;

  default :
   ::write_message( dam , him , me , type , attack );
   break;
 }
}
