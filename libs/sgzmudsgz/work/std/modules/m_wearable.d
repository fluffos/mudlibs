// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** wearable.c
**
** Mixed in to create a wearable item.  The client should also
** mix in M_GETTABLE.
**
** 07-Sep-94. Created. Rust/Belboz.
** 12-Nov-94. Updated for "modules" approach. Deathblade.
*/

#include <mudlib.h>

inherit OBJ;
void hook_state(string, string, int);

//### Huh?  This appears to be unused.
private static string   wearmsg;
private static int      is_on;
#ifdef USE_BODYSLOTS
private static string   slot;
#endif

mixed ob_state() {
    if (!is_on) return 0;
#ifdef USE_BODYSLOTS
    return slot;
#else
    return 1;
#endif
}

void
remove() {
#ifdef USE_BODYSLOTS
    if(!slot)
        return 0;
    environment()->depopulate_body_slot(slot, this_body());
#endif        
}
//:FUNCTION set_wearmsg
//Set the message used when an object is worn.
void
set_wearmsg( string s )
{
  wearmsg = s;
}

//:FUNCTION query_wearmsg
//Return the message given when an object is used.
string
query_wearmsg()
{
  return wearmsg;
}


#ifdef USE_BODYSLOTS
//:FUNCTION set_slot
//Set the bodyslot that the wearable object takes up.
void
set_slot(string what)
{
    slot = what;
}

//FUNCTION query_slot
//Return the bodyslot the wearable object takes up.
string
query_slot()
{
    return slot;
}

#endif

//:FUNCTION set_is_on
//set_is_on(1) causes an object to become worn.  set_is_on(0) removes it.
void
set_is_on( int g )
{
  is_on = g;
  hook_state("extra_short", "穿戴着", is_on);
  hook_state("prevent_drop", "你要先把它脱下来。\n", is_on);
}

//:FUNCTION do_wear
//Makes the object worn and prints an appropriate message.
void
do_wear()
{
#ifdef USE_BODYSLOTS
    if(!slot)
        return;
    if(!environment()->populate_body_slot(slot, this_body()))  {
//        this_body()->simple_action(//"$N $vdiscover $ns cannot wear $o.\n"
//                                   "$N发现$n不能穿$o。\n", this_object());
//        return;
    }
    
#endif
    set_is_on(1);
    this_body()->simple_action(//"$N $vwear a $o.\n"
                               "$N穿上一件$o。\n", this_object());
}

//:FUNCTION do_remove
//Removes an object and prints an appropriate message.
void
do_remove() {
#ifdef USE_BODYSLOTS
    if(!slot)
        return 0;
    environment()->depopulate_body_slot(slot, this_body());
#endif        
    set_is_on(0);
    this_body()->simple_action(//"$N $vremove $p $o.\n"
                               "$N脱下$o。\n", this_object());
}

//:FUNCTION direct_wear_obj
//Handle parser checks for "wear OBJ"
mixed  direct_wear_obj() {
    
    object who = owner(this_object());

    if (who != this_body())
        return 0;                                       
    if(!this_body()->has_body_slot(slot))  
        return "你看不出该把它穿在哪儿。\n";//"You can't seem to find anywhere to put it on!\n";
    if( is_on )                                         
        return "你正穿着呢！\n";//"But you're already wearing it!\n";
    return 1;
}

//:FUNCTION direct_remove_obj
//Handle parser checks for "remove OBJ"
mixed direct_remove_obj() {
    
    object who = owner(this_object());

    if (who != this_body())
        return 0;                                 
    if (environment() != this_body() || !is_on)
        return "你根本就没有穿它！\n"; //"But you aren't wearing it!\n";
    return 1;
}
