/******************************************************************
  Guild slot machine 
  Coded by: Germ
  Last modified: Jan 26, 96

  Comments:  

  This machine is set up as follows:

   Symbol    R1   R2   R3   R4  |    Winning combo     #      x    $$ 
   ---------------------------- | ----------------------------------------
    fighter  10   10   10    0  |  ftr  ftr       :-)14400     2  28800 
    ninja     3    7    7    0  |  ftr  ftr  ftr  :-) 9000     4  36000
    necro     2    3    3    0  |  nja  nja       :-) 3591     6  21546 
    priest    1    2    2    0  |  nja  nja  nja  :-) 1323    10  13230
    mage      1    1    2    0  |  nec  nec  nec  :-)  162    20   3240
    thief     1    1    2    1  |  pst  pst  pst  :-)   36    50   1800
      -       0    0    0    9  |  mag  mag  mag  :-)   18   100   1800
   ---------------------------- |  thf  thf  thf  thf    2  1000   2000
	     18   24   26   10  | 

  Total combinations: 112320     
	Total income: 112320*bet 
       Total payouts: 108416*bet 

	 House margin:  3.5% 
    Margin/no jackpot:  6.9%
      Low payoff freq: 79.6%
     High payoff freq: 20.4% 
	 Winning freq: 25.4%

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
#define SLOT_LOG "LOGS/SLOT4.LOG"
#define TP this_player()
#define QN query_name()
#define QRN query_real_name()
#define NAME capitalize(person->QN)
#define TRUE 1
#define FALSE 0
#define BET_AMOUNT 1000
#define REELS 4                 /* How many reels on machine */
#define REEL1_SIZE 18           /* Total number of symbols per reel   */
#define REEL2_SIZE 24
#define REEL3_SIZE 26
#define REEL4_SIZE 10
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

    desc = "This slot machine is decorated with common guild emblems. \
 On the front of the machine is a clear panel through which you can\
 see four reels with symbols etched on their outer surfaces.\
 Attached to the side of the machine is an arm with a handgrip,\
 and a small plaque is affixed just below the panel. \
 You can \'insert coins\', \'pull arm\'.  This machine requires\
 insertion of "+num+" gold coins.\n";

    if ( (int)(TP->query_coder_level())  > 0 )
	desc += " Coders can \'view profits\'.\n";

    set_id( ({"slot","machine"}) );
    set_short("A guild slot machine");
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
       fighter fighter          :-)      2000 coins\n\
       fighter fighter fighter  :-)      4000 coins\n\
       ninja   ninja            :-)      6000 coins\n\
       ninja   ninja   ninja    :-)     10000 coins\n\
       necro   necro   necro    :-)     20000 coins\n\
       priest  priest  priest   :-)     50000 coins\n\
       mage    mage    mage     :-)    100000 coins\n\
       thief   thief   thief   thief  1000000 coins\n\n");

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

    call_out( "spinning", 1, "The first reel stops on  "+reel[0]+".");
    call_out( "spinning", 2, "The second reel stops on "+reel[1]+".");
    call_out( "spinning", 3, "The third reel stops on  "+reel[2]+".");
    call_out( "payoff", 4 );

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
	num = random( REEL1_SIZE );     /* size = 18 */
	if (num<0)   return "error";
	if (num<10)  return "FIGHTER";  /* 10 fighters on reel */
	if (num<13)  return "NINJA";    /*  3 ninjas on reel   */
	if (num<15)  return "NECRO";    /*  2 necros on reel   */
	if (num==15) return "PRIEST";   /*  1 priests on reel  */
	if (num==16) return "MAGE";     /*  1 mages on reel    */
	if (num==17) return "THIEF";    /*  1 thieves on reel  */
    }
    else
    if ( reelnum == 1 )
    {
	num = random( REEL2_SIZE );     /* size = 24 */
	if (num>23)  return "error";
	if (num>13)  return "FIGHTER";  /* 10 fighters on reel */
	if (num>6)   return "NINJA";    /*  7 ninjas on reel   */
	if (num>3)   return "NECRO";    /*  3 necros on reel   */
	if (num>1)   return "PRIEST";   /*  2 priests on reel  */
	if (num==1)  return "MAGE";     /*  1 mages on reel    */
	if (num==0)  return "THIEF";    /*  1 thieves on reel  */
    }
    else
    if ( reelnum == 2 )
    {
	num = random( REEL3_SIZE );      /* size = 26 */
	if (num<0)   return "error";
	if (num<10)  return "FIGHTER";  /* 10 fighters on reel */
	if (num<17)  return "NINJA";    /*  7 ninjas on reel   */
	if (num<20)  return "NECRO";    /*  3 necros on reel   */
	if (num<22)  return "PRIEST";   /*  2 priests on reel  */
	if (num<24)  return "MAGE";     /*  2 mages on reel    */
	if (num<26)  return "THIEF";    /*  2 thieves on reel  */
    }
    else
    if ( reelnum == 3 )
    {
	num = random( REEL4_SIZE );      /* size = 10 */
	if (num<0)   return "error";
	if (num==0)  return "THIEF";     /* 1 thief on reel */
	if (num<10)  return " :-) ";     /* 9 - on reel     */
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

    if (( match == 3 )&&( reel[0]=="THIEF" )
      &&( reel[3]=="THIEF"))
	return 1000;                           /** 4 thieves = 1000:1 **/

    if ( reel[3] == "THIEF" )
	return 0;                              /** no win if reel4=THIEF **/


    if ( reel[0] == "FIGHTER" )
    {
	if ( match == 2 )  return 2;           /** 2 fighters = 2:1 **/
	return 4;                              /** 3 fighters = 4:1 **/
    }

    if ( reel[0] == "NINJA" )
    {
	if ( match == 2 )  return 6;           /** 2 ninjas = 6:1  **/
	return 10;                             /** 3 ninjas = 10:1 **/
    }

    if ( match == 3 )
    {
	if ( reel[0] == "NECRO" )
	    return 20;                           /** 3 necros = 20:1 **/

	if ( reel[0] == "PRIEST" )
	    return 50;                           /** 3 priests = 50:1 **/

	if ( reel[0] == "MAGE" )
	    return 100;                          /** 3 mages = 100:1 **/

	if ( reel[0] == "THIEF" )
	    return 1000;                         /** 4 thieves = 1000:1 **/
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

    this_room->tell_here("The fourth reel stops on "+reel[3]);

    result = evaluate_reels()*BET_AMOUNT;

    if ( result > 60000 )
	this_room->tell_here("JACKPOT!!!!!!");

    if ( person=present(name, this_room) )
    {
	if ( result > 0 )
	{                                        /* we won something */

	    person->tell_me("You win "+result+" gold coins!\n"); 

	    this_room->tell_here(
	      NAME+" has won "+result+" gold coins.\n",person);

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

#if RECORD_LOSSES == TRUE
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

