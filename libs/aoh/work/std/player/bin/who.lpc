/*--------------------------------------------------------------------------
 * /std/player/bin/who.c  --  The player's who command.
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 * TODO: Put the MUDNAME above all names and set it off nicely (Superj...!)
 */

#include <properties.h>
#include <daemons.h>
#include <msgclass.h>

#define WHO_PLAYERS 1
#define WHO_WIZARDS 2
#define WHO_ILLEGAL 8
#define WHO_SHORT   16

#define MAXIDLE     300

/*-------------------------------------------------------------------------*/
private int compareNames (object a, object b)

/* Compare the real names of the two objects for sort_array().
 */

{
  return ((({string})a->Query(P_REALNAME)||"") > (({string})b->Query(P_REALNAME)||""));
}

private string formatLine (string e, int pw )
{
  return sprintf(" | %-*s |\n",(pw>60)?pw-10:50, e);
}

/*-------------------------------------------------------------------------*/
public int main( string arg ) {
  int mode, imax, i, ic, uc, pw;
  object * ua;
  string ret, tx, * args;

  mode = 0;
  if ( arg ) {
    /* explode the args and cycle through them to get the modes */
    args = explode( arg, " " ) - ({ "" });
    for( i = 0; i < sizeof( args ); i ++ ) {
      switch(lower_case(args[i])) {
      case "w":
      case "wiz":
      case "wizard":
      case "wizards":
	mode |= WHO_WIZARDS;
	break;
      case "p":
      case "player":
      case "players":
	mode |= WHO_PLAYERS;
	break;
      case "s":
      case "short":
	mode |= WHO_SHORT;
	break;
      default:
	mode |= WHO_ILLEGAL;
	break;
      }
    }
  }
  else
    mode = WHO_WIZARDS | WHO_PLAYERS;

  /* illegal parameter - abort */
  if ( mode & WHO_ILLEGAL )
    return notify_fail( "who: unsupported option - see help who.\n" ), 0;

  /* let's check if one WHO_SHORT has been defined */
  if ( mode == WHO_SHORT )
    mode |= ( WHO_PLAYERS | WHO_WIZARDS );

  pw = ({int})this_player()->Query(P_PAGEWIDTH);
  ua = sort_array(users(), #'compareNames /*'*/ );
  ret = sprintf("\n /%*'-'s\\\n", (pw>60)?pw-8:52,"");
  imax = sizeof(ua);
  for (i = 0; i < imax; i++)
  {
    object u;
    int wu, ui;

    u = ua[i];
    wu = query_user_level(u);
    if ( ( ( mode & WHO_WIZARDS ) && wu ) || ( ( mode & WHO_PLAYERS ) && !wu))
    {
      ui = ({int})u->Query(P_INVIS);
      if (!ui || query_user_level(this_player()) )
      {
        if (ui)
          tx = "(" + capitalize(({string})u->Query(P_REALNAME)) + ")";
        else {
	  if ( mode & WHO_SHORT )
	    tx = capitalize(({string})u->Query(P_NAME));
	  else
	    tx = ({string})u->Short();
	}
        if (sizeof(tx))
        {
          string * lines;

          uc++;
          if (query_idle(u) > MAXIDLE )
            ic++;
          lines = explode(sprintf( "<%2s> %=-*s %c%c%c%c %-=25s\n"
                                 , wu ? "Wz"
                                      : to_string(({int})u->Query(P_LEVEL))
				 , (pw>60)?(pw-47):13
                                 , tx
                                 , (   query_input_pending(u)
                                    || query_editing(u)
                                    || ({int})u->Query(P_EDITING))
                                   ? 'E' : '.'
                                 , ({int})u->Query(P_NEWBIE_HELPER) ? 'N' : '.'
                                 , ({int})u->Query(P_AWAY) ? 'A' : '.'
                  	         , (query_idle(u) > MAXIDLE ) ? 'I' : '.'
                                 , "["+({string})COUNTRY_D->GetCountry(u, 1)+"]"
                                 )
                         , "\n")
                  - ({ "" }); /* lines = ... */
          ret += implode(map(lines, #'formatLine /*'*/, pw ), "");
        }
      } /* if (user visible to who'er) */
    } /* if (user to be displayed) */
  } /* for */

  if ( mode & ( WHO_WIZARDS | WHO_PLAYERS ) )
    tx = "user";
  else if ( mode & WHO_WIZARDS )
    tx = "wizard";
  else if ( mode & WHO_PLAYERS )
    tx = "player";
  else
    tx = "being"; /* should not happen .) */

  if (!uc || uc > 1)
    tx += "s";

  ret += sprintf(" \\%|'-'*s/\n"
		, (pw>60)?pw-8:52
                , sprintf(" %d %s online, %d idle at %s "
                         , uc, tx, ic, MUDNAME
                ));

  msg_write( CMSG_GENERIC|MMSG_MORE, ret );

  return 1;
}

/***************************************************************************/
