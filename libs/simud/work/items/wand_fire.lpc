#include <const.h>
#include <item.h>
#include <condition.h>
#include <saveload.h>
#include <magic.h>
#include <object.h>

create () {
   ::create();
   set_condition(query_max_condition());
}

   DISTANT("an ebony wand")
   ALT_NAME( ({"ebony wand"}) )
   SPECIFIC("the wand")
   PLURAL("ebony wands")
   NAME("wand")
   LOOK( "A small black wand. You could ~CCOMuse~CDEF this on "+
          "someone, probably to their great consternation." )
   GETTABLE(1)
   DROPPABLE(1)
   WEIGHT(200)
   BULK(1)
   VALUE(100)
   CONDITION(100)	// ~5 condition per charge
   ALT_PLURAL( ({ "wands" }) )
   TASTE( "It tastes like burning!" )

varargs int on_use(object who) {
   int cost;
   if (!who)
      who = this_player();
   set_actor(this_player());
   set_target(who);

   if (query_broken()) {
      msg("~CWRNYou cannot use a broken wand.~CDEF");
      return 1;
   }

   if ( !who->query_is_living() ) {
      msg("Attacking inanimate objects is pointless. Yay, you win.");
      return 1;
   }

   if ( environment(who) != environment(this_player()) &&
        environment(who) != this_player() ) {
      msg("You cannot blast ~targ from here.");
      return 1;
   }

   if ( who == this_player() ) {
      msg("Not gonna do it. Wouldn't be prudent.");
      return 1;
   }

   //I hate how Allaryin never removes debugging
   //debug( "wand xp = "+this_player()->query_skill_current_xp("magic.item.wand") );

   if( !this_player()->skill_check("magic.item.wand",10) ||
       !this_player()->skill_check("magic.mana.fire",10) ) {
      this_player()->add_readiness(-250);
	  this_player()->msg_local("[030~Name ~verbshake ~poss wand at ~targ, but nothing happens.~CDEF");
	  return 0;
   }

   cost = MAGIC_DAEMON->query_cost("fire",5);
   if (this_player()->query_mana() < cost) {
      notify_fail("You do not have enough mana ("+cost+") to use the wand.\n");
      return 0;
   }

   MAGIC_DAEMON->draw_mana(this_player(),"fire",5);
   this_player()->msg_local("~[030~Name ~verbshoot flame from ~poss wand at ~targ!~CDEF");
   this_player()->add_readiness(-500);

   // wand downgrade, part one, wc 8 -> 5
   who->take_damage( (["fire":5 + this_player()->skill_ckeck("magic.item.wand",25,50,75,100) ]) );

   //I hate how Allaryin never removes debugging
   //debug( "wand xp = "+this_player()->query_skill_current_xp("magic.item.wand") );

   // wand downgrade, part two, wands start combat ;)
   this_player()->start_combat(who);

   // wand downgrade, part three, wands break ;)
   add_condition(-cost / 2);

   return 1;
}

mapping query_aspects() {
   return ([ C_WAND, C_WOOD, C_APPLEWOOD ]);
}
