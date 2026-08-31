#include <std.h>
inherit ARMOUR;
int add_bonus();
int remove_bonus();
void create() {
 ::create();
set("dragon wear", 1);
   set_name("an experience ring");
set_short("an experience ring");
   set_long("This ring bestows a very RANDOM amount of experience.  Wear it and it's gone!");
   set_id(({ "ring"}));
   set_weight(5);
   set_limbs(({"right hand", "left hand"}));
   set_type("ring");
   set_ac(1);
   set_wear( (: add_bonus :) );
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 1);
}
int add_bonus(){
if (!this_object()->query_worn())
   this_player()->add_exp(random(5000000));
   this_object()->remove();
   return 1;
   }
