/* -------------------------------------------------------------------------
 * basic room for the osb domain
 * -------------------------------------------------------------------------
 * 26-May-97 [MagicTcs]  Creation
 * 29-May-97 [Mica]      Added P_INT_WIZMSG, removed search-command
 * ??-Jun-97 [Sonic]     Moved P_MAP to /std/room.c
 * 16-Jun-97 [Tune]      Added TimeMsg()
 * 10-Jul-97 [Sonic]     Added handling of Windows
 * 13-Jul-97 [Sonic]     Added transparency and cleaning to the windows
 * -------------------------------------------------------------------------
 */

#include <properties.h>
#include <msgclass.h>
#include <moving.h>
#include <macros.h>
#include <nightday.h>
#include <sykorath.h>

inherit "/std/room";
/*
inherit "/d/sykorath/std/vget";          // get support
inherit "/d/sykorath/std/vdrink";        // drink support
inherit "/d/sykorath/std/vfood";         // food support
*/

// replaced by maproom:
//inherit "/d/sykorath/std/maproom";

/* -------------------------------------------------------------------------
 * IntLong handles P_INT_WIZMSG property
 * -------------------------------------------------------------------------
 */

public varargs string IntLong(string what)  {
  string s, w;
  
  if ( ! ( s = ::IntLong(what) ) )
    return s;
  
  if ( ( TP ) &&
       ( query_user_level( TP ) ) &&
       ( ! TP->Query( P_NOWIZ ) ) &&
       ( w = Query( P_INT_WIZMSG ) ) )
    return s + "\n" + w;
  else
    return s;
}

/* -------------------------------------------------------------------------
 * TimeMsg - This allows you to add extra text to rooms which is time-based
 *  To use it, embed this into your long description: @@TimeMsg@@
 *  Then add a property P_TIME_MSG which is a mapping of strings.
 * -------------------------------------------------------------------------
 */

public string TimeMsg() {
  int state;
  string s;
  
  state = NIGHTDAY->QueryState();
  
  if(s = Query(P_TIME_MSG)[state])
    return s;
  else if(NIGHTDAY->IsDay() && (s = Query(P_TIME_MSG)[DAY_DEFAULT_MSG]))
    return s;
  else if(s = Query(P_TIME_MSG)[NIGHT_DEFAULT_MSG])
    return s;
  return "";
}

/* ********************************************************************** */

create() {
  ::create();
/*
  AddRoomCmd("get",  "cmd_get_vitem");
  AddRoomCmd("take", "cmd_get_vitem");
  AddRoomCmd("drink","cmd_drink_vitem");
  AddRoomCmd("eat",  "cmd_eat_vitem");
*/
}

// special reset
reset() {
  "room"::reset();
/*
  "vget"::reset();
  "vdrink"::reset();
  "vfood"::reset();
*/
}

