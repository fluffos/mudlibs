#include <const.h>
#include <wizard.h>

int main(string param) {
   string ret;

   WIZ_CHECK

   if(!param) {
      notify_fail("==> [Format] makehelpindex [help|wiz]\n");
      return 0;
   }

   if (param == "help") {
       "/help/makeindex"->make_help("/help");
       return 1;
       }
   else
   if (param == "wiz") {
       "/help/makeindex"->make_help("/help/wiz");
       return 1;
       }
}
