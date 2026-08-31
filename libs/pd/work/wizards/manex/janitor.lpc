#include <std.h>
inherit MONSTER;

void create() {
::create();
   set_name("Janitor");
    set_short("A crazed janitor");
   set_long("This is a janitor.  what you dont know is he is also an ex "
     "marine, and he could kick your butt easily, you might want to "
     "think twice before you try to take on this pissed off custodian.");
   set_id(({"janitor", "crazed janitor", "monster"}));
   set_level(25);
   set_race("human");
   set_body_type("human");
   set_gender("male");
   new("/wizards/manex/broomstick")->move(this_object());
   this_object()->force_me("wield broomstick");
}
