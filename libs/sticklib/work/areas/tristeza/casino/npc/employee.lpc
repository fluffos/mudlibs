/*********************************************************************
  casino employee
  Coded by: Germ
  Last modified: Feb 5, 1996

  All the casino dealers, bouncers, etc are cloned from this object.

  The employees are very tough monsters.  They have to be so because
  the whole point of the casino is to gamble, and nobody can gamble
  if thieves steal their money.  So, these dudes have to be a 
  sufficient deterrent for thieves.  Yes, it should be (and is) possible
  to steal in the casino.  I just want it to be really risky.

  If employee is attacked, he will summon the bouncers to help him.
  Bouncers will come and help no matter where they are in the casino.
  They will also relentlessly pursue attacker until he dies or they
  die.  After attacker is dead, the bouncers return to the casino
  security room.  

  Currently, the bouncers will even pursue a player to link-death.
  This is a cool feature IMO, I don't like players who always hit
  the LD button at the first hint of trouble.


**********************************************************************/

#include <equipped_group_npc.h>
#include <conditions.h>
#include "../casino.h"

#define SUMMON_DELAY 2
#define RECORD_ATTACKS 1
#define LOGFILE "LOGS/BOUNCERS.LOG"

object enemy_to_follow;   /** we want to remember who we are killing **/

create_monster()
{
    set_name("dealer");
    set_id( "dealer" );
    set_race("human");
    set_gender(G_MALE);

    set_short("The dealer");

    set_long("The dealer is an immaculately groomed man wearing\
 a fine black tuxedo.  His sharp eyes constantly scan the area\
 for evidence of impropriety, and you doubt that anything you do\
 would escape his notice.");

    /** These are pretty big dudes...maybe  **/
    /** later they will need tuning down    **/ 
    set_level(60);
    set_ep(1000000); 
    set_hp( 3000 );
    set_money( random(500) );

    set_wc(60, 1);
    set_ac(80, 1);
    set_alignment( 0 );

    set_spell_chance( 40 );
    set_spell_dam( 80 );

    set_spell_mess1(":%<me.name>% boots %<him.name>% to the head!");
    set_spell_mess2(":%<me.name>% boots you to the head!");

    load_a_chat( 30, ({ ":%<me.name>% yells: Boot to the head!!!" }) ); 



    set_group("casino_employees");
    set_group_message("ask_help_msg", 
      ":%<me.name>% shouts: I have a criminal here!");
    set_group_message("can_help_msg",
      "You hear running footsteps nearby.");
    set_group_message("cant_help_msg",0);

}


/********************************************************************************
  Every heartbeat we will check if we are killing some criminal.
  If so, we will continue killing him.  If he has fled to another place,
  we will go to where he is at.  If he goes mort or dies, we will
  return to the casino security room.
********************************************************************************/

void heart_beat()
{

    /** lets be nasty and make employees **/
    /** stun-resistant.  :-)             **/

    if ( this_object()->query_condition( C_STUNNED ) )
	this_object()->set_condition( C_STUNNED, random(2) );


    if ( enemy_to_follow )
    {

	/** we know how to kill pets really **/
	/** efficiently :)                  **/       

	if (( enemy_to_follow->query_ctrl() 
	    || (enemy_to_follow->query_name() == "demon") )
	  &&( this_object()->query_name() == "Bouncer" )
	  &&( !random(3)))

	{
	    environment()->tell_here("Bouncer crushes "
	      +enemy_to_follow->query_name()+"'s skull with a powerful kick!");

	    enemy_to_follow->death(1, this_object() );

	    enemy_to_follow = 0;
	}
	/** if we are a bouncer and our enemy **/
	/** is still fighting us...           **/
	else
	if ( this_object()->query_name() == "Bouncer" )
	    if ( !enemy_to_follow->query_dead() 
	      &&( enemy_to_follow->query_hp() > -50 ))

	    {
		/** if enemy has ran away from here.. **/
		/** go to where he is at.             **/

		if ( environment() != environment( enemy_to_follow )) 
		{
		    this_object()->move_player("moving rapidly",
		      environment( enemy_to_follow ));

		    this_object()->attack_object( enemy_to_follow );
		}
	    }
	    else                       /** if enemy is dead, return to office **/
	    {
		environment(this_object())->tell_here(
		  "Bouncer says: And let that be a lesson to you!!!" );

		this_object()->move_player("with a self-satisfied smirk",
		  find_object( AREA_PATH+"rooms/security"));

		enemy_to_follow = 0;

	    }

    }
    else
    {

	enemy_to_follow = query_attack(); 

	/** if we have no enemy and     **/
	/** we arent in the office then **/
	/** return to the office        **/

	if (( !enemy_to_follow )&&( this_object()->query_name() == "Bouncer")
	  &&( environment( this_object() )->query_short()
	    != "Security and surveilance room."))

	    this_object()->move_player("with a self-satisfied smirk",
	      find_object( AREA_PATH+"rooms/security"));

    }


    ::heart_beat();
}



/********************************************************************************
  We mask group_attacked to allow bouncers to come from anywhere in the casino.
********************************************************************************/

status group_attacked( object victim, object attacker, object *members )
{
    mixed bouncer;
    object enemy;
    int i,j, stat;


    stat = ::group_attacked( victim, attacker, members );

    /** If we are attacked by a pet **/
    /** lets blame the master!      **/ 


    enemy_to_follow = attacker;

    /** Only call for help if we    **/
    /** are the victim.             **/ 
    if ( victim == this_object() )
    {
	/** See if any other bouncers   **/
	j=0;                                 /** are alive somewhere else    **/

	for ( i=0; i<sizeof(members); i++ )
	    if ((bouncer = members[i]) && ( bouncer != this_object() )
	      &&( !present( bouncer, environment(attacker) )) 
	      &&( bouncer->query_name() == "Bouncer" ))
	    {
		/** yes! summon them to help me!**/ 

		call_out("delayed_summon", SUMMON_DELAY+j*2, bouncer, attacker );  
		j++;
	    }

#if RECORD_ATTACKS != 0

	write_file( AREA_PATH+LOGFILE, attacker->query_real_name()+
	  " attacked "+victim->query_real_name()+".\n" );

	if ( enemy != attacker )
	    write(" with a "+enemy->query_name()+".\n" );
	else
	    write(".\n");

#endif

    }

    return stat; 
}



/******************************************************************************
  Can be called by call_other to tell a bouncer who his enemy is.
******************************************************************************/


void set_enemy( object enemy )
{
    enemy_to_follow = enemy;

} 




/******************************************************************************/
/******************************************************************************/

void delayed_summon( object bouncer, object attacker )
{
    bouncer->move_player("moving rapidly", environment( attacker ));
    bouncer->attack_object( attacker );

    call_other( bouncer, "set_enemy", attacker );      
    environment( attacker )->tell_here("Bouncer shouts: BOOT TO THE HEAD!!!");
}



/******************************************************************************/
/******************************************************************************/

