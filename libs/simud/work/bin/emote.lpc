#include <textdraw.h>

int main(string str) {
   if(!str) {
      notify_fail("What do you want to emote?\n");
      return 0;
   }

   if(str[0..0] != "'")
      str = " " + str;

   str = recolor(str, "~CEMO");

   if (!this_player()->query_toad()) {
      this_player()->say_local("~CEMO~Name"+str+"~CDEF",
                                strlen(this_player()->query_cap_name()) + 1);
      foreach( object ob : all_inventory(environment(this_player()))
                           - ({ this_player() })) {
         ob->on_soul( 0, 0, this_player(), str );
      }
   }
   msg("~CCOMYou emoted: ~CEMO"+this_player()->query_cap_name()+ str+"~CDEF", 12);
   return 1;
}
