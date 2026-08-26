
#if !efun_defined(reference_allowed)

private nosave int _in_reference_allowed;
private nosave int _in_reference_allowed_callout;

/**
 * This method is used to test to see if a reference is allowed to this
 * object.  It tests things like the allow array and that sort of stuff.
 * @param thing the object to test
 * @param referee the thing trying to reference us
 * @return 1 if the reference is allowed
 */
int reference_allowed( object thing, mixed referee ) {
    string *allowed;
    int i;

    if( !thing )
        return 0;

    i = (int)thing->query_invis();

    if( !i || _in_reference_allowed )
        return 1;

    if( !referee )
        return 0;

    if( objectp(referee) ) {
        if( thing == referee )
            return 1;
        referee = referee->query_name();
    }

    if( !referee || !stringp(referee) )
        return 0;

    _in_reference_allowed = 1;

    if( !_in_reference_allowed_callout )
        _in_reference_allowed_callout = call_out(
        (: _in_reference_allowed = _in_reference_allowed_callout = 0 :), 0 );

    if( pointerp( allowed = (string *)thing->query_allowed() ) ) {
        if( member_array( referee, allowed ) != -1 ||
            ( member_array("playtesters", allowed ) != -1 &&
            TO->playtesterp( referee, 1 ) ) ||
            ( member_array("friends", allowed ) != -1 &&
            thing->query_friend(referee) ) ) {
            _in_reference_allowed = 0;
            return 1;
        }
    }

    _in_reference_allowed = 0;

    switch( i ) {
      case 3 :
        return TO->adminp( referee );
      break;
      case 2 :
        return TO->lordp( referee );
      break;
      case 1 :
        return TO->creatorp( referee );
      break;
      default :
        return 1;
    }

} /* reference_allowed() */
#endif
