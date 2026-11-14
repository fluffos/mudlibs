#define SENDROOM "/std/special/trade/send_room"
#define SENDPLAYER "/obj/line/send_player"
#define LINENAME   "[Trade] "
#define LINECOMMAND "Trade"
#define LINETOCOMMAND "Tradeto"
#define LINEOFF     "Tradeoff"
#define LINEON      "Tradeon"
#define LINEMEMBERS "Traders" 
#define LINECOMMAND_WITHOUT_ARG_EQUALS_MEMBERCOMMAND 1
#define NO_FEELINGS 1                       
#define NO_EMOTE 1 
#define PASS_LINETO_WHEN_OFFLINE 1 

#define OWN_SENDCOST_FUNCTION
/* This will make SENDCOST obsolete, instead
   own_sendcost_function() will be called.
   This function should return 1 for success
   and 0 for failiure.
   No messages will be printed if failure.
   It is usally a BAD idea to define SENDCOST
   when this is used, since it then will also
   check for SP.*/

#define OWN_SENDTOCOST_FUNCTION
/*
  Same as above, buy for SENDTO, function
  own_sendtocost_function() will be called.
  These functions are intended if something else than SP should be used
  as cost for using the line.  
  #define OWN_LINETO_OK_MESSAGE  Redefine the "Ok" that is sent to the player
  as confirmation on lineto-command.
*/
           
#define CHECK_AWAYSTRING 1  
#define SET_REPLY_TO 1
