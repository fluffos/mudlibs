
// NOTE: Channel-T Packets are currently unsupported.

mapping all_channels() { return config->channel_list->list; }
mapping admin_channels() { return admin_channels; }
string *listen_channels() { return listen_channels; }

string *admitted_channels( string channel ) {
    if( classp(admin_channels[channel]) )
        return admin_channels[channel]->members;
    return 0;
} /* admitted_channels() */

string *available_channels() {
    return filter( keys( config->channel_list->list ),
        (: member_array( $1, listen_channels ) != -1 :) );
} /* available_channels() */

int available_channel( string channel ) {
    return member_array( channel, available_channels() ) != -1;
} /* available_channel() */

int channel_exists( string channel ) {
  return !undefinedp( config->channel_list->list[channel] );
} /* channel_exists() */

int query_channel_type( string channel ) {
    mixed *info;

    if( info = config->channel_list->list[channel] )
        return info[1];

} /* query_channel_type() */

string query_channel_owner( string channel ) {
    mixed *info;

    if( info = config->channel_list->list[channel] )
        return info[0];

} /* query_channel_owner() */

/**
 * This method sends a channel message to the router.
 * @param channel the channel to send the message to
 * @param name the name of the person sending the message
 * @param message the message to send
 * @return 1 upon success, 0 upon failure
 */
int channel( string channel, string name, string message ) {
    mixed *packet;

    if( file_name(PO) != CHANNEL_H )
        return 0;

    if( message[0] == '@') {
        packet                          = packet_allocate(CHANNEL_E_PACKET);
        packet[P_SENDER]                = lower_case(name);
        packet[S_P + CHANNEL_E_CNAME]   = channel;
        packet[S_P + CHANNEL_E_VISNAME] = CAP(name);
        packet[S_P + CHANNEL_E_MESSAGE] = "$N "+message[1..];
    } else {
        packet                          = packet_allocate(CHANNEL_M_PACKET);
        packet[P_SENDER]                = lower_case(name);
        packet[S_P + CHANNEL_M_CNAME]   = channel;
        packet[S_P + CHANNEL_M_VISNAME] = CAP(name);
        packet[S_P + CHANNEL_M_MESSAGE] = message;
    }

    add_buffer( 0, packet );
    send_buffer( 0 );

    return 1;

} /* channel() */

// Incoming remote emotes.
private void channel_e( mixed *packet ) {
    string channel, str, who;

    if( sizeof(packet) != ( S_P + SIZEOF_CHANNEL_E ) ) {
        packet_invalid(packet);
        return;
    }

    if( !available_channel( channel = packet[ S_P + CHANNEL_E_CNAME ] ) )
        return;

    if( !channel = CHANNEL_H->query_channel_name(channel) )
        return;

    who = sprintf("%s@%s", CAP( packet[S_P + CHANNEL_E_VISNAME] ),
                           CAP( packet[P_SOURCE] ) );

    str = packet[S_P + CHANNEL_E_MESSAGE];
    str = replace_string( str[0..1] == "$N" ? str[3..] : str, "$N", who );

    CHANNEL_H->send_intermud_chat( 0, channel, "", str, 1, 0, who );

} /* channel_e() */

// Incoming remote messages.
private void channel_m( mixed *packet ) {
    string channel;

    if( sizeof(packet) != ( S_P + SIZEOF_CHANNEL_M ) ) {
        packet_invalid(packet);
        return;
    }

    if( !available_channel( channel = packet[ S_P + CHANNEL_M_CNAME ] ) )
        return;

    if( !channel = CHANNEL_H->query_channel_name(channel) )
        return;

    CHANNEL_H->send_intermud_chat( 0, channel, "",
        packet[S_P + CHANNEL_M_MESSAGE], 0, 0,
        packet[S_P + CHANNEL_M_VISNAME]+"@"+packet[P_SOURCE] );

} /* channel_m() */

private void channel_t( mixed *packet ) {
    return;
} /* channel_t() */

/**
 * This method makes us listen or stop listening a channel.
 * @param cname the name of the channel
 * @param state 1 to start listening to a channel, 0 to disconnect
 * @return a message describing our progress
 */
string listen_channel( string cname, int state ) {
    mixed *packet;

    if( state < 0 || state > 1 )
        return "Invalid intermud channel state.\n";

    if( !channel_exists(cname) )
        return "No channel by that name exists.\n";

    packet = packet_allocate(CHANNEL_LISTEN_PACKET);
    packet[P_DESTINATION] = config->routers[0][0];
    packet[P_SENDER] = TU ? TU->query_name() : "admin";
    packet[S_P + CHANNEL_LISTEN_CNAME] = cname;
    packet[S_P + CHANNEL_LISTEN_STATE] = state;

    add_buffer( 0, packet );
    send_buffer( 0 );

    log_file("IMUD_CHANNELS", sprintf("%s: channel-listen %s %d (%s)\n",
        ctime(time()), cname, state, packet[P_SENDER] ) );

    if( state ) {
        if( member_array( cname, listen_channels ) == -1 ) {
            listen_channels += ({ cname });
            if( !call_id )
                call_id = call_out( (: save_me :), 4 );
        }
        return "Connecting to "+cname+".\n";
    }

    if( member_array( cname, listen_channels ) != -1 ) {
        listen_channels -= ({ cname });
        if( !call_id )
            call_id = call_out( (: save_me :), 4 );
    }

    return "Disconnecting from "+cname+".\n";

} /* listen_channel() */

/**
 * This method creates an intermud channel.
 * The channel types that can be used are:<br>
 * 0 - selectively banned.<br>
 * 1 - selectively admitted.<br>
 * 2 - filtered (selectively admitted).
 * @param cname the name of the channel to create
 * @param ctype the type of the channel to create
 * @return a message describing our progress
 */
string create_channel( string cname, int ctype ) {
    mixed *packet;

    if( !adminp(TU) )
        return "Insufficient privilege to affect intermud channels.\n";

    if( ctype < 0 || ctype > 2 )
        return "Invalid intermud channel type.\n";

    if( channel_exists(cname) )
        return "An intermud channel of that name already exists.\n";

    packet                          = packet_allocate(CHANNEL_ADD_PACKET);
    packet[P_DESTINATION]           = config->routers[0][0];
    packet[P_SENDER]                = TU->query_name();
    packet[S_P + CHANNEL_ADD_CNAME] = cname;
    packet[S_P + CHANNEL_ADD_TYPE]  = ctype;

    admin_channels[cname] = new( class admin_channel,
        type : ctype, members : ({ }) );

    add_buffer( 0, packet );
    send_buffer( 0 );

    save_me();

    log_file("IMUD_CHANNELS", sprintf("%s: channel-add %s %d (%s)\n",
        ctime(time()), cname, ctype, packet[P_SENDER] ) );

    return "Creating intermud channel "+cname+" (type "+ctype+").\n";

} /* create_channel() */

/**
 * This method deletes an intermud channel.
 * @param cname the name of the channel to delete
 * @return a message describing our progress
 */
string delete_channel( string cname ) {
    mixed *packet;

    if( !adminp(TU) )
        return "Insufficient privilege to affect intermud channels.\n";

    if( !channel_exists(cname) )
        return "No intermud channel of that name exists.\n";

    packet = packet_allocate(CHANNEL_REMOVE_PACKET);
    packet[P_DESTINATION] = config -> routers[0][0];
    packet[P_SENDER] = TU->query_name();
    packet[S_P + CHANNEL_REMOVE_CNAME] = cname;

    map_delete( admin_channels, cname );

    add_buffer( 0, packet );
    send_buffer( 0 );

    save_me();

    log_file("IMUD_CHANNELS", sprintf("%s: channel-remove %s (%s)\n",
        ctime(time()), cname, packet[P_SENDER] ) );

    return "Deleting intermud channel "+cname+".\n";

} /* delete_channel() */

/**
 * This method is used to administrate an intermud channel.
 */
string administrate_channel(string cname, string *add_list,
                            string *remove_list) {
    mixed *packet;
    string owner;

    if( ( PO && base_name(PO) != INTERMUD_H ) && !adminp(TU) )
        return "Insufficient privilege to affect intermud channels.\n";

    if( !channel_exists(cname) )
        return "No intermud channel of that name exists.\n";

    if( MUD_NAME != ( owner = query_channel_owner(cname) ) )
        return cname+" is not owned by "+MUD_NAME+", but by "+owner+".\n";

    if( !arrayp(add_list) )
        add_list = ({ });

    if( !arrayp(remove_list) )
        remove_list = ({ });

    if( classp( admin_channels[cname] ) )
        add_list -= admin_channels[cname]->members;

    if( !sizeof(add_list) && !sizeof(remove_list) )
        return "Why bother making no changes (both lists are empty)?\n";

    if( classp( admin_channels[cname] ) ) {
        admin_channels[cname]->members += add_list;
        admin_channels[cname]->members -= remove_list;
    }

    packet = packet_allocate(CHANNEL_ADMIN_PACKET);
    packet[P_DESTINATION] = config->routers[0][0];
    packet[P_SENDER]      = TU ? TU->query_name() : "admin";
    packet[S_P + CHANNEL_ADMIN_CNAME]  = cname;
    packet[S_P + CHANNEL_ADMIN_ADD]    = add_list;
    packet[S_P + CHANNEL_ADMIN_REMOVE] = remove_list;

    add_buffer( 0, packet );
    send_buffer( 0 );

    save_me();

    log_file("IMUD_CHANNELS", "%s: channel-admin %s (%s)%s%s\n",
        ctime(time()), cname, packet[P_SENDER], sizeof(add_list) ?
        sprintf("\nAdded:\n%#-*s", 79, implode( add_list, "\n") ) : "",
        sizeof(remove_list) ? sprintf("\nRemoved:\n%#-*s", 79,
        implode( remove_list, "\n") ) : "");

    return "Administrating intermud channel "+cname+".\n";

} /* administrate_channel() */

// Update available remote channels.
private void chanlist_reply( mixed *packet ) {
    if( sizeof(packet) != ( S_P + SIZEOF_CHANLIST_REPLY ) ) {
        packet_invalid(packet);
        return;
    }

    config->channel_list->id = packet[S_P + CHANLIST_REPLY_ID];
    config->channel_list->list = filter( packet[S_P + CHANLIST_REPLY_LIST],
        (: stringp($1) && $2 :) );

    // Register the channels we're listening to with the router.
    map( available_channels(), (: listen_channel( $1, 1 ) :) );

    // Add all muds using Skylib to the allow list.
    if( mud_name() == "Divided Sky")
        administrate_channel("skylib", skylibs, 0 );

    config->configured = 1;
    save_me();

} /* chanlist_reply() */

private void chan_who_reply( mixed *packet ) {
    string *users;
    object user;

    if( sizeof(packet) != ( S_P + SIZEOF_CHAN_WHO_REPLY ) ) {
        packet_invalid(packet);
        return;
    }

    if( !user = find_player( packet[P_RECIPIENT] ) )
        return;

    users = packet[S_P + CHAN_WHO_REPLY_USERS];

    if( sizeof(users) ) {
        if( ( users[0] == "Just ask.") || !users[0] ||
            ( users[0][0..23] == "There is no such channel") )
            return;
    } else {
        return;
    }

    tell_object( user, ""+packet[P_SOURCE]+": "+implode( users, ", ")+"\n");

} /* chan_who_reply() */

private void chan_who_request( mixed *packet ) {
    mixed *reply;
    string channel, *listeners;

    if( sizeof(packet) != ( S_P + SIZEOF_CHAN_WHO_REQ ) ) {
        packet_invalid(packet);
        return;
    }

    if( !channel = CHANNEL_H -> query_channel_name(
        packet[S_P + CHAN_WHO_REQ_CNAME] ) )
        return;

    CHANNEL_H->update_users(channel);

    if( !listeners = CHANNEL_H->query_users(channel) )
        listeners = ({ });

    listeners = map( listeners, (: $1->query_cap_name() :) );

    reply = packet_allocate(CHAN_WHO_REPLY_PACKET);
    reply[P_DESTINATION]              = packet[P_SOURCE];
    reply[P_RECIPIENT]                = packet[P_SENDER];
    reply[S_P + CHAN_WHO_REPLY_CNAME] = channel;
    reply[S_P + CHAN_WHO_REPLY_USERS] = listeners;

    add_buffer( 0, reply );
    send_buffer( 0 );

} /* chan_who_request() */

/**
 * This method queries who are listening to the specified
 * intermud channel.
 * @param channel the channel to get the who list for
 * @param mud the
 * @return 1 upon success, 0 upon failure
 */
int chan_who( string channel, string mud ) {
    mixed *packet;

    if( !mud ) {
        int i, sz;

        sz = sizeof( packet = keys( config->mud_list->list ) );

        while( sz-- ) {
            if( mud = packet[sz] )
                i += chan_who( channel, mud );
        }

        return i;
    }

    // Service is unavailable.
    if( shutdown || !( mud = mud_exists(mud) ) || mud == MUD_NAME ||
        !available_channel(channel) )
        return 0;

    packet = packet_allocate(CHAN_WHO_REQ_PACKET);
    packet[P_SENDER]                 = TU->query_name();
    packet[P_DESTINATION]            = mud;
    packet[S_P + CHAN_WHO_REQ_CNAME] = channel;

    add_buffer( 0, packet );
    send_buffer( 0 );

    return 1;

} /* chan_who() */
