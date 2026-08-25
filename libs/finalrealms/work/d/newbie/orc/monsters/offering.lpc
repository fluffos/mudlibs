
inherit "/obj/monster";
#include "path.h";

void setup()
{
add_alias("prisoner");
   set_name("prisoner");
   set_race("human");
   set_gender(1);
set_main_plural("prisoners");
   add_plural("angry prisoners");
add_plural("humans");
   set_al(100);
   set_aggressive(0);
   set_random_stats(10,15);
   set_con(18);
   set_level(3+random(2));
   set_wimpy(0);
set_short("Prisoner");
set_long("\n"
"  He sits there on the floor in one of the corners. Around him lays "
"dead, partially eaten rats. He wears nothing but a loin cloth "
"and has a great number of scares across his chest and back. "
"He seems a bit out of touch with reality.\n");
   load_chat(200,
      ({
1,": says  AAAARRRRRRGGGGGGHHHHHH!!!!!!'",
1,": says  AAAARRRRRRGGGGGGHHHHHH!!!!!!'",
1,":says ' hey! thats MY RAT!!!'",
1,":says 'heheheh, I'm ,hehehee, I'm , hehhe,...I AM , HEHEHEE'",
1,":says 'ssshhhhshh, its sleeping...'",
1,":yells 'I WILL NOT SAY ANYTHING MORE!! YOU WILL HAVE TO KILL ME!!!",
      }));

load_a_chat(200,
({
1,":says OK!!!! I know of a sceret way out!!",
1,":says you have to 'move' the cental 'plate'....*gasp*",
1,":screams!!",
1,":screams!!",
1,":screams!!",
1,":screams!!",
1,":says thank you, KILL ME!!!",
1,":yells 'I'LL KILL YOU IN THE NEXT LIFE!!!'",
1,":says 42, yeah..that was the answer...hmm",
}));
}
