inherit MONSTER;

#include "../path.h"

#define say(x) "/command/mortal/say"->main(x)
#define room(x) message("standard", x, ENV(THIS), THIS)

create_monster()
{
     set_name(({ "ho ming", "traveller" }));
     set_short("ho ming, a traveller abroad");
     set_long(wrap("Ho ming is a man of small stature. He has dark black hair which is "+
      "perfectly straight and cut very short. He is wearing a light blue, loose shirt and "+
      "bright yellow pants.\n"));

     set_emote(({"Ho Ming looks all around, taking in everything he sees.",
                 "Ho Ming sneezes loudly."}));

     set_language ("choui");
     set_gender (1);
     set_wander(1,15);
     set_talk(({"Are you misser sparkol?",
                "I answer all you questions, hundred percent."}));

     set_race("yangir");

     set_levels(([ "fighter" : 30 + random(10) ]));

     set_pick(45);
}
init()
{
  THOB->force_us("say Hello chief?  Let's talk, why not?");
}

