#include <const.h>
#include <daemon.h>

object my_player;

id(str) { return str=="sub_daemon"; }

move( object dest ) {
  move_object( this_object(), dest );
  my_player = environment(this_object());
  call_out("stat_check", 1);
}

query_charge() { return my_player; }

stat_check() {
   remove_call_out( "stat_check" );
  if(my_player->query_level()>=WIZLEVEL)
    "/secure/master_security"->check_player(my_player->query_name(), my_player->query_level());
  call_out("stat_check", DAEMON_SECURE);
}

void on_suspend() {
   destruct(this_object());
}
