// Incoming tell for a user

private void tell_reply(mixed *packet) {
  object user;
  mixed *err;

  if (sizeof(packet) != (S_P + SIZEOF_TELL)) {
    packet_invalid(packet);
    return;
  }

  if (!(user = find_player(packet[P_RECIPIENT]))) {
    err = packet_allocate(ERROR_PACKET);
    err[P_DESTINATION]         = packet[P_SOURCE];
    err[P_RECIPIENT]           = packet[P_SENDER];
    err[S_P + ERROR_CODE]      = "unk-user";
    err[S_P + ERROR_MESSAGE]   = "unknown target user";
    err[S_P + ERROR_ERRPACKET] = packet;
    add_buffer(0, err);
    send_buffer(0);
    return;
  }

  user->event_person_tell(TO,sprintf("%s@%s tells you: ",
                     packet[S_P + TELL_SHORT], packet[P_SOURCE]), 
                     packet[S_P + TELL_MESSAGE] , "common");
} /* tell_reply() */

// Initiate a remote tell
int tell(string user, string mud, string message) {
  mixed *packet;

  if ((shutdown) || (!(mud = mud_exists(mud))))
    return 0;  // Service is unavailable

  packet = packet_allocate(TELL_PACKET);
  packet[P_SENDER]            = TU -> query_name();
  packet[P_DESTINATION]       = mud;
  packet[P_RECIPIENT]         = lower_case(user);
  packet[S_P + TELL_SHORT]    = TU -> query_cap_name();
  packet[S_P + TELL_MESSAGE]  = message;

  add_buffer(0, packet);
  send_buffer(0);
  return 1;
} /* tell() */
