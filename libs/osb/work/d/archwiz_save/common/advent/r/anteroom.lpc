/* Advent - Anteroom -- Mateese, 23-Aug-96
 *
 * The Anteroom before Witt's End, accessible from Bedquilt and Complex
 * Junction.
 */

#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "advent.h"

inherit ADVENT("i/stdroom");

/*-----------------------------------------------------------------------*/
public void create()
{
  string msg;

  ::create();

  // Main description
  Set(P_INT_SHORT, "Anteroom");
  Set(P_INT_LONG,
"You are in an anteroom leading to a large passage to the east.  Small "
"passages go west and up. The remnants of recent digging are evident.\n"
"A sign hangs in midair.\n"
     );
  Set(P_BRIGHT, 0);

  // Exits
  AddExit("up", ADVENT("r/complexjunct"));
  AddExit("west", ADVENT("r/bedquilt"));
  AddExit("east", ADVENT("r/wittsend"));
  
  // Details
  msg = 
"  'Cave under construction beyond this point.\n"
"   Proceed at own risk.\n"
"   [Witt Construction Company]'\n"
      ;
  AddOrigDetail("sign", "A sign in midair here says:\n"+msg);
  AddReadMsg("sign", msg);
    
  // Items
  AddItem(ADVENT("o/spelunker"), REFRESH_REMOVE|REFRESH_HOME);
}

/*************************************************************************/
