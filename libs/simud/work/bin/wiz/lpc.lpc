#include <const.h>
#include <wizard.h>

int main(string param) {
   string ret;

   WIZ_CHECK

   if(!param) {
      notify_fail("==> [Format] lpc code...\n");
      return 0;
   }

   if (param[<1] != ';')
     param = param + ";";
   ret = exec_code( param );
   if( ret != "0" )
      write("Execution returned:\n"+ret+"\n");
   return 1;
}