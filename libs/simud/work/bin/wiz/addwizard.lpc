#include <const.h>

main(str) {
  string wiz, temp;
  int lvl;

  if(this_player()->query_level()<ADMLEVEL) {
    notify_fail("==> [Error] Access denied.\n");
    return 0;
  }

  if( getuid(previous_object()) != MASTER_UID ) {
    notify_fail("==> [Error] Access denied.\n");
    return 0;
  }

  if(!str || sscanf(str, "%s %s", wiz, temp) !=2) {
    notify_fail("==> [Format] addwizard <name> <level>\n");
    return 0;
  }

  lvl = to_int(temp);

  if(!lvl) {
    notify_fail("==> [Error] You must enter a number for the wizlevel!\n");
    return 0;
  }

  if( file_size("/home/" + wiz) != -2 && !mkdir("/home/" + wiz) ) {
    notify_fail("==> [Error] Unable to make direcotry /home/"+wiz+", aborting.\n");
    return 0;
  }

  if( lvl < ADMLEVEL )
     temp = wiz;
  else
     temp = MASTER_UID;

  if( !"/secure/file_security"->set_dir_owner("/home/"+wiz+"/", temp) )
     msg("==> [Warning] Setting ownership of the directory /home/"+wiz+"/ to "+temp+" failed; Do it manually.");

  log_file("secure", ctime(time()) + " " + capitalize(this_player()->query_name()) + " added wizard "+wiz+" at level "+lvl+"\n");
  call_other("secure/master_security", "add_wizard", wiz, lvl);
  msg("==> [Wizard Added]");
  return 1;
}