// QC Passed - Cyanide

#include <mudlib.h> 

inherit WEAPON;

void create() {
    seteuid(getuid());
    set("author", "cattt");
    set("name", "nails");
    set("id", ({ "nails", "acrylic nails" , "fake nails" }) );
    set("short", "a set of acrylic nails");
    set("long", 
      "A cheap pair of fake acrylic nails. The look like they could hurt.\n");
    // For something like this, you can set the size to -1.
    // That means anybody can use them...
    // set("size", 3);
    set("size", -1);

    // We never use this anymore...
    // set("weapon", 3);

    set("type","cutting");
    set_weapon_type("dagger");
    set("nosecond",1);

    /* We try not to set mass manually. Thats taken care of by 
    ** the set_weapon_type() function.
	set("bulk", 5);
	set("mass",10);
    */

    // This type of value setting we never, never use anymore.
    // Let me know where you found this...  I want to get
    // rid of it.

    // set("value",({ 30, "copper" }) );
    set("value", 1);

    set("damage",({ 2, 5 }) );
    set_verbs( ({ "scratch", "slash", "cut into" }) );
    set_verbs2( ({ "scratches", "slashes", "cuts into" }) );
}
