#include <std.h>
#include <purgatory.h>

inherit BEACH;

void create() {
    ::create();
     set_name("Honeymoon room");
     set_short("Honey Moon Room");
     set_long("The Beach\n"
"A glossy white sandy beach stretches out, unbroken by human feet, for miles "
"in either direction. The sea, a light blue color, lap against the sands with "
"the soothing sound of breaking water. A small cottage lies in the foliage at "
"the edge of the beach, and it looks quite confortable. Tables and beach chairs "
"have been set up under the shade of a lone palm tree, fruity drinks sit sweating "
"in the humid climate.");
     set_night_long("The Beach\n"
"Night has fallen over this pristene beach, the waves now seem soothing as they crash "
"into the sands. The full moon overhead gives plenty of light to see by and gives the "
"beach a mystical and romantic feeling. A small candle casts its light from the cottage, "
"and shapes move in the darkness. A cool breeze flows in from the sea, now a dark blue, "
"as the light ripples across its surface.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no magic"    : 1,
        "no scry"     : 1,
        "no teleport" : 1,
        "no attack"   : 1,
        "no bump"     : 1,
        "outdoors"    : 1,
        "beach"       : 1,
        "no steal"    : 1,
]));
 set_exits( ([
              "square" : "/d/tirun/square"]) );

     set_smell("default", "The smell of the crashing surf and growing plants hangs in the air.");
     set_listen("default", "Waves crash, birds chirp, and the sounds of a happy couple can be heard.");
    set_items( ([
        "beach"  : "The white sands stretch for miles in both directions with out a single foorprint among them.",
        "cottage" : "It is a small cottage built along the beach, the wood it was built with looks drafty and has a touch of age along with it. It looks like it would be cool in any climate.",
        "waves" : "The waves crash against the beach, smaller around the cottage and larger as you move down the beach.",
        "sea" : "The sea during the day looks clear, blue, and very inviting. Small fish swim through the waters close to be the beach and a rather large coral reef can be seen just offshore.",
        "candle" : "A small candle lights the main room of the small cottage, letting its slight glow fill the cabin.",
        ({"sand", "sands"}) : "The white sands of the beach look unmarred, save for the scuttling crab seeking food for the day. The waves crash against the sands, keeping it wet and cool.",
        "foliage" : "Scattered palm trees and small low pants provide just enough cover to shade this small area of the shore, palm trees line the edge and drop coconuts ever now and then.",
        ({"table","tables"}) : "The tables were made out of a rather large stump, flattened to allow drinks on top of it.",
        "beach chairs" : "The chairs look to be made from natural branches, curved to fit the body and are very confortable.",
        "chairs" : "The chairs look to be made from natural branches, curved to fit the body and are very confortable.",
        "tree" : "Large palm trees sprout from the sands around the cottage, shading it and the tables. ",
        "palm tree" : "Large palm trees sprout from the sands around the cottage, shading it and the tables. ",
        "drinks" : "Fruity drinks sit sweating on the table stump, they look very refreshing and filled with strawberries, cherries and limes.",
        "fruity drinks" : "Fruity drinks sit sweating on the table stump, they look very refreshing and filled with strawberries, cherries and limes.",
        "moon" : "The moon hangs low in the sky, a brilliant orange color as it illuminates the land.",

      ]) );

}

