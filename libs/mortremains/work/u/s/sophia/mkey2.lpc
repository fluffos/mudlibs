
#include <mudlib.h>

inherit OBJECT ;

void create() {
seteuid(getuid());
    set("author", "sophia");

    //the id makes it able to be examined in more than 1 way
set ("id", ({ "maple key", "key" }) );

    //the short is what you see in an inventory, or on the ground
set ("short", "A maple key");

    //long is what is seen after the player examines it
    //the @EndText makes it a bit easier to code
    set ("long", @EndText
It looks like an ordinary maple key, the kind you played helicoptor with 
when you were a child; might as well toss it in the fire.
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

void init() {
 add_action("toss", "toss");
}

int toss(string str) {
   if (str == "key in the fire") {
     write("You whip the key into the fire.\n");
     say(TPN+" whips a maple key into the fire.\n");
   remove();
   return 1;
 }
return 1;
}
