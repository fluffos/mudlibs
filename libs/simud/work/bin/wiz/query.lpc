#include <const.h>
#include <wizard.h>

int main(string str) {
   string ret;
   string obj, func;
   mixed param;

   WIZ_CHECK

   if(!str || sscanf(str, "%s %s", obj, func) != 2 ) {
      notify_fail("==> [Format] query obj func [param]\n");
      return 0;
   }

   param = 0;
   // If there is a space, look for parameters (If this fails, param stays '0')
   sscanf(func, "%s %s", func, param);
   // If it is in the right format, turn param into an integer.
   if( param )
      sscanf(param, "%d", param);

   ret = exec_call( obj + " query_" + func + (param?" " + param:"") );
   msg("query_"+func+"("+(param?param:"")+") returned:");
   write(ret+"\n");
   return 1;
}