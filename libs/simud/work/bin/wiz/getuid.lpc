#include <wizard.h>
#include <const.h>

int main(string param) {
   object ob;

   if( this_player()->query_level() < WIZLEVEL ) {
      notify_fail("==> [Error] Access denied\n");
      return 0;
   }

   if( !param ) {
      notify_fail("==> [Format] getuid object\n");
      return 0;
   }

   ob = find_thing(param);
   if( !ob ) {
      notify_fail("==> [Error] Could not find object "+param+"\n");
      return 0;
   }

   msg("The UID of "+param+" is "+getuid(ob));
   return 1;
}