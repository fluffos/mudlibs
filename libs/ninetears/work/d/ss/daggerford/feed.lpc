#include "armory.h"
#include "path.h"
inherit "/std/room";

object lady,
cauldron;

void setup() {
   set_short("Backroom");
   set_long("This backroom appears to be a combined mini-kitchen and bedroom.  "+
      "It looks well lived in.\n");
   set_light(60);
   add_exit("east", ROOM+"gambling", "door");
}

void reset() {
   object ob;
   if (!lady) {
      lady = clone_object("obj/monster");
      lady->set_short("A small lady");
      lady->set_name("lady");
      lady->set_long("A small wizened woman who looks like she has done much more "+
         "than her fair share of house work.  She is grimly clutching a fry pan as "+
         "if to ward off the evil hordes by thwacking them one by one around the head with it.\n");
      lady->add_adjective("small");
      lady->set_main_plural("small ladies");
      lady->load_chat( 10, ({
               1, "'I bet you have come to steal my cauldron like all the others.",
               1, "'bloody demons.",
               1, ":peers suspiciously at you."
               }));
      lady->set_race("human");
      lady->set_level(3);
      lady->load_a_chat(20, ({
               1, "'Wait till my husband hears about this!",
               1, ":bashes you on the head with a fry pan.",
               1, "'You will never get my cauldron alive!"
               }));
      ob = (object)ARMORY->request_weapon("knife",100);
      ob->move(lady);
      lady->move(this_object());
      lady->wield("frypan");
   }
}

int do_search(string str) {
   if (cauldron) {
      write("You find the place where a cauldron should go... but it isn't "+
         "there.\n");
      say(this_player()->query_cap_name()+" searches around a bit.\n");
      return 1;
   }
   if (lady && environment(lady) == this_object()) {
      write("You see the cauldron, but the lady screams and snatches it away "+
         "from you.\n");
      say(this_player()->query_cap_name()+" searches around a bit and then tries "+
         "to steal the lady's cauldron.  The lady screams and snatches it off "+
         this_player()->query_pronoun()+".\n");
      return 1;
   }
   write("You find a cauldron.\n");
   say(this_player()->query_cap_name()+" searches around and finds a cauldron.\n");
   cauldron = clone_object("/std/liquid");
   cauldron->set_name("cauldron");
   cauldron->set_short("small cauldron");
   cauldron->set_long("A small black cauldron, obviously been used for cooking "+
      "for a large number of years.  The encrusted dirt and "+
      "protein enhancing things attached to the cauldron "+
      "give it away.\n");
   cauldron->set_main_plural("small cauldrons");
   cauldron->add_adjective("small");
   cauldron->set_max_volume(6000);
   cauldron->set_liquid_name("chunky soup");
   cauldron->set_volume(2000);
   cauldron->set_volume_per_dose(100);
   cauldron->set_weight(40);
   cauldron->set_max_weight(30);
   cauldron->add_property("feeding_frenzy", "cauldron");
   if (cauldron->move(this_player())) {
      write("You cannot pick it up. it's far too heavy and hot.\n");
      cauldron->move(this_object());
   }
   return 1;
}

void dest_me() {
   if (lady)
      lady->dest_me();
   ::dest_me();
}
