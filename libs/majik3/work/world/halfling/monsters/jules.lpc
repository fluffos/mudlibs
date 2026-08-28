inherit BANK;

#include "../path.h";
#define say(x) "/command/mortal/say"->main(x)


create_monster()
{
     set_name(({"Jules","banker"}));
     set_short("Jules, a halfling banker");
     set_long(wrap("Jules is a stout, round halfling with bright blue eyes "
      + "and sandy blonde hair. He is wearing a tight cloth vest and large "
      + "baggy breaches. He wears an eye piece over his left eye.\n"));

     set_race ("halfling");

     set_language("sartog");

     set_emote(({"Jules ajusts his eyepiece as he reads some papers.",
                 "Jules quickly examines everyone in the room."}));

     set_talk(({"How may I help you today?",
                "The Halfling Traders Union is just down the road, to the west."}));


     set_gender (1);     
     
     set_levels(([ "fighter" : 19 + random(8) ]));

     add_alignx (random(1100));
     add_aligny (random(50));
}
