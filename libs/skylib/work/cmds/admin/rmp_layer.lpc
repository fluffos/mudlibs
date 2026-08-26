/**
 * rmplayer - deletes a player's save file and all related files.
 */

#include <login.h>

inherit COMMAND_BASE;

/** @ignore yes */
private void sure( string response, string player ) {
    if( PO ) {
        user_event("inform", "Illegal attempt to delete a player in "+
            file_name(TO)+".", "admin");
        unguarded( (: log_file, "CHEAT", ctime(time())+": illegal attempt "
            "to delete a player.\nTrace: " + back_trace() :) );
        write("No.\n");
        return;
    }

  if( response == "YES" ) {
      string olduid;

      if( find_player(player) ) {
          write("Sorry, you cannot delete an online player.\n");
          return;
      }

      write("Ok.  Deleting...\n");
      olduid = geteuid();
      seteuid("Root");

      if( adminp(TP) ) {
          BULK_DELETE_H->delete_related_files( player, 1 );
          if( file_exists( LOGIN_OBJ->query_player_file_name(player)+".o") )
              unguarded( (: rm,
                  LOGIN_OBJ->query_player_file_name(player)+".o" :) );
          if( file_exists(
              LOGIN_OBJ->query_delete_player_file_name(player)+".o") )
              unguarded( (: rm,
                  LOGIN_OB->query_delete_player_file_name(player)+".o" :) );
      } else {
          user_event("inform", "Illegal attempt to delete a player in "+
              file_name(TO)+".", "admin");
          unguarded( (: log_file, "CHEAT", ctime(time())+": illegal attempt "
              "to delete a player.\nTrace: " + back_trace() :) );
      }
      seteuid(olduid);
      return;
  }

  write("Ok.  Not deleting\n");
  return;

} /* sure() */

/** @ignore yes */
protected int cmd( string player ) {
    if( !adminp( previous_object(-1)) ) {
        unguarded( (: log_file, "CHEAT", ctime(time())+
          ": illegal attempt to delete a player.\nTrace: "+back_trace() :) );
        return notify_fail("Sorry: only admin can delete players.\n");
    }

    if( find_player(player) )
        return notify_fail("Sorry, you cannot delete online players.\n");

    if( creatorp(player) )
        return notify_fail("Sorry, but "+player+" is a creator, please "
            "demote them first.\n");

    if( !PLAYER_H->test_user(player) )
        return notify_fail("Sorry, but "+player+" isn't a player.\n");

    if( !adminp(previous_object(-1) ) && adminp(player) ) {
        unguarded( (: log_file, "CHEAT", ctime(time())+": Illegal attempt "
            "to delete an Admin.\nTrace: "+back_trace() :) );
        return notify_fail("Sorry.  You cannot delete an admin.\n");
    }

    write("This will permanently delete the player " + player + ".\n" +
        "THIS IS PERMANENT.\n" +
        "Are you sure?  (only \"YES\" will delete the player)  ");

    input_to( (: sure :), 0, player );
    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
  return ({ "<word'player name'>", (: cmd($4[0]) :) });
} /* query_patterns() */
