/**
 * This includes the query_ac() function used by both the
 * standard armour inherit, and the pocketed one.
 * @author Sandoz
 */

/** @ignore yes */
varargs int query_ac( string type, int amount, string zone ) {
    int a_class;
#ifdef INFORM
    string message;
#endif

    a_class = armour_logic::query_ac( type, amount, zone );

#ifdef INFORM
    message = query_short()+": striking "+zone+", basic value "+a_class;
#endif

    if( a_class > AC_LIMIT )
        a_class = AC_LIMIT;

    a_class += ( a_class * query_enchant() ) / query_max_enchant();
    a_class += query_enchant();

#ifdef INFORM
    message += "; after enchant "+ a_class;
    if( objectp( worn_by ) )
        event( ENV( worn_by ), "inform", message, "combat");
#endif

    do_damage( type, amount );
    a_class = ( a_class * cond ) / max_cond;

    // Damage may get through depending on how good the armour is.
    switch( random( a_class ) ) {
    case 0:
      return 0;
    case 1:
      return a_class / 2;
    case 2..3:
      return a_class * 2 / 3;
    default:
      // They'll always take a small amount of damage.
      if( a_class > amount )
          return amount - ( amount / ( 5 + random( 5 ) ) );
      return a_class - ( a_class / ( 5 + random( 5 ) ) );
    }

} /* query_ac() */
