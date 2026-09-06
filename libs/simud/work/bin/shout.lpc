#include <textdraw.h>

int main(string str) {

   if( !str ) {
      notify_fail("What do you want to shout?\n");
      return 0;
   }

   str = recolor( str );

   if (!this_player()->query_toad())
      this_player()->say_all("~[140" + this_player()->query_cap_name()+ " shouts~[070: " + str, strlen(this_player()->query_cap_name()) + 9);
   msg("~[140You shout~[070: " + str, 12 );
   return 1;
}
