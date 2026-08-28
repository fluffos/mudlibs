inherit MONSTER;

#include "../path.h"
#define say(x) "/command/mortal/say"->main(x)

create_monster()
{
     set_name(({ "Bertha", "bertha", "citizen", "halfling" }));
     set_short("Bertha, a citizen of the Shire");
     set_long(wrap("Bertha is clothed rather modestly. She has only a long red dress. It is "+
      "pretty dirty and has seen a lot of use. She has long blonde hair and deep blue eyes. "+
      "She is carrying a basket with some fruit it it.\n"));

     set_emote(({"Bertha argues with a merchant about something."}));

     set_language ("palen");

     set_talk(({"I'll never be able to feed my family with these prices!",
                "Poor Sammy, he's a growing boy and needs to eat well."}));

     set_race("halfling");

     set_levels(([ "fighter" : 1 ]));
 
     set_gender(2);
     add_money (random(5));
}

