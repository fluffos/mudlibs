#include "/players/redsexy/guild/obdefs.h"
#include "/players/redsexy/guild/formulae.h"
#include "/players/redsexy/guild/functions.h"
#include "/players/redsexy/guild/arrays.h"

int original;

id(arg) { return arg == "smokeobject"; }

get() { return 1; }

set_master() {
  original = TP->query_n_ac();
  TP->set_n_ac(original + SMOKE_AC);
  call_out("dissolve", SMOKE_TIME);
  return 1;
}

dissolve() {
  write("The smoky cloud around you dissipates.\n");
  say("The smoky cloud surrounding " + TP->NAME + " dissipates.\n");
  TP->set_n_ac(original);
  destruct(TO);
  return 1;
}

extra_look() {
  return "A smoky haze surrounds " + TP->OBJ;
}
