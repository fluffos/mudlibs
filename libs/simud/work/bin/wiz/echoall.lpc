#include <const.h>

main(string str) { // This is the local echo func.  Any wiz is allowed to do it
  object who;
  string wiz_str;
		
  WIZ_CHECK

  if(!str) {
    notify_fail("==> [Format] echoall [message]\n");
    return 0;
  }

  str = "~CTIT"+str+"~CDEF";
  wiz_str = "<echoall:~CCOM"+this_player()->query_name()+"~CDEF> "+str;

  foreach( who : users() ) {
	if ( who->query_level() >= WIZLEVEL )
      msg_object(who,wiz_str);
	else
      msg_object(who,str);
  }
  return 1;
}
