// Coded by Whit
// Coded for Primal Darkness
// snake1.c

#include <std.h>
#include <citrin.h>
inherit MONSTER;
int wear_arm=0;	
void create() {
    ::create();
   set_name("green snake");
   set_id( ({ "snake" }) );
    set_short("a green snake");
    set_level(21);
   set_long("This is a green slimy snake.  He must of came wanting to eat one of the "
	    "baby spiders for lunch.");
   set_body_type("imp");
   set_alignment(-10);
   set("race", "imp");
   set_gender("male");
   new(ARM"snakeskin")->move(this_object());
}
void heart_beat() {
 ::heart_beat();
   if (!wear_arm) {
      this_object()->force_me("wear snakeskin");
      wear_arm = 1;
   }
}
