inherit "room/room";
#include "../path.h" 

    reset(arg)  {
if (arg) return;

property=({"no_teleport"});

set_light(1);
  short_desc = "Opening to courtyard";
long_desc = 
"      You step out of the shadow of the gate arch into a bright \n"
+"sunny scene filled with people and sounds.  Busy merchants \n"
+"offer their wares to the many inhabitants of the castle, \n"
+"including noblemen, maidens, servants, and a few scattered \n"
+"warriors.  Music fills the air as minstrels seeking their \n"
+"livelihoods dance around the courtyard with instruments in \n"
+"in hand.  Children run wild, playing in the divine warmth of \n"
+"the sun, thanks to the Holy Lady, Gwendolyn.  Women draw  \n"
+"buckets of water from a large well resting in the very heart \n"
+"of the courtyard. \n"
+"      The flowery courtyard opens wide in all directions, and \n"
+"to the south lie the castle gates. \n\n";

dest_dir = ({
PATH + "/cyard2", "west",
PATH + "/cyard3", "east",
PATH + "/cyard4", "northwest",
PATH + "/cyard5", "north",
PATH + "/cyard6", "northeast",
PATH + "/enter", "south"
});
items = ({
"merchants", "These men of trade fill the area offering pots, clothing, and various \n"
+"other neccessities and some luxuries",
"noblemen", "Easily distinguished by their rich clothing and large purses, they also \n"
+"wander the grounds",
"maiden", "Several women of incredible beauty wander in packs teasing the warriors",
"maidens", "Several women of incredible beauty wander in packs teasing the warriors",
"warriors", "The men are clad full in armour and weapons, and are treated with great \n"
+"respect from all present",
"well", "The well is north of you",
"minstrel", "Many of these wandering musicians dance about the courtyard. ",
"minstrels", "Many of these wandering musicians dance about the courtyard. ",
"children", "Kids run around wildly playing games and jokes that make mothers \n"
+"cringe in worry. "
});
smell = "The smell of fresh grass and flowers hit you like Springtime.";
 }
init() {
::init() ;
add_action("listen", "listen"); }
listen() {
write("The sounds are many and fun; all entertwine to create a wonderfully fun \n"
+"and enjoyable atmosphere. \n");
return 1;
}
