#include <emote.h>

string query_cself() {
   return "~Name ~verblook for someone to tickle.@@looking for someone to tickle.";
}

string query_ctarget() {
   return "~Name ~verbtickle ~targ.@@tickling ~targ.";
}

main( param ) {
   object *tlist, t, victim;
   int attribute;
   string doing, self, target;

   string ctarget = query_ctarget();
   string cself = query_cself();

   if( param ) {
      tlist = all_present(param, environment(this_player()), (: $1->query_distant() :));
      if( (!tlist || !sizeof(tlist)) )
         tlist = all_present(param, this_player(), (: $1->query_distant() :));
      if( !tlist || !sizeof(tlist) )
         return notify_fail("Nothing here to tickle matching '"+param+"'.\n");

      foreach( t : tlist ) {
         if(!t->query_distant())
           continue;

         set_target(t);
         if( sscanf(ctarget, "%s@@%s", target, doing) == 2 )
            this_player()->set_doing( doing, t );
         else target = ctarget;
         this_player()->msg_local(EMOTE_COLOR+target+"~CDEF");
         victim = t;
         t->on_tickle();
      }
   }
   else {
      if( sscanf(cself, "%s@@%s", self, doing) == 2 )
         this_player()->set_doing( doing );
      else self = cself;
      this_player()->msg_local(EMOTE_COLOR+self+"~CDEF");
   }
   if( attribute = this_object()->query_emote_attribute() )
      foreach( t : all_inventory(environment(this_player())) )
         if( t->query_is_living() && t != this_player() )
            t->on_soul( attribute, victim, this_player(), query_verb() );
   return 1;
}

EMOTE_ATTRIBUTE( ATT_PHYSICAL | ATT_FOOLISH )
		
