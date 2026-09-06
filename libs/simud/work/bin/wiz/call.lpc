#include <const.h>
#include <wizard.h>

int main(string param) {
   string ret;

   WIZ_CHECK

   if(!param) {
      notify_fail("==> [Format] call obj func param OR obj->func(param1, param2, ...)\n");
      return 0;
   }

   ret = exec_call( param );
   msg("Call returns:");
   write(ret + "\n" );
   return 1;
}