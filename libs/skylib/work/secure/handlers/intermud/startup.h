// Initialize intermud services.
private void startup_reply(mixed *packet) {
    string host;
    int port;

    if (sizeof(packet) != (S_P + SIZEOF_STARTUP_REPLY)) {
        packet_invalid(packet);
        return;
    }

    if ((packet[S_P+STARTUP_REPLY_ROUTERS][0][0]!=config->routers[0][0]) ||
      (packet[S_P+STARTUP_REPLY_ROUTERS][0][1]!=config->routers[0][1])) {
        tcp_client::close_socket(0);
        config -> connected = NULL;
        config -> routers = copy(packet[S_P + STARTUP_REPLY_ROUTERS]);
        sscanf(config -> routers[0][1], "%s %d", host, port);
        open_socket(host, port, MUD);
        return;
    }

    config -> routers = packet[S_P + STARTUP_REPLY_ROUTERS];
    config -> connected = packet[S_P + STARTUP_REPLY_ROUTERS][0][0];
    config -> passwd = packet[S_P + STARTUP_REPLY_PASSWD];

    config -> mud_list -> list = ([ ]);
    config -> channel_list -> list = ([ ]);

    save_me();

} /* startup_reply() */

// Register ourselves with the router.
private void startup_req() {
    mixed *packet = packet_allocate(STARTUP_REQ_PACKET);

    packet[P_DESTINATION]              = config -> routers[0][0];
    packet[S_P + STARTUP_REQ_PASSWD]   = config -> passwd;
    packet[S_P + STARTUP_REQ_MUDLIST]  = config -> mud_list -> id;
    packet[S_P + STARTUP_REQ_CHANLIST] = config -> channel_list -> id;
    packet[S_P + STARTUP_REQ_PPORT]    = PORT_MUD;
    packet[S_P + STARTUP_REQ_TCPPORT]  = PORT_OOB;
    packet[S_P + STARTUP_REQ_UDPPORT]  = 0;
    packet[S_P + STARTUP_REQ_MUDLIB]   = MUDLIB;
    packet[S_P + STARTUP_REQ_BMUDLIB]  = "Discworld";
    packet[S_P + STARTUP_REQ_DRIVER]   = __VERSION__;
    packet[S_P + STARTUP_REQ_TYPE]     = "LP";
    packet[S_P + STARTUP_REQ_STATUS]   = "Mudlib Development";
    packet[S_P + STARTUP_REQ_EMAIL]    = ADMIN_EMAIL;
    packet[S_P + STARTUP_REQ_SERVICES] = SERVICES;
    packet[S_P + STARTUP_REQ_OTHER]    = ([ ]);

    add_buffer(0, packet);

} /* startup_req() */
