#include <emote.h>

string blargh(int x) {
   switch (x) {
      case 11: return "a";
      case 12: return "b";
      case 13: return "c";
      case 14: return "d";
      case 15: return "e";
      case 16: return "f";
      case 17: return "g";
      case 18: return "h";
      case 19: return "i";
      case 20: return "j";
      case 21: return "k";
      case 22: return "l";
      case 23: return "m";
      case 24: return "n";
      case 25: return "o";
      case 26: return "p";
      case 27: return "q";
      case 28: return "r";
      case 29: return "s";
      case 30: return "t";
      case 31: return "u";
      case 32: return "v";
      case 33: return "w";
      case 34: return "x";
      case 35: return "y";
      case 36: return "z";
      case 37: return "!";
      case 38: return "@";
      case 39: return "#";
      case 40: return "$";
      case 41: return "%";
      case 42: return "&";
      case 43: return "*";
      default: return as_string(x);
   }
}

string blah() {
   int x;
   string buf = blargh(random(44));
   for (x = 0; x < random(15)+10; x++)
     buf += blargh(random(44));
   return buf;
}

string query_cself() { return "~Name ~verbgo `"+blah()+".'"; }
string query_ctarget() { return "~Name ~verbgo `"+blah()+"' at ~targ."; }

main(param) {
   object t;
   if(param)
      if( t = present(param,environment(this_player()))) {
         set_target(t);
         this_player()->msg_local(EMOTE_COLOR+"~Name ~verbgo `"+blah()+"' at ~targ.~CDEF");
      } else msg ("~[010No one by that name here~[070.");
   else
      this_player()->msg_local(EMOTE_COLOR+"~Name ~verbgo `"+blah()+".'~CDEF");
   return 1;
}
