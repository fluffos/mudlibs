#include <std.h>
#include <purgatory.h>
inherit MONSTER;
int crapgo();


void create() {
 ::create();
   set_name("%^BOLD%^%^BLACK%^Purgatory %^BOLD%^%^WHITE%^Sk%^BOLD%^%^BLACK%^ele%^BOLD%^%^WHITE%^to%^BOLD%^%^BLACK%^n Guard%^RESET%^%^RED%^");
   set_short("%^BOLD%^%^BLACK%^Purgatory %^BOLD%^%^WHITE%^Sk%^BOLD%^%^BLACK%^ele%^BOLD%^%^WHITE%^to%^BOLD%^%^BLACK%^n Guard%^RESET%^%^RED%^");
   set_id(({"skeleton", "monster", "guard"}));
   set_long("%^BOLD%^%^BLACK%^Risen from the grave, this skeleton is forced by Death to guard his city.");
   set_level(40+random(15));
   set("aggressive", 20);
   set_gender("neuter");
   set_race("skeleton");
   set_body_type("human");
   set_class("mage");
   set_subclass("necromancer");
   set_swarm("");
   set_spell_chance(40);
   set_spells(({"slash"}));
   //set_emotes(2,({ "The clunk of bones can be heard as the guard makes his patrol." }),0);
   set_die((:  crapgo  :));


new(EQ"skeletoncloak")->move(this_object());
force_me("wear cloak");

new(EQ"skeletonboots")->move(this_object());
force_me("wear boots");

new(EQ"slime")->move(this_object());
force_me("wear slime");

new(EQ"eyeearrings")->move(this_object());
force_me("wear earrings");

new(EQ"skeletongloves")->move(this_object());
force_me("wear gloves");

new(EQ"earbelt")->move(this_object());
force_me("wear belt");

new(WEAP"boneclub")->move(this_object());
force_me("wield bone");

new(WEAP"boneclub")->move(this_object());
force_me("wield bone");
}


int crapgo() {
object ob;
   tell_room(environment(this_object()),"%^GREEN%^A nasty slime rots off the skeletons corpse.", ({ }));
  if (present("slime", this_object())) {
      ob = present("slime", this_object());
      catch ( ob->remove() );
   }

//this_object()->remove();
  return 1;
}
