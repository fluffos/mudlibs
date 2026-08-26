class user_stats {
  int date_created, date_last_login, date_last_logout;

  int login_count;    // Number of times that the user has so far.
  int login_attempts; // Number of failed login attempts since last login.
  int login_time;     // Total time spent online so far.

  string *sites;      // Sites logged in from on the past.
} /* class user_stats */

class user_info {
  string name;               // real life name
  string email_address;      // e-mail address
  string location;           // real life location
  string homepage_url;       // homepage URL
  string birthdate;          // birthdate
} /* class user_info */

// Reply for a local user finger request
private void finger_reply(mixed *packet) {
  object user;
  string ret = "", unknown = "unknown";
  int idle;

  if( sizeof(packet) != (S_P + SIZEOF_FINGER_REPLY) ) {
      packet_invalid(packet);
      return;
  }

  if( !( user = find_player(packet[P_RECIPIENT]) ) )
      return;

  ret += sprintf("Real name:  %35-s\n", sizeof(packet[S_P +
      FINGER_REPLY_NAME] ) ? packet[S_P + FINGER_REPLY_NAME] : unknown );
  ret += sprintf("Email:      %35-s\n", sizeof(packet[S_P +
      FINGER_REPLY_EMAIL] ) ? packet[S_P + FINGER_REPLY_EMAIL] : unknown );
  ret += sprintf("Home page:  %35-s\n", unknown );
  ret += sprintf("Location:   %35-s\n", unknown );
  ret += sprintf("Birthday:   %35-s\n", unknown );

  if( ( idle = packet[S_P + FINGER_REPLY_IDLETIME]) > -1 ) {
      ret += "On since " + packet[S_P + FINGER_REPLY_LOGINOUT] + ".";

      if( idle > 60 )
          ret += "\nIdle for " + time_string(idle) + ".";
  } else {
        ret += "Last logged on "+packet[S_P + FINGER_REPLY_LOGINOUT]+".";
  }

  tell_object( user, ret + "%^RESET%^\n> ");

} /* finger_reply() */

// Remote users finger request
private void finger_request(mixed *packet) {
  class user_stats ustats;
  class user_info uinfo;
  object ob;
  mixed *reply, *info;
  string ip, user, login, title;
  int idle;

  return;

  if( sizeof(packet) != (S_P + SIZEOF_FINGER_REQ) ) {
      packet_invalid(packet);
      return;
  }

  user = packet[S_P + FINGER_REQ_NAME];
  info = ({"This function is broken","This function is broken"});
  ustats = info[1];
  uinfo = info[0];

  if( ob = find_player(user) ) {
      login = ctime(ustats -> date_last_login);
      idle = (interactive(ob) ? query_idle(ob) : -1);
      ip = query_ip_name(ob);
      title = TITLE_H->query_title(ob);
  } else {
      login = ctime(ustats -> date_last_logout);
      idle = -1;
  }

  reply = packet_allocate(FINGER_REPLY_PACKET);
  reply[P_DESTINATION]               = packet[P_SOURCE];
  reply[P_RECIPIENT]                 = packet[P_SENDER];
  reply[S_P + FINGER_REPLY_SHORT]    = CAP(packet[S_P + FINGER_REQ_NAME]);
  reply[S_P + FINGER_REPLY_TITLE]    = title;
  reply[S_P + FINGER_REPLY_NAME]     = uinfo -> name;
  reply[S_P + FINGER_REPLY_EMAIL]    = uinfo -> email_address;
  reply[S_P + FINGER_REPLY_LOGINOUT] = login;
  reply[S_P + FINGER_REPLY_IDLETIME] = idle;
  reply[S_P + FINGER_REPLY_IPNAME]   = ip;
  reply[S_P + FINGER_REPLY_LEVEL]    = NULL;
  reply[S_P + FINGER_REPLY_EXTRA]    = NULL;

  add_buffer( 0, reply );
  send_buffer(0);

} /* finger_request() */

// Inititate a remote finger request
int finger( string user, string mud ) {
  mixed *packet;

  if( shutdown || !( mud = mud_exists(mud) ) )
      return 0;  // Service is unavailable

  packet = packet_allocate(FINGER_REQ_PACKET);
  packet[P_SENDER]        = TU->query_name();
  packet[P_DESTINATION]   = mud;
  packet[S_P + FINGER_REQ_NAME] = user;

  add_buffer( 0, packet );
  send_buffer(0);

  return 1;

} /* finger() */
