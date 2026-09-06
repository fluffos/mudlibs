#include <const.h>

main(str) {
   object r;
   string fname;
   int i;

   WIZ_CHECK

   if(!str) {
      notify_fail("==> [Format] addroom name\n");
      return 0;
   }

   if(!environment(this_player())) {
      notify_fail("==> [Error] Can't put a room there\n");
      return 0;
   }

   if( !environment(this_player())->query_has_map() ) {
      notify_fail("==> [Error] You are not inside of an area object. Maybe you want the 'dig' command instead.\n");
      return 0;
   }

   if( strlen(str) < 1 || !legal_filename(str) ) {
      notify_fail("==> [Error] Illegal filename for room.\n");
      return 0;
   }

   r = clone_object("/world/room");
   r->move(environment(this_player()));

   r->set_name(str);
   r->set_short(capitalize(str));
   r->set_long("A bleak and desolate place, remarkably non-descript.");
   r->save_self();
   msg("==> [Notice] Room "+str+" created.");
   return 1;
}
