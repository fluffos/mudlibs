
#if !efun_defined(shuffle)
/**
 * This method randomizes an array.  It places all the elements of an
 * array back in random order.
 * @param args the array to shuffle
 * @return the randomized array
 * @see roll_MdN()
 * @see efun::random()
 */
mixed shuffle( mixed arr ) {
    int i, j, sz;
    mixed tmp;

    if( !pointerp( arr ) )
        return ({ });

    if( ( sz = sizeof( arr ) ) < 2 )
        return arr;

    for( i = 0; i < sz; i++ ) {
       if ( i == ( j = random( i + 1 ) ) )
           continue;
       tmp = arr[ i ];
       arr[ i ] = arr[ j ];
       arr[ j ] = tmp;
    }

    return arr;

} /* shuffle() */
#endif
