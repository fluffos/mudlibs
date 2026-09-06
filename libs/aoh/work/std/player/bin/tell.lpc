/*--------------------------------------------------------------------------
 * /std/player/bin/tell.c  --  The tell command.
 *
 * Copyright (C) 1997, 1998 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 * CHANGES
 *  06/28/98 [Mica] implemented features.h
 */

#include <msgclass.h>
#include <properties.h>
#include <daemons.h>
#include <secure/udp.h>
#include <secure/wizlevels.h>
#include <features.h>
#include <driver/object_info.h>
#include <i3.h>

/*
 *--------------------------------------------------------------------------
 * some private helpfuns
 *--------------------------------------------------------------------------
 */

private string atconcat( string * x ) {
  return capitalize(x[0])+"@"+x[1];
}

private string name_w( object x ) {
  if ( ({int})x->Query( P_INVIS ) )
    return "("+capitalize(({string})x->Query(P_REALNAME))+")";
  else
    return ({string})x->Query( P_NAME );
}

private string name_p( object x ) {
  if ( ({int})x->Query( P_INVIS ) )
    return 0;
  else
    return ({string})x->Query( P_NAME );
}

/* -------------------------------------------------------------------------
 * the main tell handler, called by 'tell' and 'reply'
 * -------------------------------------------------------------------------
 */

int main ( string str ) {
  object ob;
  object * lt; /* local recipients */
  mixed * mt; /* mudlink recipients, arrays ({ user, mud }) */
  string user, mud; /* temp data for mudlink */
  string * usr; /* user-list realnames */
  int i, j; /* counter vars */
  mixed * tmp; /* temp array */
  mixed tmp2;
  string btext, wbtext, * whos, name, msg;
  string txt;
  string * rn; /* names of the tell targets */

  if ( query_verb() == "reply" ) {
    if ( !str )
      str = "nothing";

    msg = str;
    name = "back";
  }
  else {
    if (!str) str = "me nothing";

    if ( ( sscanf( str, "\"%s\" %s", name, msg ) != 2 ) &&
         ( sscanf( str, "%s %s", name, msg ) != 2 ) ) {
      notify_fail("tell whom what?\n"); return 0;
    }
  }

  if (!stringp(name))
    return 0;

  if ( ({int})this_player()->Query( P_INVIS ) ) {
    btext = ({string})this_player()->Query(P_NAME);
    wbtext =
      "("+({string})this_player()->Query(P_PRESAY)+
      capitalize( ({string})this_player()->Query( P_REALNAME ) )+")";
  }
  else if (lower_case( ({string})this_player()->Query(P_NAME)) != ({string})this_player()->Query(P_REALNAME)) {
    btext = ({string})this_player()->Query(P_NAME);
    wbtext =
      ({string})this_player()->Query(P_NAME)+" ("+
      ({string})this_player()->Query(P_PRESAY)+
      capitalize( ({string})this_player()->Query(P_REALNAME))+")";
  }
  else
    btext = wbtext =
      ({string})this_player()->Query(P_PRESAY)+({string})this_player()->Query(P_NAME);

  if (! ({int})this_player()->Query(P_FROG)) {
    wbtext += " tells ";
    btext += " tells ";
  }
  else {
    wbtext += " croaks to ";
    btext += " croaks to ";
  }

  if ( name == "back" ) {
    whos = ({string *})this_player()->Query(P_TELL_REPLYTO);
    if ( ! pointerp( whos ) ) {
      msg_write( CMSG_GENERIC, "Sorry, you did not receive any tell to reply on.\n" );
      return 1;
    }
  }
  else if ( name == "same" ) {
    whos = ({string *})this_player()->Query(P_TELL_RECIPIENTS);
    if ( ! pointerp( whos ) ) {
      msg_write( CMSG_GENERIC, "Sorry, you did not tell anybody yet.\n" );
      return 1;
    }
  }
  else {
    /* initialize targets array */
    whos = explode( name, "," ) - ({ "" });
  }

  /* initialize our vars */
  lt = ({ }); mt = ({ }); usr = 0; rn = ({ });

  for( i = 0; i < sizeof( whos ); i ++ ) {
    /* invalid string check */
    if ( ! sizeof( whos[i] ) )
      continue;

    /* lower case it */
    whos[i] = lower_case( whos[i] );

    /* look for intermud-tell and add it to the mt array */
    if ( sscanf( whos[i], "%s@\"%+s\"", user, mud ) == 2
      || sscanf( whos[i], "%s@'%+s'", user, mud ) == 2
      || sscanf( whos[i], "%s@%s", user, mud ) == 2 ) {
      mt += ({ ({ user, mud }) });
      rn += ({ whos[i] });
      continue;
    }

    /* try to find the target */
    if ( ! ob = ( find_player(whos[i]) ||
    find_living(whos[i]) ) ) {
      /* not found, try if it is an abbreviated name */

      /* if we did not already initialise usr-array for abbrev checking */
      if ( ! usr ) {
  tmp = users();
  if ( ! IS_IMMORTAL( this_player() ) )
    tmp -= filter_objects( tmp, "Query", P_INVIS );
  usr = map_objects( tmp, "Query", P_REALNAME );
  usr -= ({ 0 });
      }

      tmp = ({});
      for (j = sizeof( usr ); j--; ) {
  if ( ! strstr( usr[j], whos[i] ) ) {
    if ( whos[i] != usr[j] )
      tmp += ({ usr[j] });
  }
      }

      switch( sizeof( tmp ) ) {
      case 1:
  if ( ob = find_living( tmp[0] ) )
    break;
  /* fallthough */
      case 0:
  write( "No living named '"+capitalize(whos[i])+"' found.\n");
  break;
      default:
  tmp = map( tmp, #'capitalize /*'*/ );
  write("Who is '"+whos[i]+"': ");
  if (sizeof(tmp) > 1)
    write(implode(tmp[0..<2], ", ")+" or ");
  write(tmp[<1]+"?\n");
  break;
      }
    }

    /* we found a player, a living or an abbreviated player */
    if ( ob ) {
      /* check for netdead and ignore */
      if (!interactive(ob) && query_once_interactive(ob))
  write( capitalize(({string})ob->Query(P_REALNAME))+" is currently netdead.\n" );
      else if ( ( ! interactive( ob ) ) ||
  ( ({int})ob->check_ignore( "tell", this_player() ) > 0 ) ) {
  lt += ({ ob }); /* add to local recipients */
        rn += ({ ({string})ob->Query( P_REALNAME ) });
      }
      else {
  /* write proper message for ignore */
  if ( ! IS_IMMORTAL( this_player() ) && ({int})ob->Query( P_INVIS ) )
    write( "No living named '"+capitalize(whos[i])+"' found.\n");
  else
    write( capitalize(({string})ob->Query(P_REALNAME))+" ignores you.\n" );
      }

      /* for invisible targets and player tells fake not found */
      if ( ! IS_IMMORTAL( this_player() ) && ({int})ob->Query(P_INVIS ) )
  write( "No living named '"+capitalize(whos[i])+"' found.\n");
    }
  }

  /* handle intermud tells first */
  for( i = 0; i < sizeof( mt ); i ++ ) {
#ifdef FEATURES_INTERMUD3
    if ( txt = ({string})I3_TOOL("mudlist")->mud_find( mt[i][1] ) ) {
      I3_TOOL("tell")->send_tell( mt[i][0], txt, msg, this_player() );
    }
    else {
#endif
      if ( tmp2 = ({mixed})INET_D->send_packet( mt[i][1],
                                   ([
                                     REQUEST: "tell",
                                     RECIPIENT: mt[i][0],
                                     SENDER: ({string})this_player()->Query( P_REALNAME ),
                                     DATA: msg
                                    ]), 1) ) {
      write( "Intermud tell to "+atconcat(mt[i])+" failed with error: "+tmp2 );
      mt[i] = 0;
      }
#ifdef FEATURES_INTERMUD3
    }
#endif
  }

  /* remove error entries */
  mt -= ({ 0 });
  rn -= ({ 0 });

  /* write apropriate message */
  if ( i = sizeof( mt ) ) {
    write( "Intermud tell"+(i>1?"s":"")+" to " );
    switch( i ) {
    case 1:
      write( atconcat( mt[0] ) );
      break;
    default:
      tmp = map( mt, #'atconcat /*'*/ );
      write( implode( tmp[0..<2], ", " ) + " and "+tmp[<1] );
      break;
    }
    write( " sent.\n" );
  }

  /* handle local recipients */
  for( i = 0; i < sizeof( lt ); i ++ ) {
    ob = lt[i];

    if (IS_IMMORTAL(ob)) {
      tmp = map( lt - ({ ob }), #'name_w /*'*/ );
      tmp += map( mt, #'atconcat /*'*/ );
      tmp -= ({ 0 });

      if ( sizeof(tmp) )
        txt = wbtext+implode( tmp, ",")+" and ";
      else
        txt = wbtext;
    }
    else {
      tmp = map( lt - ({ ob }), #'name_p /*'*/ );
      tmp += map( mt, #'atconcat /*'*/ );
      tmp -= ({ 0 });

      if ( sizeof ( tmp ) )
  txt = btext+implode( tmp, "," )+" and ";
      else
  txt = btext;
    }

    ob->receive_msg( CMSG_TELL, this_player(), txt+"you: "+msg+"\n" );
    ob->Set( P_TELL_REPLYTO, ( rn -
                               ({ ({string})ob->Query(P_REALNAME) }) +
                               ({ ({string})this_player()->Query(P_REALNAME) }) ) );

    if ( ! IS_IMMORTAL( this_player() ) && ({int})ob->Query( P_INVIS ) )
      lt[i] = 0;
  }

  /* remove 0'ed invisible target entries */
  lt -= ({ 0 });

  /* set our last tell names */
  this_player()->Set( P_TELL_RECIPIENTS, rn );

  /* write the nobody message or echo the tell */
  if ( ! sizeof( lt ) && ! sizeof( mt ) )
    write("Nobody listened.\n");
  else if ( sizeof( lt ) ) { /* only echo messages that go to local recp */
    txt = "You told ";

    if (IS_IMMORTAL(this_player()))
      tmp = map( lt, #'name_w /*'*/ );
    else
      tmp = map( lt, #'name_p /*'*/ );

    tmp += map( mt, #'atconcat /*'*/ );
    tmp -= ({ 0 });

    if ( sizeof( tmp ) > 1 )
      txt += implode( tmp[0..<2], ",")+" and "+tmp[<1];
    else if ( sizeof( tmp ) )
      txt += tmp[0];

    if ( ({int})this_player()->Query( P_ECHOMODE ) )
      msg_write( CMSG_TELL|MMSG_NOREPLY, txt+": "+msg+"\n" );
    else
      msg_write( CMSG_TELL|MMSG_NOREPLY, "Ok.\n" );
  }

  /* finally done */
  return 1;
}
