#include <const.h>
#include <wizard.h>

main(str) {
   string src, dest;
   object ob, destob;

   WIZ_CHECK

   if( !str ) {
      notify_fail("==> [Format] trans object\n");
      return 0;
   }

   ob = find_living(str);
   if(!ob) {
      notify_fail("==> [Error] That living creature could not be found.\n");
      return 0;
   }

   destob = environment(this_player());

   ob->move_player( destob, "teleport" );

   if( ob ) {
      ob->set_coord(this_player()->query_coord());
      ob->validate_position();
      msg_object( ob, "~CBRTYou feel a strange yanking sensation, and then you appear elsewhere.~CDEF" );
   }
   else
      msg("That creature self-destructed when moved.");
   return 1;
}
