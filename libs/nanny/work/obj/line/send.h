/* Read /doc/RULES/guilds.r before using this file */
#define SENDROOM "players/rohan/send_room"
  /*You can make a copy of /obj/line/send_room.c*/ 
#define SENDPLAYER "/obj/line/send_player"
  /*You can have an own version but this is not recomended. */
#define LINENAME   "[Monks] "

#define SENDCOST   0
  /* SENDCOST must be at least 10sp for clubs */

#define SENDTOCOST 3    /* 3 is minimum cost for clubs and highly
                           recomended for guilds. */

  /* LINECOMMAND is the command for sending something on the guildline */
  /* e.g.  M <text>     sends something on the line                    */
  /*       M !command   sends a command over the line                  */
  /*       M #<text>    sends an emote over the line                   */
#define LINECOMMAND "M"
#define LINETOCOMMAND "Mto"
#define LINEOFF     "Moff"
#define LINEON      "Mon"

#define LINEMEMBERS "monks"
  /* Show all players logged on in the line/club */

/* #define LINECOMMAND_WITHOUT_ARG_EQUALS_MEMBERCOMMAND 1
      This line can be added and also set the LINEMEMBERS string
      equal to LINECOMMAND, then LINECOMMAND without argument becomes
      a membercommand.     */

/* #define NO_FEELINGS 1        This line can be added if you don't want */
                            /*  to allow feelings over the line. */
/* #define NO_EMOTE 1           This line can be added if you don't want */
                            /*  to allow emote over the line. */

/* #define QUERY_ECHO_LINETO 1  This will enable the guildmark to have
                                av function called query_echo_lineto()
                                that returns 1 if LINETO commads shall have
                                echo and 0 otherwise. If this in NOT
                                defined LINETO will be echoed. */

#define PASS_LINETO_WHEN_OFFLINE 1 
                                /* This will make LINETO commands work even
                                if target has gone offline. */

/* #define SORT_OBJECT <object>   This will replace the print_list()
                                  function in the line with the function
                                  line_print_list(*objects) in <object>.
                                This is often usefull for making changes on
                                how memberlist is presented and sorted.
                                read /obj/line/line.c function print_list()
                                for futher details. */

/* Some defines that can be used to change some texts that are echoed to
   the player when using the LINEON and LINEOFF commands. 
   ARE_ONLINE  GOES_ONLINE  ARE_OFFLINE  GOES_OFFLINE
   e.g. #define ARE_ONLINE "You are already online!"           */

/* #define OWN_SENDCOST_FUNCTION  This will make SENDCOST obsolete, instead
                                  own_sendcost_function() will be called.
                                  This function should return 1 for success
                                  and 0 for failiure.
                                  No messages will be printed if failure.
                                  It is usally a BAD idea to define SENDCOST
                                  when this is used, since it then will also
                                  check for SP.
   #define OWN_SENDTOCOST_FUNCTION   Same as above, buy for SENDTO, function
                                     own_sendtocost_function() will be called.
   These functions are intended if something else than SP should be used
   as cost for using the line.

   #define OWN_LINETO_OK_MESSAGE  Redefine the "Ok" that is sent to the player
                                  as confirmation on lineto-command.
*/
           
#define CHECK_AWAYSTRING 1  /* Check if target has awaystring set when
                               using lineto */

#define SET_REPLY_TO 1    /* This means that lineto will change targets
                             reply to sender. 0 means do not change
                             reply on target. This only works when
                             CHECK_AWAYSTRING is 1.*/

/*
#define EXTRA_SEND_PLAYER_INFO (["general":"<GUILDINFO> ",
                                 "to":"<GUILDTO> ",
				 "guildmark":this_object()])
       Sets a few variables in each send_player to change
       introtext depending on type of message.
  To send general text the text should begin with the char #
*/

