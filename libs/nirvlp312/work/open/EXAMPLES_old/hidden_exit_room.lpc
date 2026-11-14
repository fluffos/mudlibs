inherit "room/room";

reset ( arg )
{
    if ( ! arg )
    {
        set_light ( 1 );
        short_desc = "A testing room";
        long_desc =
"This is a simple test room.\n";

        dest_dir = ({
            "room/LPCC_enter", "west",
More: (line 17) 
                  });
    }
}

init()
{
    ::init();  /* Call the init() in the original master room. */

    add_action ( "Move_north", "north" );
}

Move_north()
{
    /* Two different methods. Second one is good for special messages. */
    this_player()->move_player ( "north", "room/adv_inner" );
    return 1;
More: (line 33) 
#if 0  /* The other method. */
    say ( this_player()->query_name() + " moves off into the distance.\n" );
    move_object ( this_player(), "room/adv_inner" );
    say ( this_player()->query_name() + " arrives.\n" );
    command ( "look", this_player() );
    return 1;
#endif
}
