/// \todo Must document this. Later.

int query_closed() {
   QBODY( "closed", 0 );
}

void set_closed( int x ) {
   SBODY( "closed", x )
}

int query_is_lockable() {
   return 1;
}

int query_locked() {
   object ob;

   foreach( ob : all_inventory() ) {
      if( ob->query_locked() ) return 1;
   }
   return 0;
}

object query_lock() {
   object ob;

   foreach( ob : all_inventory() )
      if( ob->query_is_lock() ) return ob;
   return 0;
}

int query_is_openable() {
   return 1;
}

int on_open() {
   object remote;
   if( !this_object()->query_closed() ) {
      msg(capitalize((string) this_object()->query_specific()) + " is already open. Attempting to open it again would just look strange.");
      return 1;
   }
   if( query_locked() ) {
      msg( capitalize(this_object()->query_specific()) + " is locked. You can't open it.");
      return 1;
   }
   set_target( MOBJ );
   this_player()->msg_local( "~CACT~Name ~verbopen ~targ.~CDEF" );
   this_object()->set_closed( 0 );
   return 1;
}

int on_close() {
   object remote;
   if( this_object()->query_closed() ) {
      msg(capitalize((string) this_object()->query_specific()) + " is already closed. Attempting to close it further would likely arouse undesired criticism.");
      return 1;
   }
   if( query_locked() ) {
      msg( capitalize(this_object()->query_specific()) + " is locked. You can't close it.");
      return 1;
   }
   set_target( MOBJ );
   this_player()->msg_local( "~CACT~Name ~verbclose ~targ.~CDEF" );
   this_object()->set_closed( 1 );
   return 1;
}
