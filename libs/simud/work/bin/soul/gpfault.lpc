#include <emote.h>

string *choices_self = ({
                          "~Name ~verbfix a bug.",
                          "~Name ~verbcrash the mud.",
                          "~Name ~verbreboot the mud.",
                          "~Name ~verbbreak the mud with an experiment gone wrong.",
                          "~Name ~verbgrumble about permission problems."
                       });
string *choices_targ = ({
                          "~Name ~verbfix ~post bug.",
                          "~Name ~verbapologize profusely to ~targ for crashing the mud.",
                          "~Name ~verbreimburse ~targ after rebooting the mud.",
                          "~Name ~verbfix ~targ after a bad experiment goes awry.",
                          "~Name ~verbwhine to ~targ about some random permission problem."
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
