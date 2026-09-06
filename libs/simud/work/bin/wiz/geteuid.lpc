#include <wizard.h>
#include <const.h>

int main(string param) {
   object ob;

   if( this_player()->query_level() < WIZLEVEL ) {
      notify_fail("==> [Error] Access denied\n");
      return 0;
   }

   if( !param ) {
      notify_fail("==> [Format] geteuid object\n");
      return 0;
   }

   ob = find_thing(param);
   if( !ob ) {
      notify_fail("==> [Error] Could not find object "+param+"\n");
      return 0;
   }

   msg("The EUID of "+param+" is "+geteuid(ob));
   return 1;
}