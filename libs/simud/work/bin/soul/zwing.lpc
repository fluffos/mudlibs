#include <emote.h>

mapping readers;

void create() { readers = ([ ]);}

mapping query_readers() { return readers; }

string carroll() {

  remove_call_out("time_out");
  call_out("time_out", 300);

  readers[this_player()]++;

  if( readers[this_player()] > 19 ) readers[this_player()] = 3;

  switch (readers[this_player()]) {
    case 18:
    case 1: return "In A.D. 2101";

    case 19:
    case 2: return "War was beginning";

    case 3: return "Captain: What happen ?";

    case 4: return "Mechanic: Somebody set up us the bomb.";

    case 5: return "Operator: We get signal.";

    case 6: return "Captain: What !";

    case 7: return "Operator: Main screen turn on.";

    case 8: return "Captain: It's you !!";

    case 9: return "Cats: How are you gentlemen !!";

    case 10: return "Cats: All your base are belong to us. ";

    case 11: return "Cats: You have no chance to survive make your time.";

    case 12: return "Cats: HA HA HA HA ....";

    case 13: return "Operator: Captain !!";

    case 14: return "Captain: Take off every 'zig' !!";

    case 15: return "Captain: You know what you doing.";

    case 16: return "Captain: Move 'Zig'.";

    case 17: return "Captain: For great justice.";

  }

  return ""; // for spammy warning
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
