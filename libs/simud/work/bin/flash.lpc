#include <const.h>

string player_name;

create() {
   enable_commands();
}

// New code has been added to make exporting the UID onto the player
// object work properly. This is the only secure way to give a player
// its UID back after it flashes.

int main() {
   object player_ob;

   if( this_player()->query_in_combat() ) {
      notify_fail("Get out of combat first.\n");
      return 0;
   }

   load_object("/obj/player");
   if( member(clones("/obj/player"), this_player()) >= 0 ) {
      notify_fail("You do not need to flash.\n");
      return 0;
   }

   // general niceness for wizards
   debug( this_player()->query_name() + " has flashed" );

   player_name = this_player()->query_real_name();

   // this line is important, otherwise flashing wreaks havoc with nolife ;)
   catch("/daemon/nolife"->logout(player_name));

   player_ob = this_player();
   seteuid(getuid(player_ob));
   if( geteuid() != getuid(player_ob) ) {
      notify_fail("==> [Error] Unable to preserve your UID. Does flash verb have root privileges?\n");
      return 0;
   }

   msg("==> [Notice] You briefly flash out of existence, then return (player object updated)");
   exec( this_object(), player_ob );

   player_ob->quit( 2 );
   player_ob = clone_object( "/obj/player" );
   export_uid( player_ob );
//   msg("Debug: my euid is "+geteuid(this_object())+" and the player's uid is "+getuid(player_ob));
   player_ob->load_self( player_name );
   exec( player_ob, this_object() );
   player_ob->enter_world( 2 );
   player_ob->write_prompt();
   return 1;
}
