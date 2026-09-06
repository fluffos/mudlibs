string query_action_name() {
   return "Flee";
}

int main(string arg) {
   object *exit_list;
   object exit;

   if (!this_player()->query_in_combat())
      return notify_fail("You've got no reason to flee ;)\n");
   // don't repeat fleeing if you're already running
   if ( this_player()->query_action_name() == query_action_name() )
      return notify_fail("You are already advancing to the rear.\n");

   exit_list = filter( all_inventory(environment(this_player())), (: $1->query_is_exit() :) );
   if ( arg ) {
      switch ( arg ) {
         case "n": arg = "north"; break;
         case "s": arg = "south"; break;
         case "e": arg = "east"; break;
         case "w": arg = "west"; break;
         case "nw": arg = "northwest"; break;
         case "ne": arg = "northeast"; break;
         case "sw": arg = "southwest"; break;
         case "se": arg = "southeast"; break;
      }
      exit_list = filter( exit_list, (: $1->query_dir() == arg :) );
   }

   if( !sizeof(exit_list) ) {
      if ( arg )
         return notify_fail("There is no such exit '"+arg+"' here.\n");
      else
         return notify_fail("There's nowhere for you to run!\n");
   }

   exit = exit_list[random(sizeof(exit_list))];
   this_player()->msg_local("~CEMO~Name ~verbpanic and ~verbbegin to look for an exit!~CDEF");
   this_player()->add_readiness(-500);

   this_player()->push_action( ({ 500, this_object(), this_player(), ST_STANDING, exit }) );

   return 1;
}

void on_action( object target, mixed exit ) {
   string str = this_player()->query_movement_type();
   this_player()->set_movement_type("flee");
   this_player()->add_endurance(-5);
   exit->exit_action();
   // silly 'temporary' hack
   call_out("restore_movement_type",6,this_player(),str);
}

void restore_movement_type( object who, string str ) {
   if (pointerp(who) && stringp(str))
      who->set_movement_type(str);
}
