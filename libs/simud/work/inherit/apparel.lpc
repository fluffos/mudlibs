#include <const/raceconst.h>

/** Used for items of clothing or apparel. Need more docs here...
 */

int worn;           ///< 1 if worn
int flexible;       ///< whether or not the item can bend
int size;           ///< 0..50 (humans can wear sizes 12..28)
int body_parts;     ///< body parts covered by this item
int layer;          ///< which layer this item is being worn on

/// Object editor information.
string apparel_info() {
  return "flexible\nsize\nbody_parts";
}

/****************************** Queries ****************************/

// Prototype
int query_worn();
varargs int remove_armour(int silent);

int query_flexible() {
   QBODY( "flexible", this_object()->query_default_flexible() )
}

int query_size() {
   QBODY( "size", this_object()->query_default_size() )
}

int query_worn() {
   if (environment() && !environment(this_object())->query_is_living())
      worn = 0;
   return worn;
}

int query_body_parts() { QBODY( "body_parts", this_object()->query_default_body_parts() ) }

int query_layer() {
   if (!worn && layer)
      layer = 0;
   return layer;
}

/******************************* Sets *******************************/


void set_worn(int x) {
  if (x == 1 || x == 0)
    worn = x;
}

void set_flexible(int x) {
   SBODY( "flexible", x )
}

void set_size(int x) {
   SBODY( "size", x )
}

void set_body_parts(int x) { SBODY( "body_parts", x ) }

void set_layer(int x) { layer = x; }

/****************************** Other *******************************/

varargs int wear_armour(int silent) {
   object owner = environment(this_object());
   object obj;
   int tlayer = 0;
   set_target(this_object());
   if (worn) {
      if (!silent)
         msg("You are already wearing ~targ!");
      return 0;
   }
   if (!owner->query_is_living())
      return 0;
   if (!owner->query_has_bp(query_body_parts())) {
      if (!silent)
         msg("You lack the required appendages to wear ~targ!");
      return 0;
   }

   // returns non-zero if base requirements are not met
   if (this_object()->query_requirements_met(this_player()) != 0)
      return 0;

   if (this_object()->query_broken()) {
      if (!silent)
         msg("You can't wear ~targ, it's broken!");
      return 0;
   }
   //debug("size = "+query_size()+", flex = "+query_flexible());
   // check if they're wearing anything already
   foreach ( obj : all_inventory(owner) ) {
      if (obj->query_is_apparel() && obj->query_worn()) {
         if (obj->query_body_parts() & query_body_parts()) {
            int osize = obj->query_size();
            int oflex = obj->query_flexible();
            int ocloth = obj->query_cloth();
            int small;

            if (ocloth) {
               if (oflex && osize > query_size()) {
                  // flexible cloth
                  small = 1;
            } else if (!oflex && osize > query_size() - 3) {
                  // rigid cloth
                  small = 1;
               }
            } else {
               if (oflex && osize > query_size() - 5) {
                  // flexible metal (example: chainmail)
                  small = 1;
               }

               // can't wear rigid clothing over other rigid clothing.
               if (!oflex && !query_flexible()) {
                  small = 1;
               }
            }
            if (small) {
               msg("You can't wear ~targ over your "+obj->query_name()+".");
               return 0;
            }
            if (obj->query_layer() > tlayer)
               tlayer = obj->query_layer();
         }
      }
   }
   layer = tlayer + 1;
   // returns true if on_wear() has been defined, so false means we need
   // to manually wear the item for them
   if (this_object()->on_wear() == 0) {
      if (!silent) {
         owner->msg_local("~Name ~verbwear ~targ.");
      }
      set_worn(1);
      owner->recalc();
      return 1;
   }
}

varargs int remove_armour(int silent) {
   object owner = environment(this_object()), obj;
   if (!worn)
      return 0;
   if (!owner->query_is_living())
      return 0;
   set_target(this_object());
   // check if they're wearing anything over this item
   foreach ( obj : all_inventory(owner) ) {
      if( obj->query_is_apparel() &&
         (obj->query_body_parts() & query_body_parts()) &&
         obj->query_layer() > layer) {
         if( !silent )
           msg("You can't remove ~targ, without first removing "+obj->query_name()+".");
         return 0;
      }
   }
   // returns true if on_remove() has been defined, so false means we have
   // to do this our selves as well
   if (this_object()->on_remove() == 0) {
      if (this_object()->query_cursed()) {
         if (!silent)
            msg_object(owner,"You can't remove ~targ! It appears to be cursed!");
      } else {
         if (!silent)
            owner->msg_local("~Name ~verbremove ~targ.");
         set_worn(0);
         owner->recalc();
         return 1;
      }
   }
}

/// \return True, indicating that this object is apparel.
int query_is_apparel() {
   return 1;
}

/// Have to take things off to drop them
int on_drop( object who ) {
   if (this_object()->query_worn())
      return this_object()->remove_armour();
   return 1;
}

/* Prevent stupid items from magically being worn if somehow flagged as worn
 * by their container.
 */
int on_get( object who ) {
   int gettable = this_object()->query_gettable();
   if(gettable && this_object()->query_worn())
      this_object()->set_worn(0);
   return gettable;
}
