/* 08/19/06 Earwax: Daemonized this */
int cmd_emergency(string str) {
  
  if (!str) {
    write("Shout what?\n");
  return 1;
  }
  
  if((int)this_player()->query_channelcount() > 3) {
    write("Spaming level reached. Message not sent.\n");
    return 1;
  }
  if ((string)this_player()->query_real_name() == "guest"
  || (int)this_player()->query_age() < 1800) {
    write("Players less than one half hour old cannot use emergency.\n"+
        "If you have a REAL problem please tell any wizard or higher level player\n"+
        "to relay your message.  Guest cannot use emergency either.\n"+
        "This was done to stop abuse by those who wished to disturb others on the mud.\n");
    return 1;
  }
  
  this_player()->add_channelcount();
  shout("!" + (string)this_player()->query_name() + " screams: " + str + "\n");
  log_file("EMERGENCY",(string)this_player()->query_real_name()+ ": " + str + "\n");
  write("Ok. But it better be an emergency!\n");
  return 1;
}
