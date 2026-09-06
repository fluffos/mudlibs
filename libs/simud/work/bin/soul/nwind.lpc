#include <emote.h>

mapping readers;

void create() { readers = ([ ]);}

mapping query_readers() { return readers; }

string carroll() {

  remove_call_out("time_out");
  call_out("time_out", 300);

  readers[this_player()]++;

  if( readers[this_player()] > 30 ) readers[this_player()] = 1;

  switch (readers[this_player()]) {
    case 1: return "Cultivate your hunger before you idealize.";
    case 2: return "Motivate your anger to make them all realize.";
    case 3: return "Climbing the mountain, never coming down";
    case 4: return "Break into the contents, never falling down";
    case 5: return "My knee is still shaking, like I was twelve,";
    case 6: return "Sneaking out the classroom by the backdoor.";
    case 7: return "A man railed at me twice though, but I didn't care,";
    case 8: return "Waiting is wasting for people like me.";
    case 13:
    case 26:
    case 9: return "Don't try to live so wise.";
    case 14:
    case 27:
    case 10: return "Don't cry cause you're so right.";
    case 15:
    case 28:
    case 11: return "Don't dry with fakes or fears,";
    case 16:
    case 29:
    case 30:
    case 12: return "Cause you will hate yourself in the end.";
    case 17: return "You say, 'Dreams are dreams.";
    case 18: return "'I ain't gonna play the fool anymore.'";
    case 19: return "You say, 'Cause I still got my soul.'";
    case 20: return "Take your time, baby, your blood needs slowing down.";
    case 21: return "Breach yourself to reach yourself before you gloom.";
    case 22: return "Reflection of fear makes shadows of nothing.";
    case 23: return "Shadows of nothing";
    case 24: return "You still are blind if you see a winding road,";
    case 25: return "Cause there's always a straight way to the point you see.";
  }

}

void time_out(){
   readers = ([ ]);
}

string query_cself() { return "~Name ~verbsing: "+carroll(); }
string query_ctarget() { return "~Name ~verbsing to ~targ: "+carroll(); }

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
