
/* argl ... please don't change pats files if you don't know how : whisky :*) */

#define HIT_CHANCE    ((TP->query_dex()+TP->query_int())/2) /* chnc to hit   */
#define CHNC_DIV      (5)                                   /* decrease fact */
#define HIT_POWER     ((TP->query_dex()+TP->query_str())/2) /* damage-factor */

critical_hit( arg )
{
   object ns;
   int    critHit, hitChnc, monstLvl, hitChncPer;
   int info;
   
   ns = present( "ninja_soul", wielded_by );
   if ( ns ) {
      hitChncPer = ns->query_accuracy() / CHNC_DIV + 1;
      monstLvl = (TP->query_attack())->query_level();
   } /* endif */
      
      if ( HIT_CHANCE > monstLvl )                            /* hit chance */
         hitChnc = hitChncPer*2 - ( monstLvl * hitChncPer ) / HIT_CHANCE;
      else
         hitChnc = (HIT_CHANCE * hitChncPer) / monstLvl;

     if ( hitChnc > random( 100 ) ) 
     {
         critHit = HIT_POWER * HIT_FACT +50;
         if ( critHit > (this_player()->query_attack())->query_ac() ) 
         {
            write( "CRITICAL HIT with the " + query_name() + " !!!\n" );
            tell_object( TP->query_attack(), TP->query_name() + 
            " makes a CRITICAL HIT " +
                         "with the " + query_name() + " !!!\n" );
            say( TP->query_name() + " makes a CRITICAL HIT with the " + query_name() +
                 " !!!\n", TP->query_attack() );
       } /* endif */
         critHit = (critHit / 1) + random(critHit / 1) + 40;
         if ( ns->query_accuracy() <= RAISE_BLOCK )
            ns->weapon_hit( 1 );
            if (this_player()->query_immortal())
                write("Extradam: "+critHit+"\n");
         return( critHit );
      }  /* endif */
      else if (TP->query_npc() && TP->query_ninja() ) {
        hitChnc = TP->query_accuracy();
        if ( hitChnc > random( 100 ) ) {
           critHit = TP->query_level() * MONST_HIT_FACT + 4;
           if ( critHit > (this_player()->query_attack())->query_ac() ) {
           write( "CRITICAL HIT with the " + query_name() + " !!!\n" );
           tell_object( TP->query_attack(), TP->query_name() + " makes a CRITICAL HIT " +
                         "with the " + query_name() + " !!!\n" );
            say( TP->query_name() + " makes a CRITICAL HIT with the " + query_name() +
                 " !!!\n", TP->query_attack() );
         }
         info = critHit/1 + random(critHit/1) + 40;
         if (this_player()->query_immortal())
             write("Extradam:"+info+"\n");
        return ( info );
      }
   }
}
