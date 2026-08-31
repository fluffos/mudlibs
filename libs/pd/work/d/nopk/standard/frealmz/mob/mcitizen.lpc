// Male shapeshifter citizen
#include <std.h>
inherit MONSTER;

void create() {
 int x;

 ::create();
   set_short("a strange citizen");
   set_id(({ "citizen", "clone", "beast" }));
   set_name("a citizen");
   set_level(random(30));
   set_long("This hidious man has the eyes of a cat, "
            "wings of a roc, and other horrible body "
            "parts. He bares his spider fangs and "
            "crouches in a defensive pose.");
   set_body_type("human");
   x = random(10);
   switch(x) {
      case 1:
        set_race("beast");
        set("aggressive", 300);
        break;
      case 2:
        set_race("clone");
        set("aggressive", 1);
        break;
      case 7:
        set_race("human");
        set("aggressive", 8);
        break;
      default:
        set_race("monster");
        set("aggressive", 17);
        break; 
  }
   set_gender("male");
}
