
#include <std.h>
inherit MONSTER;
int wielded_wep=0;

void create() {

  ::create();
   set_id( ({ "duck","deranged duck" }) );
   set_name("Demented Duck");
   set_short("The deranged, demented, marginally corrupt duck");
   set_long(
     "He is a calm water fowl with a crazy look in his eye. "
   );
   set_class("rogue");
   set_level(10);
   set_exp(10000);
   set_max_hp(415);
   set_hp(415);
   set_stats("strength",25);
   set_stats("constitution",30);
   set_stats("dexterity",35);
   set_stats("intelligence",25);
   set_stats("wisdom",25);
   set_stats("charisma",25);
   set_skill("attack",30);
   set_skill("defense",30);
   set_skill("knife",30);
   set_race("duck");
   set_body_type("fowl");
   set_gender("male");
   new("/wizards/vicissitude/toybox/bknife")->move(this_object());
}

void heart_beat() {

   ::heart_beat();
   if(!wielded_wep) {
     this_object()->force_me("wield knife");
     wielded_wep = 1;
}
}




