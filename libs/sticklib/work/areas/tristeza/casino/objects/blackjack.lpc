/******************************************************************
  Casino blackjack 
  Coded by: Germ
  Last modified: Feb 12, 1996 

  Modification history:
    (2/11/96) -  fixed bug when both player & dealer have blackjack.
    (2/12/96) -  Reduced bet limits to min=100, max=10000
	      - Coder's games no longer get logged or included
		in the profit/loss stats. 
  Comments: 

  This is pretty much casino blackjack, with a couple of
  differences:

    - Splitting pairs is not coded.  This is mainly because
      the current game design makes splitting really awkward.
      It probably should be coded sometime though.

    - Insurance isn't coded either, partly because it's also
      awkward to code correctly, but mostly since insurance 
      generally favors the house, not having it offsets the
      lack of splitting, which generally favors the player.

  Lets wait and see if anybody complains. =-)

  Also, since at some casinos the dealer must stand on a
  soft 17, while other casinos allow the dealer to hit
  on a soft 17, I have included the flag HIT_SOFT17 that
  can be set for either way of playing.  Hitting on soft 17
  generally favors the casino.

*******************************************************************/

#include <treasure.h>
#include "../casino.h"

#define RECORD_WINS 1                /* 1=record wins, 0=don't     */ 
#define RECORD_LOSSES 1
#define RECORD_PROFITS 1

#define DEBUG_MODE 0                 /* enables the setc function  */
#define GAME_LOG "LOGS/BJACK.LOG"
#define PROFIT_LOG "LOGS/bjack.profits"
#define TP this_player()
#define QN query_name()
#define QRN query_real_name()
#define TRUE 1                       /* boolean flag               */
#define FALSE 0                      /* boolean flag               */
#define ERROR -1                     /* general error flag         */
#define DEAL 1                       /* get_card arg               */
#define LOOKAT 2                     /* get_card arg               */
#define NORMAL 0                     /* general purpose arg        */ 
#define SPACER_CHAR "*"              /* used in name string        */

#define MIN_PLAYERS 1                /* min players for a game     */ 
#define MAX_PLAYERS 6                /* max players in the game    */
#define DEALER_DELAY 2               /* delay before he says stuff */
#define WARN_DELAY 30                /* delay before warning       */
#define FOLD_DELAY 15                /* delay after warning        */
#define DECK_SIZE 52                 /* number of cards in deck    */
#define HAND_SIZE 2                  /* number of cards dealt      */
#define DISCARD_MAX 3                /* max cards you can discard  */
#define MIN_BET 100                  /* default minimum bet        */
#define MAX_BET 10000                /* default maximum bet        */ 
#define HIT_SOFT17 1                 /* Dealer hits on soft 17     */

/*******************************************************************/
/*********************** function prototypes ***********************/
void shuffle();
int  get_card( int pos, int func );
int  get_bets( string forwho );
int  errorcheck( string person );
void delay_func( int func );
void timer_func( string person, int func );
void show_cards( int whofirst );
void show_hand( string who, int func );
void payoff( int dealer_score ); 
void dealer_play();
int  evaluate( string person );

/*******************************************************************/
/************************* global vars *****************************/

string player_names, *player;         /* players in the game      */
string player_bets,  *bets;
string card_num, card_suit;           /* text of most recent card */
int c_num, c_suit;                    /* info on most recent card */
int *card;                            /* The deck of cards        */
int current;                          /* which card dealt next    */
int soft;                             /* is an Ace present        */
int turn;                             /* It is this player's turn */

int playing;              /* TRUE if a game is in progress        */
int number_of_deals;      /* Total games since reset              */
int number_of_players;    /* number of players who began          */
int table_profits;        /* The cumulative profit since reset    */
int last_profits;
int bet_volume;
int can_do;

mapping hand;             /* the player's hand of cards           */
mapping hand_ptr;

object this_room;         /* the poker room                       */ 



/*******************************************************************
  blackjack object maintenance 
 *******************************************************************/

void create_treasure()
{
    int min;
    int num,suit;
    string desc;

    desc = "It is a blackjack table big enough to accomodate about\
 six players at a time.  On the edge of the table you notice a\
 small plaque.  Valid game commands are:\n\n\
      bet <amount>   -  Do this to get in the game\n\
      deal           -  Begin dealing\n\
      hit            -  Ask dealer to deal you another card\n\
      stand          -  Don't get another card\n\
      double         -  Double your bets\n\
      view cards     -  See the cards you were dealt\n\
      view status    -  See the game status and stuff\n\n\
 Currently the minumum bet is "+MIN_BET+" and the maximum bet is "
    +MAX_BET+".\n\n"; 


    set_id( ({"table","blackjack"}) );
    set_short("A blackjack table");
    set_long( desc );


    /** initialize global vars **/

    player_names = "";
    playing = FALSE;
    number_of_players = 0;
    number_of_deals = 0;
    table_profits = 0;
    bet_volume = 0;
    can_do = FALSE;

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
    add_action("bet_cmd", "bet");
    add_action("deal_cmd", "deal");
    add_action("stand_cmd", "stand");
    add_action("hit_cmd","hit");
    add_action("split_cmd","split" );
    add_action("insurance_cmd","insurance");
    add_action("double_cmd","double");
    add_action("view_cmd","view");
    add_action("read_cmd","read");

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
	  +", Deals = "+number_of_deals+", "+ctime(time())+"\n");

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

    write("The rules for this table are as follows:\n\n\
 - Payoff for blackjack is 3:2.\n\
 - Payoff for winners is 1:1.\n\
 - Players may double down on two-card totals of 10 or 11.\n\
 - Dealer hits on soft 17.\n\
 - Players cannot split pairs.\n\
 - Insurance betting is not allowed.\n\n");

    return 1;

}




/*******************************************************************
  Process the bet command
*******************************************************************/

status bet_cmd(string arg)
{
    object tm;
    int temp, howmuch;
    string symb;

    if ( !present("dealer", this_room ))
    {
	notify_fail("The dealer is not here.\n");
	return 0;
    }


    if ( strstr( SPACER_CHAR+player_names, (TP->QRN)+SPACER_CHAR, 0 ) != -1 )
    {
	notify_fail("Dealer tells you: You are already in.\n");
	return 0;
    }

    if ( playing == TRUE )
    {
	notify_fail("Dealer tells you: Wait until this game is over.\n");
	return 0;
    }

    if (!arg || sscanf(arg, "%d", howmuch) != 1 )
	return 0;

    if (howmuch < MIN_BET )
    {
	notify_fail("Dealer tells you: The minimum bet for this table is "+MIN_BET+"\n");
	return 0;
    }

    /* without a betting limit, a rich player can never lose */

    if ( howmuch > MAX_BET )
    {
	notify_fail("Dealer tells you: The maximum bet for this table is "
	  +MAX_BET+ ".\n");
	return 0;
    }


    if (TP->query_money() < howmuch )
    {
	notify_fail("Dealer tells you: You don\'t have enough gold!\n");
	return 0;
    }

    if ( number_of_players == MAX_PLAYERS )
    {
	notify_fail("Dealer tells you: We already have "
	  +MAX_PLAYERS+" in the game.\n");
	return 0;
    }


    TP->tell_me("Ok. You bet "+howmuch+" coins.");
    environment(TP)->tell_here(TP->QN + " bets "+howmuch+" coins.", TP);

    TP->add_money(-(howmuch));         /* subtract the bet from player's cash */

    player_bets = player_bets + (string)howmuch + SPACER_CHAR;
    player_names = player_names + TP->QRN + SPACER_CHAR;    

    if ( !( TP->query_coder_level()) )
	bet_volume += howmuch;

    number_of_players++;

    return 1;

} /** bet_cmd **/     





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
	  +MIN_PLAYERS+" player.\n");
	return 0;
    }


    if ( strstr( SPACER_CHAR+player_names, (TP->QRN)+SPACER_CHAR, 0 ) == -1 )
    {
	notify_fail("Dealer tells you: You haven't joined the game yet.\n");
	return 0;
    }

    current = 0;
    turn = 0;
    playing = TRUE;

    number_of_deals++;
    /** shuffle the deck **/
    for ( i=0; i<random(2)+2; i++ )
	shuffle();

    this_room->tell_here("The dealer shuffles the cards...");



    player = allocate(number_of_players+1);
    player = explode( player_names+"dealer"+SPACER_CHAR, SPACER_CHAR );

    bets = allocate( number_of_players+1 );
    bets = explode( player_bets, SPACER_CHAR );

    tmp = allocate(number_of_players+1);
    hand = mkmapping( player, tmp, tmp, tmp, tmp, tmp, tmp, tmp, tmp );

    hand_ptr = mkmapping( player, tmp );

    /* deal the cards */
    /* Note: The deck never changes until the next shuffle     */
    /*       As cards are dealt, "current" increments to point */
    /*       to the next card to be dealt.                     */

    for ( i=0; i<number_of_players+1; i++ )
	if (( person=present( player[i], this_room ))
	  ||( i == number_of_players ))
	{
	    for ( j=0; j<HAND_SIZE; j++ )
		hand[ player[i], j ] = get_card( current++, DEAL ); 

	    hand_ptr[ player[i] ] = HAND_SIZE;

	    if ( i != number_of_players ) 
	    { 
		person->tell_me("The dealer deals you "+HAND_SIZE+" cards!");
		this_room->tell_here( person->QN+
		  " is dealt "+HAND_SIZE+" cards.", person ); 

		show_hand( player[i], LOOKAT );

	    }
	}   
	else
	{
	    this_room->tell_here("Dealer says: Hmm..where is "+player[i]+"?");
	}

    this_room->tell_here("Dealer deals himself "
      +HAND_SIZE+" cards, the 2nd of which is: "
      +card_num+" of "+card_suit+".");

    call_out("delay_func", DEALER_DELAY, NORMAL );

    return 1;
}







/****************************************************************************
 stand.
 ***************************************************************************/

status stand_cmd( string arg )
{
    string person, temp;
    int result,i;


    if (arg && ( sscanf(arg, "%s %s", temp, person ) == 2 )
      && ( temp == "_AUTO_" ));
    else
    { 
	person = TP->QRN;


	if ( !errorcheck( person ) )
	    return 0;


	TP->tell_me("Ok. You stand.");
	this_room->tell_here( TP->QN+" stands.", TP ); 

    }
    /** player is standing, so **/
    /** no need to warn or fold them **/
    remove_call_out("timer_func");


    if (( hand_ptr[ person ] == 2 )
      &&( evaluate( person ) == 21 )
      &&( evaluate( "dealer" ) != 21 ))  

    {
	TP->tell_me("You have blackjack!");
	this_room->tell_here(TP->QN+" has blackjack!", TP);

	result = (int)bets[turn];
	result = (int)(result*1.5);

	TP->tell_me("You win "+result+" coins!");

	this_room->tell_here(TP->QN+" wins "+
	  result+" coins!", TP );


	TP->add_money(result*2);

	if ( !( TP->query_coder_level()) )
	    table_profits -= result;

#if RECORD_WINS == TRUE
	if ( !( TP->query_coder_level()) )            /** lets not log coders **/
	    write_file( AREA_PATH+GAME_LOG, capitalize(player[turn])
	      +", "+result+"->BJ, " 
	      +table_profits+", "+number_of_deals+"\n");
#endif

    }


    turn++;

    if ( turn == number_of_players )
    {
	call_out("dealer_play", DEALER_DELAY );
	return 1;
    }

    can_do = FALSE;

    call_out("delay_func", DEALER_DELAY, NORMAL );

    return 1; 

}  /** call_cmd **/






/****************************************************************************
 hit.
 ***************************************************************************/

status hit_cmd( string arg )
{
    string person, temp;
    int total;

    person = TP->QRN;

    if ( !errorcheck( person ))
	return 0;

    /** player is hitting, so **/
    /** no need to warn or fold them **/
    remove_call_out("timer_func");


    TP->tell_me("Ok, you hit.");
    this_room->tell_here(TP->QN+" hits.", TP );

    hand[ person, hand_ptr[person] ] = get_card( current++, DEAL );
    hand_ptr[person]++;

    TP->tell_me("The dealer deals you: "+card_num+" of "+card_suit+".");

    this_room->tell_here("The dealer deals "+TP->QN+": "
      +card_num+" of "+card_suit+".", TP );


    if (( total = evaluate( person )) > 21 )
    {
	this_room->tell_here("Dealer says: "+TP->QN+" busts.");

	turn++;

	if ( turn == number_of_players )
	{
	    call_out("dealer_play", DEALER_DELAY ); 
	    return 1;
	}

    }

    can_do = FALSE;
    call_out("delay_func", DEALER_DELAY, NORMAL );

    return 1;

} /** hit_cmd **/




/****************************************************************************
 double.
 ***************************************************************************/

status double_cmd( string arg )
{
    string person, temp;
    int total, result, i;

    person = TP->QRN;

    if ( !errorcheck( person ))
	return 0;

    this_room->tell_here(TP->QN+" turns over "+TP->Possessive()+
      " cards: ");

    show_hand( person, NORMAL );

    if ( hand_ptr[player[turn]] != 2 )
    {
	this_room->tell_here("Dealer says: Sorry "+TP->QN+
	  ", you can only double down on your first 2 cards.");
	return 1;
    }

    total = evaluate( player[turn] );

    if  ((( total != 10 )&&( total != 11 )
	&&(( total != 20 )||( soft == FALSE ))))
    {
	this_room->tell_here("Dealer says: Sorry "+TP->QN+
	  ", you can only double down on a 10 or 11.");
	return 1;
    }


    result = (int)bets[turn];

    if (( TP->query_money() - result ) < 0 ) 
    {
	this_room->tell_here("Dealer says: Sorry "+TP->QN+
	  ", you don't have enough gold to double down.");
	return 1;
    }
    /** player is doubling, so **/
    /** no need to warn or fold them **/
    remove_call_out("timer_func");


    TP->add_money( -result );

    if ( !( TP->query_coder_level()) )
	bet_volume += result;

    bets[turn] = (string)(2*result);

    TP->tell_me("Ok, you bet another "+result+" coins and double down.");
    this_room->tell_here( TP->QN+" bets another "
      +result+" coins and doubles down.", TP );

    hand[ person, hand_ptr[person] ] = get_card( current++, DEAL );
    hand_ptr[person]++;

    TP->tell_me("The dealer deals you: "+card_num+" of "+card_suit+".");
    this_room->tell_here("The dealer deals "+TP->QN+": "
      +card_num+" of "+card_suit+".", TP );


    if (( total = evaluate( person )) > 21 )
	this_room->tell_here("Dealer says: "+TP->QN+" busts.");

    turn++;

    if ( turn == number_of_players )
    {
	call_out("dealer_play", DEALER_DELAY );
	return 1;
    }

    can_do = FALSE;
    call_out("delay_func", DEALER_DELAY, NORMAL );

    return 1;

}




/****************************************************************************
 split.
    - splitting probably should be coded, but it's a pain in the ass
      to manage it using this style of game setup.
 ***************************************************************************/

status split_cmd( string arg )
{
    string person;

    person = TP->QRN;

    if ( !errorcheck( person ))
	return 0;

    TP->tell_me("Dealer tells you: Sorry, this casino doesn't allow splitting.");

    return 1;

}




/****************************************************************************
 insurance.
    - Insurance isn't coded either. Blah.  Who cares?
 ***************************************************************************/

status insurance_cmd( string arg )
{
    string person;

    person = TP->QRN;

    if ( !errorcheck( person ))
	return 0;

    TP->tell_me("Dealer tells you: Sorry, this casino doesn't give insurance.");

    return 1;
}




/***************************************************************************
    Errorcheck
    Standard errorcheck function for player commands.
       - is Dealer present? 
       - has the game started?
       - is this player in the game?
       - has this player already folded?
       - is it this player's turn?
 ***************************************************************************/

int errorcheck( string person )
{

    if (!present("dealer", this_room ))
    {
	notify_fail("The dealer is not here.\n");
	return 0;
    }


    if ( playing == FALSE )
    {
	notify_fail("Since the game hasn't started yet, you cannot do that.\n");
	return 0;
    }


    if ( member( hand, person ) == ERROR )
    {
	notify_fail("Dealer tells you: You are not in the game.\n");
	return 0;
    }


    if (( person != player[turn] )||( can_do == FALSE ))
    {
	notify_fail("Dealer tells you: Please wait for your turn.  It is "
	  +capitalize(player[turn])+"'s turn now.\n");
	return 0;
    }


    return 1;

} /** errorcheck **/ 




/****************************************************************************
  view 
    - cards, hand
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
	if (( playing == FALSE )||( member( hand, who ) == ERROR ))
	{
	    notify_fail("You have no cards to view.\n");
	    return 0;
	}

	show_hand( who, LOOKAT );

	if ( random( 2 ) == 1 )
	    this_room->tell_here(TP->QN+" studies "
	      +TP->Possessive()+" cards intently.", TP );
	else
	    this_room->tell_here(TP->QN+" glances at "
	      +TP->Possessive()+" cards.", TP );


	return 1;
    }

    if (( temp == "status" )||( temp == "profits" ))
    {
	if ( playing == FALSE )
	{
	    write("There is no game in progress.\n\n");

	    if ( player_names != "" )
	    {
		player = allocate(number_of_players);
		player = explode( player_names, SPACER_CHAR );
		write("The following players have placed bets:\n");
		for ( i=0; i<number_of_players; i++ )
		    write("   "+capitalize(player[i])+"\n");
	    }
	}
	else
	{
	    write("The following players are in the game:\n");
	    for ( i=0; i<number_of_players; i++ )
		write("   "+capitalize(player[i])+"\n");
	    write("\nIt is "+capitalize(player[ turn ])+"'s turn.\n");
	}

	if ( TP->query_coder_level() )
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
  delay_func
    - used by call_out to delay what the dealer says
 ****************************************************************************/

void delay_func( int func )

{
    int total;
    string temp;
    object whoami;

    whoami = find_player( player[turn] );

    temp = "Dealer says: "+whoami->QN;
    total = evaluate( player[turn] );

    if (( hand_ptr[ player[turn]] == 2 )
      && (( total == 10 )||( total == 11 )
	||(( total == 20 )&&( soft == TRUE ))))
	temp += ", you can hit, stand, or double."; 
    else
	temp +=", you can hit or stand.";

    this_room->tell_here( temp );

    can_do = TRUE;

    call_out("timer_func", WARN_DELAY, player[turn], FALSE );

} 





/****************************************************************************
  timer_func 
    - used to allow inactive players to be auto-folded after a delay
 ****************************************************************************/

void timer_func( string person, int func )
{

    if ( func == TRUE )
    {
	this_room->tell_here("Dealer says: I am standing "
	  +find_player( person )->QN+" for wasting our time.");

	stand_cmd("_AUTO_ "+person );
    }
    else
    {
	this_room->tell_here("Dealer says: "+find_player( person )->QN
	  +", make your play or stand.");

	call_out("timer_func", FOLD_DELAY, person, TRUE );
    }

}


/****************************************************************************
  show hand
    - shows a player's hand, either to him or everyone
 ****************************************************************************/

void show_hand( string who, int func )

{
    int j;

    for ( j=0; j<hand_ptr[who]; j++ )
    {
	get_card( hand[ who, j ], LOOKAT );

	if ( func == NORMAL )
	    this_room->tell_here("   "+card_num+" of "+card_suit+"\n");
	else
	    TP->tell_me("   "+card_num+" of "+card_suit+"\n");
    }
}




/****************************************************************************
  dealer_play 
 ****************************************************************************/

void dealer_play()
{
    int i, total;
    string person;

    total = TRUE;

    for ( i=0; i<number_of_players; i++ )
	if ( evaluate( player[i] ) < 22 )
	    total = FALSE;

    if ( total == TRUE )
    {
	this_room->tell_here("Dealer says: All players have busted.");

	player_names = "";
	player_bets = "";
	number_of_players = 0;
	playing = FALSE;
	can_do = FALSE;

	return;
    }

    person = "dealer";
    this_room->tell_here("The dealer's cards are: ");

    show_hand( person, NORMAL );

    total = evaluate( person );  

    if ( total  == 21 )
	this_room->tell_here("Dealer has blackjack!");
    else
	while (( total < 17 )
	  || (( total == 17 )&&( soft == TRUE )&&(HIT_SOFT17 == TRUE )))
	{
	    hand[ person, hand_ptr[person] ] = get_card( current++, DEAL );
	    hand_ptr[ person ]++;


	    if (( random(2) )
	      &&( total = evaluate( person )) > 21 ) /** whoops! hehehe **/
		hand[ person, hand_ptr[person]-1 ] = get_card( current++, DEAL );


	    this_room->tell_here("The dealer deals himself: "
	      +card_num+" of "+card_suit+"." );

	    total = evaluate( person );
	}


    if ( total > 21 )
	this_room->tell_here("Dealer says: "+capitalize(person)+" busts.");


    call_out("payoff", DEALER_DELAY, total );

}





/****************************************************************************
  Payoff winners 
 ****************************************************************************/

void payoff( int dealer_score )
{
    int i, score, result;
    object person;

    for ( i=0; i<number_of_players; i++ )
    {

	score = evaluate( player[i] );

	if ( person=present( player[i], this_room) )
	{
	    result = (int)bets[i];
	    /** player had blackjack **/
	    /** and dealer didnt     **/

	    if (( score == 21 )&&( hand_ptr[ player[i] ] == 2 )
	      &&(( dealer_score != 21 )||( hand_ptr["dealer"] > 2 ))); 
	    else
	    if ( score < 22  )                   /** player didn't bust **/
	    {
		if (( score > dealer_score )||( dealer_score > 21 ))   /** player wins **/
		{
		    person->tell_me("You win "+result+" coins!");          

		    this_room->tell_here( person->QN+" wins "+ 
		      result+" coins!", person );


		    person->add_money(result*2);  

		    if ( !( person->query_coder_level()) )
			table_profits -= result;

#if RECORD_WINS == TRUE
		    if ( !( person->query_coder_level()) )     /** lets not log coders **/
			write_file( AREA_PATH+GAME_LOG, capitalize(player[i])
			  +", W "+score+", "+dealer_score+", "+result
			  +", "+table_profits+", "+number_of_deals+"\n");
#endif

		}
		else                                    /*** player pushes **/
		if (( score == dealer_score )&&( dealer_score < 22 )) 
		{
		    person->tell_me("You push, and get back your "+result+" coins.");

		    this_room->tell_here( person->QN+
		      " pushes, and gets back "+person->Possessive()+" "+
		      result+" coins.", person );


		    person->add_money(result);

		}
		else                                   /** player loses **/
		{
		    person->tell_me("You lose your "+result+" coins.");

		    this_room->tell_here(person->QN+" loses "
		      +person->Possessive()+" "+result+" coins.", person );

		    if ( !( person->query_coder_level()) )
			table_profits += result;

#if RECORD_LOSSES == TRUE
		    if ( !( person->query_coder_level() ))
			write_file(AREA_PATH+GAME_LOG, capitalize( player[i] )
			  +", L, "+score+", "+dealer_score+", "+result
			  +", "+table_profits+", "+number_of_deals+"\n" );
#endif

		}
	    }
	    else
	    if ( !( person->query_coder_level()) )
		table_profits += result;               /** player busted earlier **/

	}  /* if person == present */
	else                                        /** player isn't here **/
	{
	    if ( person = find_player( player[i] ))
	    {
		if ( score < 22 )
		    this_room->tell_here( person->QN
		      +" is not here, and so forfeits "+
		      person->Possessive()+" "+result+" coins.");

		if ( !( person->query_coder_level()) )
		    table_profits += result;
	    }
	}
    }

    player_names = "";
    player_bets = "";
    number_of_players = 0;
    playing = FALSE;
    can_do = FALSE;

}






/****************************************************************************
  evaluate the score of a blackjack hand 
 ****************************************************************************/

int evaluate( string person )
{
    int total, aces, i, tmp;

    total = 0;
    aces = 0;
    soft = FALSE;

    for ( i=0; i<hand_ptr[person]; i++ )
    {
	tmp = ( hand[ person , i ] >> 4 )+2;   /** clear low bits  **/

	if ( tmp == 14 )                       /** card is an ace **/
	{
	    aces++;                             /** start with value of 11 **/
	    total += 11;
	}
	else
	{
	    if ( tmp > 10 )
		total += 10;
	    else 
		total += tmp;
	}
    }

    while(( total > 21 )&&( aces > 0 ))        /** if bust, start converting **/
    {                                         /** aces from 11 to 1         **/
	total -= 10;
	aces--;
    }

    if (( total == 17 )&&( aces > 0 ))
	soft = TRUE;

    return total;

}
