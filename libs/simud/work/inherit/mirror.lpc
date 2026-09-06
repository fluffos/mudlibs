/** Mirror objects are designed to act as slaves to a more complex 'master' object.
 * A good example of this is doors -- you have two doors, one in each room, but
 * one should be slave to the other. The simpler, slave door stores only those attributes
 * which should uniquely belong to it, and all other requests for information are passed
 * to the master door. This lets you cache things such as whether the door is open/closed,
 * locked, etc.
 */

/// Stores the master object. Should survive a reboot, though won't work for non-saveload stuff too well.
symbol master_ob;

/// \return The master object that this mirror is slaved to, as an object pointer.
object query_master_ob() {
   return find_objectref( master_ob );
}

/// Give it an object pointer, and this object will start mirroring that object.
void set_master_ob( object ob ) {
   master_ob = to_objectref( ob );
}

/// The magic that makes the mirror work. Pass calls through the master object.
int catch_call( mixed result, string func, varargs args ) {
   object ob = query_master_ob();
   if( !ob ) return 0;
   result = apply( #'call_other, ob, func, args );
   return 1;
}

int query_is_mirror() {
   return previous_object() == query_master_ob();
}
