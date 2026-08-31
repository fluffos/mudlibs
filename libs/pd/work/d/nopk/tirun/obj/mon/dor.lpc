#include <std.h>
inherit MONSTER;
int heart_beat;
void create() {
   ::create();
   set_name("dour");
   set_id( ({ "dour","guard","dour guard" }) );
   set_short("A dour guard");
   set_long("A short stocky humanoid about two and a half feet tall."
            "Powerfully muscled, it looks mean.\n");
   set_level(15);
   set_body_type("human");
   set_alignment(-200);
   set_race("dour");
   set_class("fighter");
   set_heart_beat(1);
   }
int heart_beat(){
      this_object()->set_paralyzed(2);
      set_heart_beat(heart_beat_on = 1);
  }
