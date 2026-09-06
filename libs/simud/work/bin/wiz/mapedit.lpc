#include <const.h>
#include <wizard.h>

main(string str) {
   object mapob, targ;

   if(this_player()->query_level() < WIZLEVEL) {
      notify_fail("==> [Error] Access denied\n");
      return 0;
   }

   if( !str ) {
      notify_fail("==> [Format] mapedit area\n");
      return 0;
   }

   targ = find_thing( str );
   if( !targ ) {
      notify_fail("==> [Error] Couldn't find the area '"+str+"'.\n");
      return 0;
   }

   mapob = clone_object("/obj/mapedit");
   mapob->move( this_player() );

   mapob->start_edit( targ );

   return 1;
}
