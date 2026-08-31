#include <std.h>
#include <arlon2.h>
inherit VIRTUALSERVER;
void create() {
  ::create();
  set_how_long(4);
  set_first_sentence("%^BOLD%^The roads of Arlon are neatly paved with red and brown bricks.%^RESET%^");
  set_day_sentances( ({
      "Dead insects litter the side of the road.",
      "Flowers are planted on the side of the road.",
      "There is a candlelit lamp post here, made of intricately shaped steel.",
      "There are a few missing stones from the pattern below.",
      "Sand is scattered among the stones, a sign that a beach must be near.",
      "Weeds grow in between the stones underfoot.",
      "Broken shards of glass litter the otherwise clean environment.",
      "Horse manure is scattered on the road from the stable horses.",
      "Water is present on some of the stones, darkening them.",
      "Some of the stones underfoot have been faded by sunlight.",
      "Short grass surrounds the sides of the road.",
      "Moss sticks out between random stones, spreading throughout the road.",
      "A tall willow tree provides shade on the side of the road.",
      "A random smooth stone sits in the place of a brick here.",
      
      }) );
  set_night_sentances( ({
      "Dead insects litter the side of the road.",
      "Flowers are planted on the side of the road.",
      "There is a candlelit lamp post here, made of intricately shaped steel.",
      "There are a few missing stones from the pattern below.",
      "Sand is scattered among the stones, a sign that a beach must be near.",
      "Weeds grow in between the stones underfoot.",
      "Broken shards of glass litter the otherwise clean environment.",
      "Horse manure is scattered on the road from the stable horses.",
      "Water is present on some of the stones, darkening them.",
      "Some of the stones underfoot have been faded by sunlight.",
      "Short grass surrounds the sides of the road.",
      "Moss sticks out between random stones, spreading throughout the road.",
      "A tall willow tree makes a shadow on the side of the road.",
      "A random smooth stone sits in the place of a brick here.",
      
  }) ); 
  set_item_list( ([
      ({"brick", "bricks"}) : "The bricks covering the road are very finely sanded to be smooth, even without boots on.",
      ({"insects", "dead insects"}) : "There are dead ants and flies on the sides of the road, probably due to some magical repellent.",
      ({"flower", "flowers"}) : "There are lilacs and roses lined up alongside the road.",
      ({"lamp", "lamppost"}) : "The lamp post appears to be more for decoration than for lighting.",
      ({"stones"}) : "There are missing stones from the path, probably stolen by some hoodlum teenager.",
      ({"road"}) : "The road, although nearly perfect, has taken wear to the weather conditions of Arlon.",
      ({"weeds", "weed"}) : "It looks like Arlon needs a better landscaper, as weeds have started to sprout out between many of the stones of the road.",
      ({"glass", "shards", "shards of glass"}) : "No doubt remains of a night of teenage partying, shards of glass are waiting to be swept up by a maid or housewife of Arlon.",
      ({"manure", "horse manure"}) : "This manure looks like it's been sitting here for quite a while, and is starting to mold and decay.",
      ({"water"}) : "Whether from rain, a spilled drink, or spray from the ocean, water has seemed to find a way onto the path here.",
      ({"stone", "smooth stone"}) : "A blue stone rests in the place where a brick should be.",
      ({"tree", "tall tree", "tall willow tree", "willow tree"}) : "An old willow tree, at least 40 feet tall, is on the side of the road.", 
      ({"moss"}) : "The moss is spreading throughout the road, and it seems as if it will take over soon.",
      ({"grass", "short grass"}) : "The grass on the side of the road is bright green, with no dead patches to be found.",
  ]) );
  set_smell("The salty smell of the ocean is very strongly present.");
  set_listen("The busy city can be heard from the roads.");
  set_reset_list( ({
      MOB"arlonshopper", MOB"arlonmerchant", MOB"arlonteenager",
MOB"arlonteenager2", MOB"arlonteenager3", MOB"arlonteenager4", 
      MOB"arlonyoungster", MOB"arlonyoungster2", MOB"arlonyoungster3",
      MOB"arlonyoungster4", MOB"arlonshopper2"
  }) );
  set_properties( ([ "light" : 1,
                     "night light" : 1,
                     "town" : 1,
                     "road" : 1
                   ]) );
  set_short("The streets of Arlon.");
  set_mob_cap(4);
}
