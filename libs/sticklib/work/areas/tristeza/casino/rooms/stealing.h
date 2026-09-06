/*******************************************************************
  stealing.h   :  Deal with stealing in the casino  
  Coded by     :  Germ
  Last modified:  Feb 7, 1996

  Basically, we mask the steal command, and when someone tries to
  steal, we transport the bouncer to the thief and attack him.
  We must manually call group_attacked so that the rest of the
  bouncers will be summoned to help.

  This should be included by every room that contains a gambling
  machine.

  Things to do:
    - Allow the casino to be a PK area, and make the bouncers
      protect innocent players?

*******************************************************************/
#include <daemons.h>
#define HERE environment(this_player())
#define STEAL_NOTICED 60              /** percent of steals noticed **/
#define LOGFILE "LOGS/BOUNCERS.LOG"
#define RECORD_STEALS 1

status steal_cmd( string arg)
{
  string who;
  object victim, thief, bouncer;
  int rnd;

   if (!arg || sscanf(arg, "%s", who) != 1 )
      return 0;

                                      /** lets only attack on a valid **/
                                      /** steal command.              **/

   if ( !(victim = present( who, HERE )) ) 
        return 0;

   rnd = random(101);

#if RECORD_STEALS != 0 

   write_file( AREA_PATH+LOGFILE, this_player()->query_real_name()+
                    " stole from "+victim->query_real_name()+"." );

   if ( rnd > STEAL_NOTICED )
      write_file( AREA_PATH+LOGFILE, "\n" );
   else
      write_file( AREA_PATH+LOGFILE, " Bouncers came.\n");

#endif


                                    /** We don't see all the attempts **/

   if ( rnd > STEAL_NOTICED )
        return 0;



   HERE->tell_here("You hear an alarm go off in the distance!");

                                    /** Find bouncers and summon them **/
                                    /** to the criminal after delay.  **/

   if (( bouncer = find_living("bouncer"))
      &&( !present( bouncer, HERE )))
       call_out("delayed_summon", 1, bouncer, this_player() );

   return 0; 
}



/********************************************************************************/
/********************************************************************************/

void delayed_summon( object bouncer, object attacker )
{
  object groupd;

                                    /** If bouncer attacks player, other  **/
                                    /** bouncers won't be called to help. **/         
                                    /** So, we must call group_attacked   **/
                                    /** to call the other bouncers!       **/

  if ( groupd = find_object( GROUP_D ))
    {
      bouncer->move_player("moving rapidly", environment( attacker ));
      bouncer->attack_object( attacker );

      call_other( bouncer, "set_enemy", attacker );
      environment( attacker )->tell_here("Bouncer shouts: HALT, THIEF!!!");
      groupd->group_attacked( bouncer, this_player(), "casino_employees" );
    }

}


