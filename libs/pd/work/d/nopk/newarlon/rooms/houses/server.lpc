#include <std.h>
#include <arlonhouses.h>
inherit VIRTUALSERVER;
void create() {
  ::create();
  set_how_long(4);
  set_first_sentence("%^BOLD%^This is a very elegant and expensive looking house.%^RESET%^");
  set_day_sentances( ({
      "There is a staircase leading to more of the house, but it appears to be magically blocked off.",
      "The ground is covered in beautiful hardwood, without a flaw.",
      "The sunlight from outside shines in through a large window." ,
      "There is a bookcase overflowing books, scrolls, and potions.",
      "A beautiful and large tapestry hangs on the wall.",
      "A thick lion's fur has been made to be used as a rug.",
      "There are trophies and ribbons in a corner of the house.",
      "A plaque with a coat of arms hangs on a wall solitarily.",
      "A feather duster has been left on the floor, gathering dust.",
      "A ceramic vase with flowers sits on the window sill.",
      "A small round table surrounded by chairs is placed in a corner.",
      "A comfortable looking couch covered in lion furs sits against a wall.",
      "A rectangular coffee table with flowers and candles sits in the middle of the room.",
 
  }) );
  set_night_sentances( ({
      "There is a staircase leading to more of the house, but it appears to be magically blocked off.",
      "The ground is covered in beautiful hardwood, without a flaw.",
      "The moonlight from outside glows through a large window.",
      "There is a bookcase overflowing books, scrolls, and potions.",
      "A beautiful and large tapestry hangs on the wall.",
      "A thick lions fur has been made to be used as a rug.",
      "There are trophies and ribbons in a corner of the house.",
      "A plaque with a coat of arms hangs on a wall solitarily.",
      "A feather duster has been left on the floor, gathering dust.",
      "A ceramic vase with flowers sits on the window sill.",
      "A small round table surrounded by chairs is placed in a corner.",
      "A comfortable looking couch covered in lion furs sits against a wall.",
      "A rectangular coffee table with flowers and candles sits in the middle of the room.",
      
  }) ); 
  set_item_list( ([
      ({"staircase"}) : "The staircase appears to lead upstairs, although the magical barricade darkens the view.",
      ({"magic", "magical barricade"}) : "A glowing blue force seems to block off the upstairs from trespassers.",
      ({"ground", "floor"}) : "The ground is covered in hardwood, and appears to be very neat and tidy.",
      ({"hardwood", "wood"}) : "The hardwood is a very dark color, and is scratchless.",
      ({"sun light", "sunlight"}) : "The sun streams in through the window, illuminating the room.",
      ({"window"}) : "The window is very large and regal, fitting well in Arlon.",
      ({"bookcase", "book case"}) : "The bookcase has many shelves, and is made of a dark wood that matches the floor.  It doesn't look very significant.",
      ({"books", "scrolls", "potions"}) : "Books, scrolls, and potions litter the bookcase, everything from fighting and stealth technique to spellbooks.  They are all very new looking.",
      ({"tapestry"}) : "The tapestry is very elegant, with a large lion in the middle.",
      ({"lion", "lion's fur", "rug"}) : "The rug seems to still be very fresh, it must have been killed recently.",
      ({"trophies", "ribbons"}) : "Trophies and ribbons that the kids brought home from their lessons are stored neatly in a corner display.",
      ({"plaque", "coat of arms"}) : "The coat of arms is the only thing on its wall, obviously demanding some sort of respect.",
      ({"duster", "feather duster"}) : "The duster is starting to gather dust.  Perhaps the maid has had a few too many days off.",
      ({"vase", "ceramic vase", "flowers"}) : "Beautiful red roses blossom out of the red vase.  They appear to be enchanted to stay fresh.",
      ({"sill", "window sill"}) : "The window sill is spotless and dustless, and big enough to curl up on with a book.",
      ({"moonlight", "moon light"}) : "The moonlight eerily seeps in to the house, illuminating it.",
      ({"small table", "small round table", "round table", "chairs", "chair"}) : "A small round table of dark wood surrounded by dark wood chairs.  There is a vase of flowers in the middle of it.",
      ({"coffee table", "rectangular table", "rectangular coffee table"}) : "The coffee table is a dark wood, with random books and scrolls on it.",
      ({"table"}) : "Which table do you mean, the coffee table or the small table?",
      ({"couch"}) : "The couch in covered in lion furs and looks extremely comfortable.",

  ]) );
  set_smell("The scent of fresh flowers overpowers the living room.");
  set_listen("Neighborhood children can be heard playing through the window.");

  set_reset_list( ({
      MOB"arlonhousewife", MOB"arlonhusband", MOB"arlonteenager", MOB"arlonteenager2", MOB"arlonteenager3", MOB"arlonteenager4", 
      MOB"arlonyoungster", MOB"arlonyoungster2", MOB"arlonyoungster3",
      MOB"arlonyoungster4"
  }) );
  set_properties( ([ "light" : 1,
                     "night light" : 1,
                     "indoors" : 1,
                     "house" : 1
                   ]) );
  set_short("The houses of Arlon.");
  set_mob_cap(4);
}
