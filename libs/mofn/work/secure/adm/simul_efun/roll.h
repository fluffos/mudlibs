/**
 * Cotains some simul_efuns.
 * @author Pinkfish
 */
/**
 * This method rolls a bunch of dice to get a nice weighted medium.
 * @param dice the number of dice to roll
 * @param sides the number of sides each dice has
 * @return the total of the rolls
 * @see efun::random()
 * @see shuffle()
 * @example
 * roll_MdN(3, 6);
 * roll_MdN(1, 20);
 */
int roll_MdN( int dice, int sides ) {
   int roll;

   if ( ( dice > 0 ) && ( sides > 0 ) ) {
      while ( dice ) {                   
         roll += 1 + random( sides );
         dice--;
      }         
   }   
   return roll;
}

/**
 * This method randomizes an array.  It places all the elements of an
 * array back in random order.
 * @param args the array to shuffle
 * @return the randomized array
 * @see roll_MdN()
 * @see efun::random()
 */
mixed *shuffle( mixed *args ) {
   int i, j;
   mixed temp;
   if ( !pointerp( args ) )
      return ({ });        
   if ( sizeof( args ) < 2 )
      return args;          
   for ( i = 0; i < sizeof( args ); i++ ) {
      j = random( i + 1 );                 
      if ( i == j )       
         continue;
      temp = args[ i ];
      args[ i ] = args[ j ];
      args[ j ] = temp;     
   }
   return args;
}
