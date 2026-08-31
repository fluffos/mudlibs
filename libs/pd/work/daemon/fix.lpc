
#include <std.h>

inherit DAEMON;

mapping fixes;

void fix_me(object pl);

void create() {
  ::create();
  fixes = ([
    "clean1" : 1177723864,
  ]);
}

void fix_me(object pl) {
  int last = pl->query_property("last update") || 0;
  int flag = 0;

  foreach (string fix, int time in fixes) {
    message("info", fix+" "+(string)time, pl);
    if (time > last) {
      flag = 1;
      switch (fix) {
        
        case "clean1":
          pl->remove_property("vigor");
          pl->remove_property("riposte");
          pl->remove_property("iceblast_wait");
          pl->remove_property("paralyze_spell");
          pl->remove_property("wearing_healing_ring");
          pl->remove_property("watching_fmv");
        break;
        
        default:
      }
    }
  }

  if (flag) {
    pl->remove_property("last update");
    pl->set_property("last update", time() );
  }

}


