/* File: diamond.c
// Purpose: A gem or somthing.
// Date: September somthing.
*/

#include <mudlib.h>

inherit OBJECT;

void create(){
    seteuid(getuid());

    //id makes it able to be examined
    set("id", ({ "diamomd", "gem" }) );

    //short is what you see w/o examineing it
    set("short", "a diamond");

    //the long is what you get when you examine the object. the @Gem
    //statement allows you to put the description in w/o haveing to use
    // n\"+ all the damn time.
    set("long", @Gem
This is a rather large diamond. It looks like it may bring a good 
price at the local gem shop.
Gem
    );

    //value is how much you would get in the shop
    set("value", 1000);
}
