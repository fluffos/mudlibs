#include <const.h>

/* A wizard verb used to find the location of a player
 * or to get a list of all players with locations.
 */

/* str: The name of the player whose location you wish to
 * know, or "all" for a list of all players with locations.
 */
main(str) {
   object target;
   int filter;

   if(this_player()->query_level() < WIZLEVEL) {
      msg("==> [Error] Access denied");
      return;
   }

   if(!str) {
      notify_fail("==> [Format] whereis [-f] <name>\n");
      return 0;
   }

   filter = 0;
   if( sscanf(str, "-f %s", str) == 1 ) {
      filter = 1;
      write("Only listing objects at invalid locations.\n");
   }

   if( str == "all" ) {
      object *userlist;

      userlist = users();
      foreach( target : userlist ) {
         msg( "~CBRT" + target->query_cap_name() + " ~CDEFis located at ~CLAB" +
              (environment(target)?get_location(environment(target))
              :"[an invalid location]") + "~CDEF" );
      }
      return 1;
   }

   target = find_player(str);
   if(!target) target = find_living(str);
   if(!target) target = find_object(this_player()->make_path_absolute(str));
   if(!target) {
      notify_fail("==> [Error] Could not find that person or thing\n");
      return 0;
   }
   if( !is_clone(target) ) {
      object ob;
      int i;

      i = 0;
      foreach( ob: all_clones(target) ) {
         if( filter && environment(ob) && member(all_environment(ob), find_object("/world/world")) >= 0 )
            continue;
         msg( "~CBRT" + object_name(ob) + " ~CDEFis at ~CLAB" +
              (environment(ob)?get_location(environment(ob))
              :"[an invalid location]") + "~CDEF" );
         i++;
//         if( i == 20 ) {
//            msg("~CWRNTruncated: There exist " + sizeof(all_clones(target)) + " in all.~CDEF");
//            return 1;
//         }
      }
   }
   else {
      target = environment(target);
      if(!target)
         msg("==> [WhereIs] Location: *Invalid* (0)");
      else msg("==> [WhereIs] Location:" +
               get_location(target) +
               " ("+object_name(target)+")");
   }
   return 1;
}