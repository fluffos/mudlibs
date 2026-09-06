main(string addy) {
  int hidden = this_player()->query_hide_email();

  if (!addy) {
    msg("Your email address is currently set to ~CBRT"+this_player()->query_email()+"~CDEF.");
    msg("It is currently "+(hidden?"~CBRThidden~CDEF from":"~CBRTvisible~CDEF to")+" other players.");
    return 1;
  }

  // ok, so i was bored and put this in a switch statement... shrug
  switch (addy) {
    case "hide":
      if (hidden)
         msg("Your email address is already being ~CBRThidden~CDEF.");
      else {
         this_player()->set_hide_email(1);
         msg("Ok, your email address is now ~CBRThidden~CDEF.");
      }
      return 1;

    case "show":
      if (!hidden)
         msg("Your email address is already ~CBRTvisible~CDEF.");
      else {
         this_player()->set_hide_email(0);
         msg("Ok, your email address is now ~CBRTvisible~CDEF.");
      }
      return 1;
  }

  if (member(addy,'@') == -1 ||
      member(addy,'.') == -1 ||
      member(addy,' ') != -1) {
     string *domain = explode(query_ip_name(this_player()),".");
     string suggestion, buf;
     if (sizeof(domain) == 1)
        suggestion = "simud.org";
     else {
        if (sizeof(domain) > 2)
           domain = domain[1..];
        suggestion = implode(domain,".");
     }
     buf = "Your email address must be something valid, of the form ~CBRT"+
           this_player()->query_name()+"@"+suggestion+"~CDEF.";
     if (suggestion != "simud.org")
        buf += " But please make sure the address you give is your real email address, ok?";
     msg(buf);
     return 1;
  }

  this_player()->set_email(addy);
  msg("Email address set to ~CBRT"+addy+"~CDEF.");

  return 1;
}
