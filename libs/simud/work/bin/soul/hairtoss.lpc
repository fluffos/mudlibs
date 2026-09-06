#include <emote.h>

string hTypes() {
   string *hair;

   hair = this_player()->query_env_var("hair");

   if(member(hair,"bald") >= 0)
      return "bald head";
   else
      return implode(hair, ", ") + " hair";
}

string query_cself() { return "~Name ~verbtoss ~poss "+hTypes()+" from side to side."; }
string query_ctarget() { return "~Name ~verbtoss ~poss "+hTypes()+" from side to side at ~targ."; }

main(param) {
   object t;

   if(param) {
      if( t = present(param,environment(this_player()))) {
         set_target(t);
         if (!this_player()->query_toad())
            this_player()->msg_local("~CEMO"+query_ctarget()+"~CDEF");
         else
            this_player()->msg_local("~CEMO"+query_ctarget()+"~CDEF");
      }
      else msg ("~[010No one by that name here~[070.");
   }
   else {
      if (!this_player()->query_toad())
         this_player()->msg_local("~CEMO"+query_cself()+"~CDEF");
      else
         this_player()->msg_local("~CEMO"+query_cself()+"~CDEF");
   }
   return 1;
}
