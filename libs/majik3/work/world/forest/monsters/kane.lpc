inherit MONSTER;

#include "../path.h";

create_monster()
{
     set_name(({"Kane", "kane", "human" }));
     set_short("Kane, the black-robed human mage torturer");
     set_long(wrap("Kane is a human, or that is your best guess since he wears a shimmering "+
      ", black robe that covers his entire body. The only skin you see is the pale white skin "+
      "of his hands and the vauge glimpse you get of his face under the heavy hood.\n"));

     set_race ("thari");
     set_language ("alande");

     set_talk(({"Release the mist, Filonius, or you will suffer eternal torture at my hand!",
                "Oh, how I do enjoy the pain of my victims."}));

     set_aggressive();     
     set_gender (1);
     set_levels(([ "caster" : 48 + random(30) ]));
     add_money (10 + random(100));
}
