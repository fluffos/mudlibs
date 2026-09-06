// this is a little sign to be dropped. Used by me as a warning for
// players :-)
// created:          Sonic    [29-Jul-1997]
// last changed:     not yet

#include <properties.h>
#include <macros.h>
#include <silvere.h>
inherit "/std/thing";

void create()
{
  ::create();
  Set(P_IDS, ({"sign"}) );
  Set(P_ADS, ({"red","large"}) );
  Set(P_SHORT,"a large red sign");
  Set(P_LONG,
"This is a large sign, placed on the road. The sign is painted "
"in a dark, red color. Written in black letters are the words:\n"
"                     MAN\n"
"                      AT\n"
"                     WORK\n"
"on it.\n");

  Set(P_NOGET,1);
  Set(P_NOSELL,1);
  Set(P_WEIGHT,3000);
  Set(P_READ_MSG,
"             MAN      AT       WORK\n\n"
"Warning! Due to some construction works, the rooms behind that "
"place may be a little bit unstable from time to time. On the other "
"hand, details can appear in a second. With other words: There is a "
"wizard at work.\n");
}
