#include <const.h>

main(string str) { // This is the local echo func.  Any wiz is allowed to do it
  object who;
  string wiz_str;
		
  WIZ_CHECK

  if(!str) {
    notify_fail("==> [Format] echo message\n");
    return 0;
  }

  str = "~CACT"+str+"~CDEF";
  wiz_str = "<echo:~CCOM"+this_player()->query_name()+"~CDEF> "+str;

  foreach( who : all_inventory(environment(this_player())) ) {
    if ( !who->query_is_player() )
      continue;
	else if ( who->query_level() >= WIZLEVEL )
      msg_object(who,wiz_str);
	else
      msg_object(who,str);
  }
  return 1;
}
