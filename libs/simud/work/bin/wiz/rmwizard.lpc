#include <const.h>

main(str) {
  object victim;

  if(this_player()->query_level()<ADMLEVEL) {
    notify_fail("==> [Out of Cheese Error] Please insert 1000 coins and try again.\n");
    return 0;
  }
  if( !str ) {
    notify_fail("==> [Format] rmwizard wizname\n");
    return 0;
  }

  if( victim = find_player(str) )
     victim->set_level( WIZLEVEL - 1 );
  if(!call_other("/secure/master_security", "remove_wizard", str)) {
    notify_fail("==> [Error] Wizard removal has failed.\n");
    return 0;
  }
  log_file("secure", ctime(time()) + " " + capitalize(this_player()->query_name()) + " removed wizard " + str + "\n");
  msg("==> [Done] Wizard has been removed.");
  return 1;
}