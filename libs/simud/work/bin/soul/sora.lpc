#include <emote.h>

string *choices_self = ({
                          "~Name ~verbreport a bug.",
                          "~Name ~verbcomplain about a bug.",
                          "~Name ~verbexploit a bug.",
                          "~Name ~verbpost a bug that wasn't clear to the forum.",
                          "~Name ~verbpost a rhetorical question to the bug forum."
                       });
string *choices_targ = ({
                          "~Name ~verbreport a bug to ~targ.",
                          "~Name ~verbcomplain to ~targ about a bug.",
                          "~Name ~verbaccuse ~targ of exploiting a bug.",
                          "~Name ~verbpost a bug that wasn't clear to ~targ to the forum.",
                          "~Name ~verbpost a rhetorical question about ~targ to the bug forum."
                       });

string query_cself() {
   int number = random(5);
   return choices_self[number];
}

string query_ctarget() {
   int number = random(5);
   return choices_targ[number];
}

int main (string param) {
   object t;

   if(param) {
      if( t = present(param,environment(this_player()))) {
         set_target(t);
         this_player()->msg_local("~CEMO"+query_ctarget()+"~CDEF");
      }
      else msg ("~[010No one by that name here~[070.");
   }
   else
     this_player()->msg_local("~CEMO"+query_cself()+"~CDEF");
   return 1;
}

EMOTE_ATTRIBUTE( ATT_VISUAL | ATT_MEAN )
