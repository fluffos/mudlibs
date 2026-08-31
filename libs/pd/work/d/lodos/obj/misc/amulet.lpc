#include <std.h>
inherit OBJECT;
 
void create() {
 ::create();
   set_name("amulet");
   set_short("a ruby amulet");
   set_long("The amulet is made of gold with a dark ruby afixed in "
      "the center of it. A dark mist swirls inside of the ruby piece. "
      "For some reason you have an urge to touch the ruby.");
   set_weight(2);
   set_curr_value("gold", 150);
   set_id(({ "amulet", "ruby amulet", "gold amulet" }));
    set_property("magic item", ({"touch"}) );
}
 
int touch(string str) {
   if (str != "amulet" && str != "ruby") return 0;
   if (this_player()->query_magic_protection() >1){
      write("The amulet resists your touch.\n");
      return 1;
   }
   write("%^BOLD%^%^WHITE%^A %^RESET%^%^RED%^dark red%^BOLD%^%^WHITE%^ "
     "mist climbs up your arm and spreads across your body.");
   tell_room(environment(this_player()), "%^RED%^A dark red mist fills "
     "the room.", ({ this_player() }));
  if (this_player()->query_magic_protection() < 10)
   this_player()->add_magic_protection(({0,7+random(3),200}));
   this_object()->remove();
   return 1;
}
 
void init() {
 ::init();
   add_action("touch", "touch");
}
