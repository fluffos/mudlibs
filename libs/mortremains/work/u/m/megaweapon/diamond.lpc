/* File: diamond.c
// Purpose: A gem or somthing.
// Date: September somthing.
*/

#include <mudlib.h>

inherit OBJECT;
   void create(){
   seteuid(getuid());
   set("id", ({ "diamomd", "gem" }) );
//id makes it able to be examined
   set("short", "a diamond");
//short is what you see w/o examineing it
   set("long", @Gem
This is a rather large diamond. It looks like it may bring a good 
price at the local gem shop.
Gem
//the long is what you get when you examine the object. the @Gem
//statement allows you to put the description in w/o haveing to use
// n\"+ all the damn time.
  );
   set("value", 1000);
//value is how much you would get in the shop
 }
