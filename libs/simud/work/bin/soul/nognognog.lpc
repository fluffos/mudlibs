#include <emote.h>

string nog() {
   string month,junk;
   sscanf(ctime(time()),"%s %s %s",junk,month,junk);
   if (month == "Dec")
      return "eggnog";
   return "nog";
}

string query_cself() { return "~Name ~verb"+nog()+" until ~poss head falls off."; }
string query_ctarget() { return "~Name ~verb"+nog()+" like crazy at ~targ."; }

main(param) {
   object t;

   if(param) {
      if( t = present(param,environment(this_player()))) {
         set_target(t);
         if (!this_player()->query_toad())
            this_player()->msg_local("~CEMO"+query_ctarget()+"~CDEF");
         else
            msg("~CEMO"+query_ctarget()+"~CDEF");
      }
      else msg ("~[010No one by that name here~[070.");
   }
   else {
      if (!this_player()->query_toad())
         this_player()->msg_local("~CEMO"+query_cself()+"~CDEF");
      else
         msg("~CEMO"+query_cself()+"~CDEF");
   }
   return 1;
}
