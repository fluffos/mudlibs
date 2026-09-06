#include <const.h>
inherit "/obj/food";

void create() {
   ::create();
   set_edible(1);
}

string query_seed_type() {
   return "/econ/seed/" + explode(load_name(), "/")[<1];
}

int query_is_crop() {
   return 1;
}