#include <const.h>
#include <wizard.h>

main(str) {
   string src, dest;
   object ob, destob;

   WIZ_CHECK

   if(!str || sscanf(str, "%s %s", src, dest) != 2) {
      notify_fail("==> [Format] move <object> <destination>\n");
      return 0;
   }

   ob = find_thing(src);
   if(!ob) {
      notify_fail("==> [Error] That object could not be found\n");
      return 0;
   }

   destob = find_thing(dest);
   if(!destob) {
      notify_fail("==> [Error] Could not find that destination\n");
      return 0;
   }

   set_target(ob);
   set_actor(this_player());
   if( environment(ob) == environment(this_player()) && ob->query_specific() )
      this_player()->msg_local("~CBRT~Name ~verbsnap ~poss fingers, and with a \"pop,\" ~subt ~vertdisappear.~CDEF");
   else {
      this_player()->msg_local("~CBRT~Name ~verbsnap ~poss fingers.~CDEF" );
      set_target(ob);
      set_actor(this_player());
      set_listener(this_player());
      if( ob->query_specific() && environment(ob) )
         msg_room( environment(ob), "~CBRT~Targ ~vertdisappear with a popping sound.~CDEF" );
   }

   ob->move(destob);

   if( ob ) {
      ob->validate_position();
      set_target(ob);
      set_actor(this_player());
      msg_room(environment(ob), "~CBRTThere is a faint pop, and ~subt ~vertappear.~CDEF");
   }
   else
      msg("Object self destructed when moved.");
   msg("==> [Move] Object moved");
   return 1;
}
