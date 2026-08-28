inherit MONSTER;

#include "../path.h"
#define say(x) "/command/mortal/say"->main(x)

create_monster()
{
     set_name("patan");
     set_short("Patan, a drunk");
     set_long(wrap("As you look at Patan it becomes obvious he is a drunk. He is wearing some "+
      "dirty clothes that he's probably had on for a number of days.  Futhermore, his eyes are "+
      "glazed and he is babbling some incoherent dribble.\n"));

     set_gender (1);
     set_language ("palen");

     set_emote(({"Patan slobbers all over himself.",
                 "Patan tries to stand up and falls, smacking his head on the floor.",
                 "The feint smell of puke comes from Patan."}));

     set_talk(({"Gimme another beer, barkeep.",
                "Beer is the solution to all of lifes problems."}));

     set_race("halfling");

     set_levels(([ "fighter" : 6 ]));
 
}
