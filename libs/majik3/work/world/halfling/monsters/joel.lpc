inherit MONSTER;

#include "../path.h"
#define say(x) "/command/mortal/say"->main(x)

create_monster()
{
     set_name(({ "joel", "lunatic", "halfling" }));
     set_short("Joel, the local lunatic");
     set_long(wrap("Joel is a real piece of work.  His shoes are untied, "+
     "and is clothes are terribly tattered.  He has large amounts "+
     "of drool and snot running down his face.  His eyes are gazing "+
     "out into the distance with the vacant stare of a lunatic.  "+
     "His hair is very dirty and sticking up all over the place.  "+
     "He is truly a repulsive sight."));

     set_gender (1);
     set_language ("palen");

     set_emote(({"Joel drools all over himself.",
                 "Joel leans down, picks up a bug and eats it.",
                 "A large streak of snot runs down Joel's face.",
                 "Joel is talking to himself very loudly.",
                 "Joel starts to scream loudly.",
                 "With a crazed grin on his face, Joel picks his nose.",
                 "Joel craizly smiles at you showing his green teeth.",
                 "Joel begins to cry and scream."}));

     set_talk(({"Are you the Keymaster?",
                "I am the Gate Keeper of Gozer.",
                "Argggh Barrg Klargg Marggg!",
                "ScOTT!",
                "I am the Lizard King, I can do anything.",
                "BLEEETHEAEW!",
                "Some one shoot me!"}));

      set_wander(1, 20);

     set_race("halfling");

     set_levels(([ "fighter" : 25 ]));
 
}
