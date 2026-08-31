#include <std.h>
#include <guild.h>
inherit ROOM;
void create() {
::create();
 set_properties( ([ "no attack"   : 1,
                    "no magic"    : 1,
                    "no bump"     : 1,
                    "light"       : 2,
                    "night light" : 2,
		    "no teleport" : 1,
		    "no scry" : 1,
		    "indoors" : 1,
                    "no steal"    : 1 ]) );


   set_name("a Forsaken room");
   set_long("This room is circular and on the walls there are many weapons "
"mounted. This appears to be a training area. Hung from the wall is an ebony "
"plaque. A ladder emerging from a hole in the floor leads up and down.");
set_items(([
  "ladder" : "This ladder extends from deep with in the floor and leads high in to the attic",
  "plaque" : "The Ten Commandments of Warfare\n"
"     1 - I am the Warlord and the Wrathful God of Combat, and I will always \n"
"lead you from the front not the rear. \n"
"     2 - I will treat you all alike - just like scum. \n"
"     3 - Thou shalt not do anything I will not do first and thus will you \n"
"be created Warriors in My deadly image. \n"
"     4 - I shall punish thy bodies because the more thou sweatest in \n"
"training, the less thou bleedest in combat. \n"
"     5 - Indeed if thou hurteth in thy efforts and thou suffer painful \n"
"dings, then thou art Doing It Right \n"
"     6 - Thou hast not to like it - Thou hast just to do it \n"
"     7 - Thou shalt Keep It Simple, Stupid. \n"
"     8 - Thou shalt never assume. \n"
"     9 - Verily, thou art not paid for thy methods, but for thy results, by \n"
"which meanth thou shalt killeth thine enemy before he killeth you by any \n"
"means available. \n" 
"     10 - Thou shalt, in thy Warrior's Mind and Soul, always remember My \n"
"ultimate and final commandment: In combat there are no rules - Win at all \n"
"costs.",
]));
set_exits(([
"east" : ROOMS"forsaken/hall",
 "up" :ROOMS"forsaken/mistroom",
"down" : ROOMS"forsaken/mainportal",
]));
}
