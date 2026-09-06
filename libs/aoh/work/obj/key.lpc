/* /obj/key
**
** A standard key to clone or inherit.
**
**  05-Oct-92 [Mateese]
**  21-Jan-93 [Mateese] KeyCode now optional to allow generic keys.
**  25-Mar-94 [Deepthought] Keycode back in id() to allow use of keycode
**  18-Jul-94 [Mateese] Adapted for new lock mechanism.
**  09-Sep-94 [Mateese] Made P_IDS and P_KEYIDS more distinct.
*/

#define ME this_object()

#include <properties.h>

inherit "/std/thing";

private nosave string * Pkeyids;
private nosave mixed Pkeycode;

//-------------------------------------------------------------------------

public mixed SetKeyCode (mixed i) { return Pkeycode = i; }
public mixed QueryKeyCode() { return Pkeycode; }

public string * SetKeyIds (mixed ids) {
  return Pkeyids = pointerp(ids) ? ids : ({ ids });
}
public string * QueryKeyIds () { return Pkeyids; }
public string * AddKeyId (string ids) {
  if (!Pkeyids)
    Pkeyids = ({ ids });
  else if (-1 == member(Pkeyids, ids))
    Pkeyids += ({ ids });
  return Pkeyids;
}

//-------------------------------------------------------------------------
// id() has to recognize P_IDS as well as P_KEYIDS.

public int id (string str) {
  string *kids;

  return    thing::id(str)
         || (    sizeof(kids = QueryKeyIds())
              && member(kids, str) != -1
            )
        ;
}

//-------------------------------------------------------------------------
// Initialize us.

void create () {
  ::create();
  SetShort("a key");
  SetLong("A simple key.\n");
  SetValue(10);
  SetWeight(50);
  AddId("key");
  Set(P_HELP_MSG, 
"A key, which can be used to unlock or lock things like doors or chests with.\n"
     );
}

/*************************************************************************/
