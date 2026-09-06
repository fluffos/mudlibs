#include <item.h>
#include <condition.h>
#include <saveload.h>
#include <magic.h>
#include <object.h>

TASTE( "It tastes like magical fairy dust." )

create() {
   ::create();
   set_distant("a Fairy wand");
   set_alt_name( ({ "healing wand", "wand", "fairy wand", "Fairy wand" }) );
   set_specific("the Fairy Wand");
   set_plural("Fairy Wands");
   set_name("fairy wand");
   set_look( "This white, wooden wand has a gold-painted star on the end, and a few pink silk ribbons hanging from it.");
   set_gettable(1);
   set_droppable(1);
   set_weight(200);
   set_bulk(1);
/*
   set_wc( (["blunt":1]) );
   set_weapon_type("mace");
   set_type("weapon");
*/
   set_value(12000);
   set_max_condition(100);
}

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

   if ( environment(who) != environment(this_player()) &&
        environment(who) != this_player() ) {
      msg("You cannot blast ~targ from here.");
      return 1;
   }

   cost = MAGIC_DAEMON->query_cost("mana",4);
   if (this_player()->query_mana() < cost) {
      notify_fail("You do not have enough mana ("+cost+") to use the wand.\n");
      return 0;
   }
   MAGIC_DAEMON->draw_mana(this_player(),"mana",4);
   if(this_player()!=who)
   {
      this_player()->msg_local("~CACT~Name ~verbwave ~poss wand elaborately, and a ray of warm light engulfs ~targ. ~Targ ~vertis healed!~CDEF");
   }
   else if(this_player()==who)
   {
      this_player()->msg_local("~CACT~Name ~verbwave ~poss wand elaborately at ~targ, and ~prot ~vertis healed!~CDEF");
   }
   add_condition(-cost);
   who->add_hp(10);
   this_player()->add_readiness(-1000);
   return 1;
}
