inherit MONSTER;

#include "../path.h"

#define say(x) "/command/mortal/say"->main(x)
#define room(x) message("standard", x, ENV(THIS), THIS)

create_monster()
{
     set_name(({ "drakar","dwarf","farmer" }));
     set_short("drakar, a dwarven farmer");
     set_long(wrap("Drakar looks like your average dwarf in height and weight. He also "+
      "has a long, dark beard as most dwarves do. However, he is dressed in a pair of grey "+
      "overalls, which are very stained and dirty.\n"));

     set_emote(({"Drakar puts his tumbs in his pockets and begins to whistle a tune.",
                 "Drakar pulls on his beard and scratches his butt in deep thought."}));

     set_language ("draz");
     set_gender (1);

     set_wander(1, 30);

     set_talk(({"Some folks call me strange, livin above ground 'n all.",
                "I may not be the quality smith the others are, but I'm the best farmer of 'em all."}));

     set_race("dwarf");

     set_levels(([ "fighter" : 22 + random(14) ]));

     set_pick(5);
}


