/******************************************************************
  Lordly slot machine 
  Coded by: Germ
  Last modified: Jan 26, 96

  Comments:  

  This machine is set up as follows:

   Symbol   Reel1  Reel2  Reel3 |      Winning combo        #     x    $$ 
   ---------------------------- | ----------------------------------------
    lord     20     20      8   |  lord    lord           4800     2  9600 
    earl     15     15      4   |  lord    lord    lord   3200     3  9600
    count     8      8      4   |  earl    earl           2100     4  8400 
    prince    4      4      2   |  count   count          1344     5  6720
    king      2      2      1   |  earl    earl    earl    900     6  5400
    emperor   1      1      1   |  prince  prince          368     7  2576
   ---------------------------- |  count   count   count   256     8  2048
	     50     50     20   |  king    king             96    10   960
				|  emperor emperor          49    15   735
  Total combinations: 50000     |  prince  prince  prince   32    20   640
	Total income: 50000*bet |  king    king    king      4   100   400
	Total payouts:48079*bet |  emperor emperor emperor   1  1000  1000
				|
	 House margin:  3.8% 
    Margin/no jackpot:  5.8%
      Low payoff freq: 88.0%
     High payoff freq: 12.0% 
	 Winning freq: 26.3%

   This machine will "break" if any of two things happen:
     1) random() produces out-of range numbers
     2) the machine loses more than BROKEN_THRESHOLD

   Also, the evaluation function has been written so that
   no winning combination exists for all 3 random numbers equal.
   This prevents gold from being lost if random() gets "stuck"
   on one number.  I don't know how or why this might happen
   but hey, it's easy just to be safe.

   Things to do:
     - Code a progressive jackpot system, ie a jackpot that
       increases as people play the machine(s).

     - Allow players to insert varying amounts of coinage.

*******************************************************************/

#include <treasure.h>
#include <generic_items.h>

#include "../casino.h"

#define RECORD_WINS 1           /* 1=record them, 0=don't */ 
#define RECORD_LOSSES 1
#define SLOT_LOG "LOGS/SLOT3.LOG"
#define TP this_player()
#define QN query_name()
#define QRN query_real_name()
#define NAME capitalize(person->QN)
#define TRUE 1
#define FALSE 0
#define BET_AMOUNT 1000
#define REELS 3                 /* How many reels on machine */
#define REEL1_SIZE 50           /* Total number of symbols per reel   */
#define REEL2_SIZE 50
#define REEL3_SIZE 20
#define BROKEN_THRESHOLD 5000000  /* Something is wrong if the  */
/* machine loses more than this. */

/*******************************************************************/
/*********************** function prototypes ***********************/
string spin_reel( int reelnum );
status payoff();
void spinning( string message );

/*******************************************************************/
/************************* global vars *****************************/

int machine_profits;    /* The cumulative profit since reset */
int spinning;           /* Is the wheel currently spinning?  */
int broken;             /* Did the wheel give away too much? */
int busy;               /* Has money been inserted?          */
int number_of_pulls;    /* Total pulls since reset           */
string *reel;
string name;            /* Who inserted the coins            */
object this_room;




/*******************************************************************
  Create the object and stuff
 *******************************************************************/

void create_treasure()
{
    int num;
    string desc;
    num = BET_AMOUNT;

    desc = "This slot machine appears to be in very good condition,\
 and is painted with symbols of royalty.\
 On the front of the machine is a clear panel through which you can\
 see three reels with symbols etched on their outer surfaces.\
 Attached to the side of the machine is an arm with a handgrip,\
 and a small plaque is affixed just below the panel. \
 You can \'insert coins\', \'pull arm\'.  This machine requires\
 insertion of "+num+" gold coins.\n";

    if ( (int)(TP->query_coder_level())  > 0 )
	desc += " Coders can \'view profits\'.\n";

    set_id( ({"slot","machine"}) );
    set_short("A lordly slot machine");
    set_long( desc );

    /*** initialize global vars ***/

    spinning = FALSE;
    broken = FALSE;
    busy = FALSE;
    machine_profits = 0;
    number_of_pulls = 0;

    reel = allocate( REELS );
}


status get() { return 0; }

void init_treasure()
{
    add_action("insert_cmd", "insert");
    add_action("pull_cmd", "pull");
    add_action("view_cmd", "view");
    add_action("read_cmd", "read"); 

    this_room = environment(TP);

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

    write("\nThe payoffs for this machine are:\n\n\
       lord    lord                2000 coins\n\
       lord    lord    lord        3000 coins\n\
       earl    earl                4000 coins\n\
       count   count               5000 coins\n\
       earl    earl    earl        6000 coins\n\
       prince  prince              7000 coins\n\
       count   count   count       8000 coins\n\
       king    king               10000 coins\n\
       emperor emperor            15000 coins\n\
       prince  prince  prince     20000 coins\n\
       king    king    king      100000 coins\n\
       emperor emperor emperor  1000000 coins\n\n");

    return 1;

}


/*******************************************************************
  Process the insert command
*******************************************************************/

status insert_cmd(string arg)
{
    int howmuch;
    string temp;

    if (!arg || sscanf(arg, "%s", temp ) != 1 || temp != "coins" )
    {
	notify_fail("Insert what?\n"); 
	return 0;
    }

    if ( spinning == TRUE )
    {
	notify_fail("You must wait till the machine is ready.\n");
	return 0;
    }


    /* Broken can only happen if the wheel loses more than BROKEN_THRESHOLD */
    /* or if random() generates an incorrect number.                        */

    if ( broken == TRUE )
    {
	notify_fail("The machine is broken.  Please try again later.\n");
	return 0;
    }

    if ( busy == TRUE )
    {
	notify_fail("Someone has already inserted coins into this machine.\n");
	return 0;
    }


    howmuch = BET_AMOUNT;

    if (TP->query_money() < howmuch  )
    {
	notify_fail("You don\'t have "+howmuch+" coins to insert.\n");
	return 0;
    }

    TP->tell_me("Ok. You insert "+howmuch+" coins into the machine.");

    environment(TP)->tell_here(
      TP->QN + " inserts " +howmuch+ " coins into the machine.", TP);

    TP->add_money(-(howmuch));         /* subtract the bet from player's cash */

    busy = TRUE;

    return 1;
}


/***************************************************************************
  Process the pull command
 ***************************************************************************/

status pull_cmd(string arg)
{
    string temp; 
    int x;

    if (!arg || sscanf(arg, "%s", temp) != 1 || temp!="arm" )
    {
	notify_fail("Pull what?\n"); 
	return 0;
    }

    if ( spinning == TRUE )
    {
	notify_fail("You can\'t pull the arm while the machine is working.\n");
	return 0;
    }

    if ( busy == FALSE )
    {
	notify_fail("You must insert coins first.\n");
	return 0;
    }

    TP->tell_me("Ok. You pull the arm, and the reels spin!"); 
    this_room->tell_here(TP->QN + " pulls the arm, and the reels spin!", TP); 


    /* make sure that random() returns a number in the correct range */

    for ( x=0; x<REELS; x++ )
    {
	if ( (reel[x]=spin_reel(x)) == "error" )
	{
	    broken = TRUE;
	    notify_fail("The machine makes a grating noise.\n");
	    return 0;
	}
    }

    /*** everything seems ok...spin it! ***/

    name = TP->QRN;

    call_out( "spinning", 1, "The first reel stops on "+reel[0]+".");
    call_out( "spinning", 2, "The second reel stops on "+reel[1]+".");
    call_out( "payoff", 3 );

    number_of_pulls++;
    busy = FALSE;

    return 1;
}



/****************************************************************************
  Process 'view profits'
 ****************************************************************************/

status view_cmd(string arg)
{
    string temp;

    if (!arg || sscanf(arg, "%s", temp) != 1 || temp != "profits" )
    {
	notify_fail("View what?\n");
	return 0;
    }

    /*** only coders can check profits ***/

    if ( (int)(TP->query_coder_level()) > 0 ) 
    {
	TP->tell_me("The total profits for this machine are "+machine_profits+ 
	  " in " +number_of_pulls+ " spins.\n");
	return 1;
    }

    return 0;

}


/****************************************************************************
  Generate and return the winning symbol from the wheel
 ****************************************************************************/

string spin_reel( int reelnum )     
{
    int num;

    spinning = TRUE;

    /* Note..the values of num corresponding to the symbols monsters
       are arranged on each reel so that there are no winning combinations
       possible if all 3 random() functions produce the same number.
       This prevents the machine from giving away money if random()
       breaks and gets stuck on one number.  I don't know why it
       would do this, but hey why risk it.
    */

    if ( reelnum == 0 )
    {
	num = random( REEL1_SIZE );     /* size = 50 */
	if (num<0)   return "error";
	if (num<20)  return "LORD";     /* 20 lords on reel    */
	if (num<35)  return "EARL";     /* 15 earls on reel    */
	if (num<43)  return "COUNT";    /*  8 counts on reel   */
	if (num<47)  return "PRINCE";   /*  4 princes on reel  */
	if (num<49)  return "KING";     /*  2 kings on reel    */
	if (num==49) return "EMPEROR";  /*  1 emperor on reel  */
    }
    else
    if ( reelnum == 1 )
    {
	num = random( REEL2_SIZE );     /* size = 50 */
	if (num>49) return "error";
	if (num>29) return "LORD";      /* 20 lords on reel    */
	if (num>14) return "EARL";      /* 15 earls on reel    */
	if (num>6)  return "COUNT";     /*  8 counts on reel   */
	if (num>2)  return "PRINCE";    /*  4 princes on reel  */
	if (num>0)  return "KING";      /*  2 kings on reel    */
	if (num==0) return "EMPEROR";   /*  1 emperor on reel  */
    }
    else
    if ( reelnum == 2 )
    {
	num = random( REEL3_SIZE );      /* size = 20 */
	if (num<0)   return "error";
	if (num<8)   return "LORD";      /* 8 lords on reel    */
	if (num<12)  return "EARL";      /* 4 earls on reel    */
	if (num<16)  return "COUNT";     /* 4 counts on reel   */
	if (num<18)  return "PRINCE";    /* 2 princes on reel  */
	if (num==18) return "KING";      /* 1 king on reel     */
	if (num==19) return "EMPEROR";   /* 1 emperor on reel  */
    }

    return "error";
}


/****************************************************************************
  Evaluate the reels 
****************************************************************************/

int evaluate_reels()
{
    int match;

    if ( reel[0] != reel[1] )  return 0;      /** we lost **/

    match = ( reel[0] == reel[2] ) ? 3 : 2;

    if ( reel[0] == "LORD" )
    {
	if ( match == 2 )  return 2;           /** 2 lords = 2:1 **/
	return 3;                              /** 3 lords = 3:1 **/
    }

    if ( reel[0] == "EARL" )
    {
	if ( match == 2 )  return 4;           /** 2 earls = 4:1 **/
	return 6;                              /** 3 earls = 6:1 **/
    }

    if ( reel[0] == "COUNT" )
    {
	if ( match == 2 )  return 5;           /** 2 counts = 5:1 **/
	return 8;                              /** 3 counts = 8:1 **/
    }

    if ( reel[0] == "PRINCE" )
    {
	if ( match == 2 )  return 7;           /** 2 princes =  7:1 **/
	return 20;                             /** 3 princes = 20:1 **/
    }

    if ( reel[0] == "KING" )
    {
	if ( match == 2 )  return 10;          /** 2 kings =  10:1 **/
	return 100;                            /** 3 kings = 100:1 **/
    }

    if ( reel[0] == "EMPEROR" )
    {
	if ( match == 2 )  return 15;          /** 2 emperors =   15:1 **/
	return 1000;                           /** 3 emperors = 1000:1 **/
    }

    return 0;

} 


/****************************************************************************
  Payoff if we won 
****************************************************************************/

status payoff()
{  
    int result;
    object person, money;

    this_room->tell_here("The third reel stops on "+reel[2]+"!");

    result = evaluate_reels()*BET_AMOUNT;

    if ( result > 90000 )
	this_room->tell_here("JACKPOT!!!!!!");

    if ( person=present(name, this_room) )
    {
	if ( result > 0 )
	{                                        /* we won something */

	    person->tell_me("You win "+result+" gold coins!\n"); 

	    this_room->tell_here( person->QN
	      +" has won "+result+" gold coins.\n",person);

	    person->add_money(result);
	    machine_profits -= result - BET_AMOUNT; 

#if RECORD_WINS == TRUE
	    if ( !( person->query_coder_level()) )     /** lets not log coders **/
		write_file( AREA_PATH+SLOT_LOG, person->QRN+", "+result+", "
		  +reel[0]+" "+reel[1]+" "+reel[2]+", "
		  +machine_profits+", "+ number_of_pulls +"\n" );
#endif

	}
	else
	{                                        /* we did not win */
	    result = BET_AMOUNT;
	    machine_profits += result;

#if RECORD_WINS == TRUE
	    if ( !( person->query_coder_level()) )         /** lets not log coders **/
		write_file( AREA_PATH+SLOT_LOG, person->QRN+", "+result+", "
		  +reel[0]+" "+reel[1]+" "+reel[2]+", "
		  +machine_profits+", "+ number_of_pulls +"\n" );
#endif

	} 
    }
    else                                       /* winner isnt here */
    {
	if ( result > 0 )
	{
	    this_room->tell_here(result+" gold coins fall out of the machine!\n"); 
	    money = clone_object(GENERIC_MONEY_OBJECT);
	    money->set_money( result );
	    move_object( money, this_room );
	    machine_profits -= result - BET_AMOUNT;
	}
    }

    if ( machine_profits < -BROKEN_THRESHOLD )
    {
	broken = TRUE;
	this_room->tell_here("Suddenly you hear a grinding noise from the machine!\n");
    }


    name = ""; 
    spinning = FALSE;
    busy = FALSE;

    return 1;
}



/***************************************************************************
  Called by call_out to display the "reel spins" messages 
***************************************************************************/

void spinning( string message )
{
    this_room->tell_here( message );
}


/***************************************************************************/
/***************************************************************************/

