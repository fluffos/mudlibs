
#if !efun_defined(ordinal)
/**
 * Adds a "rd", "th", "st" onto a number.  Takes a number as an input and
 * adds the ordinal type on it.  So you get 3rd and 2nd etc as return
 * strings.
 * @param number the number to add the ordinal too
 * @return a string being the number plus the ordinal
 */
string ordinal( int number ) {
    string nve;

    if( number < 0 ) {
        nve = "-";
        number *= -1;
    } else {
        nve = "";
    }

   if( ( number % 100 > 10 ) && ( number % 100 < 14 ) )
       return nve + number +"th";

   if( number % 10 == 1 )
       return nve + number +"st";

   if( number % 10 == 2 )
       return nve + number +"nd";

   if( number % 10 == 3 )
       return nve + number +"rd";

   return nve + number +"th";

} /* ordinal() */
#endif

/**
 * This method returns the mud time for the input time number.  This
 * function takes the same input as the efun ctime().  You pass in
 * the time number and it returns a string detailing the time in the mud.
 * @return a string containing the mud time
 * @see TIME_H->query_time()
 */
string mudtime( int number, int flag ) {
   return TIME_H->query_time( number, flag );
} /* mudtime() */
