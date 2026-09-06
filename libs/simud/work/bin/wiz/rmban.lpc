#include <const.h>

int main( string param ) {
   int i;
   string *exps;

   ADM_CHECK

   if( !param || !(i = to_int(param)) || i < 1 || i > sizeof(exps = "/secure/banned_names"->query_banned_names())) {
      notify_fail("==> [Format] rmban ban_number\n");
      return 0;
   }

   exps = exps[..i-2] + exps[i..];
   "/secure/banned_names"->set_banned_names( exps );

   return 1;
}