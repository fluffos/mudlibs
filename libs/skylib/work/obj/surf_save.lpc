inherit "/std/surface";

mapping details;
nosave string save_file;

void do_load() {
   if ( save_file ) {
      all_inventory( this_object() ) -> dest_me();
      if ( file_size( save_file + ".o" ) > 0 ) {
         unguarded((: restore_object, save_file :));
         if ( sizeof( details ) ) init_dynamic_arg( details );
      }
   }
} /* do_load() */

void create() {
   save_file = "";
   details = ([ ]);
   ::create();
} /* create() */

int test_remove( object ob, int flag) {
   if ( find_call_out( "do_save" ) == -1 )
      call_out( "do_save", 0 );
   return 1;
} /* test_remove() */

int test_add( object ob, int flag) {
   if ( find_call_out( "do_save" ) == -1 )
      call_out( "do_save", 0 );
   return 1;
} /* test_add() */

void do_save() {
   if ( save_file ) {
      details = ([ ]);
      details = query_dynamic_auto_load();
      unguarded((: save_object, save_file :));
   }
} /* do_save() */

void check_euid() {
   if ( previous_object() )
     seteuid( geteuid( previous_object() ) );
} /* check_euid() */

void set_save_file( string file ) {
   save_file = file;
   do_load();
} /* set_save_file() */
