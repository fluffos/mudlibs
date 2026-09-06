#include <const.h>

/** This object is used to store quantities. If you're using all_present()
 * for identifying objects, it will be able to split up quantifiable
 * objects into distinct parts (for example, you might use this for
 * coins; then, 'get five coins' from a pile of ten should make two
 * piles of five coins).
 *
 * There is one rather awkward difficulty in dealing with quantity objects --
 * all_present() may be used to split them apart in order to make
 * usable units for a player action. However, if the action does not
 * trigger immediately, it is possible for the quantity to recombine
 * and thus cause you to, for example, drop ALL your apples, instead
 * of just the three that you said you wished to. For this reason, you
 * may 'lock' a quantity object in its split state by giving it a pointer
 * to the player who wishes to operate on it (ob->set_player_lock).
 * The object will remain locked until either is moved or the player
 * in question's action queue is clear.
 *
 * \warn If the quantity is greater than 1 when you edit the object,
 * modified descriptions may be clobbered when the quantity is reset to
 * 1.
 */

/// The stored quantity
int quantity;

mapping *qvars;

/// A pointer to the player locking this quantity object as separate
nosave object player_lock;

/** Sets the quantity of this item. This is generally insufficient for
 * a well-behaved item, but you will need to override the behavior
 * you want to change. New query_distant and query_specific functions
 * are generally a good idea.
 */
varargs void set_quantity( int x, mixed *new_qvars ) {
   quantity = to_int(floor(x));
   if( new_qvars ) {
      if( sizeof(new_qvars) == quantity )
         qvars = new_qvars;
      else
         debug("Used set_quantity with a mis-sized new_qvars array: " + x + " and arr is " + as_lpc(new_qvars));
   }
   if( qvars ) {
      if( sizeof(qvars) >= 1 ) {
         // This is lazy. Could be more efficient w/ memory but whatever.
         while( sizeof(qvars) < quantity ) qvars += qvars;
         // Note: returns empty array of quantity = 0, this is
         // deliberate.
         if( sizeof(qvars) > quantity ) qvars = qvars[..quantity-1];
      }
      else {
         // No sample var maps to duplicate to set the new quantity (old
         // one was 0), so just throw in 0's.
         qvars = allocate(quantity);
      }
   }
}

void set_player_lock( object player ) {
   player_lock = player;
   call_out( "clear_player_lock", 8 );
}

void clear_player_lock() {
   if( objectp(player_lock) &&
      sizeof(player_lock->query_actions()) ) {
     call_out( "clear_player_lock", 8 );
   }
   else {
      call_out("combine_check", 0);
      player_lock = 0;
   }
}

object query_player_lock() {
   return player_lock;
}

varargs void add_quantity( int x, mixed *new_qvars ) {
   // Simple case
   if( x <= 0 || !pointerp(new_qvars) )
      set_quantity( quantity + x );
   else {
      if( sizeof(qvars) + sizeof(new_qvars) == quantity + x ) {
         quantity += x;
         if( qvars )
            qvars += new_qvars;
         else
            qvars = new_qvars;
      }
      else {
         set_quantity( quantity + x );
         // The sizeof the two qvar arrays didn't match. Please
         // hang up and try again. Program tries to resist failure,
         // but is going to lose some vars now.
         debug( "Incorrect use of add_quantity; array size mismatch. Check /log/qbug for details." );
         log_file( "qbug", "Quantity bug. The qvars is: " + as_lpc(qvars) + ", the new_qvars is: " + as_lpc(new_qvars) + ", quantity is " + as_lpc(quantity) + ", x is " + as_lpc(x) + "\n" );
      }
   }
}

/// \return The quantity of this item
int query_quantity() {
   return quantity;
}

/** \return The maximum quantity that fits within the weight \a w.
 * For example, if w is 550, and this object weighs 100 per unit,
 * The most you can carry is 5 units at 100 each. This function will
 * return 5 in that case. The maximum value that will be returned
 * is the actual quantity of this object.
 *
 * Generally, you call this function to figure out what value to
 * use for split_quantity when picking up part of a large pile.
 */
int get_weight_quantity( int w ) {
   if( w < 0 ) return 0;
   // This, along with the previous line, guarantees no divide by 0...
   if( this_object()->query_weight() * quantity <= w ) return quantity;
   return w / this_object()->query_weight();
}

/// A messy function that cuts this object into distinct parts. Very yucky.
// gp:  Now returns the object that was split off.
object split_quantity( int new_quantity ) {
   object new_ob;

//   debug("split_quantity called.");
   if( new_quantity >= quantity ) return 0;
   new_ob = clone_object( load_name(this_object()) );
   new_ob->move( environment(this_object()) );
   this_object()->save_self();
   new_ob->load_template( "/secure/odin"->get_save_file_name(this_object()->query_unique_id()) );
   // Give it a qvars array.
   if( pointerp(qvars) ) {
      new_ob->set_quantity( quantity - new_quantity, qvars[new_quantity..] );
      set_quantity( new_quantity, qvars[..<quantity - new_quantity + 1] );
   }

   else {
      new_ob->set_quantity( quantity - new_quantity );
      set_quantity( new_quantity );
   }
   new_ob->on_split(this_object());
   return new_ob;
}

void combine_check() {
   object ob;
   string qualified_name;

   qualified_name = load_name(this_object()) + ":" + this_object()->query_name();

   if( !environment(this_object()) )
      return;
   foreach( ob : all_inventory(environment(this_object())) )
   if( ob != this_object() &&
      load_name(ob) + ":" + ob->query_name() == qualified_name &&
      (!environment()->query_has_map() || this_object()->query_coord() == ob->query_coord()) &&
      !player_lock && !ob->query_player_lock() ) {
      ob->add_quantity( quantity, qvars );
      destruct(this_object());
      return;
   }
}

mapping *query_qvars() {
   return qvars;
}

mapping *set_qvars( mapping *x ) {
   return qvars = x;
}

mixed query_qvar( string var, int index ) {
   if( !qvars ) return 0;
   if( index >= quantity || index < 0 ) return 0;
   if( !mappingp(qvars[index]) ) return 0;
   return qvars[index][var];
}

void set_qvar( string var, mixed val, int index ) {
   if( index == -1 ) {
      int i;
      for( i = 0; i < quantity; i++ )
         set_qvar(var,val,i);
      return;
   }
   if( index >= quantity || index < 0 )
      return 0;
   if( !qvars || sizeof(qvars) != quantity )
      qvars = allocate(quantity);
   if( !mappingp(qvars[index]) )
      qvars[index] = ([ var: val ]);
   else
      qvars[index][var] = val;
}


/** Used for combining objects together ... actually does this on a delayed
 * function call, so you'll have about two seconds with the objects uncombined
 * (unless something else calls combine_check() earlier). If you override the
 * on_move event, objects will not recombine! This function is also used
 * to clear player_lock, which is documented in the object description.
 */
void on_move( object src ) {
   quantity = to_int(floor(quantity));
   call_out("combine_check", 0);
   player_lock = 0;
}

int query_is_quantity() {
   return 1;
}
