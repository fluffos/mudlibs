#include <mudlib.h>

inherit OBJECT ;

void create() {
    // Author is the person who coded this. It should be in 
    // every object or room you code.
    set("author", "nightmask");

    //the id makes it able to be examined in more than 1 way
    set ("id", ({ "rose", "flower", "long stemmed rose" }) );

    //the short is what you see in an inventory, or on the ground
     set("short", "a long-stemmed rose") ;

    //long is what is seen after the player examines it
    //the @EndText makes it a bit easier to code
    set ("long", @EndText
This is a long stemmed rose, dethorned and beautiful.
It has a light, sweet fragrance that tickles your nose.
EndText
    );
  set("smell", "It has a light, sweet fragrance that tickles your nose.\n") ;

    //mass is how much it weighs
    set ("mass", 0);

    //this is how much you would get for it in the shop
    set ("value", 0);

}
