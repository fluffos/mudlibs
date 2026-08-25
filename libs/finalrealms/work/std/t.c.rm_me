void start_clean_up()
{
    int old_call_out;
#ifdef FAST_CLEAN_UP
    // when folk in room, update timers {Laggard}
    old_call_out = remove_call_out( "clean_up_room" );
#endif
    room_init_time = time();
#ifdef FAST_CLEAN_UP
    if ( old_call_out < FAST_CLEAN_UP
      &&  (room_init_time - room_create_time) < FAST_CLEAN_UP )
    {
        // was merely passing through {Laggard}
        call_out( "clean_up_room", FAST_CLEAN_UP, 0 );
    }
    else if ( !room_stabilize )
    {
        call_out( "clean_up_room", old_call_out, 0 );
    }
#endif

} /* init() */
