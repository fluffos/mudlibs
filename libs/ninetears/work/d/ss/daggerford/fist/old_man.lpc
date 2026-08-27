#include "path.h"
inherit "/obj/monster";
 
void setup() {
   add_alias("old man");
   add_alias("beggar");
   add_alias("bum");
   set_name("man");
   set_short("Old Man");
   set_long("A scruffy old bum, obviously the scum of the earth.\n");
   set_main_plural("old men");
   set_gender(1);
   set_race("human");
   set_guild("fighter");
   set_random_stats(15, 18);
   adjust_str(5);
   adjust_con(1);
   adjust_dex(10);
   set_level(7);
   set_al(random(-100));
   set_wimpy(40);
 
   load_chat(500, ({
         1, "'Where did I put that map?",
         1, "'I know I HAD an amulet around here somewhere...",
      1, "'What do you want now?",
      1, "'I've always been afriad of water.",
      1, "'Ships.  Can't abide em'  Never been on one, never hope to.",
      1, ":gets a faraway look in his eyes.",
      1, ":raises his fist in the air. 'Power to the Band of the Silver fist!'",
      1, "'Threw me in jail, he did.",
      1, "'I'd need an army to take on the Demon King, now.",
         1, ":mumbles:  Bloody demons...",
         1, ":mumbles:  Sand. That was the key.",
         1, "'I don't think I'll EVER get the smell out of my clothes.",
         1, "'Let me tell you, there were rats EVERYWHERE.",
         1, ":spits on the ground.",
         1, "'I am nothing more than an Old, Old man.  Let me be.",
         1, "'If I were only younger, I'd go down there and kill em myself."
   }));
   load_a_chat(300, ({
           1, "'This is Foolish!",
           1, "'Kill me and you will NEVER get in!",
           1, "'Things are not always what they seem!",
           1, "@sigh",
           1, ":casts a curse on you!",
           1, "'Don't say I didn't warn you!"
   }));
 
} /* setup() */
 
