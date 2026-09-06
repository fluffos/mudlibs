/** A simple component that allows this object to be embedded
 * in another -- essentially, it just tracks a 'host' object.
 * You will probably need to implement other functionality yourself.
 */

void set_host( object x ) {
   this_object()->set_var("host", to_objectref(x));
}

object query_host() {
   if( !symbolp(this_object()->query_var("host")) )
      return 0;
   return find_objectref( this_object()->query_var("host") );
}
