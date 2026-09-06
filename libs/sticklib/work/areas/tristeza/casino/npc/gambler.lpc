/*********************************************************************
  casino gambler 
  Coded by: Germ
  Last modified: Feb 6, 1996

  This crazy dude is created by the Wheel of Misfortune.  Indeed,
  unless the player is powerful and prepared, he will probably
  suffer the misfortune of a MK.  Hehehe!

**********************************************************************/

#include <npc.h>


create_monster()
{
    set_name("gambler");
    set_id( "gambler" );
    set_race("human");
    set_gender(G_MALE);

    set_short("An insane gambler");

    set_long(
      "This patron of the casino is dirty and ragged, with wildly\
 gleaming eyes and a snarling rictus of a mouth.  He has\
 obviously spent FAR too much time in the casino, and appears\
 to have lost not only his money, but his mind as well." );


    set(NPC_AGGRESSIVE);
    set_level(30+random(20));
    set_hp( 1000+random(2000) );

    set_alignment( 0 );

    set_spell_chance( 30 );
    set_spell_dam( 30 );

    set_spell_mess1(":%<me.name>% scratches at %<him.name>%'s eyes!");
    set_spell_mess2(":%<me.name>% scratches at your eyes!");

    load_a_chat( 30, ({ "%<me.name>% yells: It's MY wheel! MINE!!!" }) ); 


    /** lets block the player from fleeing **/
    /** This may be a bit harsh, but hey,  **/
    /** this is definitely misfortune :)   **/

    add_block("up","all",0,0,
      ":%<me.name>% intercepts you as you try to flee.",
      ":%<me.name>% intercepts %<him.name>% as %<him.pronoun>% tries to flee.", 0, 0 );



}


/********************************************************************************/
/********************************************************************************/

