#include <const.h>
#include <wizard.h>

main(string param) {
   object ob, *obs, i, n, env;
   string s;

   ADM_CHECK

   if(!param) {
      msg("==> [Format] nuke <objects>");
      return 1;
   }

   ob = find_thing(param);

   if(!ob) {
      notify_fail("==> [Error] Unable to locate object "+param+"\n");
      return 0;
   }

   obs = all_inventory( ob );

   set_target(ob);
   this_player()->msg_local("~CBRT~Name ~verbclap ~poss hands. A heavy banging sound is heard, like a cannon-shot.~CDEF");

   foreach( ob : obs ) {
      if( !ob->query_is_player() )
         destruct(ob);
   }
   return 1;
}
