// May 21, 2002, written by Calidron for Walraven

main(string str) {
   object target;
   string buf,message;
   int idle;

   if (!str) {
      if (message = this_player()->query_env_var("idlemsg")) {
         msg("~CBRTYour idle message is set to~CDEF: "+message);
         msg("Type ~CCOMidle off~CDEF to clear it.");
      } else {
         msg("You do not have an idle message set.");
         msg("To set one, type ~CCOMidle set message~CDEF, and to check someone's idle status, type ~CCOMidle name~CDEF.");
      }
      return 1;
   }

//   str = lower_case(str);

   if (str == "set clear" || str == "set off" || str == "0" || str == "off" ) {
      if (this_player()->query_env_var("idlemsg")) {
         msg("Your idle message has been cleared.");
         this_player()->set_env_var("idlemsg",0);
      } else
         msg("You don't have an idle message to clear.");
      return 1;
   }

   if (sizeof(str) > 4 && str[0..3] == "set ") {
      msg("~CBRTIdle message set to~CDEF: "+str[4..]);
      this_player()->set_env_var("idlemsg",str[4..]);
      return 1;
   }

   target = find_player(str);

   if (!target) {
      msg(str + " does not exist or is not logged in right now.");
      return 1;
   }

   idle = query_idle(target);
   message = target->query_env_var("idlemsg");

   buf = "~CLAB" + capitalize(str) + "~CDEF has been idle for ~CBRT" + int_to_time(idle) + "~CDEF";
   if (idle>60 && message)
      buf += ", but left the following message: ~CMA1" + message + "~CDEF";

   msg( buf );

   return 1;
}
