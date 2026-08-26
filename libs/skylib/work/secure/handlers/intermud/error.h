// Error messaging
private void packet_error(mixed *packet) {
  string err;
  object user;

  if (sizeof(packet) != (S_P + SIZEOF_ERROR)) {
    packet_invalid(packet);
    return;
  }

  if (ROUTER_ERRORS[packet[S_P + ERROR_CODE]])
    err = ROUTER_ERRORS[packet[S_P + ERROR_CODE]];
  else
    if (MUD_ERRORS[packet[S_P + ERROR_CODE]])
      err = ROUTER_ERRORS[packet[S_P + ERROR_CODE]];
    else
      err = packet[S_P + ERROR_CODE] + " : " + 
            packet[S_P + ERROR_MESSAGE];

  if (err = "feature not yet implemented")
    return;

  if ((user = find_player(packet[P_RECIPIENT])) && err)
    tell_object(user, err + "\n");

} /* packet_error() */

