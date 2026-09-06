#include <battle.h>
#include <const/raceconst.h>

int *possible_hands = ({BP_LHAND,BP_RHAND,BP_LHAND2,BP_RHAND2});
string *wield_messages = ({ });

int hand_mask( int *hands ) {
   int x, total = 0;
   foreach (x : hands)
      total |= x;
   return total;
}

int *do_hold(object ob, string verb, int *hands) {
   int *l = ({}), x;
   if (!(x = ob->query_hands()))
      x = 1;
   while (sizeof(l) < x) {
      int q = hands[random(sizeof(hands))];
      if (member(l,q) == -1)
         l += ({q});
   }
   if (!ob->on_hold(hand_mask(l))) {
      //string buf = "~targ";
      string buf = ob->query_specific();
      if ( this_player()->query_bp_name(hand_mask(l)) )
         buf += " in ~poss "+this_player()->query_bp_name(hand_mask(l));
      ob->set_held(hand_mask(l));
      this_player()->recalc();
      set_target(ob);
      wield_messages += ({ buf });
   }
   return l;
}

int main( string param ) {
   object *list, ob, *held = ({});
   int *hands = ({}), thand, x, *l;
   string target, verb = query_verb(), old_form = this_player()->query_form();

   // My biggest objection to this verb is that it was so SPAMMY. So I've
   // changed it around a bit. It still has all the old messages, but it
   // chucks out redundant or unnecessary ones. It stacks up all the diagnostics
   // as it goes along, but doesn't message until the END, and does so in an
   // order that doesn't have to be tied to code flow.
   string error_message = 0;
   object *unwield_objects = ({ });
   wield_messages = ({ });

   if( !param ) {
      msg("What would you like to "+verb+"?");
      return 1;
   }

   if( sscanf(param,"%s in %s",param,target) == 2 )
      msg("You don't get to pick which hand you "+verb+" something in yet ;P");

   list = all_present(param, this_player(), (: !$1->query_broken() :) );
   if (!list)
      list = all_present(param, this_player() );

   if (!list)
      return notify_fail("You have nothing of the sort!\n");

   if (thand)
      hands = ({thand});
   else {
      foreach ( x : possible_hands )
         if (this_player()->query_has_bp(x))
            hands += ({ x });
   }

   set_actor(this_player());

   //unhold all weapons
   foreach( ob:all_inventory(this_player()) )
   if( ob->query_held() ) {
      ob->set_held( 0 );
      held += ({ ob });
   }

   unwield_objects += held;

   foreach( ob: list ) {
      if ( !sizeof(hands) || (ob->query_hands() > sizeof(hands)) ) {
         msg("You don't have enough free hands! You wield as much of it as possible.");
         this_player()->adopt_best_form();
         return 1;
      }
      if (ob->query_weapon())
         verb = "wield";
      else
         verb = "hold";
      if (ob->query_held()) {
         error_message = "You are already " + verb + "ing "+ob->query_specific() + "!";
         list -= ({ ob });
      } else if( environment(ob) != this_player() || !ob->query_name() )
        list -= ({ ob });
      else if( !ob->query_holdable() ) {
        error_message = "You cannot figure out a way to effectively " + verb + " "+ob->query_specific() + ".";
        list -= ({ ob });
      } else if (ob->query_broken()) {
         // Give a cuter message if it's *obviously* broken.
         if( strstr(ob->query_specific(), "broken") )
            error_message = capitalize(ob->query_specific()) + " is, well, broken.";
         else
            error_message = capitalize(ob->query_specific()) + " is broken!";
         list -= ({ ob });
      } else {
         l = do_hold(ob, verb, hands);
         if (!ob->query_held())
            list -= ({ob});
         else
            hands -= l;
      }
   }

   // make sure that the player's form works with their current weapons...
   string best_form = this_player()->get_best_form();
   if( !best_form ) {
      // Unhold all weapons
      wield_messages = ({ });
      error_message = "You don't know any forms that use " + inventory_string(list) + ".";
      foreach( ob:all_inventory(this_player()) )
         if( ob->query_held() && !ob->query_cursed() ) {
            ob->set_held( 0 );
         }

      best_form = this_player()->get_best_form();
      if( !best_form ) {
         this_player()->add_form( "brawl" );
         best_form = "brawl";
      }
   }

   if( sizeof(unwield_objects) && !sizeof(wield_messages) )
      this_player()->msg_local("~CACT~Name ~verbstop "+verb+"ing " + inventory_string(unwield_objects) + ".~CDEF");
   if( sizeof(wield_messages) )
      this_player()->msg_local( "~CACT~Name ~verb" + verb + " " + comma_list(wield_messages) + ".~CDEF" );

   if( !sizeof(wield_messages) && error_message )
      msg( error_message );

   if( best_form != old_form ) {
      this_player()->set_form( best_form );
      this_player()->msg_local( "~CACT" + this_player()->query_form_object()->query_change_message() + "~CDEF" );
   }

   return 1;
}
