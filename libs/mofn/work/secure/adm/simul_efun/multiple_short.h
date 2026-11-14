/**
 * Cotains some simul_efuns.
 * @author Pinkfish
 */
/** 
 * Returns a nice string which looks like "Frog, fish and chicken".  This
 * takes in an array of objects and or strings and returns a message
 * like that shown above.  It also does things like adding the number of
 * each type at the start of the function.
 * <p>
 This function has two main uses: to produce the control codes for a
     set of objects and to produce a nice list from a set of strings.
     The "type" argument is optional and may be "a", "the", "one" or
     "poss", defaulting to "a": it determines which of a_short,     
     the_short, one_short or poss_short will be used to make the control
     code sequence for the objects in "args".  If all of the elements of
     "args" are objects, it simply returns the block control code for
     the relevant shorts of the objects.  Otherwise, it looks through
     the elements one at a time, replacing objects by the result of  
     calling the relevant short function on them; finally it
     concatenates the elements with commas between each pair, except
     between the last pair which have " and " between them.  Since the
     output will contain processing codes if there are any objects in
     "args", it should be passed through convert_message before being
     stored.
 *
 * @param args the array to do the processing on
 * @param type the type of short to use "a", "the", "one", "poss"
 * @param no_dollars this forces the output to be a real string
 * @return the processed string
 */
varargs string query_multiple_short( mixed *args, string type,
                                     int no_dollars, int flag ) {
   int i;
   //int found_object;
   string func;
   string ret;

   args = copy(args);
   if ( !type ) {
      type = "a";
   }
   for ( i = 0; i < sizeof( args ); i++ ) {
      if ( !objectp( args[ i ] ) ) {
         break;
      }
   }
   /*
    * Changed to use a function instead of the fast direct method to handle
    * the problem where things with variable shorts are used in multiple
    * lists.
    */
   func = type + "_short";
   if ( i == sizeof( args ) && !no_dollars) {
      for ( i = 0; i < sizeof( args ); i++ ) {
         args[ i ] = call_other(args[ i ], func, flag);
         //args[ i ] = "$"+ type +"_short:"+ file_name( args[ i ] ) +"$";
      }
      return "$M$"+ implode( args, "" ) +"$M$";
   }
   for ( i = 0; i < sizeof( args ); i++ ) {
      if ( objectp( args[ i ] ) ) {
         args[ i ] = call_other(args[ i ], func, flag);
         //args[ i ] = "$"+ type +"_short:"+ file_name( args[ i ] ) +"$";
      } else if ( pointerp( args[ i ] ) ) {
         /* This may still be used somewhere. */
         args[ i ] = "$"+ type +"_short:"+ file_name( args[ i ][ 1 ] ) +"$";
      }/* else if (stringp(args[ i ]) && !no_dollars) {
         args[ i ] = "$mirror_short:" + args[i] + "$";
      } */
   }
   //if (!no_dollars) {
      //return "$M$"+ implode( args, "" ) +"$M$";
   //}
   i = sizeof( args );
   switch ( i ) {
      case 0 :
         return "";
      case 1 :
         ret = args[ 0 ];
         break;
      default :
         ret = implode( args[ 0 .. i - 2 ], ", " ) +" and "+ args[ i - 1 ];
         break;
   }
   if (no_dollars) {
      if (this_player()) {
         return this_player()->convert_message(ret);
      } else {
         return PLAYER_OBJ -> convert_message(ret);
      }
   }
   return ret;
}
