/*
  thiefling.c
  
  Thiefling.
  
  Gives bonus to thievery and stealth. Gives more bonus if you're a Tiefling.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

inherit RING;

sting owner;

void create()
{
    ::create();
    
    set_name("thiefling");
    set_id( ({ "ring", "thiefling ring", "thief ring", "thiefling" }) );
    set_short("");
    set_obvious_short("");
    set_long("");
    set_lore("");
    set_property("lore difficulty", 40);
    set_property("id difficulty", 40);
    set_value(10000);
    set_flag_required("boss avatar");
    //set_property("enchantment", 7);
    //set_heart_beat(1);
    set_wear((:this_object(),"wear_fun":));
    set_remove( (: this_object(),"remove_fun" :) );
}

int wear_fun()
{
    int align;
    
    align = this_player()->query_true_align();
    
    if(!this_player()->is_class("thief"))
    {
        tell_object(this_player(), "The ring slips through your fingers!");
        return 0;
    }
    
    if(!strlen(owner))
    {
        owner = this_player()->query_name();
        tell_object(this_player(), "The ring pulses furiously for a moment as you put it on");
    }
    else
    {
        if(owner != this_player()->query_name())
        {
            tell_object(this_player(), "This is not your ring!");
            return 0;
        }
    }
    
    if(this_player()->query("subrace") == "tiefling")
    {
        set_item_bonus("stealth", 7);
        set_item_bonus("thievery", 7);
    }
    else
    {
        set_item_bonus("stealth", 6);
        set_item_bonus("thievery", 6);
    }
    
    tell_object(this_player(), "The ring slides onto your finger, and you feel it sharpen your skills!");
    
    return 1;
}

int remove_fun()
{
    tell_object(this_player(), "You remove the ring and feel its dark power leave you.");
    return 1;
}
    
    