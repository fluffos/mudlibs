#include <const.h>
#include <wizard.h>

void set_coord( object ob, int x, int y ) {
   ob->set_x( x );
   ob->set_y( y );
   command( "xy " + ob->query_name(), this_player() );
}

int main( string str ) {
   object ob;
   int x, y;
   string tg;

   WIZ_CHECK

   ob = this_player(); // Leave. Is used with no parameters

   // sets the object to the given coordinates.
   // the str before the && is needed because null strings evaluate to 0.
   if ( str && (sscanf( str, "%s %d,%d", tg, x, y ) == 3 ||
                sscanf( str, "%s %d %d", tg, x, y ) == 3  ||
                sscanf( str, "%s (%d,%d)", tg, x, y ) == 3) )
   {
      if ( ob = find_thing(tg) ) {
         set_coord( ob, x, y );
         return 1;
      }
   }

   // if no coordinates are given...
   if ( str )
      ob = find_thing( str );
   if ( !ob ) {
      notify_fail( "==> [Format] xy object (Also, try to use objects that exist.)\n" );
      return 0;
   }

   // return the player's coordinates...
   if ( ob->query_is_player() )
      msg_object( this_player(), "~CTIT" + capitalize( ob->query_name() ) +
                  "'s Coordinates: (" + ob->query_x() + "," + ob->query_y() + ")~CDEF" );
   // ...or return the object's coordinates
   else
      msg_object( this_player(), "~CTIT" + capitalize( ob->query_specific() ) +
                  "'s Coordinates: (" + ob->query_x() + "," + ob->query_y() + ")~CDEF" );
   return 1;
}
