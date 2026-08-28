inherit MONSTER;

#include "../path.h"
#define say(x) "/command/mortal/say"->main(x)

create_monster()
{
     set_name(({ "corin", "mayor", "halfling" }));
     set_short("Corin, mayor of the Shire");
     set_long(wrap("Corin is a very short, plump halfling. He wears plain, light brown breeches "+
      "and a dark brown shirt.  He has black hair and brown eyes. The only thing that stands "+
      "out about him is the necklace he is wearing. It is the symbol that denotes him as the "+
      "mayor of the Shire.\n"));

     set_gender (1);
     set_language ("palen");

     set_emote(({"Corin grabs an apple from somewhere behind the counter and takes a bite.",
                 "Corin glances over some papers."}));

     set_talk(({"If you have any complaints or requests please post them on the board.",
                "I am very busy but, I'm working as fast as I can."}));

     set_race("halfling");

     set_levels(([ "fighter" : 6 + random(4) ]));
 
}
