#include <emote.h>

string query_cself() {
   string gender;
   int gendInt;

   gendInt = this_player()->query_gender();

   if(gendInt == 2){
      gender = "queen";
   }
   else if(gendInt == 1){
      gender = "king";
   }
   else{
      gender = "monarch";
   }

   return "~Name ~verbdeclare ~refl the "+gender+" of spam.";
}

string query_ctarget() {
   string gender;
   int gendInt;
   object t = query_target();

   if(t->query_is_living()){
      gendInt = t->query_gender();
   }

   if(gendInt == 2){
      gender = "queen";
   }
   else if(gendInt == 1){
      gender = "king";
   }
   else{
      gender = "monarch";
   }

   return "~Name ~verbdeclare ~targ the "+gender+" of spam.";
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
