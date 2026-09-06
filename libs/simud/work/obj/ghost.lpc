// This is the object you become when you die, eh?
// Still hacking on it, don't play too much just yet ... -- Adam

#include <object.h>

void init() {
   if( this_player() != this_object() )
      return;
   add_action( "main_cmd", "", 1 );
   add_action( "quit", "quit" );
}

void main_cmd( string s ) {
   if( file_exists("/bin/" + query_verb()) )
      ("/bin/" + query_verb())->main(s);
}