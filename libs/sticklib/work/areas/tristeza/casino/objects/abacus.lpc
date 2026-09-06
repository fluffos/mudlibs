/*****************************************************************************
  Abacus 
  Coded by: Germ
  Last modified: Feb 7, 1996

  The abacus functions like the HP-SP reporter with gold coins.
  When it is turned on, each heartbeat the abacus compares the gold
  that a player has with the gold they had on the previous heartbeat
  and reports the difference, if any.  If the abacus is turned off
  or dropped, its heartbeat function is also turned off.

  It is pretty cool in the casino to keep track of your long-term
  profits/losses.

  We probably don't want too many of these wandering around the mud
  because the have a heartbeat (only if they are carried by a player).

*****************************************************************************/

#include "/sys/configuration.h"

#include <treasure.h>

int start_gold,gold,previous_gold;
object player;

void
create_treasure()
{
    set_short("A small stone abacus");
    set_long("It is a small stone rectangle with several columns of beads.\
 You can use it to help keep track of your finances with\
 'abacus <on/off/reset>.'");

    set_id("abacus");
    set_weight(1);
    set_value(1000);


}

void init_treasure()
{
    add_action("abacus", "abacus");

    player=this_player();

    if ( !interactive( environment() ))
	configure_object(this_object(), OC_HEART_BEAT, 0); /* turn off heartbeat if not being carried */
    else
	configure_object(this_object(), OC_HEART_BEAT, 1); /* turn on heartbeat if carried */

    gold = player->query_money();
    start_gold = gold;
}


int get() { return 1; }
int drop() { return 0; }




void heart_beat()
{

    if ( environment() == player )
    {
	previous_gold = gold;
	gold = player->query_money();
	/** if gold has decreased */
	if ( previous_gold > gold )
	    player->tell_me("Abacus: gold is now "+gold
	      +" ( -"+( previous_gold-gold)
	      +" ) ( "+(gold-start_gold)+" so far ).\n");

	else                            /** if gold has increased */
	if ( gold > previous_gold )
	    player->tell_me("Abacus: gold is now "+gold
	      +" ( +"+( gold-previous_gold )
	      +" ) ( "+(gold-start_gold)+" so far ).\n");
    }
    else
    if ( interactive( environment() ))
    {
	player = environment();
	gold = player->query_money();
	start_gold = gold;
    }
    else
	configure_object(this_object(), OC_HEART_BEAT, 0);

}


status abacus( string arg )
{
    string temp;

    if (!arg || sscanf(arg, "%s", temp) != 1 )
	return 0;

    if ( !living( environment() ))
    {
	notify_fail("You don\'t have the abacus.\n");
	return 0;
    }

    if ( temp == "on" )
    {
	configure_object(this_object(), OC_HEART_BEAT, 1);
	player->tell_me("The abacus is now on.\n");
	return 1;
    }

    if ( temp == "off" )
    {
	configure_object(this_object(), OC_HEART_BEAT, 0);
	player->tell_me("The abacus is now off.\n");
	return 1;
    }

    if ( temp == "reset" )
    {
	player->tell_me("Ok you reset the abacus.\n");
	return 1;
    }


    return 0;
}
