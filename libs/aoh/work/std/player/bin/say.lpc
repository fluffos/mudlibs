/*--------------------------------------------------------------------------
 * /std/player/bin/tell.c  --  The say command.
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 */

#include <properties.h>
#include <msgclass.h>
#include <macros.h>

void deliver_say( object ob, string txt, int flag ) {
  if ( ( interactive( ob ) ) &&
       ( ({int})ob->check_ignore( flag ? "converse" : "communicate",
			   this_player() ) <= 0 ) )
    return; /* we are ignored */

  msg_object( ob, CMSG_SAY, txt );
}

int main( string str ) {
  string verb;
  object *wiz, *other;

  verb = query_verb();
  if (verb[0] == "'"[0]) str = verb[1..] + (str ? " "+str : "");

  other = all_inventory(environment(this_player()))-({this_player()});

  if ( ({int})this_player()->Query(P_INVIS) ) {
    wiz = filter(other, SF(query_user_level) );
    if (!query_user_level(this_player()))
      wiz += filter_objects(other-wiz, "Query", P_SEE_INVIS);
    other = other - wiz;
  }

  if (str) {
    if ( ({int})this_player()->Query( P_ECHOMODE ) )
      msg_write( CMSG_SAY|MMSG_NOREPLY, "You say: "+str+"\n" );
    else
      msg_write( CMSG_SAY|MMSG_NOREPLY, "Ok.\n" );

    map( other,
	       SF(deliver_say),
	       ({string})this_player()->Query(P_NAME)+" says: "+str+"\n",0 );

    if (sizeof(wiz))
      map( wiz,
		 SF(deliver_say),
		 "("+({string})this_player()->Query(P_REALNAME)+") says: "+str+"\n",0 );
  }
  else {
    if ( ({int})this_player()->Query( P_ECHOMODE ) )
      msg_write( CMSG_SAY|MMSG_NOREPLY, "You say nothing.\n" );
    else
      msg_write( CMSG_SAY|MMSG_NOREPLY, "Ok.\n" );

    map( other,
               SF(deliver_say),
	       ({string})this_player()->Query(P_NAME)+" says nothing.\n", 0);

    if (sizeof(wiz))
      map( wiz,
		 SF(deliver_say),
		 "("+({string})this_player()->Query(P_REALNAME)+") says nothing.\n" ,0 );
  }
  return 1;
}

int converse( string arg ) {
  msg_write( CMSG_SAY, "Start talking. Give '**' or '.' to stop.\n" );
  msg_write( CMSG_SAY, "]" );
  this_player()->set_no_buffering( 1 );
  input_to("_converse_more");
  return 1;
}

void _converse_more( string str ) {
  this_player()->set_no_buffering( 1 );
  if (str == "**" || str == ".") {
    msg_write( CMSG_SAY|MMSG_DIRECT, "Ok.\n" );
    this_player()->set_no_buffering( 0 );
    return;
  }
  if (str && str != "") {
    map(all_inventory(environment(this_player()))-({this_player()}),
	      SF(deliver_say),
	      ({string})this_player()->Query(P_NAME) + " says: " + str + "\n", 1 );
  }
  msg_write( CMSG_SAY|MMSG_DIRECT, "]" );
  input_to("_converse_more");
}
