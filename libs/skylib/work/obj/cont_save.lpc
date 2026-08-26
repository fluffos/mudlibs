
inherit "/obj/baggage";

mapping details;
nosave string save_file;

varargs void do_load( object thing ) {
  if ( save_file ) {
    all_inventory( this_object() ) -> dest_me();
    if ( file_size( save_file + ".o" ) > 0 ) {
      unguarded((: restore_object, save_file :));
      if ( thing )
        set_player( thing );
      if ( sizeof( details ) )
        init_dynamic_arg( details, 0 );
    }
  }
} /* do_load() */

void create() {
   save_file = "";
   details = ([ ]);
   ::create();
} /* create() */

int test_remove( object thing, int flag, mixed dest ) {
   remove_call_out( "do_save" );
   if ( find_call_out( "do_save" ) == -1 )
      call_out( "do_save", 1 );
   return ::test_remove( thing, flag, dest );
} /* test_remove() */

int test_add( object ob, int flag) {
   remove_call_out( "do_save" );
   if ( find_call_out( "do_save" ) == -1 )
      call_out( "do_save", 1 );
   return 1;
} /* test_add() */

void do_save() {
   if ( save_file && save_file != "") {
      details = ([ ]);
      details = query_dynamic_auto_load();
      unguarded((: save_object, save_file :));
   }
} /* do_save() */

void check_euid() {   
   if ( previous_object() )
      seteuid( geteuid( previous_object() ) );
} /* check_euid() */

varargs void set_save_file( string file, object thing ) {
   save_file = file;
   call_out( "do_load", 0, thing );
} /* set_save_file() */

/**
 * This method returns the current save file for the object.
 * @return the current save file
 */
string query_save_file() {
   return save_file;
} /* query_save_file() */
