#include <std.h>
#include <nwvforest3.h>
inherit "/std/virtual/vserver_static";
void create() {
  ::create();
  set_how_long(6);
  set_day_sentances( ({
      "The thick underbrush makes travelling the path treacherous in places.",
      "The forest is dense from so many dfferent types of trees.",
      "The thick growth of the forest makes the surrounding area dark and omenous.",
      "The foilage of the trees grow together making a thick canopy that blocks out the sun.",
      "Thick vines of some plant grow up the trunks of neardy trees.",
      "Trees of all shapes and sized grow thick all around blocking any attempt to leave the path.",
      "The path is the only opening in the thick underbrush that allows passage.",
      "Tracks of a large feline run along the path for a ways then vear off into the forest.",
      "The humidity of the forest is thick enough to cause the nearby trees to sweat.",
      "A tree has fallen over the path long ago and is now rotting slowly.",
      "Vines, thornbushes, and ther plants grow thickly together between the trees.",
      "Broken branches and trampled grass in the underbrush mark the passage of some animal.",
      "A bird's nest in a nearby tree looks like it has weathered with age.",
      "A rotting stump nearby looks as if it was hollowed out by some animal.",
      "The remains of some kind of rodent are decaying near the path.",
      "Squirrels chatter at one another off in the distance.",
      "A fresh mound of dirt near the path looks to be freshly dug.",
      "Thick tree limbs hang low over the path.",
      "The branches on a nearby tree look like the hands of some skeleton in the poor light.",
      "Nearby, the leaves on a tree rustle as some animal makes it's way through the tree tops." 
      
  }) );
  set_night_sentances( ({
      "The darkness of night makes traversing the path dangerous.",
      "Due to the canopy of the trees, the stars are not visible.",
      "Dark shapes in the forest could be trees or might prove to be something more ominous.",
      "The dark of night lends an evil menace to the forest.",
      "A howl off in the distance send nearby animals scurrying through the underbrush.",
      "Dark shapes move in the trees nearby.",
      "Shadowy shapes hang above the path reaching down like hands perpaired to grasp anything passing nearby.",
      "Shadowy movements along the path might be trees swaying in the breeze or they might be something more sinister.",
      "The lack of light down the path gives a distinct feeling of danger and trepidation.",
      "The darkness shrouds everything in shadow creating a sense of doom and despair.",
      "Rustling sounds out in the forest lend themselves to the rustling sounds underfoot.",
      "Shadowy forms out in the forest seem to creep closer to the path.",
      "Creaking noises accompany the wind each time it blows.",
      "Darkness closes in around the area leaching light out of the forest.",
      "Rough uneven ground makes travelling at night treacherous.",
      
  }) ); 
  set_item_list( ([
      "trees" : "A dense growth of many different kinds of trees.",
      "leaves" : "The branches of the nearby trees are covered in leaves.",
      "vines" : "The vines grow around trees and underbrush chocking out the sky and passage through the forest.",
      "path" : "An animal track through the underbrush.",
      ({"shadow", "shadows"}) : "Dark forms out in the forest.",
      "mound" : "A pile of dirt.",
      ({"limbs", "branches"}) : "Limbs covered in leaves growing from the trees.",
      ({"limb", "branch"}) : "Limbs covered in leaves growing from the trees.",
      "squirrels" : "Small rodentlike animals that live in the forest.",
      "stump" : "The base of a tree, the top portion long gone.",
      "forest" : "Trees growing thickly as far as the eye can see.",
      "nest" : "Twigs and grass formed together.",
      "tracks" : "Large feline tracks.",
      "foilage" : "Branches and leaves on the trees.",
      "canopy" : "At tree top level where thick foilage meet to form a roof of leaves.",
      "remains" : "A rotting corpse of a rodent.",
      "underbrush" : "Small bushes, large weeds, and other kinds of plants grown together in upassable clumps.",
      "shapes" : "Shadowy shapes in the darkened areas of the forest.",
      "thornbushes" : "A tangled mess of thorny bushes.",
  ]) );
  set_smell("The smell of decaying vegitation permeates the area.");
  set_listen("Animal calls and rustling noises drift in from off in the distance.");
  set_reset_list( ({
      MOB"chipmunk", MOB"coon", MOB"deer", MOB"deer2", MOB"dog", MOB"fox", MOB"hawk",
      MOB"bearcub", MOB"raccoon", MOB"rat", MOB"snake", MOB"squirrel", MOB"wildcat",
      MOB"wolf", MOB"wolf2",
  }) );
  set_properties( ([ "light" : 1,
                     "night light" : 0,
                     "forest" : 1
                   ]) );
  set_short("A forest path.");
}
