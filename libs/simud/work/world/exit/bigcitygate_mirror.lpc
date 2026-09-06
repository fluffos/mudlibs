#include <coord.h>
#include <shape.h>
#include <mirror.h>
inherit "/world/exit/twoway";

int exit_action() {
   if( !query_master_ob() ) return 0;
   return query_master_ob()->exit_action();
}

object id( string param ) {
   if( param == query_name() ) return this_object();
   if( query_master_ob() )
      return query_master_ob()->id( param );
   return 0;
}

void set_host( object x ) {
   set_var("host", to_objectref(x));
}

object query_host() {
   if( !symbolp(query_var("host")) )
      return 0;
   return find_objectref( query_var("host") );
}

object query_master_ob() {
   object ob = ::query_master_ob();
   if( !ob && query_backlink() ) {
      set_master_ob( query_backlink() );
      ob = ::query_master_ob();
   }
   return ob;
}

/* Be wary! This broke doors, because sometimes the shape is not
   in the same PLACE.
mapping query_shape() {
   if( !query_master_ob() ) return 0;
   return query_master_ob()->query_shape();
}
*/