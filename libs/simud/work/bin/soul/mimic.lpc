#include <emote.h>

string query_cself() {
   string doing;

   doing = this_player()->query_doing();

   doing = implode(explode(doing,"yourself"),"~refl");
   doing = implode(explode(doing,"himself"),"~refl");
   doing = implode(explode(doing,"herself"),"~refl");
   doing = implode(explode(doing,"itself"),"~refl");

   return "~Name ~verbmimic ~refl by "+doing+".";
}

string query_ctarget() {
   string doing;
   object t = query_target();

   if(t->query_is_living() && t->query_doing() != 0){
      doing = t->query_doing();
   }
   else{
     set_target(t);
     return "~Name ~verbmimic ~targ.";
   }

   doing = implode(explode(doing,"yourself"),"~refl");
   doing = implode(explode(doing,"himself"),"~refl");
   doing = implode(explode(doing,"herself"),"~refl");
   doing = implode(explode(doing,"itself"),"~refl");

   set_target(t);

   return "~Name ~verbmimic ~targ by "+doing+".";
}

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
