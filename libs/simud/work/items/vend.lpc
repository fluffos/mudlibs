#include <const.h>

//
// Coded By      : Silvermane (sylvermane@hotmail.com)
// Created On    : 19th Jan 2002
// Last Modified : 20th Jan 2002 by Silvermane
//
// Description   : Multi-Product Vending Machine.
//                 It a vending machine that can deliver multiple item types!
//
// Modified by Acius

inherit "/obj/trinket";

// Create global variable for the buttons
string *button_map;

DISTANT( "a multi-product vending machine" )
SPECIFIC( "the multi-product vending machine" )
ALT_NAME( ({ "machine", "vending machine" }) )
PLURAL( "multi-product vending machines" )
ALT_PLURAL( ({ "machines", "vending machines" }) )
TASTE( "It tastes like commerce." )

void create()
{
    ::create();
    set_name("vend");
}

string query_look() {
   string buf;
   int i;

   buf = "This is a vending machine; it's basically a way for us to distribute goods until we " +
      "have the shopkeepers working properly. For the moment, it doesn't cost you anything to use it.\n" +
      "Available products:\n";
   for( i = 0; i < sizeof(button_map); i++ ) {
      buf += "   " + (i+1) + ".  " + capitalize(button_map[i]->query_distant()) + "\n";
   }
   buf += "To buy something, 'push button #' where # is from the list above.";
   return buf;
}

void init()
{
    ::init();

    // Add a verb for PUSH and PRESS
    add_action("press_button", "press");
    add_action("press_button", "push");

    // Initialise the button mappings
    button_map = ({
                    "/items/food/flour",
                    "/items/food/egg",
                    "/items/food/salt",
                    "/items/food/yeast" });
}

int press_button(string s)
{
   WALK_ACTION_PARAM( 1000, this_object(), s );
   return 1;
}

string query_action_name() {
   return "Push button";
}

void on_action( object t, string s ) {
    object ob;
    int ibutton;

    if( !s || sscanf(s, "button %d", ibutton) != 1 ) {
       notify_fail("Press what?\n");
       return 0;
    }

    ibutton--;
    if( ibutton < 0 || ibutton >= sizeof(button_map) ) {
        notify_fail("You must press a button number between 1 and "+(sizeof(button_map)+1)+"!\n");
        return;
    }

    // Notify the player that he/she has pressed a button successfully

    this_player()->msg_local("~CACT~Name ~verbpress a button on " +
                             "the multi-product vending machine.~CDEF");

    // Create the object from the mapping and tell the player it has
    // gone into his/her inventory

    ob = clone_object(button_map[ibutton]);
    if( ob->query_liquid() ) {
       object iinv, sack;

       sack = 0;
       foreach( iinv: all_inventory(this_player()) ) {
          if( iinv->query_container() && sizeof(all_inventory(iinv)) == 0 )
             sack = iinv;
       }
       if( !sack ) {
          msg("You don't have an empty container to put it in! You need to get one.");
          return;
       }
       ob->move( sack );
       ob = sack;
    }
    else
       ob->move(this_player());

    // Just in case the distant string isnt set we will check
    if(ob->query_distant() != 0)
        msg("Suprise, " + ob->query_distant() + " falls into your grubby paws.");
    else
        msg("Suprise, an item falls into your grubby paws.");
}

ICON( '#', 15, LAYER_FURNITURE )
