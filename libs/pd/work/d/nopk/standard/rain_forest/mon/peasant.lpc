#include <std.h>
#include <rain.h>
inherit MONSTER;

void create() {
   ::create();
   set_name("peasant");
   set_short("A elven peasant");
   set_id(({"peasant", "jungle peasant"}));
   set_long("This peasant wanders around outside the town doing nothing.\n");
   set_level(5);
   set_gender("male");
   set_race("elf");
   set_body_type("human");
   add_money("gold", random(100));
 }

int is_invincible() {
    set_sp(query_max_sp());
     this_object()->force_me("say HELP!! I am being attacked by "+
      (string)previous_object()->query_cap_name());
    return 0;
}
