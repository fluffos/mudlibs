#include <const.h>

main(string str) {
   if( !str && this_player()->query_level() >= WIZLEVEL ) {
      object who;
      string buf = "~CTITCurrently Connected Players:~CDEF";
      foreach (who: users()) {
         buf += "\n~CBRT"+pad(who->query_cap_name(),15,0);
         buf += " ~CDEF"+pad(query_ip_number(who),15,2);
#ifdef __TLS__
		 buf += tls_query_connection_state(who) > 0 ? "~CTITSSL " : "    ";
#endif
#ifdef __MCCP__
		 buf += query_mccp(who) ? "~CLABMCCP " : "     ";
#endif
		 buf += who->query_env_var("Tmsp") ? "~CBRTMSP " : "    ";
		 buf +="~CDEF(~CBRT"+query_ip_name(who)+"~CDEF)";
      }
      msg(buf);
      return 1;
   }
   if( str == "me" )
      str = this_player()->query_name();
   if( str )
      return call_other("/obj/finger_daemon","finger_player",lower_case(str));
   notify_fail("Finger who?\n");
   return 0;
}
