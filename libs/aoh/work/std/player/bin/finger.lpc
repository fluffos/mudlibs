/*--------------------------------------------------------------------------
 * /std/player/bin/finger.c  --  The player's finger command.
 *
 * Copyright (C) 1997, 1998 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 * CHANGES
 *  06/07/98 [Mica] Fixed "Someone" bug (P_REALNAME is now used)
 *  06/28/98 [Mica] implemented features.h
 */

#pragma strict_types

#include <daemons.h>
#include <properties.h>
#include <secure/wizlevels.h>
#include <inetd.h>
#include <living.h>
#include <msgclass.h>
#include <string.h>
#include <features.h>
#include <i3.h>

inherit L_STRING;

#define PLAYER_DUMMY "/obj/player_dummy"

/* only show extended output to wizards with wizmode on */
#define IS_TRUE_WIZARD(x) (IS_IMMORTAL(x)&&(!({int})x->Query(P_NOWIZ)))

#define HBINT         2   /* interval between two heart_beats in seconds    */
#define MINIDLE      300   /* minimum idle time in seconds to be stated idle */
#define LORDSTR(g)  (g==GENDER_MALE ? "Lord" : "Lady") /* We HAVE female Lords !!! */

private string dtime(int time) {
  string ret;

  ret = "";
  if( time >= 86400) {
    ret += time/86400+"d ";
    time %= 86400;
  }
  if (time < 36000) ret += "0";
  ret += time/3600+":";
  time %= 3600;
  if (time < 600) ret += "0";
  ret += time/60+":";
  time %= 60;
  if (time < 10) ret += "0";
  ret += time+"";
  return ret;
}

/* Intermud-3 finger query
 * TODO: fill in all values for the FingerData
 */

public mixed * GetIntermud3FingerData( string str ) {
  mixed * res;
  object tgt;
  mapping props;

  if ( ! str )
    return 0;

  if ( ( tgt = find_player( str ) ) &&
       ( ({int})tgt->Query( P_INVIS ) ) )
    return 0;

  props = ({mapping})load_object(PLAYER_DUMMY)->QueryProperties( str );
  if ( ! sizeof( props ) )
    return 0;

  res = allocate( 9 );
  res[0] = capitalize( props[P_REALNAME] );
  res[1] = props[P_PRESAY]+props[P_NAME]+" "+props[P_TITLE];
  res[2] = 0; /* we not not provide the RL-name currently */
  res[3] = 0; /* we do not give away the email */

  if ( tgt ) {
    if ( ! interactive( tgt ) ) {
      res[4] = ctime( props[P_NETDEAD] );
      res[5] = -1;
    }
    else {
      res[4] = ctime( props[P_LAST_LOGIN] );
      res[5]= query_idle( tgt );
    }
  }
  else {
    res[4] = ctime( props[P_LAST_SAVE] );
    res[5] = -1;
  }

  res[6] = 0; /* no ip name currently */
  res[7] = query_user_level( str ) ? "Wizard" : sprintf( "Player at Level %d", props[P_LEVEL] );
  res[8] = 0;

  return res;
}


/* ---------------------------------------------------------------------------
 * MakeFingerString - this creates the actual string
 *  The optional argument is used to check the wizlevel for the things that
 *  should only be printed for wizards if it is an object, otherwise 1 will
 *  result in wizard, 0 in player output
 * ---------------------------------------------------------------------------
 */

public varargs string MakeFingerString( string str, mixed pli ) {
  mapping props;
  mixed * userinfo;
  int tx, pos;
  string ret, ts, *data, filename;
  object tgt;
  int is_true_wizard;

  if ( ! str )
    return 0;

  if ( objectp( pli ) )
    is_true_wizard = IS_TRUE_WIZARD( pli );
  else if ( intp( pli ) )
    is_true_wizard = pli;
  else
    is_true_wizard = 0;

  /* we use the dummy player object to access the user data */
  props = ({mapping})load_object(PLAYER_DUMMY)->QueryProperties( str );
  if ( ! sizeof( props ) ) {
    /* check if user is a retired wizard, i.e. secure-savefile exists */
    /* query_user_level does that for us */
    if ( tx = query_user_level( str ) )
      return capitalize( str )+ "is a retired wizard of " MUDNAME ".\n";
    else
      return "This player does not exist at " MUDNAME ".\n";
  }

  /* check if the user is on, netdead or out */
  /* handle invis as logged out for players */
  ret = props[P_PRESAY]+capitalize(props[P_REALNAME])+" "+props[P_TITLE]+"\n";
  if ( ( tgt = find_player( str ) ) &&
       ( ( ! ({int})tgt->Query( P_INVIS ) ) ||
	 ( is_true_wizard ) ) ) {
    if ( ! interactive( tgt ) ) {
      ret +=
	capitalize(props[P_PRONOUN]) + " is netdead since " +
	ctime( props[P_NETDEAD] ) +" ("+dtime(time()-props[P_NETDEAD])+")";
      if ( is_true_wizard ) {
	ret += " in ";
	if ( props[P_NETDEAD_ROOM] )
	  ret += props[P_NETDEAD_ROOM];
	else if ( environment( tgt ) )
	  ret += object_name( environment( tgt ) );
	else
	  ret += "the middle of nowhere";
      }
      ret += ".\n";
      ret += capitalize(props[P_PRONOUN])+ " was logged in from ";

      ret += ({string})COUNTRY_D->GetCountry( props[P_CALLED_FROM_IP], 1 );

      if ( is_true_wizard )
	ret += " ("+props[P_CALLED_FROM_IPNAME]+")";

      ret += ".\n";
    }
    else {
      ret +=
	capitalize(props[P_PRONOUN]) + " is logged on since " +
	ctime( props[P_LAST_LOGIN] ) +" ("+
        dtime(time()-props[P_LAST_LOGIN])+").\n";

      ret += capitalize(props[P_PRONOUN]) + " is logged on from ";

      ret += ({string})COUNTRY_D->GetCountry( tgt, 1 );

      if ( is_true_wizard ) {
	ts = query_ip_name(tgt);
	ret += " ("+query_ip_name(tgt);
	if ( sscanf( ts, "%~d.%~d.%~d.%~d" ) != 4 )
	  ret += " ["+query_ip_number(tgt)+"]";
	ret += ")";
      }

      ret += ".\n";

      if ( props[P_AWAY] )
	ret += capitalize(props[P_PRONOUN])+" is away, "+props[P_AWAY]+".\n";

      if ( ( tx = query_idle(tgt) ) > MINIDLE ) {
	ret += capitalize(props[P_PRONOUN])+" is idle";
	if ( is_true_wizard )
	  ret += " for "+dtime(tx);
	ret +=".\n";
      }
    }

    ret += "The first login was ";
    if (props[P_FIRST_LOGIN])
      ret += "on "+stime(props[P_FIRST_LOGIN], SD_DATE);
    else
      ret += "before 27-Apr-1998";
    ret += ".\n";

    if ( is_true_wizard ) {
      if ( props[P_LSTATE] == LSTATE_GHOST )
	ret += capitalize(props[P_PRONOUN])+" is currently a ghost.\n";
    }
  }
  else {
    ret +=
      capitalize(props[P_PRONOUN])+ " has logged out at "+
      ctime( props[P_LAST_SAVE] ) +" ("+dtime(time()-props[P_LAST_SAVE])+")"+
      ".\n"+capitalize(props[P_PRONOUN])+ " was logged in from ";

    ret += ({string})COUNTRY_D->GetCountry( props[P_CALLED_FROM_IP], 1 );

    if ( is_true_wizard )
      ret += " ("+props[P_CALLED_FROM_IPNAME]+")";

    ret += ".\n";
    ret += "The first login was ";
    if (props[P_FIRST_LOGIN])
      ret += "on "+stime(props[P_FIRST_LOGIN], SD_DATE);
    else
      ret += "before 27-Apr-1998";
    ret += ".\n";

  }

  /* age and race */
  ret +=
    capitalize(props[P_PRONOUN])+" is " +dtime(HBINT*props[P_AGE])+
    " old and belongs ";
  if ( props[P_RACE] ) {
    ret +=
      "to the race of "+props[P_RACE]+
      ( ( props[P_RACE][<1] == 's' ) ? "" : "s" )+".\n";
  }
  else
    ret += "to the raceless.\n";

  /* level/wiztag and guild */

  ret +=
    capitalize(props[P_PRONOUN])+" is a ";
  if ( query_user_level( str) )
    ret += "wizard";
  else
    ret += "player at level "+to_string(props[P_LEVEL]);
  ret += " and member ";
  if ( ( props[P_GUILD] ) && lower_case(props[P_GUILD]) != "none" )
    ret += "of the guild of "+props[P_GUILD]+
      ( ( props[P_GUILD][<1] == 's' ) ? "" : "s" )+".\n";
  else
    ret += "of no guild.\n";

  if ( is_true_wizard ) {
    if ( ( props[P_MAILADDR] ) &&
	 ( props[P_MAILADDR] != "none" ) &&
         ( props[P_MAILADDR] != "" ) )
	ret +=
	  capitalize(props[P_POSSESSIVE])+" email address is "+
	  props[P_MAILADDR]+".\n";
    else
      ret +=
	capitalize(props[P_PRONOUN])+" did not provide "+
	props[P_POSSESSIVE]+" email address.\n";
  }

  /* domain data */
  /* TODO:  domain data is taken from find_userinfo */
  /* TODO:: there should be a daemon one can query the domain data */

  if ( ( userinfo = ({mixed *})MASTER->find_userinfo( str ) ) &&
       ( sizeof( data = userinfo[3] ) ) ) {
    ret +=
      capitalize(props[P_PRONOUN])+" has the following domain positions:\n";

    for(pos=0; pos<sizeof(data); pos++) {
      if(pos)
	ret += ", ";
      switch(data[pos][0]) {
      case '+': ret += "Vice ";
      case '*': ret += LORDSTR(props[P_GENDER])+" of "
		  +capitalize(data[pos][1..]);
      break;
      default: ret += "Member of "+capitalize(data[pos]);
      }
    }
    ret += ".\n";
  }

  if ( query_user_level( str ) ) {
    filename="/players/"+str+"/.project";
    if(file_size(filename)>=0)
      ret +=
	capitalize(props[P_POSSESSIVE])+" project is: "+
	explode(read_file(filename), "\n")[0]+"\n";
  }

  if ( ( is_true_wizard ) &&
       ( query_user_level(str) ) ) {
    filename="/players/"+str+"/.plan";
    if(file_size(filename) <= 0)
      ret += capitalize(props[P_PRONOUN])+" currently has no plan(s).\n";
    else if(file_size(filename) > 32767)
      ret += capitalize(props[P_PRONOUN])+" has really much plans.\n";
    else
      ret +=
        /* capitalize(props[P_PRONOUN])+" has the following plan(s):\n"+ */
        "\n"+
	read_file(filename);
  }

  return ret;
}

public int main( string str ) {
  string user, mud;
  string err;


  if (!str)
   return notify_fail("Syntax: 'finger <player>[@<mud>]'\n"), 0;

  str = implode(explode(str, " ")-({""})," ");

  if (str == "" )
    return notify_fail("Syntax: 'tfinger <player>[@<mud>]'"), 0;

  /* intermud finger? */
  if (2 == sscanf(str, "%s@%s", user, mud)) {
#ifdef FEATURES_INTERMUD3
    if ( err = ({string})I3_TOOL("mudlist")->mud_find( mud ) ) {
      I3_TOOL("finger")->send_finger_request(
                          lower_case(user),
                          err,
                          ({string})this_player()->Query(P_REALNAME));
    }
    else
#endif
         if ( err = ({string})INET_D->send_packet(lower_case(mud), ([
					 I2H_REQUEST: "finger",
					 I2H_SENDER: ({string})this_player()->Query(P_REALNAME),
					 I2H_DATA: lower_case(user)
    ]), 1) ) {
      msg_write( CMSG_GENERIC, err );
      return 1;
    }

    msg_write( CMSG_GENERIC, "Finger request sent.\n");
    return 1;
  }

  msg_write( CMSG_GENERIC|MMSG_MORE, MakeFingerString( str, this_player() ) );

  return 1;
}
