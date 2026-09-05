#include "/obj/ansi.h"
/*
#define PLAN "/players/khrell/PLAN"
*/
#define PLAN "/open/pub_plans/earwax.plan"

void reset(status arg) {
  if (arg) { destruct(this_object()); return; }

  write_file(PLAN, HIR+"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n"+NORM+NORM);
  write_file(PLAN, "Responsible for: \nItem: "+HIK+"Legendary PK Tracker\n"+NORM+NORM+"Area: "+GRN+"Earwaxian National Guard Fields\n\n"+NORM+NORM);
  write_file(PLAN, "Current priority: recoding the "+HIK+"Servants of Shardak"+NORM+NORM+"\n\n");
  write_file(PLAN, HIK+"Servants of Shardak "+HIR+"Magi"+NORM+NORM+": \nJaraxle\nForbin\nLinus\nMosobp\n\nOriginal guild code by Dragnar, Balowski and Vertebraker.\n");
  write_file(PLAN, HIR+"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n"+NORM+NORM);
  destruct(this_object());
}
