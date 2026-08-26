/*
  nature_circlet.c
  
  Circlet of Nature's Kiss
  Submitted by Saralona
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

inherit ARMOUR;

void create()
{
    ::create();
    
    set_name("circlet");
    set_id( ({ "circlet", "circlet of natures kiss", "nature circlet" }) );
    set_short("Circlet of Nature's Kiss");
    set_obvious_short("A circlet formed from wild growth");
    set_long("A simple band of carved and polished ash sits upon the brow, its length entwined with the verdant, still living foliage that it is formed from. Lacking embellishment, all that sets it aside from its contemporaries is that it's made from still living vines- the wild growth sprouting thorns and flowers as te wearer moves.");
    set_lore("");
    set_property("lore difficulty", 40);
    set_property("id difficulty", 40);
    set_ac(0);
    set_value(10000);
    set_limbs( ({ "head" }) );
    set_property("enchantment", 7);
    set_item_bonus("perception", 6);
    set_item_bonus("wisdom", 6);
    set_type("clothing");
    set_wear((:TO,"wear_fun":));
}

