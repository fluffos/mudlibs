#include <const.h>

main(string str) {
   object ob;

   if ( !str ) {
      mapping ignore=this_player()->query_ignore();
      if ( !sizeof(ignore) )
         msg("You are not currently ignoring anyone.");
      else {
         string buf="", name;
         foreach ( name : m_indices(ignore) )
            buf += capitalize(name) + ", ";
         buf=buf[..<3];
         msg("Your ignore list consists of the following bonehead"+(sizeof(ignore)>1?"s":"")+": "+buf+".");
      }
      return 1;
   }

   set_actor(this_player());
   if ( this_player()->query_ignore(str) ) {
      msg("You stop ignoring "+str+".");
      this_player()->remove_ignore(str);
      ob=find_player(str);
   } else if ( !(ob = find_player(str)) )
      msg("I don't know who you mean by '"+str+"'. Note that you can only ignore players.");
   else if ( ob == this_player() )
      msg("Try as you might, you can't manage to get yourself to leave yourself alone.");
   else if ( ob->query_level() >= WIZLEVEL )
      msg("Sorry, but you can't ignore a wizard.");
   else {
      msg("From now on, you are blocking all tells from "+str+". Type ~CCOMignore "+str+"~CDEF again to stop ignoring them.");
      this_player()->add_ignore(str);
   }
   return 1;
}
