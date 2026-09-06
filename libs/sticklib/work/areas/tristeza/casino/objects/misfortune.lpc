/******************************************************************
  Wheel of Misfortune
  Coded by: Germ
  Last modified: Feb 7, 96

  Comments:  

  This wheel was originally Doomdark's idea.  Basically, bad things
  might happen to whoever spins it.  Currently, these bad things can 
  happen:

    - maybe nothing bad happens
    - lose 50% - 100% of your gold
    - Insane gambler appears, attacks, and probably MKs you
    - Blinded for a random amount of heartbeats
    - Poisoned ""
    - Hallucinated ""
    - Knocked unconsious ""
    - Random stats drained
    - Teleported to a faraway and seldom visited place: 
	 - dinosaur land (asahi)
	 - prison cell in haunted castle (asahi)
	 - hell (kantele's mansion)
	 - tunnels north of titan's area
	 - orc prison cell at faraway mountains
	 - underground lake (orctown)

  After each spin of the wheel, regardless of the outcome, a
  small amount of gold coins fall out of the wheel.  Maybe
  greedy players will keep spinning. Hehehe.

  The bad things don't happen immediately, but are delayed
  by a random amount of time so that they might not be
  associated with the wheel right away.

  This wheel currently is placed in the casino storage area
  which is not very easy to get to. 

  Things to do:
    - Perhaps forcing casino criminals to spin the wheel
      instead of MKing them? 

*******************************************************************/

#include <treasure.h>
#include <conditions.h>
#include <stats.h>
#include <areas.h>
#include <generic_items.h>

#include "../casino.h"

#define RECORD_SPINS 1       /* 1=record them, 0=don't */ 
#define WHEEL_LOG "LOGS/MISFORTUNE.LOG"
#define TP this_player()
#define QN query_name()
#define QRN query_real_name()
#define TRUE 1
#define FALSE 0
#define SPACER_CHAR "*"
#define VIEW_ALL_BETS "_X"
#define SPIN_DELAY 3 

#define DELAY(X) (random(X)+2) /** delay till badness takes effect **/


/*******************************************************************/
/*********************** function prototypes ***********************/
status spin_wheel();
status wheel_stopped( object person );
void spinning( string message );

/*******************************************************************/
/************************* global vars *****************************/

int spinning;           /* Is the wheel currently spinning? */
int number_of_spins;    /* Total spins since reset */

object this_room;

/*******************************************************************
  Create the object and stuff
 *******************************************************************/

void create_treasure()
{


    set_id( ({"wheel","stone wheel"}) );
    set_short("A large stone wheel");

    set_long("It is a large stone wheel oriented vertically in front\
 of you, vaguely reminiscent of the wheel of fortune in the casino\
 above.  Closer inspection reveals nothing except a series of\
 strange symbols faintly visible around the rim of the wheel. \
 The function of the wheel is not apparent, but you might\
 be able to spin it if you tried.");


    /** initialize global vars **/

    spinning = FALSE;
    number_of_spins = 0;

}


status get() { return 0; }

void init_treasure()
{
    add_action("spin_cmd", "spin");
    this_room = environment(TP);

}




/***************************************************************************
  Process the spin command
 ***************************************************************************/

status spin_cmd(string arg)
{
    string temp, win_symbol;

    if (!arg || sscanf(arg, "%s", temp) != 1 || temp!="wheel" )
    {
	notify_fail("Spin what?\n"); 
	return 0;
    }


    if ( spinning == TRUE )
    {
	notify_fail("The wheel is already spinning.\n");
	return 0;
    }


    TP->tell_me("Ok. You give the wheel a big spin!"); 
    this_room->tell_here(TP->QN + " gives the wheel a big spin!", TP ); 

    number_of_spins++;

    call_out( "spinning", 1, "The wheel spins...");
    call_out( "spinning", SPIN_DELAY+1, "The wheel slows...");
    call_out( "spinning", SPIN_DELAY+2, "You feel a powerful sense of foreboding...");
    call_out( "wheel_stopped", SPIN_DELAY+3, TP );


    return 1;
}





/****************************************************************************
  Evaluate the bets and payoff the winners
****************************************************************************/

status wheel_stopped( object person )
{  
    int x, result;
    string what;
    object money;

    this_room->tell_here("The wheel stops.");

    if ( !random( 3 ))
	switch( random( 12 ) )
    {
    case 0: what="disease";
	person->set_disease();
	break;                                        /** disease **/
    case 1: what="lost gold"; 
	call_out("lost_gold", DELAY(1), person );
	break;                                       /** lost gold **/
    case 2: what="monster"; 
	call_out("gen_monster", DELAY(5) );
	break;                                       /** monster  **/
    case 3: what="blind";
	call_out("set_blind", DELAY(3), person );
	break;                                       /** blind    **/
    case 4: what="poisoned";
	call_out("set_poisoned", DELAY(3), person );
	break;                                       /** poisoned  **/
    case 5: what="high";
	call_out("set_high", DELAY(10), person );
	break;                                       /** high    **/
    case 6: what="unconscious";
	call_out("set_unconscious", DELAY(10), person );
	break;                                       /** unconscious **/
    case 7: what="drained";
	call_out("set_drained", DELAY(2), person );
	break;                                       /** drained   **/
    case 8: case 9: case 10: case 11:
	what="teleported";
	call_out("set_teleport", DELAY(10), person );
	break;                                       /** teleported **/
    }
    else
	what = "nothing";

    x = random( 100 )+10;               /** coins fall out of the wheel **/
    this_room->tell_here(x+" gold coins fall out of the wheel!\n");
    money = clone_object(GENERIC_MONEY_OBJECT);
    money->set_money( x );
    move_object( money, this_room );



#if RECORD_SPINS == TRUE        
    if (( what != "nothing" )
      && !( person->query_coder_level()) )     /** lets not log coders **/
	write_file( AREA_PATH+WHEEL_LOG, capitalize(person->query_name())
	  +", "+what+", "
	  +number_of_spins +"\n" );
#endif

    spinning = FALSE;

    return 1;
}

/***************************************************************************
***************************************************************************/

void lost_gold( object person )
{
    int i;

    i = person->query_money();

    person->add_money( random(i/2) - i + 1 );  /* subtract player's cash */

}



/***************************************************************************
***************************************************************************/


void gen_monster()
{

    this_room->add_monster( AREA_PATH+"gambler", 
      "Suddenly an insane gambler comes screaming out of the shadows!", 1);

    this_room->tell_here("Gambler screams: Stay away from my wheel of fortune!!!");

}


/***************************************************************************
***************************************************************************/

void set_blind( object person )
{
    this_room->tell_here("Suddenly there is a bright flash of light!!");
    person->set_condition(C_BLIND, 10+random(10) );
}


/***************************************************************************
***************************************************************************/

void set_poisoned( object person )
{
    person->tell_me("Ouch, your hand is stinging. You notice a rash!!");
    person->set_condition(C_POISONED, 50+random(50) );
}

/***************************************************************************
***************************************************************************/

void set_high( object person )
{
    person->tell_me("Suddenly you begin to feel a bit strange.");
    person->set_condition(C_HALLUCINATING, 50+random(50) );
}


/***************************************************************************
***************************************************************************/

void set_unconscious( object person )
{
    person->tell_me("WHAM! Something hits you from behind! You pass out!");
    this_room->tell_here("WHAM! Something hits "
      +person->query_name()+" on the head!", person);

    person->set_condition(C_UNCONSCIOUS, 5+random(10) );
}


/***************************************************************************
***************************************************************************/

void set_drained( object person )
{
    int i;

    this_room->tell_here(
      "Without warning, a glowing green light pulses from the wheel!");

    for ( i=0; i<4; i++ )
	if ( !random(3) )
	    person->add_stat( i, -(random(2)+1) );

}


/***************************************************************************
***************************************************************************/

void set_teleport( object person )
{
    string dest;
    string *dests;

    dests = ({
#ifdef AREA_ASAHI
      AREA_ASAHI "prehistory/p11",
      AREA_ASAHI "haunt/cell",
#endif
#ifdef AREA_KANTELES
      AREA_KANTELES "room/hell11",
#endif
#ifdef AREA_OGRE_VALLEY
      AREA_OGRE_VALLEY "ot22",
#endif
#ifdef AREA_FARAWAY
      AREA_FARAWAY "orclair/cell",
#endif
#ifdef AREA_ORCTOWN
      AREA_ORCTOWN "lake/tunnel12",
#endif
    });
    dest = dests[random(sizeof(dests))];
    person->tell_me("WHAM! Something hits you from behind! You see stars!");

    this_room->tell_here("WHAM! Something hits "
      +person->query_name()+" on the head!", person);

    person->set_condition(C_BLIND, 5 + random(5) );   

    person->move_player(" here, dragged away by an indistinct shadowy form", dest );

}



/***************************************************************************
  Called by call_out to display the "wheel spins" messages 
***************************************************************************/

void spinning( string message )
{
    this_room->tell_here( message );
}


/***************************************************************************/
/***************************************************************************/

