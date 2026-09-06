#include <const.h>
#include <wizard.h>

main(string param) {
   object ob, i, n, env;
   string s, t;

   WIZ_CHECK

   if(!param) {
      msg("==> [Format] destruct <object>");
      return 1;
   }

   ob = find_thing(param);

   if(!ob)
      return notify_fail("==> [Error] Unable to locate object "+param+"\n");

   if( first_inventory(ob) )
      return notify_fail("==> [Error] Cannot destruct an object until you empty out its contents. Use 'wempty'\n");

   if (random(50) == 23)
      t = " a leg ";
   else
      t = " an arm ";
   s = ob->query_distant();
   set_actor(this_player());
   set_target(ob);
   if( !s ) s = "a shimmering patch of air";
   this_player()->msg_local("~CBRT~Name ~verbwave" + t +
           (this_player()->query_level() < ADMLEVEL ? "forcefully" : "lazily")+
           " and " + s + " ~vertis disintegrated.~CDEF");
   param = ob->query_name();
   if( !param )
     param = "Unnamed object";
   destruct(ob);
   msg("==> "+capitalize(param)+" destroyed successfully.");
   return 1;
}
