#include <const.h>

string query_action_name() {
   return "Butcher";
}

int main( string param ) {
   object ob;

   if( !param )
      return notify_fail( "Butcher what?\n" );

   if ( sizeof(filter( all_inventory(this_player()), (: (HAS_ASPECT($1, C_KNIFE) || HAS_ASPECT($1, C_DAGGER) || HAS_ASPECT($1, C_DIRK)) && $1->query_held() :) )) == 0 )
     return notify_fail("What, with your teeth? You need to be holding a knife to do this correctly.\n");

   ob = single_present( param, environment(this_player()),
   (: !$1->query_is_player() &&
      $1->query_monster() &&
      $1->query_dead() :) );

   if( !ob )
      ob = single_present( param, environment(this_player()) );
   if( !ob )
      return notify_fail( "Hrm, I can't seem to find that.\n" );

   if( ob->query_is_player() )
      return notify_fail("We don't support cannibalism here... Freak!\n");

   if( !ob->query_monster() )
      return notify_fail("Don't even go there. You know you can't butcher that. \n");

   if( !ob->query_dead() )
      return notify_fail( "You attempt to butcher " + ob->query_name() + ", but it seems to be suffering from a severe case of 'alive'.\n" );

   if( !ob->query_product_aspect() )
      return notify_fail( "Hmm... that's odd. This object does not support the new butchering system. If you believe it should, please inform an admin or use the 'bug' command to report it.\n");

   WALK_ACTION( 1100, ob );

   return 1;
}

void on_action( object ob ) {
   object meat_ob, knife, *knives;

   if( !ob || environment(ob) != environment(this_player()) ) {
      msg( "It appears that the object of your butchering is no longer present." );
      return;
   }

   knives = filter( all_inventory(this_player()), (: (HAS_ASPECT($1, C_KNIFE) || HAS_ASPECT($1, C_DAGGER) || HAS_ASPECT($1, C_DIRK)) && $1->query_held() :) );
   if( sizeof(knives) == 0 ) {
      msg( "Something appears to have happened to your knife... curious.");
      return;
   } else {
      knife = knives[0];
   }

   if( !ob->query_product_aspect() ) {
      msg( "This object does not support the butchering system, if you believe that this is an error, report the bug, please." );
      return;
   }
   if( !ob->query_product_quantity() ) {
      destruct( ob );
      msg( "Hmm... there's really nothing else left to this corpse." );
      return;
   }

   if( this_player()->query_stance() != ST_SITTING )
      this_player()->set_stance(ST_SITTING);

   meat_ob = ob->on_butcher();
   if (meat_ob) {
      meat_ob->move( this_player() );
      set_target(ob);
      this_player()->msg_local( "~CACT~Name ~verbcarve " + meat_ob->query_specific() + " from ~targ.~CDEF" );
      knife->add_condition(-1);
   } else {
      // failed carvings hurt the knife more than successes do
      knife->add_condition(-3);
	  // only practice knife skill on failed uses
      this_player()->practice_skill( "combat.weapon.dagger" );
   }
   this_player()->add_readiness( -250 );

   if ( ob->query_product_quantity() ) {
      if ( !knife || knife->query_broken() ) {
         this_player()->add_readiness( -100 );
         if ( sizeof(knives) > 1 ) {
           msg("You continue butchering the corpse after switching knives.");
         } else {
           msg("Since your knife is broken, you stop working on the corpse.");
           return;
         }
      }
      this_player()->set_action( -1, ({ 1000, this_object(), ob, ST_SITTING, 0 }) );
   } else {
      set_target(ob);
      this_player()->msg_local( "~CACT~Name ~verbfinish working on ~targ.~CDEF" );
      destruct(ob);
   }
}
