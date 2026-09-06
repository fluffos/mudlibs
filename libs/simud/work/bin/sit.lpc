#include <battle.h>

string query_action_name() {
   return "Sit";
}

int main(string str) {
   object ob;
   string prep;

   if (this_player()->query_stance() == ST_SITTING)
      return notify_fail("You are already seated.\n");

   if ( !str || str == "down" ) {
      WALK_ACTION_PARAM( 400, this_player(), "down" );
      return 1;
   }

   str = trim(str);

   prep = str[0..1];

   if ( prep == "by" ||
        prep == "on" ||
        prep == "in" ) {
      str = str[3..];
   } else
      prep = 0;

   if ( !(ob = single_present(str, environment(this_player()))) )
      return notify_fail("I don't know what you mean by '" + str + "'.\n");

   if ( !prep && ob->query_can_sit() )
      prep = "on";
   else if ( !prep )
      prep = "by";

   if ( prep == "by" ) {
      WALK_ACTION_PARAM( 400, ob, ob->query_specific() );

   } else {
      if ( !ob->query_can_sit() )
         return notify_fail("You can't sit " + prep + " that.\n");

      WALK_DAEMON->init_walk_action(
         WALK_DAEMON->shape_point(),
         ob->query_coord(),
         ({ 400, this_object(), ob, ST_STANDING, ob->query_specific() }) );
   }

   return 1;
}

void on_action(object victim, mixed param) {
   if ( !param ) return 0;

   if ( this_player()->query_stance() == ST_SITTING )
      return msg("You are already seated.");
   //debug("wsit on_action with param (" + as_string(param) + ")");

   if ( param && as_string(param) != "down" ) {
      this_player()->msg_local("~CACT~Name ~verbwalk to " + as_string(param) + " and ~verbsit down.~CDEF");
      // don't want the message printed
      this_player()->set_stance( ST_SITTING );
      this_player()->add_readiness( -150 );
   } else
      this_player()->change_stance( ST_SITTING );
}
