
/** @ignore yes */
int snoop( object sno, object snop ) {
    if( master()->valid_snoop( sno, snop, PO ) ) {
       if( !snop )
           efun::snoop( sno );
       else
           efun::snoop( sno, snop );
       return 1;
    }

    return 0;

} /* snoop() */
