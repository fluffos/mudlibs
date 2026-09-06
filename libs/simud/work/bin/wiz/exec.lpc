#include <const.h>
#include <wizard.h>

int main(string param) {
   string ret;

   WIZ_CHECK

   msg("~[090The exec command has been renamed to 'lpc'. Please use 'lpc' instead. This is to avoid confusion between the verb and the efun. Thanks.~CDEF");

   if(!param) {
      notify_fail("==> [Format] exec code...\n");
      return 0;
   }

   ret = exec_code( param );
   if( ret != "0" )
      msg("Execution returned:\n"+ret);
   return 1;
}