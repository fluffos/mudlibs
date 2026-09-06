/******************************************************************
  Roulette 
  Coded by: Germ
  Last modified: Feb 12, 1996 

  Modification history:
    (2/12/96) - Lowered maximum bet to 10K
	      - Prevent coder's bets from being included in
		profit/loss records and logfile. 
    (2/19/96) - Fixed bug in max bets/player checking.

  Comments:   

  This pretty much exactly models a real roulette wheel.  It is
  a European style wheel using only "0" as opposed to "0" and "00".
  However, I have not implemented combination betting because it
  would be a pain to code.  It is also unnecessary since the same
  player can place multiple bets.  Also, the European "en prison"
  rule is NOT in effect.

  The house margin for roulette is:

      American wheel using "0" and "00" : 5.26%
      European wheel using only "0"     : 2.70%
      European wheel with "en prison"   : 1.35%

  Thus, this wheel will give a house margin of 2.70%.

*******************************************************************/

#include <treasure.h>
#include "../casino.h"

#define RECORD_WINS 1       /* 1=record them, 0=don't */ 
#define RECORD_LOSS 1      /* 1=record them, 0=don't */
#define RECORD_PROFITS 1

#define WHEEL_LOG "LOGS/ROULETTE.LOG"
#define PROFIT_LOG "LOGS/roulette.profits"

#define TP this_player()
#define QN query_name()
#define QRN query_real_name()
#define NAME capitalize(name_array[x])
#define ERROR (-1)
#define TRUE 1
#define FALSE 0
#define SPACER_CHAR "*"
#define VIEW_ALL_BETS "_X"
#define SPIN_DELAY 3           /* secs between "spinning" messages  */
#define WHEEL_SIZE 37          /* Total number of symbols + 1       */
#define SYMBOLS 7              /* Number of unique symbols on wheel */
#define MIN_BET 1000                  /** minimum bet at this table  */
#define MAX_BET 10000000                /** Maximum bet at this table  */
#define BROKEN_THRESHOLD 1000000     /* Something is wrong if the   */
/* wheel loses more than this. */
#define NUMBER 44                    /* is the bet on a number?     */ 
#define SYMBOL 55                    /* is the bet on a symbol?     */

/** Dont change the following values - they are **/
/** used to bit-encode the wheel data.          **/

#define COLOUR 1                     /* Colour flag.  RED, BLACK   **/
#define ODD_EVEN 2                   /* odd/even flag. ODD, EVEN   **/
#define HIGH_LOW 4                   /* high/low flag. HIGH, LOW   **/
#define COLUMN 24                    /* Column flag. COL1,COL2,COL3 **/
#define ROW 96                       /* Row flag. ROW1, ROW2, ROW3 **/
#define RED  0
#define BLACK 1
#define ODD 0
#define EVEN 2
#define LOW 0
#define HIGH 4
#define COL1 8
#define COL2 16
#define COL3 24
#define ROW1 32 
#define ROW2 64
#define ROW3 96 
#define ZERO 128

/*******************************************************************/
/*********************** function prototypes ***********************/
int  spin_wheel();
status wheel_stopped();
int  get_bets( string forwho );
int  get_payoff( string winning_bet, int type );
void spinning( string message );
object this_room;

/*******************************************************************/
/************************* global vars *****************************/

int wheel_profits;      /* The cumulative profit since reset */
int last_profits;       /* Profits at last reset              */
int bet_volume;         /* Total bet volume since reset      */
int spinning;           /* Is the wheel currently spinning?  */
int broken;             /* Did the wheel give away too much? */
int number_of_spins;    /* Total spins since reset           */
int number_of_bets;     /* number of bets so far this round  */ 
string syms,names,bets; /* storage strings                   */
string types;           /* storage, NUMBER or SYMBOL         */
int spin_dat, spin_num; /* what the wheel landed on.         */



/*******************************************************************
  Create the object and stuff
 *******************************************************************/

void create_treasure()
{
    int min,max;
    string desc;
    min = MIN_BET;
    max = MAX_BET;


    desc = "It is a large roulette wheel.  Like most roulette wheels,\
 the bowl of the wheel contains spaces for the numbers 0-36.  Each\
 of the numbers is coloured either black or red except 0, which\
 is green.  On the side of the table is a small plaque.\
  You can \'bet <amount> on <what>\', \'spin wheel\', and\
 \'view bets\'.  Currently, the minimum bet is "+min+" and\
 the maximum bet is "+max+".\n";

    if ( (int)(TP->query_coder_level()) > 0 )
	desc += "Coders can also \'view profits\'.\n";

    set_id( ({"wheel","roulette"}) );
    set_short("A roulette wheel");
    set_long( desc );


    /** initialize global vars **/

    names = "";
    bets = "";
    syms = "";
    types = "";
    spinning = FALSE;
    broken = FALSE;
    number_of_bets = 0;
    number_of_spins = 0;
    bet_volume = 0;
    wheel_profits = 0;

}


status get() { return 0; }

void init_treasure()
{
    add_action("bet_cmd", "bet");
    add_action("spin_cmd", "spin");
    add_action("view_cmd", "view");
    add_action("read_cmd", "read");

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
  Process the read command
*******************************************************************/

status read_cmd(string arg)
{
    string temp;

    if (!arg || sscanf(arg, "%s", temp ) != 1 || temp != "plaque" )
    {
	notify_fail("Read what?\n");
	return 0;
    }

    write("The payoffs for this machine are:\n\n\
       BET         INCLUDED NUMBERS        PAYOFF\n\
      --------------------------------------------\n\
       0-36                                35:1\n\
       col1       ( 1,4,7, ..., 34 )        2:1\n\
       col2       ( 2,5,8, ..., 35 )        2:1\n\
       col3       ( 3,6,9, ..., 36 )        2:1\n\n\
       row1           (  1-12 )             2:1\n\
       row2           ( 13-24 )             2:1\n\
       row3           ( 25-36 )             2:1\n\n\
       even       ( 2,4,6, ..., 36 )        1:1\n\
       odd        ( 1,3,5, ..., 35 )        1:1\n\
       low            (  1-18 )             1:1\n\
       high           ( 19-36 )             1:1\n\
       red                                  1:1\n\
       black                                1:1\n\n");

    return 1;

}




/*******************************************************************
  Process the bet command
*******************************************************************/

status bet_cmd(string arg)
{
    int type;
    int howmuch, num;
    string symb, *valid_syms;


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


    if ( sscanf( arg, "%d on %d", howmuch, num ) == 2 )
    {
	if (( num < 0 )||( num > 36 ))
	{
	    notify_fail("Dealer tells you: That number isn't on the wheel.\n");
	    return 0;
	}

	symb = (string)num;
	type = NUMBER;
    }
    else
    if ( sscanf( arg, "%d on %s", howmuch, symb ) == 2 )
    {
	valid_syms = ({ "red", "black", "even", "odd", "high", "low",
	  "col1", "col2", "col3", "row1", "row2", "row3" });

	if ( member( valid_syms, symb ) == ERROR )
	{
	    notify_fail("Dealer tells you: You cannot bet on that.\n");
	    return 0;
	}

	type = SYMBOL;
    }
    else
    {
	notify_fail("Dealer asks you: What?.\n");
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


    TP->tell_me("Ok. You bet " + howmuch + " gold on " + symb + ".");

    environment(TP)->tell_here(
      TP->QN + " has bet " + howmuch + " gold on " + symb + ".", TP);

    TP->add_money(-(howmuch));         /* subtract the bet from player's cash */

    /* record the bet */

    names = names + TP->QRN + SPACER_CHAR;    
    syms = syms + symb + SPACER_CHAR;
    bets = bets + (string)howmuch + SPACER_CHAR;
    types = types + (string)type + SPACER_CHAR;

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
    string temp;
    int spin_data, spin_num;

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

    TP->tell_me("Ok. The dealer gives the roulette wheel a big spin!"); 
    this_room->tell_here(TP->QN + " nods to the dealer,"
      +" who then gives the roulette wheel a big spin!", TP); 


    /* make sure that random() returns a number in the correct range */

    if (( spin_num = spin_wheel()) == ERROR )
    {
	broken = TRUE;
	notify_fail("The wheel makes a grating noise. It is obviously broken.\n");
	return 0;
    }

    /*** everything seems ok...spin it! ***/

    call_out( "spinning", 1, "The wheel spins...");
    call_out( "spinning", SPIN_DELAY+1, "The wheel slows...");
    call_out( "wheel_stopped", SPIN_DELAY+2 );

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
	tmp = get_bets( VIEW_ALL_BETS );      /* write the bets list */
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
   - Note: the data for each stop of the wheel is bit-encoded as follows:

      bit 0   -> colour
      bit 1   -> odd or even
      bit 2   -> high or low
      bit 3,4 -> column
      bit 5,6 -> row
      bit 7   -> zero 

 ****************************************************************************/

int spin_wheel()     
{

    switch( spin_num = random( WHEEL_SIZE ))
    {
    case 0  : spin_dat = ZERO; break;
    case 1  : case 7  : spin_dat = RED  |ODD |LOW |COL1|ROW1; break;
    case 2  : case 8  : spin_dat = BLACK|EVEN|LOW |COL2|ROW1; break;
    case 3  : case 9  : spin_dat = RED  |ODD |LOW |COL3|ROW1; break;
    case 4  : case 10 : spin_dat = BLACK|EVEN|LOW |COL1|ROW1; break;

    case 5  : spin_dat = RED  |ODD |LOW |COL2|ROW1; break;
    case 6  : spin_dat = BLACK|EVEN|LOW |COL3|ROW1; break;
    case 11 : spin_dat = BLACK|ODD |LOW |COL2|ROW1; break;
    case 12 : spin_dat = RED  |EVEN|LOW |COL3|ROW1; break;
    case 13 : spin_dat = BLACK|ODD |LOW |COL1|ROW2; break;
    case 14 : spin_dat = RED  |EVEN|LOW |COL2|ROW2; break;
    case 15 : spin_dat = BLACK|ODD |LOW |COL3|ROW2; break;
    case 16 : spin_dat = RED  |EVEN|LOW |COL1|ROW2; break;
    case 17 : spin_dat = BLACK|ODD |LOW |COL2|ROW2; break;
    case 18 : spin_dat = RED  |EVEN|LOW |COL3|ROW2; break;

    case 19 : spin_dat = RED  |ODD |HIGH|COL1|ROW2; break;
    case 20 : spin_dat = BLACK|EVEN|HIGH|COL2|ROW2; break;
    case 21 : spin_dat = RED  |ODD |HIGH|COL3|ROW2; break;
    case 22 : spin_dat = BLACK|EVEN|HIGH|COL1|ROW2; break;
    case 23 : spin_dat = RED  |ODD |HIGH|COL2|ROW2; break;
    case 24 : spin_dat = BLACK|EVEN|HIGH|COL3|ROW2; break;
    case 25 : spin_dat = RED  |ODD |HIGH|COL1|ROW3; break;
    case 26 : spin_dat = BLACK|EVEN|HIGH|COL2|ROW3; break;
    case 27 : spin_dat = RED  |ODD |HIGH|COL3|ROW3; break;
    case 28 : spin_dat = BLACK|EVEN|HIGH|COL1|ROW3; break;

    case 29 : case 35 : spin_dat = BLACK|ODD |HIGH|COL2|ROW3; break;
    case 30 : case 36 : spin_dat = RED  |EVEN|HIGH|COL3|ROW3; break;

    case 31 : spin_dat = BLACK|ODD |HIGH|COL1|ROW3; break;
    case 32 : spin_dat = RED  |EVEN|HIGH|COL2|ROW3; break;
    case 33 : spin_dat = BLACK|ODD |HIGH|COL3|ROW3; break;
    case 34 : spin_dat = RED  |EVEN|HIGH|COL1|ROW3; break;
    default : return ERROR;
    }


    spinning = TRUE;

    return spin_num;
}




/****************************************************************************
  get_payoff 
****************************************************************************/

int get_payoff( string winning_bet, int type )
{

    if ( type == NUMBER )
	return 35;                /** 35:1 on a straight-up bet **/

    switch ( winning_bet )
    {
    case "red" :
    case "black" :
    case "high"  :
    case "low"   :
    case "even"  :
    case "odd"   : return 1;
    case "col1"  :
    case "col2"  :
    case "col3"  :
    case "row1"  :
    case "row2"  :
    case "row3"  : return 2;
    default      : return 0;
    }

}



/****************************************************************************
  Evaluate the bets and payoff the winners
****************************************************************************/

status wheel_stopped()
{  
    int x, payoff;
    string *name_array, *sym_array, *bet_array, *type_array;
    string colour, odd_even, high_low, column, row, *result;
    object person;

    colour   = (( spin_dat & COLOUR)  == BLACK ) ? "black" : "red";
    odd_even = (( spin_dat & ODD_EVEN) == EVEN ) ? "even"  : "odd";
    high_low = (( spin_dat & HIGH_LOW) == HIGH ) ? "high"  : "low";

    switch ( spin_dat & COLUMN )
    {
    case COL1 : column="col1"; break;
    case COL2 : column="col2"; break;
    case COL3 : column="col3"; break;
    default   : column="error";
    }

    switch ( spin_dat & ROW )
    {
    case ROW1 : row="row1"; break;
    case ROW2 : row="row2"; break;
    case ROW3 : row="row3"; break;
    default   : row="error";
    }

    result = ({ (string)spin_num, colour, odd_even, high_low, column, row });

    if ( spin_dat == ZERO )
	this_room->tell_here("The wheel stops on "+spin_num+"!");
    else
	this_room->tell_here("The wheel stops on "+spin_num
	  +" ("+colour+", "+odd_even+", "+high_low
	  +", "+column+", "+row+")");



    name_array = allocate(number_of_bets);
    sym_array = allocate(number_of_bets);
    bet_array = allocate(number_of_bets);
    type_array = allocate(number_of_bets);

    /** convert the strings to arrays ***/  

    name_array = explode( names, SPACER_CHAR );
    sym_array = explode( syms, SPACER_CHAR );
    bet_array = explode( bets, SPACER_CHAR );
    type_array = explode( types, SPACER_CHAR );

    for ( x=0; x<number_of_bets; x++)
    { 
	if ( person=present(name_array[x], this_room) )
	{
	    if (( (int)type_array[x] == SYMBOL &&( member( result, sym_array[x] ) != ERROR ))
	      ||( (int)type_array[x] == NUMBER )&&( (int)sym_array[x] == spin_num ))
	    {                                        /* this bet won */

		payoff = get_payoff( sym_array[x], (int)type_array[x] )*(int)bet_array[x];

		person->tell_me("You win "+payoff+" gold coins on "+sym_array[x]+".\n"); 

		this_room->tell_here( person->QN
		  +" has won "+payoff+" gold coins on "+sym_array[x]+".\n",person);

		person->add_money(payoff+(int)bet_array[x]);

		if ( !( person->query_coder_level()) )
		    wheel_profits -= payoff; 

#if RECORD_WINS == TRUE
		if ( !( person->query_coder_level()) )     /** lets not log coders **/
		    write_file( AREA_PATH+WHEEL_LOG, NAME+", "+payoff+", "+sym_array[x]+", "
		      +wheel_profits+", "+ number_of_spins +"\n" );
#endif

	    }
	    else
	    {                                        /* this bet lost */
		payoff = (int)bet_array[x];

		person->tell_me("You lose "+payoff+" gold coins on "+sym_array[x]+".\n");

		this_room->tell_here( person->QN
		  +" has lost "+payoff+" gold coins on "+sym_array[x]+".\n",person);

		if ( !( person->query_coder_level()) )
		    wheel_profits += payoff;

#if RECORD_LOSS == TRUE        
		if ( !( person->query_coder_level()) )     /** lets not log coders **/
		    write_file( AREA_PATH+WHEEL_LOG, NAME+", "+ -payoff+", "+sym_array[x]
		      +", "+wheel_profits+", "+ number_of_spins +"\n" );
#endif

	    } 
	}
	else                                       /* winner isnt here */
	if ( person = find_player(name_array[x]) )
	{

	    if (( (int)type_array[x] == SYMBOL 
		&&( member( result, sym_array[x] ) != ERROR ))
	      ||( (int)type_array[x] == NUMBER )&&( (int)sym_array[x] == spin_num ))

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
    types = "";

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

