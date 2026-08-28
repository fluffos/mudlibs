inherit MONSTER;

#include "../path.h"

#define say(x) "/command/mortal/say"->main(x)
#define room(x) message("standard", x, ENV(THIS), THIS)

create_monster()
{
     set_name(({ "velinax", "thari","man" }));
     set_short("Velinax Belmonte, the shopkeeper");
     set_long(wrap("Velinax is here clothed in a red, longsleeved shirt and dark pants. "+
      "He has a long beard which covers most of his face and neck. He is an average height "+
      "Thari with big green eyes.\n"));

     set_emote(({"Velinax picks his nose a bit.",
                 "Velinax looks through a brown sack in his hand."}));

     set_language ("sartog");
     set_gender (1);

     set_talk(({"Well, are you gonna buy something or not?",
                "Everything I sell is listed on the sign."}));

     set_race("thari");

     set_levels(([ "fighter" : 35 ]));

     set_pick(15);
}

