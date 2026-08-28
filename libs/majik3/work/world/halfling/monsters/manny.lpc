inherit MONSTER;

#include "../path.h"

create_monster()
{
     set_name(({"manny","dad","father", "halfling" }));
     set_short("Manny, an older halfling");
     set_long(wrap("Manny is a middle aged halfling. He has the look of having a lot of stress "+
      "and worries in his life. He face is lined with wrinkles and his hair is starting "+
      "to turn gray.  He is wearing some plain looking breeches and a white T-shirt.\n"));

     set_language ("palen");

     set_emote(({"Manny scratches his head and mumbles to himself.",
                 "Manny sits on the bed and lies down for a nap.",
                 "Manny covers his ears and tries to block out the world."}));

     set_talk(({"Sammy, quit complaining, your mother will be back from the market soon.",
                "Dinner will be ready as soon as your mother gets back, Sammy.",
                "If you don't quiet down boy, I'm gonna give you somthing to whine about!"}));

     set_gender (1);
     set_race("halfling");

     set_levels(([ "fighter" : 4 + random(5) ]));

     add_money (random(5));
}
