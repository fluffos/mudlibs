#include <std.h>
#include <sindarii.h>
inherit MONSTER;
int wielded_wep=0;

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
   new(WEP"dagger")->move(this_object());
}

void heart_beat() {
 ::heart_beat();
   if (!wielded_wep) {
      this_object()->force_me("wield dagger");
      wielded_wep = 1;
   }
}

