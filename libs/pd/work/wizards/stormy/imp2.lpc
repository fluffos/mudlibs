#include <std.h>
#include <sindarii.h>
inherit MONSTER;
int wear_arm=0;
void create() {
    ::create();
   set_name("imp");
   set_id( ({ "imp" }) );
    set_short("an evil imp");
    set_level(5);
   set_long("An evil imp. He smiles as you cringe.");
   set_body_type("imp");
   set_alignment(-10);
   set("race", "imp");
   set_gender("male");
   new(ARM"boots")->move(this_object());
}
void heart_beat() {
 ::heart_beat();
   if (!wear_arm) {
      this_object()->force_me("wear boots");
      wear_arm = 1;
   }
}
