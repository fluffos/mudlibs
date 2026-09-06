#include <literacy.h>
#include <shape.h>
inherit "/obj/scenery";

string message;
string owner;

void set_message( string x );
string query_message();

NAME( "sign" )
DISTANT( "a sign" )
SPECIFIC( "the sign" )
LOOK( "It's a simple sign post, made of a flat piece of wood bound by leather strips to a post.\n\nOwned by $(OWNER)." )
PLURAL( "signs" )
PHRASE( 0 )

string query_owner() {
   return owner;
}

void set_owner( string x ) {
   owner = x;
}

int query_is_razable( object razer ) {
   if( !owner ) return 1;
   if( objectp(razer) && razer->query_name() == owner ) return 1;
   return 0;
}

/// Makes it possible to build with a construction site.
int query_is_building() { return 1; }

mapping query_shape() {
   return ([
      SMAKE_C(0,0,0),
      SMAKE_C(-1,0,0),
      SMAKE_C(1,0,0),
      SMAKE_C(0,1,0) ]);
}

void on_map_paint( object painter ) {
   painter->paint_shape( query_x()-1, query_y(), "[_]", 0x70, LAYER_FURNITURE );
   painter->paint_shape( query_x(), query_y()+1, "|", 0x83, LAYER_FURNITURE );
}

int on_read( string location ) {
   if( stringp(query_message()) )
      msg( "~CTITThe sign reads~CDEF:\n\n" + query_message() );
   else
      msg( "The sign is blank." );
   return 1;
}

void set_message( string x ) {
   message = x;
}

string query_message() {
   return message;
}

string query_look() {
   if( stringp(query_message()) )
// Gpfault:  Reading is supposed to cost readiness
// don't let players get the text for free by looking
//      return ::query_look() + "\n\n" + "~CTITThe sign reads~CDEF:\n\n" + query_message();
      return "It's a simple sign post, made of a flat piece of wood bound by leather strips to a post.\n\nOwned by $(OWNER)." + "\n\nThe sign has writing on it.  Try ~CCOMread~CDEFing it.";
   else
      return "It's a simple sign post, made of a flat piece of wood bound by leather strips to a post.\n\nOwned by $(OWNER)." + "\n\nThe sign is blank.";
}

int on_raze() {
   this_player()->msg_local( "~CACT~Name ~verbknock down ~targ.~CDEF" );
   destruct(this_object());
   return 1;
}

void add_sign_line( string line ) {
   if( line == "." || line == "**" ) {
      msg("OK, done.");
      drop_interface();
      return;
   }
   if( "" == line )
      message += "\n";
   else {
      if( !message || message == "" ) message = line;
      else if( message[<1]=='\n' )
         message += "\n" + line;
      else if( message[<1] != ' ' ) message += " " + line;
      else message += line;
   }
}

void on_craft() {
   msg("What are you going to write on the sign?\n"+
      "Put . or ** on a line by itself to stop.");
   set_message( "" );
   add_interface( "add_sign_line", "> " );
}