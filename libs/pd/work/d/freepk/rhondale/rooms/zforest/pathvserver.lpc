#include <std.h>
#include <aziraphale.h>

inherit VIRTUALSERVER;

void create() {
   ::create();
     set_how_long(4);

     set_day_sentances(({
        "%^RESET%^GREEN%^The trees are huge, and provide enough shade to keep you cool despite the heat of day.",
        "%^RESET%^GREEN%^Stones litter the ground, many of them are covered in a green moss that is very slick.",
        "%^RESET%^GREEN%^Small animals scurry about the place, busily collecting food to store and eat.",
        "%^RESET%^GREEN%^One of the trees has fallen across the path, leaving a gap in the canopy where the sky can be seen.",
        "%^RESET%^GREEN%^Small shrubs and plants grow out across the path, making it difficult to follow.",
        "%^RESET%^GREEN%^The wind blows the tops of the trees above the forest, a few leaves fall to the ground from high above.",
        "%^RESET%^GREEN%^A little trickling stream is slowly making its way through the forest to a larger body of water elsewhere.",
        "%^RESET%^GREEN%^The plant life in this area is rich and lush, the shrubs and ferns are thriving on the moisture of the forest.",
        "%^RESET%^GREEN%^The rocks on the forest floor are covered in mould and slime, a few large boulders are also scattered around.",
        "%^RESET%^GREEN%^Dead plants, logs and leaves litter the the forest floor here, this place must be home to many creatures big and small."
                }));

     set_night_sentances(({
        "%^RESET%^BLUE%^Trees loom up out of the darkness, creating huge pillars of darkness.",
        "%^RESET%^BLUE%^The branches of trees seem to be reaching out, clawing at the air, looking for something to choke.",
        "%^RESET%^BLUE%^Stones litter the ground and are covered in moss, making it easy to slip.",    
        "%^RESET%^BLUE%^Dark shapes can be seen darting from shadow to shadow.",
        "%^RESET%^BLUE%^The stars can barely be seen through the treetops, and there is almost no light on the forest floor.",
        "%^RESET%^BLUE%^The wind whistles through the dark forest, the tree trunks loom out of the darkness.",
        "%^RESET%^BLUE%^A gurgling sound comes from nearby, its most likely the small stream.",
        "%^RESET%^BLUE%^Dark shapes can be seen looming in the shadows.",
        "%^RESET%^BLUE%^Beams of moonlight come through small spaces between foliage in the roof of the forest."
                }));

     set_item_list(([
        "animals"               : "Little animals collect nuts that have fallen to the ground.",
        "fallen tree"           : "The tree has been rotted at the base, and must have come down in the wind.",
        "stones"                : "The stones mustn't have moved in years, to have moss cover them completely.",
        "branches"              : "Just tree branches, nothing to get all excited about.",
        "trees"                 : "The trees are huge, and must be centuries old.",
        "leaves"                : "Leaves are falling from the tree all around, they litter the ground too.",
     ({ "tree", "trunk" })      : "These trees are huge, looming high up into the top of the forest.",
        "rocks"                 : "The rocks are extremely slippery, walking on them might get you hurt.",
        "stream"                : "The stream isn't actually visible, but it's near by, the sound of it trickling very clear.",
     ({ "plants", "fern", "shrubs" })   : "There are various types of plant life in this forest, very lush and healthy looking. This wouldn't be such a bad place to live.",
     ({ "moon", "beams", "moonlight" }) : "Only a little can be seen through the foliage, but it's a welcome sight."
                ]));

     set_smell("The smell of foliage is ever-present.");
     set_listen("Leaves rustle in the breeze.");

  set_reset_list( ({
        KEEPMOB"zforest/owlbear",
        KEEPMOB"zforest/panther",
        KEEPMOB"zforest/tiger",
        KEEPMOB"zforest/drake",
        KEEPMOB"zforest/snake",
        KEEPMOB"zforest/lizard",
        KEEPMOB"zforest/hunter",
        KEEPMOB"zforest/owlbear",
        KEEPMOB"zforest/panther",
        KEEPMOB"zforest/tiger",
        KEEPMOB"zforest/drake",
        KEEPMOB"zforest/snake",
        KEEPMOB"zforest/lizard",
        KEEPMOB"zforest/hunter"
  }) );

     set_properties(([ "light"          : 1,
                       "forest"         : 1,
                       "night light"    : 0
                   ]));
  set_short("Rhondale Forest");
}

