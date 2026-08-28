inherit MONSTER;

#include "../path.h";

create_monster()
{
     set_name(({"an elven archer", "archer","elven archer", "elven", "elf"}));
     set_short("an elven archer, easily traversing the thin rope bridge");
     set_long(wrap("The elven archer is strapped with a quiver full of finely crafted arrows. "+
      "His sharp eyesight allows him to pick off goblins on the forest floor below, even "+
      "though the canopy is very thick. He doesn't wear any armour and only carries a short "+
      "sword with him, besides his bow and arrows.\n"));

     set_emote(({"The elf fires an arrow with deadly accuracy, into the forest below."}));
     
     set_gender (1);
     set_wander (1, 25);
     set_pick (20);
     set_wimpy (20, 75);
     set_race ("tanir");
     set_levels (([ "fighter" : 38 + random(10) ]));
     add_money (0 + random(5));
}
