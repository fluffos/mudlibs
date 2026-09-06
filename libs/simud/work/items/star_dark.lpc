#include <const.h>
#include <item.h>
#include <desc.h>
#include <saveload.h>
#include <object.h>

create () {
   ::create();
}

   DISTANT("a dark star")
   ALT_NAME( ({"dark star"}) )
   SPECIFIC("the star")
   PLURAL("dark stars")
   NAME("star")
   LOOK( "A rare and powerful object most likely created "+
         "by The Dark Mages. You could ~CCOMuse~CDEF this on "+
         "someone, probably to their great consternation." )
   GETTABLE(1)
   DROPPABLE(1)
   WEIGHT(2000)
   BULK(1)
   VALUE(1000)
   ALT_PLURAL( ({ "stars" }) )
   TASTE( "It tastes like glass!" )

varargs int on_use(object who) {
   if (!who)
      who = this_player();
   set_actor(this_player());
   set_target(who);

   if ( !who->query_is_living() ) {
      msg("Throwing this at inanimate objects is pointless.");
      return 1;
   }

   if ( who == this_player() ) {
      msg("Not gonna do it. Wouldn't be prudent.");
      return 1;
   }

   this_player()->msg_local("~CDRK~Name ~verbthrow a dark star at ~targ!~CDEF");
   msg_object(who, "~CWRN5 Mana depleted by dark star.~CDEF");

   if ( who->query_mana() > 5 ) who->set_mana( who->query_mana()-5 );
   else who->set_mana( 0 );

   this_player()->add_readiness(-300);
   destruct( this_object() );

   return 1;
}
