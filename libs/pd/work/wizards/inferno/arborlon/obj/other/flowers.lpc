// - Syphon  -
// Some flowers

#include <lib.h>

inherit OBJECT;

int smellable=0;

void init() {
    add_action("smell", "smell");
}

void create() {
::create();
  set_short("patch");
  set_name("a beautiful assortment of flowers");
  set_long(
          "This beautiful assorment of flowers is like nothing you've "
          "ever seen before. These flowers look pretty rare! This would "
          "make a great gift."
  );
  set_mass(10);
  set_value(3000);
  set_id(({"assortment of flowers", "flowers"}));
}

int smell(string str) {
   if (str=="flowers" && smellable<=3) {
      write(
        "The pleasant scent fills your body. You feel revitalized."
      );
      this_player()->add_hp(random(70));
      this_player()->add_sp(random(110));
      this_player()->add_mp(random(250));
      smellable++;
   return 1;
   }
}
