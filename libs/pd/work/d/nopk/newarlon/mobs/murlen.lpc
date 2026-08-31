inherit "/std/vendor";
#include <daemons.h>
#include <std.h>
#include <arlon2.h>
void create() {
 ::create();
   set_name("murlen");
   set_id(({ "murlen", "shopkeeper", "shopkeep", "keeper" }));
   set_short("%^BOLD%^%^RED%^Murlen, the Magic Supply Master");
   set("aggressive", 0);
   set_level(30);
   set_long("%^BOLD%^%^RED%^Murlen is the magic and other items master in Arlon.  He thinks you should type <help inventory> to see a little bit about your inventory command and items commands.");
   set_type(({ "other", "object" }));
   set_gender("male");
   set_race("human");
   add_money("silver", random(300));
    set_exp(1);
   set_body_type("human");
   set_currency("gold");
   set_storage_room(ROOMS "supstore");
   set_property("no bump", 1);
}

