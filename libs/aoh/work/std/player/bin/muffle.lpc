/*--------------------------------------------------------------------------
 * /std/player/bin/muffle.c  --  The muffle's color command.
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 */

#include <properties.h>
#include <msgclass.h>
#include <secure/wizlevels.h>

#define VALID_CLASSES ({ "channel", "fun" })

private string translate_class( int class ) {
  switch( class ) {
  case CMSG_CHANNEL:
    return "channel";
  case CMSG_FUN:
    return "fun";
  default:
    return "<"+to_string(class)+">";
  }
  return 0;
}

public int main( string arg ) {
  int * m, class;
  string tmp, tx, * ty;

  if ( ! arg ) {
    /* print out all classes that are muffled */
    if ( m = ({int *})this_player()->QueryClassMuffs() ) {
      tmp = "You currently do not listen to the following classes:\n";

      ty = map( m, #'translate_class /*'*/ );
      ty -= ({0});

      if ( sizeof( ty ) == 1 )
	tmp += ty[0];
      else
	tmp += implode( ty[0..<2], "," )+" and "+ty[<1];

      write( tmp+".\n" );
      return 1;
    }
    else {
      write( "You listen to everything.\n" );
      return 1;
    }
  }
  else {
    if ( ( sscanf( norm_id( arg ), "%s %s", tmp, tx ) != 2 ) ||
	 ( member( ({ "on", "off" }), tx ) == -1 ) )
      return notify_fail( "Usage: muffle <class> on/off\n" ), 0;

    if ( member( VALID_CLASSES, tmp ) == -1 ) {
      write( "Invalid class given. Valid classes are:\n"+
	     implode( VALID_CLASSES[0..<2], "," )+" and "+
	     VALID_CLASSES[<1]+".\n" );
      return 1;
    }

    switch( tmp ) {
    case "fun":
      class = CMSG_FUN;
      break;
    case "channel":
      class = CMSG_CHANNEL;
      break;
    default:
      write( "Panic! Terror! An Error!\n" );
      return 1;
    }

    if ( tx == "on" ) {
      this_player()->AddClassMuff( class );
      write( "You do not listen to class \""+tmp+"\" anymore.\n" );
    }
    else {
      this_player()->RemoveClassMuff( class );
      write( "You listen to class \""+tmp+"\" again.\n" );
    }

    return 1;
  }
}
