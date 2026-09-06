/******************************************************************
  Casino draw poker 
  Coded by: Germ
  Last modified: Feb 13, 96

  Modification history:
    (2/13/96) - Fixed bug in discard_cards()
    (2/14/96) - Fixed a bug in auto-folding

  Comments: 
     This table lets up to six players play 5-card draw poker.
     The rules are close to identical to standard draw poker,
     and the house gets a 5% cut of each pot, up to a max
     of 4*ante.

     As with real poker, the only random element here is the
     shuffling of the deck.

     In order to save memory space, the 52-card deck is an
     array of integers, with the lower 4 bits being the suit
     and the upper bits being the rank.

     Things to do:
	- Perhaps we should mask tells, channels, etc - any
	  kind of private communication.  This would make it
	  harder for poker players to work as a team and drive
	  up the pot when one has a good hand.  

*******************************************************************/

#include <treasure.h>
#include <generic_items.h>

#include "../casino.h"

#define RECORD_POTS 1                /* 1=record wins, 0=don't     */ 
#define DEBUG_MODE 0                 /* enables the setc function  */
#define GAME_LOG "LOGS/POKER.LOG"
#define TP this_player()
#define QN query_name()
#define QRN query_real_name()
#define TRUE 1                       /* boolean flag               */
#define FALSE 0                      /* boolean flag               */
#define ERROR -1                     /* general error flag         */
#define DEAL 1                       /* get_card arg               */
#define LOOKAT 2                     /* get_card arg               */
#define NORMAL 0                     /* general purpose arg        */ 
#define DONE_CHECK 5                 /* next_player arg            */
#define ANYTIME 9                    /* error check arg            */
#define SPACER_CHAR "*"              /* used in name string        */

#define FIRST_BETS 10                /* round identifier           */
#define DISCARDING 11                /* round identifier           */
#define LAST_BETS  12                /* round identifier           */

#define MIN_PLAYERS 2                /* min players for a game     */ 
#define MAX_PLAYERS 6                /* max players in the game    */
#define DEALER_DELAY 1               /* delay before he says stuff */
#define WARN_DELAY 30                /* delay before warning       */
#define FOLD_DELAY 15                /* delay after warning        */
#define DECK_SIZE 52                 /* number of cards in deck    */
#define HAND_SIZE 5                  /* number of cards dealt      */
#define DISCARD_MAX 3                /* max cards you can discard  */
#define ANTE_DEFAULT 250             /* default ante               */
#define MIN_RAISE_DEFAULT 1000       /* default minimum raise      */
#define MAX_RAISE_DEFAULT 3000       /* default maximum raise      */ 

/*******************************************************************/
/*********************** function prototypes ***********************/
void shuffle();
int  get_card( int pos, int func );
int  get_bets( string forwho );
int  errorcheck( string person, int func );
void  bubble_sort( int *arry1, int *arry2 );
void delay_func( int func );
void timer_func( object person, int func );
int  next_player( int current_player, int func );
int  evaluate( string person );
void show_cards( int whofirst );
void show_hand( string who, string thehand, int func );
void give_pot( string name, string tie_name, string thehand, int tie );

/*******************************************************************/
/************************* global vars *****************************/

string result, raised_result;         /* final card hands         */
string names, *player;                /* players in the game      */
string card_num, card_suit;          /* text of most recent card */
int c_num, c_suit;                   /* info on most recent card */
int *card;                            /* The deck of cards        */
int current;                          /* which card dealt next    */

int turn;                             /* It is this player's turn */
int size_of_bet;                      /* current round bet amount */
int last_raise;                       /* size of the last raise   */
int last_to_raise;                    /* player who raised last   */
int tiebreaker;                       /* single-card score        */

int ante;                             /* size of ante             */
int min_raise;                        /* minimum raise            */
int max_raise;                        /* maximum raise            */

int pot;                              /* the coins on the table   */
int round;                /* FIRST_BETS, DISCARDING, or LAST_BETS */
int drawing_done;         /* TRUE if everyone is done discarding  */

int playing;              /* TRUE if a game is in progress        */
int number_of_deals;      /* Total games since reboot              */
int number_of_players;    /* number of players who began          */
int table_profits;        /* The cumulative profit since reboot   */
int bet_volume;           /* Total bet volume since reboot        */
int still_in;             /* how many players have not folded     */


mapping hand;             /* the player's hand of cards           */
mapping player_bet;       /* how much player has bet this round   */
mapping player_folded;    /* TRUE if player has folded            */

object this_room;         /* the poker room                       */ 





/*******************************************************************
  Poker table object maintenance 
 *******************************************************************/

void create_treasure()
{
    int min;
    int num,suit;
    string desc;

    desc = "It is a large circular poker table with room enough to\
 seat half a dozen players.  Poker player's can do the following:\n\n\
   ante              :  Pay the ante and enter the game\n\
   deal              :  After ante, play will start\n\n\
   view cards        :  View the hand you were dealt\n\
   view pot          :  See how much money is on the table\n\
   view status       :  View the game status\n\n\
   reorder a b c d e :  Reorder your cards. a-e are the card\n\
                        numbers for the new card order\n\
   discard a b c     :  Specify which cards to discard\n\
   discard none      :  Don't discard any cards\n\
   raise <n>         :  Raise the current bet by <n> coins\n\
   call              :  stay in the game but do not raise\n\
   fold              :  leave the game\n\n\
   define ante <num> :  set the ante\n\
   define min <num>  :  set the minimum raise to num\n\
   define max <num>  :  set the maximum raise to num\n";


    set_id( ({"table","poker"}) );
    set_short("A large circular poker table");
    set_long( desc );


    /** initialize global vars **/

    names = "";
    playing = FALSE;
    number_of_players = 0;
    number_of_deals = 0;
    table_profits = 0;
    bet_volume = 0;

    pot = 0;
    ante = ANTE_DEFAULT;
    min_raise = MIN_RAISE_DEFAULT;
    max_raise = MAX_RAISE_DEFAULT;

    card = allocate( DECK_SIZE );
    min = 0;
    /** generate deck **/ 
    for ( num=0; num<13; num++ )
	for ( suit=0; suit<4; suit++ )
	{                                    /** lower 4 bits -> suit **/
	    card[min] = suit | ( num << 4 );  /** upper bits   -> rank **/ 
	    min++;
	}
}

/********************************************************************/

status get() { return 0; }

void init_treasure()
{
    add_action("ante_cmd", "ante");
    add_action("deal_cmd", "deal");
    add_action("view_cmd", "view");
    add_action("reorder_cmd","reorder");
    add_action("raise_cmd","raise");
    add_action("call_cmd","call" );
    add_action("fold_cmd","fold" );
    add_action("discard_cmd","discard");
    add_action("define_cmd","define");

#if DEBUG_MODE == TRUE
    add_action("setc_cmd","setc");
#endif

    this_room = environment(TP);

}




/*******************************************************************
  Process the ante command
*******************************************************************/

status ante_cmd(string arg)
{
    object tm;
    int temp;
    string symb;

    if ( !present("dealer", this_room ))
    {
	notify_fail("The dealer is not here.\n");
	return 0;
    }

    if ( strstr( SPACER_CHAR+names, (TP->QRN)+SPACER_CHAR, 0 ) != -1 )
    {
	notify_fail("Dealer tells you: You are already in.\n");
	return 0;
    }

    if ( playing == TRUE )
    {
	notify_fail("Dealer tells you: Wait until this game is over.\n");
	return 0;
    }


    if (TP->query_money() < ante )
    {
	notify_fail("Dealer tells you: You don\'t have enough gold for the ante!\n");
	return 0;
    }

    if ( number_of_players == MAX_PLAYERS )
    {
	notify_fail("Dealer tells you: We already have "
	  +MAX_PLAYERS+" in the game.\n");
	return 0;
    }


    TP->tell_me("Ok. You toss " + ante + " gold on the table.");

    environment(TP)->tell_here(
      TP->QN + " tosses " + ante + " gold on the table.", TP);

    TP->add_money(-(ante));         /* subtract the bet from player's cash */
    pot += ante;                    /* add coins to the pot */

    bet_volume += ante;
    names = names + TP->QRN + SPACER_CHAR;    
    number_of_players++;

    return 1;

} /** ante_cmd **/     





/***************************************************************************
  Process the deal command
 ***************************************************************************/

status deal_cmd(string arg)
{
    int i,j, *tmp;
    string temp;
    object person;

    if (!present("dealer", this_room ))
    {
	notify_fail("The dealer is not here.\n");
	return 0;
    }

    if ( playing == TRUE )
    {
	notify_fail("Dealer tells you: A game is already in progress.\n");
	return 0;
    }


    if ( number_of_players < MIN_PLAYERS )
    {
	notify_fail("Dealer tells you: We need at least "
	  +MIN_PLAYERS+" players.\n");
	return 0;
    }

    if ( strstr( SPACER_CHAR+names, (TP->QRN)+SPACER_CHAR, 0 ) == -1 )
    {
	notify_fail("Dealer tells you: You haven't joined the game yet.\n");
	return 0;
    }

    current = 0;
    turn = 0;
    playing = TRUE;
    last_to_raise = 0;
    last_raise = 0;
    size_of_bet = 0;
    round = FIRST_BETS;
    still_in = number_of_players;
    number_of_deals++;
    /** shuffle the deck **/
    for ( i=0; i<random(2)+2; i++ )
    {
	shuffle();
	this_room->tell_here("The dealer shuffles the cards...");
    }



    player = allocate(number_of_players);
    player = explode( names, SPACER_CHAR );

    tmp = allocate(number_of_players);
    hand = mkmapping( player, tmp, tmp, tmp, tmp, tmp );

    player_bet = mkmapping( player, tmp );
    player_folded = mkmapping( player, tmp );

    /* deal the cards */
    /* Note: The deck never changes until the next shuffle     */
    /*       As cards are dealt, "current" increments to point */
    /*       to the next card to be dealt.                     */

    for ( i=0; i<number_of_players; i++ )
	if ( person=present( player[i], this_room ) )
	{
	    for ( j=0; j<HAND_SIZE; j++ )
		hand[ player[i], j ] = get_card( current++, DEAL ); 

	    player_bet[ player[i] ] = 0;
	    player_folded[ player[i] ] = FALSE;

	    person->tell_me("The dealer deals you "+HAND_SIZE+" cards!");
	}   
	else
	{
	    this_room->tell_here("Dealer says: Hmm..where is "+player[i]+"?");
	    player_folded[ player[i] ] = TRUE;
	}

    call_out("delay_func", DEALER_DELAY, NORMAL );

    return 1;
}







/****************************************************************************
 call.
 ***************************************************************************/

status call_cmd( string arg )
{
    int amount;
    string person;

    person = TP->QRN;

    if ( !errorcheck( person, NORMAL ) )
	return 0;


    amount = size_of_bet - player_bet[person];

    if (TP->query_money() < amount )
    {
	notify_fail("Dealer tells you: You do not have enough gold!\n");
	return 0;
    }

    pot += amount;                    /* increase the pot */
    TP->add_money(-(amount));         /* subtract the raise from player's cash */
    player_bet[ person ] = size_of_bet;
    bet_volume += amount; 

    if ( amount > 0 )
    {
	TP->tell_me("Ok. You toss "+amount+" coins on the table and call.");
	this_room->tell_here( TP->QN+" tosses "+amount
	  +" coins on the table and calls.", TP );
    }
    else 
    {
	TP->tell_me("Ok. You call.");
	this_room->tell_here( TP->QN+" calls.", TP ); 
    }
    /** player is calling, so **/
    /** no need to warn or fold them **/
    remove_call_out("timer_func");


    turn = next_player( turn, NORMAL );               /** who's turn is next? **/

    if ( last_to_raise == turn )
    {
	if ( round == LAST_BETS )
	{
	    this_room->tell_here( "Dealer says: Ok, time to show the cards!");
	    call_out("show_cards", DEALER_DELAY, last_to_raise );
	    return 1;
	}
	else
	{                                /** get the first non-folded player **/
	    turn = next_player( 0, DISCARDING ); 
	    round = DISCARDING;

	    this_room->tell_here( "Dealer says: Ok, time to draw!");
	    call_out("delay_func", DEALER_DELAY, DISCARDING );
	    return 1;
	}
    } 

    call_out("delay_func", DEALER_DELAY, NORMAL );

    return 1; 

}  /** call_cmd **/







/****************************************************************************
 fold.
 ***************************************************************************/

status fold_cmd( string arg )
{
    string person, temp;
    object last_person;
    int autofold;

    autofold = -1;
    /** auto-folded **/
    if (arg && ( sscanf(arg, "%s %s", temp, person ) == 2 )
      && ( temp == "_AUTO_" )) 
    {
	this_room->tell_here("The dealer takes away "
	  +find_player(person)->QN+"'s cards." );

	autofold = turn;
    }
    else
    {
	person = TP->QRN;

	if ( !errorcheck( person, NORMAL ) )
	    return 0;


	TP->tell_me("Ok. You throw your cards on the table and fold.");

	this_room->tell_here(TP->QN+" throws "+TP->Possessive()
	  +" cards on the table and folds.", TP );

	remove_call_out("timer_func");

    }


    player_folded[ person ] = TRUE;
    still_in--;
    turn = next_player( turn, NORMAL );          /** who's turn is next? **/

    if ( still_in < 2 )                          /** everyone has folded **/
    {
	call_out("give_pot", DEALER_DELAY,
	  player[turn], player[turn], "fold", FALSE );

	return 1;
    }

    if ( last_to_raise == turn )                 /** betting round over  **/
    {
	if ( round == LAST_BETS )                  /** show cards **/
	{
	    this_room->tell_here( "Dealer says: Ok, time to show the cards!");
	    call_out("show_cards", DEALER_DELAY, last_to_raise );
	}
	else
	{
	    turn = next_player( 0, DISCARDING );   /** discard cards **/
	    round = DISCARDING;

	    this_room->tell_here( "Dealer says: Ok, time to draw!");

	    call_out("delay_func", DEALER_DELAY, DISCARDING );
	}
    }
    else                                       /** continue betting **/
	call_out("delay_func", DEALER_DELAY, NORMAL );



    /** if we auto-folded the last to raise **/
    /** then select next player             **/
    if ( last_to_raise == autofold )
	last_to_raise = next_player( last_to_raise, NORMAL );


    return 1;

} /** fold_cmd **/





/****************************************************************************
 raise bet.
 ***************************************************************************/

status raise_cmd( string arg )
{
    int amount, howmuch;
    string person;

    if (!arg || sscanf(arg, "%d", howmuch) != 1 )
	return 0;

    person = TP->QRN;

    if ( !errorcheck( person, NORMAL ))
	return 0;


    if (( howmuch < min_raise )||( howmuch > max_raise ))
    {
	notify_fail( "Dealer says: That raise is outside the raise limits.\n");
	return 0;
    }

    if ( howmuch < last_raise )
    {
	notify_fail( "Dealer tells you: You cannot raise less than the previous raise of "
	  +last_raise+".\n");
	return 0;
    }


    /** match previous raises plus own raise **/
    amount = size_of_bet - player_bet[ person ] + howmuch;


    if (TP->query_money() < amount )
    {
	notify_fail( "Dealer tells you: You do not have enough gold!\n");
	return 0;
    }

    /** player is acting, so **/
    /** no need to warn or fold them **/
    remove_call_out("timer_func");


    last_raise = howmuch;
    pot += amount;                    /** add raise to the pot **/
    TP->add_money(-(amount));         /* subtract the raise from player's cash */
    size_of_bet += howmuch;
    bet_volume += amount;
    player_bet[ person ] = size_of_bet;

    TP->tell_me("Ok. You raise "+howmuch+", tossing "
      +amount+" coins on the table.");

    this_room->tell_here( TP->QN+" raises "+howmuch+", tossing "
      +amount+" coins on the table.", TP );


    last_to_raise = turn;
    turn = next_player( turn, NORMAL );           /** who's turn is next **/

    /** continue the betting **/
    call_out("delay_func", DEALER_DELAY, NORMAL );

    return 1; 

} /** raise_cmd **/





/****************************************************************************
 discard cards.
 ***************************************************************************/

status discard_cmd( string arg )
{
    string person, temp;
    int *c, i,j, discarding, args, discard, valid_flag;

    person = TP->QRN;

    if ( !errorcheck( person, DISCARDING ) )
	return 0;

    c = allocate( HAND_SIZE );
    discarding = TRUE;
    /** discard none **/
    if (arg &&( args = sscanf( arg, "%s", temp ) == 1 )
      &&( temp == "none" ))
	discarding = FALSE;


    /** player is acting, so **/
    /** no need to warn or fold them **/
    remove_call_out("timer_func");


    if ( discarding == TRUE )
    {

	if ( !arg || ( args = sscanf( arg, "%d %d %d %d %d",
	      c[0], c[1], c[2], c[3], c[4] )) < 1 )
	{
	    notify_fail("Discard what?\n");
	    return 0;
	}

	if ( args > 3 )
	{
	    notify_fail( "Dealer tells you: You cannot discard more than "
	      +DISCARD_MAX+" cards.\n");
	    return 0;
	}


	for ( i=0; i<args; i++ )
	    if (( c[i] < 1 )||( c[i] > HAND_SIZE ))
	    {
		notify_fail("Invalid card number: "+c[i]+".\n" );
		return 0;
	    }



	discard = args;

	TP->tell_me("OK. You discard:");

	for ( i=0; i<args; i++ )
	{    
	    c[i]--;
	    valid_flag = TRUE;

	    for ( j=0; j<i; j++ )
		if ( c[i]==c[j] )
		{                   /** cant discard same card twice **/
		    valid_flag = FALSE;
		    c[i] = ERROR;
		    discard--;
		}

	    if ( valid_flag == TRUE )   /** show the discarded cards **/
	    {
		get_card( hand[ person, c[i] ], LOOKAT );
		TP->tell_me("   "+(c[i]+1)+": "+card_num+" of "+card_suit+"\n");
	    }
	}


	TP->tell_me("The dealer gives you:");

	for ( i=0; i<args; i++ )
	    if ( c[i] != ERROR )             /** show the new cards **/
	    {
		hand[ person, c[i] ] = get_card( current++, DEAL );
		TP->tell_me("   "+(c[i]+1)+": "+card_num+" of "+card_suit+"\n");
	    }

	this_room->tell_here( TP->QN+" discards "+discard+" cards.", TP);
    }
    else
    {
	TP->tell_me("Ok, you keep all of your cards.");

	this_room->tell_here(TP->QN+" keeps all of "
	  +TP->Possessive()+" cards.", TP); 
    }

    drawing_done = FALSE;
    turn = next_player( turn, DONE_CHECK );           /** who's turn is next? **/

    if ( drawing_done == TRUE )
    {
	this_room->tell_here( "Dealer says: Ok, time to bet!");
	round = LAST_BETS;
	last_to_raise = 0;
	last_raise = 0;
	size_of_bet = 0;    

	for ( i=0; i<number_of_players; i++ )
	    player_bet[ player[i] ] = 0;

	call_out("delay_func", DEALER_DELAY, NORMAL );  /** begin betting **/
    }
    else 
	/** continue discarding */
	call_out("delay_func", DEALER_DELAY, DISCARDING );

    return 1;

} /** discard_cmd **/




/***************************************************************************
    Errorcheck
    Standard errorcheck function for player commands.
       - is Dealer present? ( func != ANYTIME )
       - has the game started?
       - is this player in the game?
       - has this player already folded?
       - is it this player's turn?  ( func != ANYTIME )
       - trying to bet,call,fold in discarding round? (func == DISCARDING )
       - trying to discard in a betting round? (func != DISCARDING )

 ***************************************************************************/

int errorcheck( string person, int func )
{

    if (!present("dealer", this_room ) && func != ANYTIME )
    {
	notify_fail("The dealer is not here.\n");
	return 0;
    }

    if ( playing == FALSE )
    {
	notify_fail("Since the game hasn't started yet, you cannot do that.\n");
	return 0;
    }


    if (( player_folded[ person ] == TRUE )||( member( hand, person ) == ERROR ))
    {
	notify_fail("Dealer tells you: You are not in the game.\n");
	return 0;
    }


    if (( person != player[turn] )&&( func != ANYTIME ))
    {
	notify_fail("Dealer tells you: Please wait for your turn.  It is "
	  +capitalize(player[turn])+"'s turn now.\n");
	return 0;
    }

    if (( round == DISCARDING )&&( func == NORMAL ))
    {
	notify_fail("Dealer tells you: We are discarding cards now.\n");
	return 0;
    }

    if (( round != DISCARDING )&&( func == DISCARDING ))
    {
	notify_fail("Dealer tells you: We are betting now.\n");
	return 0;
    }


    return 1;

} /** errorcheck **/ 



/****************************************************************************
  DEBUGGING FUNCTION : set cards.
    - Allows coder to set his hand of cards to anything.
 ***************************************************************************/

#if DEBUG_MODE == TRUE
status setc_cmd( string arg )
{
    int args, i,j, *handtmp;
    int *c, *s, *ctemp;
    string person;

    if ( playing == FALSE )
    {
	notify_fail("You have no cards to set.\n");
	return 0;
    }

    c = allocate( HAND_SIZE );
    s = allocate( HAND_SIZE );
    /** first 5 args are card ranks **/
    /** last 5 args are card suits **/
    if (!arg ||( args = sscanf( arg, "%d %d %d %d %d %d %d %d %d %d",
	  c[0], c[1], c[2], c[3], c[4],
	  s[0], s[1], s[2], s[3], s[4] )) < 2*HAND_SIZE )
    {
	notify_fail("Set what?\n");
	return 0;
    }

    for ( i=0; i<HAND_SIZE; i++ )        /** check argument ranges **/
	if (( c[i] < 0 )||( c[i] > 12 ))
	{
	    notify_fail("Invalid card number: "+c[i]+".\n" );
	    return 0;
	}
	else
	if (( s[i] < 0 )||( s[i] > 3 ))
	{
	    notify_fail("Invalid suit: "+s[i]+"\n");
	    return 0;
	}


    person = TP->QRN;

    if (( member( hand, person ) == ERROR ) || ( player_folded[ person ] == TRUE ))
    {
	notify_fail("You are not in the game and have no cards to reorder.\n");
	return 0;
    }


    for ( i=0; i<HAND_SIZE; i++ )
	hand[person, i] = s[i] | ( c[i] << 4 ); 

    this_room->tell_here("You notice the dealer giving "
      +TP->QN+" some extra cards.",TP );


    return 1;

}  /** set_cmd **/
#endif


/****************************************************************************
 reorder cards.
 ***************************************************************************/

status reorder_cmd( string arg )
{
    int args, i,j, *handtmp;
    int *c, *ctemp;
    string person;

    person = TP->QRN;

    if ( !errorcheck( person, ANYTIME ) )
	return 0;

    c = allocate( HAND_SIZE );

    if (!arg ||( args = sscanf( arg, "%d %d %d %d %d",
	  c[0], c[1], c[2], c[3], c[4] )) < HAND_SIZE )
    {
	notify_fail("Reorder what?\n");
	return 0;
    }

    for ( i=0; i<HAND_SIZE; i++ )             /** check arg ranges **/ 
	if (( c[i] < 0 )||( c[i] > HAND_SIZE ))
	{
	    notify_fail("Invalid card number: "+c[i]+".\n" );
	    return 0;
	} 

    handtmp = allocate( HAND_SIZE );

    for ( i=0; i<HAND_SIZE; i++ )
	handtmp[i] = hand[ person, i ]; 


    ctemp = allocate( HAND_SIZE );

    for ( i=0; i<HAND_SIZE; i++ )
    {
	c[i]--;

	for ( j=0; j<i; j++ )
	    if ( c[i]==c[j] )
	    {
		notify_fail("Cannot reorder to that configuration.\n");
		return 0;
	    }


	if ( handtmp[c[i]]!= -1 )      /** cant reorder same card twice **/
	{
	    hand[ person, i] = handtmp[c[i]];
	    handtmp[c[i]] = -1;
	}

    } 

    show_hand( person, "", LOOKAT );

    this_room->tell_here(TP->QN+" fiddles with "+TP->Possessive()+" cards.", TP );


    return 1; 

}  /** reorder_cmd **/



/****************************************************************************
  view 
    - cards, hand
    - pot
    - status
 ****************************************************************************/

status view_cmd( string arg )
{
    string who, temp;
    int tmp,i;

    if (!arg || sscanf(arg, "%s", temp) != 1 )
    {
	notify_fail("View what?\n");
	return 0;
    }

    who = TP->QRN;
    /*** view cards ***/
    if (( temp == "cards" )||( temp == "hand" ))
    {
	/** are there cards? **/ 
	if (( playing == FALSE )||( member( hand, who ) == ERROR )
	  || ( player_folded[ who ] == TRUE ))
	{
	    notify_fail("You have no cards to view.\n");
	    return 0;
	}

	show_hand( who, "", LOOKAT );

	if ( random( 2 ) == 1 )
	    this_room->tell_here(TP->QN+" studies "
	      +TP->Possessive()+" cards intently.", TP );
	else
	    this_room->tell_here(TP->QN+" glances at "
	      +TP->Possessive()+" cards.", TP );


	return 1;
    }


    /** view pot **/
    if ( temp == "pot" )
    {
	TP->tell_me("The pot contains "+pot+" coins.");
	this_room->tell_here(TP->QN+" looks longingly at the pot of coins .", TP );
	return 1;
    } 


    /** view status **/
    if ( temp == "status" )
    {

	write("Settings are:\n");
	write("   ante      : "+ante+" coins\n");
	write("   min raise : "+min_raise+" coins\n");
	write("   max raise : "+max_raise+" coins\n\n");

	if ( playing == FALSE )
	{
	    write("There is no game in progress.\n\n");

	    if ( names != "" )
	    {
		player = allocate(number_of_players);
		player = explode( names, SPACER_CHAR );
		write("The following players have anted:\n");
		for ( i=0; i<number_of_players; i++ )
		    write("   "+capitalize(player[i])+"\n");
	    }
	}
	else
	{
	    write("The following players are in the game:\n");
	    for ( i=0; i<number_of_players; i++ )
		write("   "+capitalize(player[i])+"\n"); 
	    write("\nIt is "+capitalize(player[ turn ])+"'s turn in the ");
	    if ( round == DISCARDING )
		write("drawing round.\n");
	    else
	    if ( round == LAST_BETS )
		write("final betting round.\n");
	    else
		write("initial betting round.\n");
	}

	if ( (int)(TP->query_coder_level()) > 0 )
	{
	    write("\nTable profits today are "+table_profits+" coins in "
	      +number_of_deals+" deals.\n");
	    write("Total bet volume: "+bet_volume+" coins.\n");
	}

	return 1;
    }

    return 0;

}  /** view_cmd **/





/****************************************************************************
 set stuff.
 ***************************************************************************/

status define_cmd( string arg )
{
    string temp;
    int num;  


    if (!arg || sscanf(arg, "%s %d", temp, num ) != 2 )
	return 0;


    if (( playing == TRUE )||( names != "" ))
    {
	notify_fail("Dealer tells you: You must wait until the game is over.\n");
	return 0;
    }

    if ( temp == "ante" )
    {
	if ( num > 0 ) 
	{
	    ante = num;
	    this_room->tell_here("The ante is set to "+ante+" coins.");
	    return 1;
	} 
	else
	{
	    notify_fail("Invalid ante: "+num+".\n");
	    return 0;
	}
    }

    if ( temp == "min" )
    {
	if ( num >= ante )
	{
	    min_raise = num;
	    this_room->tell_here("The minimum raise is set to "+num+" coins.");
	    return 1;
	}
	else
	{
	    notify_fail("Minumum raise cannot be less than the ante.\n");
	    return 0;
	}
    }

    if ( temp == "max" )
    {
	if ( num >= min_raise )
	{
	    max_raise = num;
	    this_room->tell_here("The maximum raise is set to "+num+" coins.");
	    return 1;
	}
	else
	{
	    notify_fail("Maximum raise cannot be less than the minimum raise.\n");
	    return 0;
	}
    }

}  /** define_cmd **/



/****************************************************************************
  Shuffle the cards.
 ****************************************************************************/

void shuffle()

{
    int i,rnd;
    int temp;
    /** swap each card with a random card */
    for ( i=0; i<DECK_SIZE; i++ )     
    {                              /** don't swap a card with itsself **/ 
	while (( rnd=random( DECK_SIZE )) == i );

	temp = card[rnd];      /** swap **/
	card[rnd] = card[i];
	card[i] = temp;

    }
}    /** swap **/



/****************************************************************************
  Deal a card from the deck.
 ****************************************************************************/

int get_card(int pos, int func )     
{
    int temp;

    temp = ( func == DEAL ) ? card[pos] : pos;

    c_suit = temp & 15;                      /** clear high bits **/ 
    c_num   = ( temp ^ c_suit ) >> 4;        /** clear low bits  **/

    if (c_num<0)  return ERROR;

    switch( c_suit )
    {
    case 0 :  card_suit = "CLUBS";    break;
    case 1 :  card_suit = "SPADES";   break;
    case 2 :  card_suit = "HEARTS";   break;
    case 3 :  card_suit = "DIAMONDS"; break;
    default:  return ERROR;
    }

    switch( c_num )
    {
    case 0 :  card_num = "  2  "; break;
    case 1 :  card_num = "  3  "; break;
    case 2 :  card_num = "  4  "; break;
    case 3 :  card_num = "  5  "; break;
    case 4 :  card_num = "  6  "; break;
    case 5 :  card_num = "  7  "; break;
    case 6 :  card_num = "  8  "; break;
    case 7 :  card_num = "  9  "; break;
    case 8 :  card_num = " 10  "; break;
    case 9 :  card_num = "JACK "; break;
    case 10:  card_num = "QUEEN"; break;
    case 11:  card_num = "KING "; break;
    case 12:  card_num = " ACE "; break;
    default:  return ERROR;
    }

    return temp;
}




/****************************************************************************
  bubble.sort.
    - sorts a hand into decending rank order
 ****************************************************************************/

void bubble_sort( int *arry1, int *arry2 )
{
    int i,j, temp;

    for ( i=0; i< HAND_SIZE; i++ )
	for ( j=(HAND_SIZE-1); j>i; j-- )
	    if ( arry1[j] > arry1[i] )
	    {
		temp = arry1[j];         /** swap the cards **/
		arry1[j] = arry1[i];
		arry1[i] = temp;
		temp = arry2[j];
		arry2[j] = arry2[i];
		arry2[i] = temp;
	    }
}




/****************************************************************************
  get next non-folded player 
 ****************************************************************************/

int next_player( int current_player, int func )
{
    int next;

    next = ( func == DISCARDING ) ? current_player : current_player+1;

    if ( next >= number_of_players )
    {
	next = 0;
	if ( func == DONE_CHECK )
	    drawing_done = TRUE;
    }

    while ( player_folded[ player[next]] == TRUE )
	if ( ++next == number_of_players )
	{
	    next = 0;
	    if ( func == DONE_CHECK )
		drawing_done = TRUE;
	}

    return next;
}



/****************************************************************************
  delay_func
    - used by call_out to delay what the dealer says
 ****************************************************************************/

void delay_func( int func )
{
    object next_player;

    /** see if we can find next player **/
    if ( next_player = find_player( player[turn] ))
    {
	if ( func == NORMAL )
	{
	    this_room->tell_here("Dealer says: "+next_player->QN
	      +", you can raise, call, or fold.");
	}
	else
	if ( func == DISCARDING )
	{
	    this_room->tell_here("Dealer says: "+next_player->QN
	      +", what cards do you wish to discard?");
	}

	call_out("timer_func", WARN_DELAY, next_player, FALSE );

    }
    else
	fold_cmd( "_AUTO_ "+player[turn] );


} 





/****************************************************************************
  timer_func 
    - used to allow inactive players to be auto-folded after a delay
 ****************************************************************************/

void timer_func( object person, int func )
{

    if ( func == TRUE )
    {
	this_room->tell_here("Dealer says: I am folding "+person->QN
	  +" for wasting our time.");

	fold_cmd( "_AUTO_ "+person->QRN );

    }
    else
    {
	this_room->tell_here("Dealer says: "+person->QN
	  +", make your play or fold.");

	call_out("timer_func", FOLD_DELAY, person, TRUE );
    }

}


/****************************************************************************
  show hand
    - shows a player's hand, either to him or everyone
 ****************************************************************************/

void show_hand( string who, string thehand, int func )

{
    int j;

    if ( func == NORMAL ) 
	this_room->tell_here("Dealer says: " 
	  +capitalize( who )+" has "+thehand+"!" );

    for ( j=0; j<HAND_SIZE; j++ )
    {
	get_card( hand[ who, j ], LOOKAT );

	if ( func == NORMAL )
	    this_room->tell_here("   "+(j+1)+": "+card_num+" of "+card_suit+"\n");
	else
	    TP->tell_me("   "+(j+1)+": "+card_num+" of "+card_suit+"\n");
    }
}




/****************************************************************************
  give pot to winner 
 ****************************************************************************/

void give_pot( string name, string tie_name, string thehand, int tie )

{
    int i,j;
    object person;
    string temp;

    i = (int)( 0.05*pot);    /** calculate the house cut  **/
    if ( i > 4*ante )        /** house gets smaller of 5% **/
	i = 4*ante;            /** of the pot or 4*ante     **/

    pot -= i;
    table_profits += i;

    if ( thehand == "fold" )
	this_room->tell_here( "Dealer says: Everyone has folded except "
	  +capitalize(name)+".");
    else
    if ( tie == FALSE )
	this_room->tell_here("Dealer says: " 
	  +capitalize(name)+" wins with "+thehand+"!");
    else
    {
	this_room->tell_here( "Dealer says: It's a tie! "
	  +capitalize(name)+" and "+capitalize(tie_name)+" win with "
	  +thehand+"!");

	pot = pot >> 1;  /** since its a tie, split pot in half **/
    }


    this_room->tell_here( "Dealer takes the house cut of "+i+" coins.");



    i = ( tie == FALSE ) ? 1 : 2;

    for ( j=0; j<i; j++ )
    {   
	temp = ( j==0 ) ? name : tie_name;

#if RECORD_POTS == TRUE
	write_file( AREA_PATH+GAME_LOG, capitalize(temp)+", "
	  +pot+", "+thehand+", "+table_profits+", "
	  +number_of_deals+"\n" );
#endif

	if ( person=present( temp, this_room ) )
	{
	    this_room->tell_here( "Dealer gives the "+pot+" coin pot to "
	      +capitalize( temp )+".", person );

	    person->tell_me("Dealer gives the "+pot+" coin pot to you!");

	    person->add_money( pot );

	}
	else
	{
	    this_room->tell_here("Dealer says: " 
	      +capitalize( temp )+" is not here to collect "
	      +person->Possessive()+" winnings.");

	    this_room->tell_here( "Dealer tosses "+capitalize( temp )+"'s "
	      +pot+" coins on the table.");

	    person = clone_object(GENERIC_MONEY_OBJECT);
	    person->set_money( pot );
	    move_object( person, this_room );

	}
    }


    /** re-init global vars **/
    names = "";
    playing = FALSE;
    number_of_players = 0;
    turn = 0;
    pot = 0;
    size_of_bet = 0;


} /** give_pot **/





/****************************************************************************
  show cards.
    - called at game end to evaluate and compare hands
 ****************************************************************************/

void show_cards( int whofirst )

{
    int i,j, temp, tie, tie_player;
    int best_so_far, best_player;
    int best_tiebreaker;
    string best_result, name; 
    object person, money;

    best_so_far = 0;
    best_tiebreaker = 0;
    tiebreaker = 0;
    tie = FALSE;

    j = whofirst;

    for ( i=0; i<number_of_players; i++ )
    {

	if ( player_folded[player[j]] == FALSE )
	{

	    temp = evaluate( player[j] );


	    if (( temp > best_so_far )
	      ||(( temp == best_so_far )&&( tiebreaker > best_tiebreaker )) )
	    {
		best_so_far = temp; 
		best_player = j;
		best_result = result;
		best_tiebreaker = tiebreaker;

	    }
	    else
	    if (( temp == best_so_far )&&( tiebreaker == best_tiebreaker ))
	    {
		tie_player = j;
		tie = TRUE;

	    }


	    if ( j == last_to_raise )
		raised_result = result;

	    j = next_player( j, NORMAL );
	}
    }




    call_out("show_hand", DEALER_DELAY,
      player[ last_to_raise ], raised_result, NORMAL );

    if (( tie == TRUE )&&( tie_player != last_to_raise )) 
	call_out("show_hand", DEALER_DELAY+1,
	  player[ tie_player ], raised_result, NORMAL );

    else
    if ( best_player != last_to_raise )
	call_out("show_hand", DEALER_DELAY+1,
	  player[ best_player ], best_result, NORMAL );


    call_out("give_pot", DEALER_DELAY+2,
      player[best_player], player[tie_player], best_result, tie );


} /** show_hands **/



/****************************************************************************
  Evaluate hand.
    - calculate a numerical score for a hand.
      Two separate scores are calculated:
	1) (score) - the score of the winning combinations (if they exist)
	2) (tiebreaker) the score for the single cards in the hand
 ****************************************************************************/

int evaluate( string person )
{
    int i,j;
    int temp;
    int *spread; 
    int score;
    int *cn, *cs;
    int flush, straight;
    int three_kind;
    int two_pair; 
    int one_pair;

    cn = allocate( HAND_SIZE );
    cs = allocate( HAND_SIZE );
    spread = allocate( 13 );

    for ( i=0; i<HAND_SIZE; i++ )
    {
	cs[i] = hand[ person, i ] & 15;                 /** clear high bits **/
	cn[i]   = ( hand[ person, i ] ^ cs[i] ) >> 4;   /** clear low bits  **/
    }

    bubble_sort( cn, cs );               /** sort hand into decending order */

    flush = TRUE;
    straight = TRUE;
    tiebreaker = 0;
    score = cn[0];

    j = HAND_SIZE-1;

    for ( i=1; i<HAND_SIZE; i++ )
    {
	if ( cs[j-i] != cs[j] )                       /** look for flush **/
	    flush = FALSE;

	if (( cn[j-i] - cn[j] ) != i )             /** look for straight **/
	{
	    if (( cn[j-i] == 12 )&&( cn[j] == 0 )
	      &&(straight==TRUE )&&( i == j ))     
		score = cn[1];                       /** 5-high straight **/
	    else
		straight = FALSE;                   /** regular straight **/
	}
    }

    if ( flush == TRUE )
    {
	if ( straight == TRUE ) 
	{
	    if ( cn[4] == 8 )                 /** if low card is a 10 **/
	    {
		result = "a royal flush";
		return 11000;
	    }
	    else
	    {
		result = "a straight flush";  
		return ( 10000 + cn[1] );
	    }
	} 
	else
	{
	    result = "a flush";
	    return ( 7000 + cn[0] );
	}
    }   

    if ( straight == TRUE )
    {
	result = "a straight";
	return ( 6000 + score );
    }

    three_kind = FALSE;
    two_pair = FALSE;
    one_pair = FALSE;
    score = 0; 

    for ( i=0; i<13; i++ )
	spread[i] = 0;

    for ( i=0; i< HAND_SIZE; i++ )
	spread[ cn[i] ]++;



    for ( i=0; i<13; i++ )
    {
	if ( spread[i] == 1 )              /** one of a kind **/
	    tiebreaker = tiebreaker | ( 1 << i );
	else
	if ( spread[i] == 2 )              /** two of a kind **/
	{
	    if ( one_pair == TRUE )
	    {
		two_pair = TRUE;
		score += 1000 + ( i << 4 );
	    }
	    else
	    {
		one_pair = TRUE;
		score += 3000 + i;
	    }
	}
	else
	if ( spread[i] == 3 )              /** three of a kind **/
	{
	    three_kind = TRUE; 
	    score += 5000 + ( i << 4 );
	}
	else
	if ( spread[i] == 4 )               /** four of a kind **/
	{
	    score = 9000 + i;
	    result = "four of a kind";
	    return score;
	}

    } 


    if ( three_kind == TRUE )
	if ( one_pair == TRUE )
	{
	    result = "a full house";
	    return score;
	}
	else
	{
	    result = "three of a kind";
	    return score;
	}

    if ( two_pair == TRUE ) 
    {
	result = "two pairs";
	return score;
    }

    if ( one_pair == TRUE )
    {
	result = "one pair";
	return score;
    }

    result = "nothing but crap";
    return score;

}

