/*--------------------------------------------------------------------------
 * /std/player/bin/messages.c  --  The messages command.
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 */

#include <properties.h>
#include <msgclass.h>
#include <daemons.h>
#include <macros.h>

#define VALID_CLASSES ({ "tell", "channel", "emote", "say" })

private void show_settings( int * tx ) {
  if ( tx ) 
    msg_write( CMSG_GENERIC, 
               "Message-history enabled for classes "+
               implode( map( tx, lambda( ({ SYM(x) }),
                                               ({ SF( call_other ), 
                                                    COLOUR_D, 
                                                    "ClassToString", 
                                                    SYM(x) }) ) ), ", " ) +
               ".\n" );
  else
    msg_write( CMSG_GENERIC, 
               "Message-history disabled.\n" );
}

public int main( mixed arg ) {
  int num;

  if ( ! arg )
    arg = "";

  arg = explode( norm_id( arg ), " " );

  if (    ( num = to_int( arg[0] ) )
       || arg[0] == "" ) {
    if ( sizeof( arg = arg[1..] ) ) {
      /* if classes are given, filter them through the closure based on
       * VALID_CLASSES
       */
      arg = filter( arg, lambda( ({ SYM(x) }),
                                       ({ SF_NEQUAL,
                                            ({ SF(member), 
                                                 quote( VALID_CLASSES ), SYM(x) }),
                                            -1 }) ) );
      
      /* convert class strings to integers 
       */
      arg = map( arg, lambda( ({ SYM(x) }),
                                    ({ SF( call_other ), COLOUR_D, 
                                         "StringToClass", SYM(x) }) ) );

      /* remove error entries if any
       */
      arg -= ({ -1 });
    }

    /* call SendMsgHistory function and we are finished
     */
    TP->SendMsgHistory( num, sizeof(arg)?arg:0 );

    return 1;
  }
  else if ( arg[0] == "show" ) {
    show_settings( ({int *})TP->Query( P_CLASS_HISTORY ) );
    return 1;
  }
  else if ( arg[0] == "?" ) {
    msg_write( CMSG_GENERIC,
               "Usage: messages [num] [classes]\n"
               "        Show the buffer, optional number of messages to show\n"
               "        and classes which should be shown only.\n"
               "       messages <nothing|tell|say|channel|emote>\n"
               "        Set the types of messages that should be in the\n"
               "        history. nothing disables history.\n"
               "       messages show\n"
               "        Show the current config.\n"
               "       messages ?\n"
               "        This help.\n" );
    return 1;
  }
  else {
    int i, tc;
    int * tx;

    tx = ({int *})TP->Query( P_CLASS_HISTORY )||({});

    for( i = 0; i < sizeof( arg ); i ++ ) {
      if ( arg[i] == "nothing" ) 
        tx = ({});
      else {
        tc = ({int})COLOUR_D->StringToClass( arg[i] );
        if ( tc == -1 ) {
          msg_write( CMSG_GENERIC, "Unknown class \""+arg[i]+"\".\n" );
          return 1;
        }
        if ( member( tx, tc ) == -1 )
          tx += ({ tc });
      }
    }
    if ( ! sizeof( tx ) ) {
      tx = 0;
      TP->Set( P_MSG_HISTORY, 0 ); /* free mem */
    }

    TP->Set( P_CLASS_HISTORY, tx );

    show_settings( tx );

    return 1;
  }
  return 1;
}
