/* Oglon Fur for Tune -- Mateese, 07-Feb-1996
 *
 * No bloody rings for my Elf!
 */

#include <properties.h>

inherit "/std/thing";

create()
{
  ::create();
  Set(P_SHORT, "a patch of Mateese's fur");
  Set(P_LONG,
({ "A small patch of the fur of Mateese. Expertly tanning kept its natural"
   "softness, charming on every touch.\n"
 , "Stitched into the leathery side is a small inscription:\n"
   "         -- Tune & Mateese - 08 Febr 1996 --\n"
})
         );
  Set(P_SMELL, 
"The smell creates visions of highlands and their unique beauty.\n"
     );
  Set(P_VALUE, 20);
  Set(P_WEIGHT, 10);
  AddId("fur");
  AddAdjective(({"patch of", "oglon"}));
  Set(P_NODROP, "You would have to destruct the fur.\n");
  Set(P_NOSELL, 1);
  Set(P_NO_QUITDROP, 1);
}

mixed QueryAutoObject() {
  if (this_player() && query_once_interactive(this_player()) 
  &&  getuid(this_player()) == "tune")
    return Query(P_EXTRALOOK) || 1;
}

mixed SetAutoObject(mixed m) {
  if (stringp(m))
    Set(P_EXTRALOOK, m);
}
