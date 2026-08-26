// Incoming emote for a user
private void emoteto_reply(mixed *packet) {
  object user;
  mixed *err;

  if (sizeof(packet) != (S_P + SIZEOF_EMOTETO)) {
    packet_invalid(packet);
    return;
  }

  if (!(user = find_player(packet[P_RECIPIENT]))) {
    err = packet_allocate(ERROR_PACKET);
    err[P_DESTINATION]         = packet[P_SOURCE];
    err[P_RECIPIENT]           = packet[P_SENDER];
    err[S_P + ERROR_CODE]      = "unk-user";
    err[S_P + ERROR_MESSAGE]   = MUD_ERRORS["unk-user"];
    err[S_P + ERROR_ERRPACKET] = packet;
    add_buffer(0, err);
    send_buffer(0);
    return;
  }
  tell_object(user, sprintf("%s@%s %s\n", packet[S_P + EMOTETO_SHORT],
              packet[P_SOURCE], packet[S_P + EMOTETO_MESSAGE]));
} /* emote_reply() */

// Initiate a remote emote
int emote(string user, string mud, string message) {
  mixed *packet;

  if ((shutdown) || (!mud_exists(mud)))
    return 0;  // Service is unavailable

  packet = packet_allocate(EMOTETO_PACKET);
  packet[P_SENDER]              = TU -> query_name();
  packet[P_DESTINATION]         = mud;
  packet[P_RECIPIENT]           = user;
  packet[S_P + EMOTETO_SHORT]   = TU -> query_cap_name();
  packet[S_P + EMOTETO_MESSAGE] = message;

  add_buffer(0, packet);
  send_buffer(0);
  return 1;
} /* emote() */
