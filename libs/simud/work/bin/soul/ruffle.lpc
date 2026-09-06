#include <emote.h>

string hTypes(object t) {
   string *hair;

   hair = t->query_env_var("desc")["hair"];
   if( !hair ) hair = ({ "brown", "afro", "medium" });
   hair -= ({ 0 });
   if(member(hair,"bald") >= 0)
      return "bald head";
   else
      return implode(hair, ", ") + " hair";
}

string query_cself() {
   if(hTypes(this_player()) == "bald head"){
      return "~Name ~verbrub ~poss bald head.";
   }
   else
      return "~Name ~verbruffle ~poss "+hTypes(this_player())+".";
}

string query_ctarget() {
   if(hTypes(query_target()) == "bald head"){
      return "~Name ~verbrub ~npot bald head.";
   }
   else
      return "~Name ~verbruffle ~npot "+hTypes(query_target())+".";
}

main(string param) {
   object t;

   if(param) {
      t = present(param, environment(this_player()));
      if(t && t->query_is_player()) {
         set_target(t);
         if (!this_player()->query_toad())
            this_player()->msg_local("~CEMO"+query_ctarget()+"~CDEF");
         else
            msg("~CEMO"+query_ctarget()+"~CDEF");
      } else
         msg ("~[010No one by that name here~[070.");
   } else {
      t = this_player();
      set_target(t);
      if (!this_player()->query_toad())
         this_player()->msg_local("~CEMO"+query_cself()+"~CDEF");
      else
         msg("~CEMO"+query_cself()+"~CDEF");
   }
   return 1;
}
