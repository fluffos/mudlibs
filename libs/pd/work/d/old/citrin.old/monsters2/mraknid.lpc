// Coded by WHit

#include <std.h>
#include <citrin.h>

inherit MONSTER;

void create() {
::create();
set_name("raknid");
set_short("the angered Raknid mother is here.");
set_long("This Raknid has been angered by your presence.");
set_gender("female");
set("aggressive", 1000);
set_body_type("raknid");
set("race", "raknid");
set_id(({
"moma raknid", "mother raknid", "mother raknid", "raknid",
"mother", "raknid_citrin",
}));

set_level(40);

new("/d/citrin/armour2/rakskin")->move(this_object());
this_object()->force_me("wear rakskin");

}
