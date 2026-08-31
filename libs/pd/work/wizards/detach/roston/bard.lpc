#include <std.h>
inherit MONSTER;

void create() {
::create();
    set_name("Bard");
    set_short("%^BOLD%^%^RED%^A old Bard%^RESET%^");
    set_long("This man is very old and very wise listen to "
             "what he has to say if you wish to live.");
    set_id(({"bard", "old bard"}));
    set_level(15);
    set_race("dwarf");
    set_body_type("human");
    set_gender("male");
   set_moving(1);
    set_languages( ({"farsi"}) );
    set_speech(5, "farsi",
        ({"The Town of Roston was founded a very long",
          "time ago. To the north is a very dark town",
          "where the people known as the Drows live.",
          "The drows hate all others, so dont travel north",
           "you might be killed."}),
        0);
 }                                       

void init()
{
 ::init();
 set_heart_beat(120);
}


void heart_beat()
{
 ::heart_beat();
this_object()->force_me("say The Town of Roston was founded a very long  "
          "time ago. To the north is a very dark town "
          "where the people known as the Drows live. "
          "The drows hate all others, so dont travel north "
           "you might be killed.");
      
} 
 
