#ifndef __specials__
#define __specials__

int camou_block;
int camou_left;
object shad;

/* ----- invis ------------------------------------------------------------ */
_camouflage( arg )
{
   if ( arg )
      return;
      
   if ( TP->query_ghost() ) {
      write( "You cannot camouflage yourself as a ghost.\n" );
      return( 1 ); 
   }
   if ( TP->hide_shad() ) {
      write( "You are already camouflaged.\n" );
      return( 1 );
   }

   if ( camou_block ) {
      write( "You have to wait a while, until you can try to camouflage yourself again.\n" );
      return( 1 );
   }
   
  if (random(105) < TP->query_dex()*2)
     {
      shad = clone_object("/players/dice/guild/hide_shad");
      shad->start_shadow(TP,0,"hide_shad");
      camou_block = 1;
      camou_left = TP->query_int()*2+ 20;
      write( "You think, you are one with your environment now.\n" );
      /* advance_skill( TP, CAMOU_SKILL, 1, 100 ); */
   }
   else {
      write( "You think, you are one with your environment now.\n" );
      call_out( "rm_camoublock", (100 - TP->query_dex()*2) * 2 + 60 + random(60) );
      camou_block = 1;
      /* advance_skill( TP, CAMOU_SKILL, 1, 20 ); */
   }
   
   return( 1 );
}

_reveal( )
{
   if ( !(TP->query_invis()) ) {
      write( "You ain't camouflaged, dude.\n" );
      return( 1 );
   }

   write( "You remove your camouflage.\n" );
   rm_invis();
   return( 1 );
}

rm_invis( )
{
   if ( TP->hide_shad() )
        destruct(TP->hide_object());
   call_out( "rm_camoublock", (100 - TP->query_wis()*2) * 2 + 60 + random(60) );
   camou_block = 1;
   camou_left = 0;
}

rm_camoublock( )
{
   camou_block = 0;
}

query_iscamou()
{
   if ( camou_left )
      return( camou_left );

   return( environment(this_object())->hide_shad() || camou_left );
}


dec_camou()
{
   camou_left -= 2;
   if ( camou_left <= 0 ) {
      rm_invis();
      camou_left = 0;
   }
}

check_camou()
{
   if ( camou_left < 1 )
      return( "You ain't camouflaged at all!" );
   else if ( camou_left < 10 )
      return( "You're camouflage is very, very poor." );
   else if ( camou_left < 20 )
      return( "You're camouflage is very poor." );
   else if ( camou_left < 30 )
      return( "You're camouflage is bad." );
   else if ( camou_left < 40 )
      return( "You're camouflage is not bad." );
   else if ( camou_left < 50 )
      return( "You're camouflage is good." );
   else if ( camou_left < 60 )
      return( "You're camouflage is excellent." );
   else if ( camou_left < 70 )
      return( "You're camouflage is superior." );
   else
      return( "You're one with your environment!" );
}


/* --- assassinate ------------------------------------------------------- */
_assassinate( arg )
{
   int    failed, damage, chance, wc, oldMonstHP, newMonstHP, holdTime;
   object *who;
   string oppoName;
  
   failed = 0;
   
   if ( !arg ) {
      write( "Assassinate who?\n" );
      return( 1 );
   }
   
   who = present( arg, environment( TP ) );
   if ( !who || !living(who) || who->query_ghost() ) {
      write( "You only can assassinate somebody, who you can see and who is alive.\n" );
      return( 1 );
   }
   
   if ( !(TP->is_invis_for(who)) ) {
      write("Bad timing!!! You are not camouflaged, this might end bad !!!\n" );
      failed = 1;
   }
   else if ( who->query_attack(this_player()) == this_player() ) {
      write( "You try to assassinate " + capitalize(who->query_name()) +
             ", but " + who->query_pronoun() + " reminds your\n"+
             "last assassinate, so you fail !!!\n" );
      failed = 1;
   }
   else if ((TP->query_attack() && present(TP->query_attack(),environment(TP))))
   {
      write( "Assassinate while fighting!? Strange attempt.\n" );
      failed = 1;
   }
   else if ( query_to_heavy() ) {
      write( "You feel to heavy to assassinate somebody.\n" );
      failed = 1;
   }
   else if ( check_armour() ) {
      write( "Your unusual armour hinders you to assassinate somebody.\n" );
      failed = 1;
   }
   else if ( !(TP->query_wielded()) ) {
      write( "Without a weapon ? Strange concept ...\n" );
      failed = 1;
   }

   if ( failed ) {
      write( "Because of your fault you run unprotected into the enemies "+
             "attack !!!\n" );
      who->attack_object( TP );
      return( 1 );
   }

   if ( query_fullattack() ) {
      write( "You're in a fullattack, you are much too busy to do this !!!\n" );
      return( 1 );
   }
      
   if ( random(who->query_level()*2) < TP->query_dex()*2 ) {
      if ( who->query_level() < ALL_STAT_AV )
       /*  advance_skill( TP, ASSASS_SKILL, 1, 100 );
      else

         advance_skill( TP, ASSASS_SKILL, 1, 50 );
      */
      oldMonstHP = who->query_hp();

      // --- handle dam
      wc = TP->query_wielded()->weapon_class();
      damage = wc*random((wc+1)/2)+TP->query_dex()*2+TP->query_str(); 
      oppoName = who->query_name();
      damage = who->hit_player(damage,2);
      TP->add_exp(damage);
      if ( TP->query_immortal() )
         write( "----- effective damage of assassinate: " + damage +"\n");

      if ( !who ) {
         write( "You place your weapon in the back of your opponent,\n"+
                "resulting in a strange noise, a lot of gore and a CORPSE !\n");
         say( "You suddenly hear a strange noise, blood spilling around and\n"+
               oppoName+" lies in a flat position, unmoveing.\n");
         return( 1 );
      }
      write("You move behind your opponent and ASSASSINATE this creep!!!\n");
      tell_object( who, "You feel a piercing pain in your spine !!!\n" );
      say( TP->query_name()+" moves behind "+who->query_name()+" and "+
           "ASSASSINATES this creep !!!\n", who );

      // --- handle the stun
      newMonstHP = who->query_hp();
      holdTime = (oldMonstHP-newMonstHP)*10/oldMonstHP;
      if ( holdTime > 0 ) {
         holdTime = holdTime > 5 ? 5 : holdTime;
         holdTime++;
         who->hold( this_object(), holdTime );
         write( who->query_name()+" is STUNNED by the sheer power of your hit "+
                "!!!\n" );
         tell_object( who, "You are stunned by the sheer power of the hit!\n");
         say(who->query_name()+" is STUNNED by the sheer power of the hit !\n",
             who );
         who->stop_fight();
         who->stop_fight();
      }
      rm_invis();
      return( 1 );
   }

   /* advance_skill( TP, ASSASS_SKILL, 1, 20 ); */
   write( "You try to assassinate your enemy, but in the last second " +
           who->query_pronoun() + " recognizes you and can avoid the hit.\n"); 
   tell_object( who, capitalize( TP->query_real_name() ) +
         " tried to assassinate you.\nBut you recognize the attempt and " +
         "can avoid the hit.\n" );

   who->attack_object( TP );
   rm_invis();
   return( 1 );
}


#endif /*__specials__*/


