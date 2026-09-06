#include <emote.h>
//modified by Kri

mapping readers;

void create() { readers = ([ ]);}

mapping query_readers() { return readers; }

string carroll() {

  remove_call_out("time_out");
  call_out("time_out", 300);

  readers[this_player()]++;

  if( readers[this_player()] > 17 ) readers[this_player()] = 3;

  switch (readers[this_player()]) {
    case 16:
    case 1: return "It may not always be so; and i say";

    case 17:
    case 2: return "that if your lips, which i have loved, should touch";

    case 3: return "another's, and your dear strong fingers clutch";

    case 4: return "his heart, as mine in time not far away;";

    case 5: return "if on another's face your sweet hair lay";

    case 6: return "in such a silence as i know, or such";

    case 7: return "great writhing words as, uttering overmuch,";

    case 8: return "stand helplessly befre the spirt at bay;";

    case 9: return "...";

    case 10: return "if this should be, i say if this should be-";

    case 11: return "you of my heart, send me a little word;";

    case 12: return "that i may go unto him, and take his hands,";

    case 13: return "saying, Accept all happiness from me.";

    case 14: return "Then shall i turn my face, and hear one bird";

    case 15: return "sing terribly afar in the lost lands.";

  }

}

void time_out(){
   readers = ([ ]);
}

string query_cself() { return "~Name ~verbquote: "+carroll(); }
string query_ctarget() { return "~Name ~verbquote to ~targ: "+carroll(); }

int main(string param) {
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
