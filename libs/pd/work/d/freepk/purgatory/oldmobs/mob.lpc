#include <std.h>
#include <purgatory.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("%^BOLD%^%^BLACK%^A Purgatory %^BOLD%^%^WHITE%^Sk%^BOLD%^%^BLACK%^ele%^BOLD%^%^WHITE%^to%^BOLD%^%^BLACK%^n Guard%^RESET%^%^RED%^");
   set_short("%^BOLD%^%^BLACK%^A Purgatory %^BOLD%^%^WHITE%^Sk%^BOLD%^%^BLACK%^ele%^BOLD%^%^WHITE%^to%^BOLD%^%^BLACK%^n Guard%^RESET%^%^RED%^");
   set_id(({"skeleton", "monster", "guard"}));
   set_long("%^BOLD%^%^BLACK%^Risen from the grave, this skeleton is forced by Death to guard his city.");
   set_level(55+random(15));
   set("aggressive", 75);
   set_gender("dead");
   set_race("skeleton");
   set_body_type("human");
   set_emotes(2,({ "The clunk of bones can be heard as the guard makes his patrol." }),0);

}
void catch_tell(string str) {
  string a, b;
  if(sscanf(str,"falls dead before you.", a, b) == 2)
    this_object()->force_me("sacrifice corpse");
}
