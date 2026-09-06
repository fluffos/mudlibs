/** Use this component by typing
 *
 * #include <container.h>
 *
 * at the top of your source code file. You should include this
 * for any object that needs to be able to hold other objects.
 * This file is not sufficient for objects that need to open and
 * close. For those objects, look at the Lid component.
 */

/// The message given when removal is forbidden
string prevent_remove,
/// The message given when insertion is forbidden
       prevent_insert,
/// The message given when the container's bulk limit is exceeded
       bulk_message,
/// The message given when the container's weight limit is exceeded
       weight_message;

/// The maximum amount that this container may hold, in cubic centimeters.
int bulk_capacity;
/// The maximum amount of weight that this container may carry, in grams.
int weight_capacity;

/// Used by the object editor.
string container_info() {
   return "prevent_remove\nprevent_insert\nbulk_nmessage\nweight_message\nbulk_capacity\nweight_capacity";
}

/** \return True, indicating that this object is a container.
 */
int query_container() {
   return 1;
}

/** \param ob Not used by the standard implementation given here.
 * This parameter is to make it easy to override this funtion in
 * child objects, and write a more discerning version that allows
 * you to pick and choose which objects to allow for removal.
 *
 * \return 0, if it is okay to remove things from this container,
 * and a message explaining why the object cannot be removed otherwise.
 */
string query_prevent_remove( object ob ) {
   return prevent_remove;
}

/** \param ob The object you are attempting to insert. Its weight
 * and bulk will be checked. The simplest way to give weight and
 * bulk to an object is using the Item component.
 *
 * \return 0, if it is legal to put things into this container,
 * and a message explaining why insertion is illegal otherwise.
 * If a weight or bulk constraint is violated, then the weight_message
 * or bulk_message is returned. If prevent_insert is set, then
 * that message is always returned, regardless of other constraints.
 */
string query_prevent_insert( object ob ) {
   if( prevent_insert ) return prevent_insert;
}

/** \return The message given when the player attempts to insert an
 * overly large object.
 */
string query_bulk_message() { return bulk_message; }

/** \return The message given when the player attempts to insert an
 * overly heavy object.
 */
string query_weight_message() { return weight_message; }

/** \return The capacity of this object to hold weight, in grams.
 */
int query_weight_capacity() { return weight_capacity; }

/** \return The capacity of this object to hold bulk, in cubic centimeters.
 */
int query_bulk_capacity() { return bulk_capacity; }

int query_weight_used() {
	int total = 0;
	object ob;
	foreach( ob : deep_inventory(this_object()) )
		total += ob->query_weight();
	return total;
}

int query_bulk_used() {
	int total = 0;
	object ob;
	foreach( ob : deep_inventory(this_object()) )
		total += ob->query_bulk();
	return total;
}

int query_bulk_free() { return query_bulk_capacity() - query_bulk_used(); }
int query_weight_free() { return query_weight_capacity() - query_weight_used(); }

/** \param s Pass in 0 if you want to allow removing objects from
 * this container, and a string giving a message to print to the player
 * if you wish removal to be illegal. When they try and remove something
 * from the container, they will receive the message.
 */
void set_prevent_remove( string s ) {
   prevent_remove = s;
}

/** \param s Pass in 0 if you want to allow insertion into this container,
 * otherwise pass in the message which you wish to print when a player
 * attempts an insertion.
 *
 * If you want to have more complicated insertion logic than simply
 * checking weight/bulk and this flag, then you should override query_prevent_insert()
 * in an inheriting object.
 */
void set_prevent_insert( string s ) {
   prevent_insert = s;
}

/** \param s The message to display when this container runs out of
 * space for more objects, and someone tries to put one in.
 */
void set_bulk_message( string s ) {
   bulk_message = s;
}

/** \param s The message to display when this container runs out of
 * weight capacity for more objects, and someone tries to put something in.
 */
void set_weight_message( string s ) {
   weight_message = s;
}

/** \param n The new bulk capacity for this object in cubic centimeters.
 */
void set_bulk_capacity( int n ) {
   bulk_capacity = n;
}

/** \param n The new weight capacity for this object in grams.
 */
void set_weight_capacity( int n ) {
   weight_capacity = n;
}

/** A default implementation for mixing the contents of a container.
 * Great for recipes.
 */
int on_mix() {
   return "/daemon/recipe"->mix_contents( this_object() );
}

/** \return True if any of the CONTENTS are drinkable.
 */
int query_is_drinkable() {
   object ob;

   foreach( ob : all_inventory() )
      if( ob->query_is_drinkable() ) return 1;

   return 0;
}

/** Tries to consume something from the contents of this object.
 */
int on_consume( int max ) {
   object ob, *drinkable;
   int res;

   drinkable = filter( all_inventory(), (: $1->query_is_drinkable() :) );
   if( !sizeof(drinkable) ) return 0;
   if( max > sizeof(drinkable) )
      max /= sizeof(drinkable);
   else
      max = 1;
   foreach( ob : drinkable )
      res |= ob->on_consume( max );
   return res;
}
