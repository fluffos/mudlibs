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
    case 1: return "'Twas brillig, and the slithy toves did gyre and gimble in the wabe.";

    case 15:
    case 2: return "All mimsy were the borogoves and the mome raths outgrabe.";

    case 3: return "Beware the Jabberwock, my son! The jaws that bite, the claws that catch!";

    case 4: return "Beware the Jubjub bird, and shun the frumious Bandersnatch!";

    case 5: return "He took his vorpal sword in hand: Long time the manxome foe he sought.";

    case 6: return "So rested he by the Tumtum tree and stood a while in thought.";

    case 7: return "And, as in uffish thought he stood, the Jabberwock, with eyes of flame, came whiffling through the tulgey wood and burbled as it came!";

    case 8: return "One, two! One, two! And through and through, the vorpal blade went snicker-snack!";

    case 9: return "He left it dead, and with its head, he went gallumphing back.";

    case 10: return "And hast thou slain the Jabberwock? Come to my arms, my beamish boy!";

    case 11: return "`O frabjous day! Calloh! Callay!' he chortled in his joy.";

    case 12: return "'Twas brillig, and the slithy toves did gyre and gimble in the wabe.";

    case 13: return "All mimsy were the borogoves and the mome raths outgrabe.";

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
         this_player()->msg_local("~CEMO"+query_ctarget()+"~CDEF");
      }
      else msg ("~[010No one by that name here~[070.");
   }
   else
     this_player()->msg_local("~CEMO"+query_cself()+"~CDEF");
   return 1;
}
