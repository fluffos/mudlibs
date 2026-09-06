#include <item.h>
#include <desc.h>
#include <saveload.h>
#include <object.h>

create() {
   ::create();
   set_distant("a bandage");
   set_specific("the bandage");
   set_plural("bandages");
   set_name("bandage");
   set_look( "A small cloth bandage. You could ~CCOMuse~CDEF this on "+
             "someone to stop their bleeding." );
   set_gettable(1);
   set_droppable(1);
   set_weight(200);
   set_bulk(1);
   set_value(100);
}

varargs int on_use(object who) {
   object bleeder;
   if (!who)
      who = this_player();
   set_actor(this_player());
   set_target(who);
   bleeder = present_clone("/battle/bleeder_object",who);
   if (bleeder && bleeder->query_type("edged")) {
      int x;
      this_player()->msg_local("~Name ~verbtie a bandage on ~post wounds.");
      if ( this_player()->query_skill("first aid") ) {
         x = this_player()->query_empathy() * 2;
         x += this_player()->query_skill("first aid") / 5;
         this_player()->practice_skill("first aid");
      } else
         x = this_player()->query_empathy() / 2;
      bleeder->add_strength(-x);
   } else
      msg("You see no reason to bandage ~targ up.");
   return 1;
}
