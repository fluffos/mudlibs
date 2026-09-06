/** This is a file which can give your object a value, the ability to be
 * picked up, weight/bulk and dimensions. The units are: centimeters,
 * grams, and cubic centimeters. To go from inches to centimeters, multiply
 * by 2.54. To go from pounds to grams, multiply by 450. To go from cubic
 * feet to cubic centimeters, multiply by 28,000.
 *
 * The value is in the smallest possible coin available on your mud --
 * think of one-cent pieces.
 */

#include <const.h>
#include <coord.h>

// Prototypes
void set_bulk( int n );
void set_weight( int n );
int query_bulk();
void set_value( int n );
int query_value();

/// An item's statistics
//int weight;
int height, value;

/// Information used by the object editor.
item_info() {
   return "gettable\ndroppable\nholdable\nheight\nweight\nbulk\nvalue\nkept\nmaterial";
}

/// \return True, if this item may be dropped, false otherwise.
int query_droppable() {
   QBODY( "droppable", this_object()->query_default_droppable() );
}

/// \param n If 0, this item is undroppable, otherwise it's droppable.
void set_droppable(int n) {
   SBODY( "droppable", n );
}

/// \return True, if this item may be picked up or received, false otherwise.
int query_gettable() {
   QBODY( "gettable", this_object()->query_default_gettable() );
}

/// \param n If 0, this item is ungettable, otherwise it's gettable.
void set_gettable(int n) {
   SBODY( "gettable", n );
}

/// \return True, if this item may be equipped by holding.
int query_holdable() {
   QBODY( "holdable", this_object()->query_default_holdable() );
}

/// \param n If 0, this item is unholdable, otherwise it's holdable.
void set_holdable(int n) {
   SBODY( "holdable", n );
}

/// \return The body part that is holding this item.
int query_held() {
   QBODY( "holding", 0 );
}

/// \param x The particular body part (hand) being used to hold this item.
void set_held(int x) {
   if( query_held() && !x )
      this_object()->on_unhold();
   if( x )
      this_object()->on_hold(x);
   SBODY( "holding", x );
}

/// \return The height in centimeters of this object.
int query_height() {
   return height;
}

/// \param n The new height, in centimeters, for this object
void set_height(int n) {
   height = n;
}

/// \return The weight of the *contents* of this object.
int query_held_weight() {
   object ob;
   int w = 0;

   foreach( ob : all_inventory(this_object()) )
      w += ob->query_total_weight();
   return w;
}

/// \return The bulk of the *contents* of this object.
int query_held_bulk() {
   object ob;
   int w = 0;

   foreach( ob : all_inventory(this_object()) )
      w += ob->query_bulk();
   return w;
}

/// \return The weight, in grams, of this object.
int query_weight() {
   QBODY( "weight", this_object()->query_default_weight() );
}

/// \return The object's weight in POUNDS.
int query_us_weight() {
   // Written to avoid undue loss of accuracy without using floats.
   return (query_weight() / 100) * 22 / 100;
}

/** \return The total weight, in grams, of this object. This
 * includes both the weight of this object and of all objects
 * contained inside of it.
 */
int query_total_weight() {
   return query_weight() + query_held_weight();
}

/// \param n The new weight (mass, really), in grams, for this object
void set_weight(int n) {
   SBODY( "weight", n );
   if(!query_height() && !query_bulk()) {
      set_height( n / 10 + 1 );
      set_bulk( query_weight() );
   }
}

/** \return The bulk, in cubic centimeters, of this object. This assumes
 * "stiff" bulk, so that if this item is a container, its bulk does not increase
 * when you put things in. For "flexible" bulk, where the bulk increases as you
 * add things, you should overrides this and add query_held_bulk() into the total.
 */
int query_bulk() {
   QBODY( "bulk", this_object()->query_default_bulk() );
}

/// \param n The new bulk, in cubic centimeters, for this object
void set_bulk(int n) {
   SBODY( "bulk", n );
}

/// \return The value, in the smallest unit of currency on the MUD, for this object
int query_value() {
   if( value ) { set_value(value); value = 0; }
   QBODY( "value", this_object()->query_default_value() );
}

/// \param n The new value, in the smallest unit of currency, for this object
void set_value(int n) {
   SBODY( "value", n );
   value = 0;
}

/** \return Whether or not the item is being "kept". Keeping an item is a
 * good way to prevent yourself from dropping it or giving it away by
 * accident. Players can toggle this via the keep and unkeep commands.
 */
int query_kept() {
   QBODY( "kept", 0 );
}

/// \param n 0 to unkeep the item. 1 to keep it. See query_kept().
void set_kept(int n) {
   SBODY( "kept", n );
}

varargs void damage_item(mapping wc, object other) {
   int me_damage = 0, o_damage = 0;
   string type;
   foreach (type : m_indices(wc)) {
      int dam = "/battle/battle"->wc_to_damage(wc[type]);
      o_damage += dam;
      switch (type) {
         case "fire":
         case "acid":
            if ( HAS_ASPECT(this_object(), C_CLOTH) ||
                 HAS_ASPECT(this_object(), C_PELT) ||
                 HAS_ASPECT(this_object(), C_PAPER) )
               me_damage += dam;
            else if (HAS_ASPECT(this_object(), C_WOOD) ||
                     HAS_ASPECT(this_object(), C_BONE) ||
                     HAS_ASPECT(this_object(), C_FOOD) )
               me_damage += dam / 2;
            else if (HAS_ASPECT(this_object(), C_STONE))
               me_damage += dam / 25;
            else
               me_damage += dam / 10;
            break;

         case "ice":
            if ( HAS_ASPECT(this_object(), C_GLASS) )
               me_damage += dam;
            else if ( HAS_ASPECT(this_object(), C_FOOD) ||
                      HAS_ASPECT(this_object(), C_LIQUID) )
               me_damage += dam / 25;
            else
               me_damage += dam / 10;
            break;

         case "electricity":
            if ( HAS_ASPECT(this_object(), C_METAL) ||
                 HAS_ASPECT(this_object(), C_LIQUID) )
               me_damage += dam;
            else if ( HAS_ASPECT(this_object(), C_STONE) )
               me_damage += dam / 25;
            else
               me_damage += dam / 10;
            break;

         default: {
            int new_dam = dam - "/battle/battle"->wc_to_damage(this_object()->query_ac(type));
            if (new_dam > 0)
               me_damage += dam / 10;
            break;
         }
      }
   }
   if (other) {
      if ( HAS_ASPECT(other, C_CLOTH) )
         o_damage = 0;
      else if ( HAS_ASPECT(other, C_FOOD) ||
                HAS_ASPECT(other, C_GLASS) ) {
         if ( HAS_ASPECT(this_object(), C_CLOTH) )
            o_damage /= 10;
         // otherwise, damage is maximum
      } else if ( HAS_ASPECT(this_object(), C_FOOD) ||
                  HAS_ASPECT(this_object(), C_GLASS) ) {
         o_damage /= 50;
      } else if ( HAS_ASPECT(other, C_STONE) ) {
         if ( HAS_ASPECT(this_object(), C_STONE) )
            o_damage /= 5;
         else if ( HAS_ASPECT(this_object(), C_METAL) )
            o_damage /= 25;
         else
            o_damage /= 50;
      } else if ( HAS_ASPECT(other, C_METAL) ) {
         if ( HAS_ASPECT(this_object(), C_METAL) ||
              HAS_ASPECT(this_object(), C_STONE) )
            o_damage /= 15;
         else
            o_damage /= 50;
      } else if ( HAS_ASPECT(other, C_WOOD) ||
                  HAS_ASPECT(other, C_BONE) ) {
         if ( HAS_ASPECT(this_object(), C_METAL) ||
              HAS_ASPECT(this_object(), C_STONE) )
            o_damage /= 5;
         else
            o_damage /= 10;
      } else {
   // case where two unidentified objects are whacking each other
        o_damage /= 10;
      }
      other->add_condition(-o_damage);
   }
   this_object()->add_condition(-me_damage);
}

/** The default on_get handler. It returns 0 (failure) if gettable is
 * false, and MOVE_OK_FLAG (success) if gettable is set. The parameter
 * is ignored. If you want something special to occur when you get an item, you
 * should override this function.
 */
int on_get( object actor ) {
   if( !query_gettable() )
      return 0;
   else
      return MOVE_OK_FLAG;
}

/** The default on_drop handler. It returns 0 (failure) if droppable is
 * false, and MOVE_OK_FLAG (success) if droppable is set. The parameter
 * is ignored. If you want something special to occur when you drop an item, you
 * should override this function. This function also implements the
 * item 'kept' semantics.
 */
int on_drop( object actor ) {
   if( !query_droppable() || query_kept() )
      return 0;
   else {
      if (this_object()->query_worn())
         return this_object()->remove_armour();
      return MOVE_OK_FLAG;
   }
}

/** The default on_give handler. It returns 0 (failure) if gettable or droppable is
 * false, and MOVE_OK_FLAG (success) if either is true. The parameter
 * is ignored. If you want something special to occur when you drop an item, you
 * should override this function. This function also implements the
 * item 'kept' semantics.
 */
int on_give( object actor ) {
   if( !query_droppable() || !query_gettable() || query_kept() )
      return 0;
   else {
      return MOVE_OK_FLAG;
   }
}

/** A default paint function for this object. You should override on_paint to
 * get ride of this. The default icon is simply an asterisk '*' at whatever
 * the object's position is.
 */
void on_paint( object painter ) {
   painter->paint( query_x(), query_y(), '*', 7, LAYER_ITEMS );
}

/** Returns whether or not this object is impossible for players to teleport.
 * A value of 0 means that the object may be ported. A value of 1 means that
 * the object is permanently prevented from teleportation, and a value of -1
 * means that teleportation is being temporarily prevented.
 */
void query_no_teleport() {
   return this_object()->query_var("no_teleport");
}

/// \param x 0 to allow teleportation, +/-1 to disallow teleportation
void set_no_teleport( int x ) {
   if (abs(x) > 1)
     x /= abs(x); // keeps flag in set [-1, 0, 1]
   this_object()->set_var("no_teleport",x);
}

_reset_item() {
   query_height(); query_bulk();
}

void set_material( string x ) {
   debug("set_material is deprecated, used in " + program_name(this_object()) + ". Please update code!");
}
