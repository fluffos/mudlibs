#include <const.h>
#include <const/battconst.h>

string query_action_name(mixed *action) {
   return "Milk";
}

int main(string arg) {
   object cow, bucket;
   string cowname, bucketname;

   if( sscanf(arg,"%s into %s",cowname,bucketname) != 2 )
      return notify_fail("Syntax: milk cow into bucket.\n");

   cow = single_present(cowname, environment(this_player()));
   if( !cow )
      return notify_fail("I can find no such '"+cowname+"' to milk here.\n");
   if( !present_clone("/ai/milkable",cow) )
      return notify_fail("Try as you might, you cannot figure out how to milk that.\n");

   bucket = single_present(bucketname, this_player());
   if( !bucket )
      return notify_fail("You don't seem to be holding any such '"+bucketname+"'.");
   if( !bucket->query_bulk_capacity() )
      return notify_fail("That doesn't seem to be a suitable container.");

   WALK_ACTION_PARAM( 1500, cow, bucket );
   return 1;
}

void on_action(object cow, object bucket) {
   object ai = present_clone("/ai/milkable",cow);
   set_target(cow);
   set_actor(this_player());
   if( !ai->query_milk() ) {
      this_player()->msg_local("~CACT~Name ~verbattempt to milk ~targ but ~verbis unceremoniously dumped on ~poss can.~CDEF");
      msg("There is no milk to be had. ~Targ is currently quite dry.");
      this_player()->set_stance( ST_LYING );
      this_player()->add_readiness( -500 );
   } else {
      // go ahead and throw the event in case we ever want to do stuff that way
      if( !ai->on_milk() ) {
         int train_check = this_player()->skill_check("craft.animal_training",25,50,75,80,90,100);
         int farm_check = this_player()->skill_check("craft.farming",25,50,75,80,90,100);
         int quantity = 50 + 25 * train_check + 10 * farm_check;
         int waste;
         object milk = clone_object("/items/drink/milk");
         // set milk type
         milk->apply_aspect( cow->query_product_aspect() ); // doesn't do anything yet
         milk->set_quantity( quantity );
         waste = quantity - bucket->query_weight_free();
         // do the milking
         ai->add_milk(-1);
         this_player()->add_readiness( -(800 + quantity) );
         this_player()->msg_local("~CACT~Name ~verbattempt to milk ~targ into ~poss "+bucket->query_name()+".~CDEF");
         this_player()->msg_local("~CACT~Name ~verbcoerce "+milk->query_distant()+" from ~targ.~CDEF");
         if( waste > 0 ) {
            this_player()->msg_local("~CBRTThe excess milk sloshes onto the ground.~CDEF");
            milk->add_quantity( -waste );
         }
         milk->move( bucket );
      }
   }
}
