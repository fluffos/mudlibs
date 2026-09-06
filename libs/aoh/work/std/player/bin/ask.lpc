/* -------------------------------------------------------------------------
 * /std/player/bin/ask.c  --  The ask command.
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 * -------------------------------------------------------------------------
 */

#include <msgclass.h>
#include <search.h>
#include <macros.h>

int main( string str ) {
  string whom, what;
  object tgt;

  notify_fail("Ask whom about what?\n", NOTIFY_NOT_OBJ);
  if (!str || !stringp(str))
    return 0;

  /* make the input more flexible by stripping of multiple blanks
   * and converting all characters in lower case chars
   */
  str = norm_id(str);

  if (    !str[0]
       || (   2 != sscanf(lower_case(str), "%s about %s", whom, what)
           && 2 != sscanf(lower_case(str), "%s for %s", whom, what)
          )
     )
    return 0;

  if ( ! tgt = ({object})TP->Search(whom, SEARCH_ENV_INV|SEARCH_OBJECT|SEARCH_IGNLIGHT))
     return 0;

  if ( ! living( tgt ) )
    return notify_fail( "That does not live.\n" ), 0;

  if ( interactive( tgt ) )
    return notify_fail( "For now, use tell to talk to players.\n" ), 0;

  /* send an ask message to the tgt and let it do the rest */
  msg_object( tgt, CMSG_ASK, what );
  return 1;
}
