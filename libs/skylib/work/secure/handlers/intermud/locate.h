// Reply for a local user locate request
private void locate_reply(mixed *packet) {
  object user;

  if (sizeof(packet) != (S_P + SIZEOF_LOCATE_REPLY)) {
    packet_invalid(packet);
    return;
  }

  if (!(user = find_player(packet[P_RECIPIENT])))
    return;

  tell_object(user, sprintf("%s was located at %s.\n",
              packet[S_P + LOCATE_REPLY_SHORT],
              packet[S_P + LOCATE_REPLY_LOCATION]));
} /* locate_reply() */

// Remote users locate request
private void locate_request(mixed *packet) {
  object user;
  mixed *reply;

  if (sizeof(packet) != (S_P + SIZEOF_LOCATE_REQ)) {
    packet_invalid(packet);
    return;
  }

  event(users(),"inform", sprintf("IMUD locate for %s from %s@%s",
      packet[S_P + LOCATE_REQ_NAME],packet[P_SENDER], packet[P_SOURCE]), "admin");

  if (!(user = find_player(packet[S_P + LOCATE_REQ_NAME])))
    return;

  if(user->query_invis())
    return;

  reply = packet_allocate(LOCATE_REPLY_PACKET);
  reply[P_DESTINATION]               = packet[P_SOURCE];
  reply[P_RECIPIENT]                 = packet[P_SENDER];
  reply[S_P + LOCATE_REPLY_LOCATION] = MUD_NAME;
  reply[S_P + LOCATE_REPLY_SHORT]    = user -> query_cap_name();
  reply[S_P + LOCATE_REPLY_IDLETIME] = query_idle(user);
  reply[S_P + LOCATE_REPLY_STATUS]   = NULL;
  
  add_buffer(0, reply);
  send_buffer(0);
} /* locate_request() */

// Initiate a locate request
int locate(string user) {
  mixed *packet = packet_allocate(LOCATE_REQ_PACKET);

  if (shutdown)
    return 0;  // Service is unavailable

  packet[P_SENDER]        = TU -> query_name();
  packet[S_P + LOCATE_REQ_NAME] = user;

  add_buffer(0, packet);
  send_buffer(0);

  return 1;
} /* locate() */
