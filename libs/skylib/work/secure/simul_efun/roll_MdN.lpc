
#if !efun_defined(roll_MdN)
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

    if( dice > 0 && sides > 0 )
        while( dice-- )
            roll += 1 + random( sides );

    return roll;

} /* roll_MdN() */
#endif
