
#include <mudlib.h>

inherit OBJECT ;

void create() {
seteuid(getuid());
    set("author", "sophia");

    //the id makes it able to be examined in more than 1 way
set ("id", ({ "campfire", "fire" }) );

    //the short is what you see in an inventory, or on the ground
set ("short", "A tiny campfire");

    //long is what is seen after the player examines it
    //the @EndText makes it a bit easier to code
    set ("long", @EndText
A tiny campfire burns here...too small to burn anything or 
warm yourself. Just a circle drawn with a stick in the earth around
it seems to contain the fire.
EndText
    );

    //mass is how much it weighs
    set ("mass", 0);

    //this is how much you would get for it in the shop
    set ("value", 0);

    //the prevents are for those items you don't want passed out.
set ("prevent_drop", 0);
    set ("prevent_insert", 1);
    set ("prevent_give", 1);
}

