#include <std.h>
#include <sindarii.h>
inherit DRINK;

void create() {
 ::create();
   set_name("special");
   set_short("special of the house");
   set_long("Made with great skill by the barkeep of The Dull and "
     "Rusty. Its ingredients are secret to all.");
   set_weight(1);
   set_strength(30);
   set_id(({ "special", "secret", "special of the house" }));
   set_empty_name("glass");
}

int drink_me(string str) {
   if (!str) return 0;
   if (present(str, this_player()) != this_object()) return 0;
//   new(OBJ"drunk")->move(this_player());
   return 0;
}

void init() {
 ::init();
   add_action("drink_me", "drink");
}
