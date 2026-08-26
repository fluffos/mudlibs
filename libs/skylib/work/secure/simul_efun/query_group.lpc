
#if !efun_defined(query_group)
/**
 * This method returns whether or not the given object(s) are a group,
 * as in there are several objects, or the object has 'group object' set.
 * This is useful in determining when to use plural verbs etc.
 * @param obs the object or array of objects to test
 * @return 1 if the object(s) are a group.
 */
int query_group( mixed obs ) {

    if( !obs )
        return 0;

    if( objectp(obs) )
        return ( obs->query_property("group object") > 0 ||
                 obs->group_object() > 0 );

    if( pointerp(obs) )
        return ( sizeof(obs) > 1 || query_group(obs[0]) );

} /* query_group() */
#endif
