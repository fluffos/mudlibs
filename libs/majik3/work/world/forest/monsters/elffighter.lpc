inherit MONSTER;

#include "../path.h";

create_monster()
{
     set_name(({"an elven fighter", "elven fighter", "elven", "elf","fighter"}));
     set_short("an elven fighter is here discreetly moving throught the forest");
     set_long(wrap("The elven fighter is clothed in all green clothes which allows him to "+
      "blend in with the forest very well. He slides in and out of the underbrush with ease "+
      "as he creeps up on unsuspecting goblins.\n"));

     set_emote(({"The elf quietly sneaks through the underbrush.",
                 "The elf quickly looks all around, then darts behind a tree."}));
     
     set_gender (1);
     set_wander (1, 26);
     set_pick (20);
     add_weapon ("iron_longsword");     
     set_wimpy (20, 65);
     set_race ("tanir");
     set_levels (([ "fighter" : 24 + random(8) ]));    
     add_money (0 + random(5));
}
