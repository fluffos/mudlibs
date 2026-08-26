/*  -*- LPC -*-  */
#include <quest_handler.h>

/*  create_dom_creator.c

    Change log:

  Whenever - Creator unknown.
  12/19/92 - Modified by Godot to add eligible_creator().
  12/20/92 - Modified by Godot to fix yesterday's bugs.
  04/02/97 - Modified by Turrican for the new security system.
*/

/*
    Prototype functions.
*/
int employ_creator( string name );
int create_domain( string name , string lord );
int create_project( string name , string lord );
int dismiss_creator( string str );
int eligible_creator( object player );


int eligible_creator( object player ) {
  int age, level;
  string age_str, reasoning;

  // Why isn't write() columnizing for this object????  I'm forced to put
  // in my own newlines.  Hopefully, no one has a <79 column terminal.
  // write called in the master object is the efun and not the simul_efun one
  // use tell_object( this_player(), instead, though you may have
  // to use "/secure/simul_efun"->tell_object...
  // Olorin

  reasoning =
    "  You do not have a *right* to create here.  In order to enhance your\n"
    "chances to be employed, you should demonstrate by your actions that you\n"
    "are worthy.\n"
    "  If our Creators find lots of your bug, typo, and idea reports in their\n"
    "directories, then your chances are improved.  If you have been a trouble-\n"
    "maker here, your chances are very slim.  Harrassing the Lords for a\n"
    "position will not help your chances either.\n"
    "  Having access to a MUD's file system is a great responsibility.  It\n"
    "cannot be given out to strangers who have not demonstrated their trust-\n"
    "worthiness.  After investing a fair amount of your time and energy in\n"
    "playing at Riftwar, you are less likely to try to hurt it.  This is\n"
    "why we cannot give out instant creatorships unless we know you from\n"
    "elsewhere.  Please try to be understanding about our policy.\n\n";

  age   = - ( (int) player->query_time_on() );
  level = (int)QUEST_HANDLER->query_player_fame(player->query_name());

  if ( ( level >= 20 ) && ( age > 432000 ) ) {
    write("  You have achieved the *minimum* requirements necessary to apply "
          "for a\n"
          "creatorship here.  You must now pass a review of the Lords "
          "to be\naccepted.\n"+ reasoning );
    return 1;
  }
  /*
    Player does not qualify.  Tell him why.
    */
  age_str = "";

  if ( age >  86400 ) 
    age_str += sprintf( "%d day" , age/86400 );
  if ( age > 172800 )
    age_str += "s";

  if ( age%86400 > 3600) {
    if ( age > 86400 )
      age_str += " and ";
    age_str += sprintf( "%d hour" , (age%86400)/3600 );
  }
  if ( age%86400 > 7200)  age_str += "s";

  write("  The *minimum* requirements to apply for a creatorship on here "
        "are\nto have completed 20% of the quests and an age of at least five "
        "days.\nYou have done " + level + "% of the quests and your age is "+
        age_str + ".\n" + reasoning );
  return 0;
} /* eligible_creator() */
