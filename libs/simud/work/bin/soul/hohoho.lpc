#include <emote.h>

main(param) {
   object t;
   string month,junk;

   sscanf(ctime(time()),"%s %s %s",junk,month,junk);

   if(param) {
      if( t = present(param,environment(this_player()))) {
         set_target(t);
         if (month!="Dec")
           this_player()->msg_local(EMOTE_COLOR+"~Name ~verbgo `Ho-ho-ho' like Jabba The Hutt at ~targ.~CDEF");
         else
           this_player()->msg_local(EMOTE_COLOR+"~Name ~verbgo `Ho-ho-ho' like Santa at ~targ.~CDEF");
      }
      else msg ("~[010No one by that name here~[070.");
   }
   else
      if (month!="Dec")
        this_player()->msg_local(EMOTE_COLOR+"~Name ~verbgo `Ho-ho-ho' slowly like Jabba The Hutt.~CDEF");
      else
        this_player()->msg_local(EMOTE_COLOR+"~Name ~verbgo `Ho-ho-ho' jollily like Santa Claus.~CDEF");
   return 1;
}
