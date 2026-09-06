/******************************************************************
  Casino Baccarat
  Coded by: Germ
  Last modified: Feb 12, 96

  Modification history:
    (2/12/96) - Reduced the max bet to 10K
	      - Coder's games no longer logged or included
		in the profit/loss stats.

  Comments: 

  This is a baccarat table that (hopefully) is identical to the
  real ones.  The only difference is that for memory-saving 
  reasons I am modeling the 7-deck chute as a simple random
  number generator rather than creating the entire 7 decks in 
  memory.

  The following statistics were generated from my baccarat
  simulator written in C.


	Number of deals: 1000000
	Betting 1 on each symbol per deal


	Winning    Total player   House %     Hit %
	Symbol       profit       margin  
       --------------------------------------------- 
	PLAYER:    -10760.00      1.076     44.692
	BANKER:    -12077.21      1.208     45.768
	TIE   :   -141454.00      14.145     9.539


  Thus, the odds appear to be what we would expect.

  As with the other casino games here, if the table 
  loses more than BROKEN_THRESHOLD, we assume something
  is bugged and the table shuts itsself down. 

*******************************************************************/

#include <treasure.h>
#include "../casino.h"

#define RECORD_WINS 1       /* 1=record them, 0=don't */ 
#define RECORD_LOSS 1       /* 1=record them, 0=don't */
#define RECORD_PROFITS 1

#define GAME_LOG "LOGS/BACCARAT.LOG"
#define PROFIT_LOG "LOGS/baccarat.profits"

#define TP this_player()
#define QN query_name()
#define QRN query_real_name()
#define NAME capitalize(name_array[x])
#define TRUE 1
#define FALSE 0
#define SPACER_CHAR "*"
#define VIEW_ALL_BETS "_X"
#define DEAL_DELAY 3
#define DECK_SIZE 13           /* number of cards in deck         */
#define SYMBOLS 3              /* Number of unique symbols on table */
#define MIN_BET 1000
#define MAX_BET 100000
#define BROKEN_THRESHOLD 10000000  /* Something is wrong if the  */
/* table loses more than this. */

/*******************************************************************/
/*********************** function prototypes ***********************/
string deal_card();
status dealing_done( string symb, float mul, int natural );
int get_bets( string forwho );
void dealing( string message );
object this_room;

/*******************************************************************/
/************************* global vars *****************************/

int table_profits;      /* The cumulative profit since reboot     */
int last_profits;       /* Profits since last reset               */
int bet_volume;         /* The total bet volume since reboot      */
int card_val;           /* Numerical value of the last card drawn */
string card_num;        /* the number of the last card drawn      */

int dealing;            /* Is the table currently dealing?        */
int broken;             /* Did the table give away too much?      */
int number_of_deals;    /* Total deals since reboot               */
int number_of_bets;     
string syms,names,bets;


/*******************************************************************
  Create the object and stuff
 *******************************************************************/

void create_treasure()
{
    string desc;


    desc = "It is a large baccarat table.\
 Around the edge of the table are symbols on which\
 you can bet: player, banker, and tie. Affixed to the\
 top of the table is a brass plaque.\
 You can \'bet <amount> on <symbol>\', \'deal cards\',\
 and \'view bets\'.  Currently, the minimum bet is "+MIN_BET+" and\
 the maximum bet is "+MAX_BET+".\n";

    if ( (int)(TP->query_coder_level()) > 0 )
	desc += "Coders can also \'view profits\'.\n";

    set_id( ({"table","baccarat"}) );
    set_short("A large baccarat table");
    set_long( desc );


    /** initialize global vars **/

    names = "";
    bets = "";
    syms = "";
    dealing = FALSE;
    broken = FALSE;
    number_of_bets = 0;
    number_of_deals = 0;
    table_profits = 0;
    bet_volume = 0;
}


status get() { return 0; }

void init_treasure()
{
    add_action("read_cmd", "read" );
    add_action("bet_cmd", "bet");
    add_action("deal_cmd", "deal");
    add_action("view_cmd", "view");

    this_room = environment(TP);

}


/********************************************************************/

void reset_treasure()
{

#if RECORD_PROFITS != 0
    if ( table_profits != last_profits )
    {
	write_file( AREA_PATH+PROFIT_LOG,
	  "Profits = "+table_profits+", Volume = "+bet_volume
	  +"Deals = "+number_of_deals+", "+ctime(time())+"\n");

	last_profits = table_profits;
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

    write("The baccarat payoffs are:\n\n\
          win on player:      1:1\n\
          win on banker:   0.95:1  ( House takes a 5% cut )\n\
          win on tie:         8:1\n\n\
         On a tie, bets for player and banker are returned.\n");

    return 1;

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

    if ( dealing == TRUE )
    {
	notify_fail("Dealer tells you: Wait until this game is over.\n");
	return 0;
    }


    /* Broken can only happen if the house loses more than BROKEN_THRESHOLD */
    /* or if random() generates an incorrect number.                        */

    if ( broken == TRUE )
    {
	notify_fail("Dealer tells you: This table is not open for bets right now.\n");
	return 0;
    }


    if (howmuch < MIN_BET )
    {
	notify_fail("Dealer tells you: The minimum bet for this table is "
	  +MIN_BET+".\n");
	return 0;
    }

    /* without a betting limit, a rich player can never lose */

    if ( howmuch > MAX_BET || get_bets(TP->QRN)+howmuch > MAX_BET )
    {                
	notify_fail("Dealer tells you: The maximum bet for this table is "
	  +MAX_BET+ " per player.\n");
	return 0;
    }

    if (TP->query_money() < howmuch )
    {
	notify_fail("Dealer tells you: You cannot bet what you don\'t have!\n");
	return 0;
    }

    if ( symb!="banker" && symb!="player" && symb!="tie" )
    {
	notify_fail("Dealer tells you: You must bet on one of the valid table symbols.\n");
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

    if ( !( TP->query_coder_level()) )
	bet_volume += howmuch;


    number_of_bets++;

    return 1;
}


/***************************************************************************
  Process the deal command
 ***************************************************************************/

status deal_cmd(string arg)
{
    string temp, *card, *num;
    int i,j, *val, psum, dsum, natural;
    float mul;

    if (!arg || sscanf(arg, "%s", temp) != 1 || temp!="cards" )
    {
	notify_fail("Deal what?\n"); 
	return 0;
    }

    if (!present("dealer", this_room ))
    {
	notify_fail("The dealer is not here.\n");
	return 0;
    }

    if ( dealing == TRUE )
    {
	notify_fail("Dealer tells you: As you can see, I am already dealing.\n");
	return 0;
    }

    if ( number_of_bets == 0 )
    {
	notify_fail("Dealer tells you: I cannot deal without any bets.\n");
	return 0;
    }

    TP->tell_me("Ok. The dealer begins dealing the cards!"); 
    this_room->tell_here(TP->QN + " nods to the dealer, who begins to deal the cards!", TP); 


    /* make sure that random() returns a number in the correct range */

    card = allocate( 6 );
    val  = allocate( 6 );
    num  = allocate( 6 );
    /* Deal the cards */


    for ( i=0; i<6; i++ )
    {
	if ( ( card[i] = deal_card()) == "error" )
	{
	    broken = TRUE;
	    notify_fail(" .\n");
	    this_room->tell_here("Dealer says: I am shutting down this table.  "
	      +"Sorry for the inconvenience.");
	    return 0;
	}
	else
	{
	    val[i] = card_val;
	    num[i] = card_num;

	}

    }


    dealing = TRUE;

    temp = "The player's cards are "+num[3]+" of "+card[3]+" and "
    +num[4]+" of "+card[4]+".";

    call_out( "dealing", 1, "The dealer deals two cards to the player and two cards to the banker..." ); 
    call_out( "dealing", DEAL_DELAY+1, temp );

    temp = "The banker's cards are "+num[0]+" of "+card[0]+" and "
    +num[1]+" of "+card[1]+".";

    call_out( "dealing", DEAL_DELAY+2, temp );


    dsum = val[0] + val[1];
    psum = val[3] + val[4];

    if ( psum > 9 ) psum -= 10;
    if ( dsum > 9 ) dsum -= 10;

    if (( dsum < 8 )&&( psum < 8 ))  
    {
	natural = FALSE;

	i = psum;

	if ( psum < 6 )           /** player draws again on 5 or less **/
	{
	    psum += val[5]; 
	    if ( psum > 9 ) psum -= 10;

	    temp = "The dealer deals a "+num[5]+" of "+card[5]+" to the player.";
	    call_out( "dealing", DEAL_DELAY+3, temp );
	} 

	if ( (( i > 5 )&&( dsum < 6 ))     /* determine if more cards must be dealt */
	  ||(( i < 6 )&&
	    (   ((( val[5] < 2 )||( val[5] == 9 ))&&( dsum < 4 ))  
	      || (( val[5] == 8 )&&( dsum < 3 ))
	      || ((( val[5] == 6 )||( val[5] == 7 ))&&( dsum < 7 ))
	      || ((( val[5] == 4 )||( val[5] == 5 ))&&( dsum < 6 ))
	      || ((( val[5] == 2 )||( val[5] == 3 ))&&( dsum < 5 )) )))
	{
	    dsum += val[2];
	    if ( dsum > 9 ) dsum -= 10;

	    temp = "The dealer deals a "+num[2]+" of "+card[2]+" to the banker.";
	    call_out( "dealing", DEAL_DELAY+4, temp );
	}
    }

    else
	natural = TRUE;

    temp = "tie";                    /* payoff is 8:1 for winning on tie */
    mul = 8.00;

    if ( psum > dsum )
    {
	temp = "player";           /* payoff is 1:1 for winning on player */
	mul = 1.00;
    }
    else
    if ( dsum > psum )
    {
	temp = "banker";            /* payoff is 1:1 for winning on banker */
	mul = 0.95;                 /* but the house takes 5% of the winnings. */
    }


    call_out( "dealing_done", DEAL_DELAY+5, temp, mul, natural );

    if ( !( TP->query_coder_level()) )
	number_of_deals++;

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
	TP->tell_me("The total profits for this table are " + table_profits 
	  + " in " + number_of_deals + " deals.\n");

	TP->tell_me("Total bet volume: "+bet_volume+" coins.");

	return 1;
    }

    notify_fail("view what?\n");
    return 0;

}






/****************************************************************************
  Deal a card from the deck.

  In Las Vegas, something 7 decks are used for baccarat.
  Since the memory penalty for creating a 7 deck game would be heavy,
  I am making the assumption that since there are so many decks, the 
  probability of any card being dealt is essentially random, regardless
  of what cards have already been dealt.  This should be an ok assumption
  since in Vegas the cards are shuffled long before all of them are dealt. 

 ****************************************************************************/

string deal_card()     
{

    switch( random( DECK_SIZE ))
    {
    case 0 : card_val = 1; card_num = "ACE";   break;
    case 1 : card_val = 2; card_num = "TWO";   break;
    case 2 : card_val = 3; card_num = "THREE"; break; 
    case 3 : card_val = 4; card_num = "FOUR";  break;
    case 4 : card_val = 5; card_num = "FIVE";  break;
    case 5 : card_val = 6; card_num = "SIX";   break;
    case 6 : card_val = 7; card_num = "SEVEN"; break;
    case 7 : card_val = 8; card_num = "EIGHT"; break;
    case 8 : card_val = 9; card_num = "NINE";  break;
    case 9 : card_val = 0; card_num = "TEN";   break;
    case 10: card_val = 0; card_num = "JACK";  break;
    case 11: card_val = 0; card_num = "QUEEN"; break;
    case 12: card_val = 0; card_num = "KING";  break; 
    default: return "error";
    }


    switch( random(4) )         /** Baccarat doesn't care about suits **/
    {
    case 0:  return "CLUBS";
    case 1:  return "SPADES";
    case 2:  return "HEARTS";
    case 3:  return "DIAMONDS";
    default: return "error";
    }

}



/****************************************************************************
  Evaluate the bets and payoff the winners
****************************************************************************/

status dealing_done( string symb, float mul, int natural )
{  
    int x, result;
    float resultf;
    string temp, *name_array, *sym_array, *bet_array;
    object person;



    name_array = allocate(number_of_bets);
    sym_array = allocate(number_of_bets);
    bet_array = allocate(number_of_bets);

    /** convert the strings to arrays ***/

    name_array = explode( names, SPACER_CHAR );
    sym_array = explode( syms, SPACER_CHAR );
    bet_array = explode( bets, SPACER_CHAR );

    if ( symb == "tie" )
	temp = "Banker and player tie!";
    else
    {
	temp = capitalize( symb ) +" wins";
	if ( natural == TRUE )
	    temp += " on a natural!";
	else
	    temp += "!";
    } 

    this_room->tell_here(temp);


    for ( x=0; x<number_of_bets; x++)
    { 
	if ( person=present(name_array[x], this_room) )
	{
	    if ( symb == sym_array[x] )
	    {                                        /* this bet won */
		resultf =  mul*(float)bet_array[x];
		result = (int)resultf;
		/* round instead of truncate */
		if ( ( resultf - result ) > 0.5 )
		    result++; 

		person->tell_me("You win "+result+" gold coins on "+sym_array[x]+".\n"); 

		this_room->tell_here( person->QN
		  +" has won "+result+" gold coins on "+sym_array[x]+".\n",person);

		person->add_money(result+(int)bet_array[x]);

		if ( !( person->query_coder_level()) )
		{
		    table_profits -= result; 

		    /* house gets a 5% cut of winnings on banker */
		    if ( symb == "banker" )  
			table_profits += (int)(result*0.05);
		}

#if RECORD_WINS == TRUE
		if ( !( person->query_coder_level()) )     /** lets not log coders **/
		    write_file(AREA_PATH+GAME_LOG, NAME+", "+result+", "+sym_array[x]+", "
		      +table_profits+", "+ number_of_deals +"\n" );
#endif

	    }
	    else
	    {                                        /* this bet lost */
		result = (int)bet_array[x];

		if ( symb == "tie" )             /* Losing bets are returned on a tie */
		{
		    person->tell_me("You get back your "+result+" gold coins on "+sym_array[x]+".\n");

		    this_room->tell_here( person->QN
		      +"'s "+result+" gold coins on "+sym_array[x]
		      +" are returned.\n",person);

		    person->add_money( result );

		}
		else
		{

		    person->tell_me("You lose "+result+" gold coins on "
		      +sym_array[x]+".\n");

		    this_room->tell_here( person->QN
		      +" has lost "+result+" gold coins on "
		      +sym_array[x]+".\n",person);

		    if ( !( person->query_coder_level()) )
			table_profits += result;

#if RECORD_LOSS == TRUE        
		    if ( !( person->query_coder_level()) )     /** lets not log coders **/
			write_file( AREA_PATH+GAME_LOG, NAME+", "+ -result+", "+sym_array[x]
			  +", "+table_profits+", "+ number_of_deals +"\n" );
#endif

		}
	    } 
	}
	else                                       /* winner isnt here */
	if ( person = find_player(name_array[x]) )
	{
	    if ( symb == sym_array[x] )
		this_room->tell_here("Dealer says: "+person->QN
		  +" is not here to collect the winnings.\n"); 

	    if ( !( person->query_coder_level()) )
		table_profits += (int)bet_array[x];
	}
    }

    if ( table_profits < -BROKEN_THRESHOLD )
    {
	broken = TRUE;
	this_room->tell_here("Dealer says: I must shut down this table now.\n");
    }

    names = "";
    syms = "";
    bets = "";

    dealing = FALSE;
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
  Called by call_out to display the dealing messages 
***************************************************************************/

void dealing( string message )
{
    this_room->tell_here( message );
}


/***************************************************************************/
/***************************************************************************/

