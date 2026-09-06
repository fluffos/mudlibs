#include <emote.h>

string hTypes() {

   int st = this_player()->query_strength();

   switch(st){

   case 0..8: return "flabby";
   case 9..10: return "little";
   case 11: return "soft";
   case 12: return "boringly average";
   case 13..14: return "shapely";
   case 15: return "well developed";
   case 16: return "rippling";
   case 17..18: return "massive";
   case 19..22: return "ginormous";
   case 23..25: return "mountainous";
   default: return "freakin' huge";
   }

   return ""; // here for spammy warnings
}

string query_cself() { return "~Name ~verbflex ~poss "+hTypes()+" muscles."; }
string query_ctarget() { return "~Name ~verbflex ~poss "+hTypes()+" muscles at ~targ."; }

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
