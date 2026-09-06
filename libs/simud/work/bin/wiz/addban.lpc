#include <const.h>

int main( string param ) {
   int exp;

   WIZ_CHECK

   if( !param ) {
      notify_fail("==> [Format] addban [-x] words...\n");
      return 0;
   }

   if( sscanf(param, "-x %s", param) == 1 )
      exp = 1;
   else
      exp = 0;

   if( exp )
      "/secure/banned_names"->add_banned_expression( param );
   else
      "/secure/banned_names"->add_banned_name( param );

   return 1;
}