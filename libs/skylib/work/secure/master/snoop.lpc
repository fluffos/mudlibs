/*  -*- LPC -*-  */

int valid_snoop(object snooper, object snoopee, object pobj) {
  string verb;

  verb = this_player()->query_current_verb();
  if (snooper == snoopee) {
    tell_object(snooper, "You can't snoop yourself.\n");
    return 0;
  }
  if (snoopee && query_snoop(snoopee)) {
    tell_object(snooper,
                snoopee->query_cap_name()+" is already being snooped.\n");
    return 0;
  }
  if (snooper->query_snoopee()) {
    user_event( snooper->query_cap_name()+" stops " + verb + "ing "+
                snooper->query_snoopee()->query_name(), "snoop");
    if (!snooper->query_property("quiet snoop")) {
      tell_object((object)snooper->query_snoopee(),
                  snooper->query_cap_name()+" stops snooping you.\n");
    } else {
      snooper->remove_property("quiet snoop");
    }
    snooper->set_snoopee(0);
  }
  if (!snoopee) {
    return 1;
  }
  if (!creatorp(snooper))
    return 0;
  if (pobj == this_object()) {
    user_event( snooper->query_cap_name()+" starts qsnooping "+
                snoopee->query_name(), "snoop");
    return 1;
  }
  if (verb == "qsnoop" && lordp(geteuid(snooper)) &&
      !lordp(geteuid(snoopee))) {
    tell_object(snooper, "You are quiet snooping "+
                snoopee->query_cap_name()+"\n");
    snooper->add_property("quiet snoop", 1);
  } else {
    tell_object(snoopee, "You are being snooped by "+
                snooper->query_cap_name()+".\n");
  }
  unguarded( (: write_file("/secure/log/SNOOP", ctime(time()) + " " +
           (string)$(snooper)->query_cap_name() + " " +
           $(verb) + "s " + (string)$(snoopee)->query_cap_name() + ".\n") :) );
  snooper->set_snoopee(snoopee);
  if (verb == "qsnoop") {
    tell_object(snooper, "Please share with us the reason why you are " +
                "quiet snooping?\n: ");
    input_to("snoop_reason");
    snoop_list[snooper] = snoopee;
    return 0;
  }
  user_event( snooper->query_cap_name()+" starts " + verb + "ing "+
              snoopee->query_name(), "snoop");
  return 1;
} /* valid_snoop() */

void snoop_reason(string str) {
  object snooper;

  snooper = this_player();
  if (this_player(1) != this_player()) {
    write("Can't force people...\n");
    return ;
  }
  if (!adminp(geteuid(this_player()))) {
    write("Not an Admin.\n");
    return ;
  }
  if (!snoop_list[snooper]) {
    write("The snoopee has just logged out.\n");
    return ;
  }
  if(!str) {
    write("Snoop canceled.\n");
    unguarded( (: write_file("/secure/log/SNOOP", "  Chickened out.\n") :) );
    return;
  }
  unguarded( (: write_file("/secure/log/SNOOP", "  Reason: " + $(str) +
                           "\n") :) );
  if (snoop(snooper, snoop_list[snooper]))
    write("Snoop suceeded,\n");
  else
    write("Snoop failed.\n");
} /* snoop_reason() */
