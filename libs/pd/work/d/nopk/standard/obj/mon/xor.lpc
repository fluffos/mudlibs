#include <std.h>
inherit "/std/vendor";

void create() {
 ::create();
   set_name("xor");
   set_id(({ "xor", "xor the old", "shopkeeper", "keeper" }));
   set_short("Xor, the old");
   set("aggressive", 0);
   set_level(12);
   set_long(
     "By far the oldest living creature in this part of the world. Despite any "
     "other claims, Xor is by far older than any. He was around for the birth of "
     "the first dragon. Xor was old when the world was still young. After having "
     "lived many lives, he has settled to run this weapon shop, for now at "
     "least.."
   );
   set_languages(({ "selunian" }));
   set_type(({ "weapon" }));
   set_gender("male");
   set_alignment(0);
   set("race", "eternal");
   set_hp(480);
   add_money("silver", random(450));
   set_body_type("human");
   set_currency("gold");
   set_storage_room("/d/standard/wstorage");
   set_skill("melee", 100);
   set_skill("bargaining", 85);
   set_property("no bump", 1);
}

int is_invincible() {
    set_sp(query_max_sp());
    this_object()->force_me("shout in selunian Help!! I am being attacked by "+
      (string)previous_object()->query_cap_name());
    return 0;
}

