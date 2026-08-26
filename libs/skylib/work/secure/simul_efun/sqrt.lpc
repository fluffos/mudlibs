/**
 * Contains some simul_efuns.
 * @author Pinkfish
 */

/**
 * This method attempts to find a square root of an input number.  This
 * returns a square root in the same type as the input type.
 * @see efun::sqrt()
 * @return the square root
 * @param number
 */
mixed sqrt( mixed number ) {
    if( floatp(number) )
        return efun::sqrt(number);

    if( !intp(number) )
        error("Bad argument 1 to sqrt()\nExpected: int or float Got: "+
            typeof(number)+".\n");

    if( number < 0 )
        return -1;

    return to_int( efun::sqrt( to_float(number) ) );

} /* sqrt() */
