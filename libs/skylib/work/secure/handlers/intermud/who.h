
/**
 * This method is called when a reply for a remote
 * online user list is received.
 * It will print the who list to the person originating the request.
 */
private void who_reply( mixed *packet ) {
    string info, base, ret, *players, *creators, *cnames, *pnames;
    mapping play_idle, cre_idle;
    string top, ptop;
    int width, bing;
    object user;

    if( sizeof(packet) != ( S_P + SIZEOF_WHO_REPLY ) ) {
        packet_invalid(packet);
        return;
    }

    if( !( user = find_player( packet[P_RECIPIENT] ) ) )
        return;

    play_idle = ([ ]);
    cre_idle = ([ ]);

    players = ({ });
    creators = ({ });
    cnames = ({ });
    pnames = ({ });

    for( int i = 0; i < sizeof( packet[S_P + WHO_REPLY_DATA] ); i++ ) {
        if( !( info = packet[S_P + WHO_REPLY_DATA][i][WHO_DATA_INFO] ) )
            continue;

        switch( lower_case(info) ) {
          default:
            switch( lower_case(info) ){
              case "admin" :
              case "senior creator" :
              case "lord" :
              case "high lord" :
                creators += ({ packet[S_P + WHO_REPLY_DATA][i][WHO_DATA_SHORT]+
                               "("+lower_case(info)+")"});
                cre_idle +=([ ( packet[S_P + WHO_REPLY_DATA][i][WHO_DATA_SHORT] ) :
                              ( packet[S_P + WHO_REPLY_DATA][i][WHO_DATA_IDLE] ) ]);
                bing = 1;
              break;
            }

            if( bing == 1 ) {
                bing = 0;
                break;
            }

            players += ({ packet[S_P + WHO_REPLY_DATA][i][WHO_DATA_SHORT] });
            play_idle += ([ ( packet[S_P + WHO_REPLY_DATA][i][WHO_DATA_SHORT] ) :
                            ( packet[S_P + WHO_REPLY_DATA][i][WHO_DATA_IDLE] ) ]);
          break;
          case "immortal" :
          case "creator" :
          case "(lord)" :
            creators += ({ packet[S_P + WHO_REPLY_DATA][i][WHO_DATA_SHORT] });
            cre_idle +=([( packet[S_P + WHO_REPLY_DATA][i][WHO_DATA_SHORT] ) :
                         ( packet[S_P + WHO_REPLY_DATA][i][WHO_DATA_IDLE] ) ]);

        }
    }

    players = sort_array( map( players, (: CAP($1) :) ), 1 );
    creators = sort_array( map( creators, (: CAP($1) :) ), 1 );


    top = "";
    ptop = "";

    for( int z = 0; z < sizeof(creators); z++ ) {
        top += creators[z];
        if( cre_idle[ lower_case(creators[z]) ] / 60 > 0 )
            top += "(idle:"+cre_idle[lower_case(creators[z])]/60+")\n";
        else
            top+="\n";
    }

    for( int z = 0; z < sizeof(players); z++ ) {
        ptop += players[z];
        if( play_idle[lower_case(players[z])] / 60 > 0 )
            ptop += "(idle:"+play_idle[lower_case(players[z])]/60+")\n";
        else
            ptop+="\n";
    }

    pnames= explode( ptop,"\n");
    cnames= explode( top,"\n");
    width = user->query_cols();

    ret= sprintf("\n%|*'-'s\n%|*s\n%*'-'|s\n%s%*'-'|s\n%s", width,
        sprintf("=======[ %s ]=======", CAP(packet[P_SOURCE])),
        width, ctime(time()), width, "=====[ creators ]====",
        sprintf("%#-*s\n", width, implode( cnames, " \n") ),
        width, "=====[ players ]=====", sprintf("%#-*s", width,
        implode( pnames, " \n") ) );

    if( sizeof(packet[S_P + WHO_REPLY_DATA]) > 1 )
        base = "[ There are "+
            query_num( sizeof(packet[S_P+WHO_REPLY_DATA]) )+" people on ]";
    else if( sizeof(packet[S_P + WHO_REPLY_DATA]) == 1 )
        base = "[ There is one person on ]";
    else
        base = "[ There is no-one on ]";

    ret += sprintf("\n%*'-'|s\n", width, base );

    tell_object( user, ret );

} /* who_reply() */

/**
 * This method returns a list of online players to the mud
 * originating the who request.
 */
private void who_request( mixed *packet ) {
    string *creators, *players;
    mixed *reply, *users;

    if( sizeof(packet) != ( S_P + SIZEOF_WHO_REQ ) ) {
        packet_invalid(packet);
        return;
    }

    users = ({ });
    creators = ({ });
    players = ({ });

    foreach( object ob in users() ) {
        if( creatorp(ob) ) {
            if( !ob->query_invis() )
                creators += ({ ob->query_name() });
        } else {
            players += ({ ob->query_name() });
        }
    }

    users += map( creators, (: ({ $1, ( interactive(find_player($1)) ?
             query_idle( find_player($1) ) : 0 ), "creator"}) :) );

    users += map( players, (: ({ $1, ( interactive(find_player($1)) ?
             query_idle( find_player($1) ) : 0 ), "player"}) :) );

    reply = packet_allocate(WHO_REPLY_PACKET);
    reply[P_DESTINATION] = packet[P_SOURCE];
    reply[P_RECIPIENT] = packet[P_SENDER];
    reply[S_P + WHO_REPLY_DATA] = users;

    event( users(),"inform", sprintf("IMUD who from %s at %s",
        packet[P_SENDER], packet[P_SOURCE]), "admin");

    if( lower_case(packet[P_SOURCE]) == "aoc")
        return 0;

    add_buffer( 0, reply );
    send_buffer( 0 );

} /* who_request() */

int who( string mud ) {
    mixed *packet;

    packet = packet_allocate(WHO_REQ_PACKET);

    if( shutdown || !( mud = mud_exists(mud) ) )
        return 0;

    packet[P_SENDER]      = TP -> query_name();
    packet[P_DESTINATION] = mud;

    add_buffer( 0, packet );
    send_buffer( 0 );
    return 1;

} /* who() */
