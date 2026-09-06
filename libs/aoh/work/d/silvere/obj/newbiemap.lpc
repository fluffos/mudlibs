// This is a map for the newbies of Silvere. It is given when a newbie
// leaves the ship and stays at the harbour. It has two pages: the
// harbour and the western part of the city of Silvere
// created:       Sonic [29-May-1997]


#include <silvere.h>
#include <properties.h>
#include <macros.h>
#include <config.h>
#include <moving.h>
inherit "/std/thing";

#define HARBOURMAP "/d/silvere/doc/maps/harbour.map"
#define SILVEREMAP "/d/silvere/doc/maps/silvere1.map"

int _read(string str)
{
   notify_fail("What do you want to read?\n", NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"map")!=-1 ||
      strstr(lower_case(str),"picture")!=-1)
   {
      write(
"There are two pictures on the map. one of the HARBOUR and one of\
 CITY. Maybe you should try to read them?\n");
      return 1;
   }
   if(strstr(lower_case(str),"harbour")!=-1)
   {
      write("You look at the picture of the harbour and see:\n");
      show(CAP(NAME(TP))+" looks curiously at a map.\n");
      TP->more(HARBOURMAP);
      return 1;
   }
   if(strstr(lower_case(str),"city")!=-1 ||
      strstr(lower_case(str),"silvere")!=-1)
   {
      write("You look at the picture of the harbour and see:\n");
      show(CAP(NAME(TP))+" looks curiously at a map.\n");
      TP->more(SILVEREMAP);
      return 1;
   }
}

void init()
{
  ::init();
  add_action("_read","read");
}

void create()
{
   ::create();
   Set(P_SHORT,"a small map of Silvere");
   Set(P_LONG,
"This is a small piece of paper. It has two small drawings written\
 on it. One shows the harbour, the other is the western part of\
 Silvere, where lots of shops, inns and other establishments can\
 be found. It could be interesting to read the map.\n");
   Set(P_IDS,({"map","silv_mmap"}) );
   Set(P_VALUE,10);
   Set(P_WEIGHT,250);
}

