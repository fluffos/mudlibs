#ifndef __move_blocked__
#define __move_blocked__

move_blocked( item, dest, block )
{
   object illusion;
   
   if ( !block )
      return( transfer( item, dest ) );
   
   illusion = clone_object( "/players/patience/GenObj/illusion" );
   
   if ( illusion ) {
      if ( transfer( item, illusion ) ) {
         destruct( illusion );
         return( -2 );
      }
      illusion->set_blocker( block );
      illusion->set_weight( item->query_weight() );
      if ( transfer( illusion, dest ) )                            /* if not possible */
         move_object( illusion, dest );                            /* move anyway     */
      
      return( 0 );
   }
   
   return( -1 );
}

#endif /*__move_blocked__*/
