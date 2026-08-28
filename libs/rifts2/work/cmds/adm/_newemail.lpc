//   A command to reassign someone's email address.
//
//   Diewarzau
//   DarkeLIB 1.0

#include <security.h>
#include <daemons.h>
#include <dirs.h>

cmd_newemail(string str) {
 string newem, plyr, file, bef, aft, oldem;

  seteuid(getuid());
  if(!str || sscanf(str, "%s for %s", newem, plyr) != 2) {
    write("Incorrect syntax.");
    return 1;
  }
  plyr = lower_case(plyr);
  if(!user_exists(plyr)) {
    write("No such user: '"+plyr+"'.");
    return 1;
  }
  if(EMAIL_D->check_dup_email(newem, plyr)) {
    write("The email address '"+newem+"' is already in use.");
    return 1;
  }
  seteuid(UID_USERSAVE);
  file = read_file(DIR_USERS+"/"+plyr[0..0]+"/"+plyr+".o");
  if(sscanf(file, "%semail \"%s\"%s", bef, oldem, aft) != 3) {
    write("Error in reading player file.  Email not changed.");
    return 1;
  }
  rm(DIR_USERS+"/"+plyr[0..0]+"/"+plyr+".o");
  write_file(DIR_USERS+"/"+plyr[0..0]+"/"+plyr+".o",
    sprintf("%semail \"%s\"%s", bef, newem, aft));
  seteuid(getuid());
  EMAIL_D->unregister_email(oldem);
  write("Email changed for "+plyr+".");
  return 1;
}

int help() {
  message("help",
  "This command is used to change a player's email address.  "
  "It can be used if the player is not logged in.\n"
  "\n"
  "Syntax: newemail <new address> for <player>\n"
  "Ex: newemail dude@wherever.org for diewarzau\n",
  this_player());
  return 1;
}

