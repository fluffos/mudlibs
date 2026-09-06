#include <emote.h>

mapping readers;

void create() { readers = ([ ]);}

mapping query_readers() { return readers; }

string carroll() {

  remove_call_out("time_out");
  call_out("time_out", 300);

  readers[this_player()]++; 

  if( readers[this_player()] > 15 ) readers[this_player()] = 3;

  switch (readers[this_player()]) {
    case 14:
    case 1: return " ";

    case 15:
    case 2: return " ";

    case 3: return " ";

    case 4: return " ";

    case 5: return " ";

    case 6: return " ";

    case 7: return " ";

    case 8: return " ";

    case 9: return " ";

    case 10: return " ";

    case 11: return " ";

    case 12: return " ";

    case 13: return " "";

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
