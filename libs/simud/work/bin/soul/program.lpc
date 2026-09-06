#include <emote.h>

string x, y;
string *l = ({ "LPC", "Perl", "C++", "C", "QBasic", "Java", "Javascript", "PHP", "Python", "COBOL", "Fortran", "Assembly", "Visual Basic", "Hypertalk", "Befunge" });

void get_language() {
   x = l[random(sizeof(l))];
   l -= ({ "Python" });      // nothing is better than Python
   y = l[random(sizeof(l))];
   while( x == y ) y = l[random(sizeof(l))];
return;
}

string query_cself() { get_language(); return "~Name ~verbsay that " + x + " is better than " + y + "."; }
string query_ctarget() { get_language(); return "~Name ~verbtell ~Targ that " + x + " is better than " + y + "."; }

int main(string param) {
   object t;

   if(param) {
      if( t = single_present(param,environment(this_player()))) {
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
