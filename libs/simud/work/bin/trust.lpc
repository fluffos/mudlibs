#include <const.h>

main(string str) {
   object ob;

   if ( !str ) {
      mapping trust=this_player()->query_trust();
      if ( !sizeof(trust) )
         msg("You trust no one. Even your own mother's out to get you.");
      else {
         string buf="", name;
         foreach ( name : m_indices(trust) )
            buf += capitalize(name) + ", ";
         buf=buf[..<3];
         msg("You trust: "+buf+".");
      }
      return 1;
   }

   set_actor(this_player());
   if ( this_player()->query_trust(str) ) {
      msg("You stop trusting "+str+".");
      this_player()->remove_trust(str);
      if (ob=find_player(str)) {
         set_listener(ob);
         set_actor(this_player());
         msg_object(ob,"~CBRT~Name has stopped trusting you.~CDEF", 0);
      }
      return 1;
   }

   ob = find_player(str);
   if (!ob)
      ob = present(str,environment(this_player()));
   if (!ob || !ob->query_is_living())
      msg("I don't know who you mean by '"+str+"'.");
   else if ( ob == this_player() )
      msg("If you can't trust yourself...");
   else {
      msg("From now on, you trust "+capitalize(str)+". Type ~CCOMtrust "+str+"~CDEF again to stop trusting them.");
      this_player()->add_trust(str);
      set_actor(this_player());
      set_listener(ob);
      msg_object(ob,"~CBRT~Name now trusts you.~CDEF");
   }
   return 1;
}
