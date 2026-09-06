/******************************************************************
  Wheel of Fortune
  Coded by: Germ
  Last modified: Feb 12, 95

  Modification history:
     (2/12/96) - Coder's games are no longer logged or used
		 for profit/loss stats.

  Comments:  I have tried to model this wheel as closely as 
	     possible to the real wheels.  The symbols and
	     payoffs are the same, so the odds should be
	     as well, depending on how random the random()
	     function is.

	     Obviously we don't want bugs in the wheel to
	     give free money to players.  I have tried to
	     safeguard against this in two ways:  shutting
	     down the wheel if it loses too much gold, and
	     shutting it down if random() returns wacky
	     values.  It would also be possible to shut
	     it down if random() returns the same value
	     too many times in a row.  Maybe I will 
	     implement this later.


*******************************************************************/

#include <treasure.h>
#include "../casino.h"

#define RECORD_WINS 1       /* 1=record them, 0=don't */ 
#define RECORD_LOSS 1       /* 1=record them, 0=don't */
#define RECORD_PROFITS 1

#define WHEEL_LOG "LOGS/WHEEL.LOG"
#define PROFIT_LOG "LOGS/wheel.profits"
#define TP this_player()
#define QN query_name()
#define QRN query_real_name()
#define NAME capitalize(name_array[x])
#define TRUE 1
#define FALSE 0
#define SPACER_CHAR "*"
#define VIEW_ALL_BETS "_X"
#define SPIN_DELAY 3
#define WHEEL_SIZE 55          /* Total number of symbols + 1       */
#define SYMBOLS 7              /* Number of unique symbols on wheel */
#define MIN_BET 100
#define MAX_BET 10000
#define BROKEN_THRESHOLD 1000000  /* Something is wrong if the  */
/* wheel loses more than this. */

/*******************************************************************/
/*********************** function prototypes ***********************/
string spin_wheel();
status wheel_stopped( string symb );
int get_bets( string forwho );
void spinning( string message );

/*******************************************************************/
/************************* global vars *****************************/

int wheel_profits;      /* The cumulative profit since reboot */
int last_profits;       /* Profits at last reset              */
int bet_volume;         /* Total bet volume since reboot      */
int win_payoff;         /* The winning symbol from the spin   */
int spinning;           /* Is the wheel currently spinning?   */
int broken;             /* Did the wheel give away too much?  */
int number_of_spins;    /* Total spins since boot             */
int number_of_bets;     
string syms,names,bets;

object this_room;

/*******************************************************************
  Create the object and stuff
 *******************************************************************/

void create_treasure()
{
    int min,max;
    string desc;
    min = MIN_BET;
    max = MAX_BET;


    desc = "It is a large wheel oriented vertically in front of you.\
 The outer rim of the wheel shows a collection of symbols: \n\n\
    Symbol    How many on the wheel   payoff \n\
   ------------------------------------------\n\
      1x             24                1:1 \n\
      2x             15                2:1 \n\
      5x              7                5:1 \n\
      10x             4               10:1 \n\
      20x             2               20:1 \n\
     house            1               45:1 \n\
     joker            1               45:1 \n\n\
You can \'bet <amount> on <symbol>\', \'spin wheel\', and\
 \'view bets\'.  Currently, the minimum bet is "+min+" and\
 the maximum bet is "+max+".\n";

    if ( (int)(TP->query_coder_level()) > 0 )
	desc += "Coders can also \'view profits\'.\n";

    set_id( ({"wheel","wheel of fortune"}) );
    set_short("A large stone wheel of fortune");
    set_long( desc );


    /** initialize global vars **/

    names = "";
    bets = "";
    syms = "";
    spinning = FALSE;
    broken = FALSE;
    number_of_bets = 0;
    number_of_spins = 0;
    wheel_profits = 0;
    bet_volume = 0;

}


status get() { return 0; }

void init_treasure()
{
    add_action("bet_cmd", "bet");
    add_action("spin_cmd", "spin");
    add_action("view_cmd", "view");
    this_room = environment(TP);

}



/********************************************************************/

void reset_treasure()
{

#if RECORD_PROFITS != 0
    if ( wheel_profits != last_profits )
    {
	write_file( AREA_PATH+PROFIT_LOG,
	  "Profits = "+wheel_profits+", Volume = "+bet_volume
	  +"Spins = "+number_of_spins+", "+ctime(time())+"\n");

	last_profits = wheel_profits;
    }
#endif
}




/*******************************************************************
  Process the bet command
*******************************************************************/

status bet_cmd(string arg)
{
    object tm;
    int howmuch;
    string symb;

    if (!arg || sscanf(arg, "%d on %s", howmuch, symb) != 2 )
    {
	notify_fail("Usage: 'bet <amount> on <symbol>'.\n"); 
	return 0;
    }

    if ( !present("dealer", this_room ))
    {
	notify_fail("The dealer is not here.\n");
	return 0;
    }


    if ( spinning == TRUE )
    {
	notify_fail("Dealer tells you: You cannot bet while the wheel is spinning.\n");
	return 0;
    }


    /* Broken can only happen if the wheel loses more than BROKEN_THRESHOLD */
    /* or if random() generates an incorrect number.                        */

    if ( broken == TRUE )
    {
	notify_fail("Dealer tells you: The wheel is broken.  Please try again later.\n");
	return 0;
    }


    if (howmuch < MIN_BET )
    {
	notify_fail("Dealer tells you: The minimum bet for this wheel is "+MIN_BET+"\n");
	return 0;
    }

    /* without a betting limit, a rich player can never lose */

    if ( howmuch > MAX_BET || get_bets(TP->QRN)+howmuch > MAX_BET )
    {                
	notify_fail("Dealer tells you: The maximum bet for this wheel is "
	  +MAX_BET+ " per player.\n");
	return 0;
    }

    if (TP->query_money() < howmuch )
    {
	notify_fail("Dealer tells you: You cannot bet what you don\'t have!\n");
	return 0;
    }

    if ( symb!="1x" && symb!="2x" && symb!="5x"
      && symb!="10x" && symb!="20x" 
      && symb!="joker" && symb!="house" ) 
    {
	notify_fail("Dealer tells you: You must bet on one of the valid wheel symbols.\n");
	return 0;
    }

    TP->tell_me("Ok. You bet "+howmuch+" gold on "+symb+".");

    environment(TP)->tell_here(
      TP->QN + " has bet "+howmuch+" gold on "+symb+".", TP);

    TP->add_money(-(howmuch));         /* subtract the bet from player's cash */

    /* record the bet */

    names = names + TP->QRN + SPACER_CHAR;    
    syms = syms + symb + SPACER_CHAR;
    bets = bets + (string)howmuch + SPACER_CHAR;

    if ( !( TP->query_coder_level()) )
	bet_volume += howmuch;

    number_of_bets++;

    return 1;
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

    if ( !present("dealer", this_room ))
    {
	notify_fail("The dealer is not here.\n");
	return 0;
    }


    if ( spinning == TRUE )
    {
	notify_fail("The wheel is already spinning.\n");
	return 0;
    }

    if ( number_of_bets == 0 )
    {
	notify_fail("Dealer tells you: The wheel cannot be spun without any bets.\n");
	return 0;
    }

    TP->tell_me("Ok. The dealer gives the wheel a big spin!"); 
    this_room->tell_here(TP->QN + " nods to the dealer,"
      +" who then gives the wheel a big spin!", TP); 


    /* make sure that random() returns a number in the correct range */

    if (( win_symbol = spin_wheel()) == "error" )
    {
	broken = TRUE;
	notify_fail("The wheel makes a grating noise. It is obviously broken.\n");
	return 0;
    }

    /*** everything seems ok...spin it! ***/

    call_out( "spinning", 1, "The wheel spins...");
    call_out( "spinning", SPIN_DELAY+1, "The wheel slows...");
    call_out( "wheel_stopped", SPIN_DELAY+2, win_symbol );

    if ( !( TP->query_coder_level()) )
	number_of_spins++;

    return 1;
}



/****************************************************************************
  Process 'view bets' and 'view profits'
 ****************************************************************************/

status view_cmd(string arg)
{
    string temp;
    int tmp; 

    if (!arg || sscanf(arg, "%s", temp) != 1 )
    {
	notify_fail("View what?\n");
	return 0;
    }

    if ( temp == "bets" )
    {
	tmp = get_bets( VIEW_ALL_BETS );      /* show the bets list */
	return 1;
    }

    /*** only coders can check profits ***/

    if ( temp == "profits" && (int)(TP->query_coder_level()) > 0 ) 
    {
	TP->tell_me("The total profits for this machine are " + wheel_profits 
	  + " in " + number_of_spins + " spins.\n");

	TP->tell_me("Total bet volume: "+bet_volume+" coins.");

	return 1;
    }

    notify_fail("view what?\n");
    return 0;

}


/****************************************************************************
  Generate and return the winning symbol from the wheel
 ****************************************************************************/

string spin_wheel()     
{
    int num;
    string k;

    num = random( WHEEL_SIZE );  /* hope this doesnt break or we are hosed */

    if (num<0)  { k = "error"; win_payoff = 0; }
    else
    if (num<24) { k = "1x"; win_payoff=1; }       /* 24 syms, 1:1 payoff  */
    else
    if (num<39) { k = "2x"; win_payoff=2; }       /* 15 syms, 2:1 payoff  */
    else
    if (num<47) { k = "5x"; win_payoff=5; }       /*  7 syms, 5:1 payoff  */
    else
    if (num<51) { k = "10x"; win_payoff=10; }     /*  4 syms, 10:1 payoff */
    else
    if (num<53) { k = "20x"; win_payoff=20; }     /*  2 syms, 20:1 payoff */
    else
    if (num==53) { k = "house"; win_payoff=45; }  /*  1 sym,  45:1 payoff */
    else
    if (num==54) { k = "joker"; win_payoff=45; }  /*  1 sym,  45:1 payoff */
    else
    { k = "error"; win_payoff = 0; }

    spinning = TRUE;
    return k;
}



/****************************************************************************
  Evaluate the bets and payoff the winners
****************************************************************************/

status wheel_stopped( string symb )
{  
    int x, result;
    string *name_array, *sym_array, *bet_array;
    object person;


    this_room->tell_here("The wheel stops on " + symb + "!");

    name_array = allocate(number_of_bets);
    sym_array = allocate(number_of_bets);
    bet_array = allocate(number_of_bets);

    /** convert the strings to arrays ***/  

    name_array = explode( names, SPACER_CHAR );
    sym_array = explode( syms, SPACER_CHAR );
    bet_array = explode( bets, SPACER_CHAR );

    for ( x=0; x<number_of_bets; x++)
    { 
	if ( person=present(name_array[x], this_room) )
	{
	    if ( symb == sym_array[x] )
	    {                                        /* this bet won */
		result = win_payoff*(int)bet_array[x];

		person->tell_me("You win "+result+" gold coins on "+sym_array[x]+".\n"); 

		this_room->tell_here( person->QN
		  +" has won "+result+" gold coins on "+sym_array[x]+".\n",person);

		person->add_money(result+(int)bet_array[x]);

		if ( !( person->query_coder_level()) )
		    wheel_profits -= result; 

#if RECORD_WINS == TRUE
		if ( !( person->query_coder_level()) )     /** lets not log coders **/
		    write_file( AREA_PATH+WHEEL_LOG,
		      NAME+", "+result+", "+sym_array[x]+", "
		      +wheel_profits+", "+ number_of_spins +"\n" );
#endif

	    }
	    else
	    {                                        /* this bet lost */
		result = (int)bet_array[x];

		person->tell_me("You lose "+result+" gold coins on "+sym_array[x]+".\n");

		this_room->tell_here( person->QN
		  +" has lost "+result+" gold coins on "+sym_array[x]+".\n",person);

		if ( !( person->query_coder_level()) )
		    wheel_profits += result;

#if RECORD_LOSS == TRUE        
		if ( !( person->query_coder_level()) )     /** lets not log coders **/
		    write_file( AREA_PATH+WHEEL_LOG,
		      NAME+", "+ -result+", "+sym_array[x]
		      +", "+wheel_profits+", "+ number_of_spins +"\n" );
#endif

	    } 
	}
	else                                       /* winner isnt here */
	if ( person = find_player(name_array[x]) )
	{
	    if ( symb == sym_array[x] )
		this_room->tell_here("Dealer says: "+person->QN
		  +" is not here to collect the winnings.\n"); 

	    if ( !( person->query_coder_level()) )
		wheel_profits += (int)bet_array[x];
	}
    }

    if ( wheel_profits < -BROKEN_THRESHOLD )
    {
	broken = TRUE;
	this_room->tell_here("Suddenly you hear a grinding noise from the wheel!\n");
    }

    names = "";
    syms = "";
    bets = "";

    spinning = FALSE;
    number_of_bets = 0;

    return 1;
}



/***************************************************************************
  if forwho=VIEW_ALL_BETS, write a list of players, bets, and symbols
  else return the amount bet by the player=forwho
***************************************************************************/

int get_bets( string forwho )
{
    int x, bet_total;
    string *name_array, *sym_array, *bet_array;

    bet_total = 0;
    if ( number_of_bets > 0 )
    { 
	name_array = allocate(number_of_bets);
	bet_array = allocate(number_of_bets);

	name_array = explode( names, SPACER_CHAR );
	bet_array = explode( bets, SPACER_CHAR );

	if ( forwho != VIEW_ALL_BETS )
	{
	    for ( x=0; x<number_of_bets; x++ )
	    {
		if ( forwho == name_array[x] )
		    bet_total += (int)bet_array[x];
	    }
	    return bet_total;
	}

	sym_array = allocate(number_of_bets);
	sym_array = explode( syms, SPACER_CHAR );

	for ( x=0; x<number_of_bets; x++ )
	    write( NAME + " has bet "+bet_array[x]+" on "+sym_array[x]+".\n");

    }
    else
    if ( forwho == VIEW_ALL_BETS )
	write("No bets have been made.\n");

    return 0;
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

