string query_action_name() {
   return "Count";
}

int main( string param ) {
   object *list, ob;
   int amount = 0;
   string result;

   if ( !param )
      return notify_fail("What do you want to count the amount of?\n");

   if ( param[0..3] != "all " )
      param = "all " + param;

   list = all_present( param, this_player()/*, (: !$1->query_container() :)*/ );
   if ( !list ) {
      list = all_present( param, environment( this_player() )/*, (: !$1->query_container() :)*/ );
   }
   if ( !list )
      return notify_fail("Could not find that to count.\n");

   foreach( ob : list ) {
      // If there's an object, there *must* be a quantity of at least one
      // quantity 0 means that this obj does not inherit /obj/quantity
      if ( ob->query_quantity() == 0 )
         amount++;
      else
         amount += ob->query_quantity();
   }

   // see thread 2005 as to why these are diked out
   // see thread 2006 for a good idea for fixing
   if ( ob->query_units() )
      if ( amount == 1 )
         result = "You count " + amount + " " + ob->query_unit() + "."; // of " + ob->query_name() + ".";
      else
         result = "You count " + amount + " " + ob->query_units() + "."; // of " + ob->query_plural() + ".";
   else
      if ( amount == 1 )
         result = "You count " + amount + "."; // " + ob->query_name() + ".";
      else
         result = "You count " + amount + "."; // " + ob->query_plural() + ".";

   if ( amount <= this_player()->query_stat("int") )
      msg(result);
   else {
      msg("You begin counting.");
      // have to pass something for the delay, this player is as good as anything
      WALK_ACTION_PARAM(1000 + (to_int(amount - this_player()->query_stat("int")) % 1000), this_player(), result);
   }

   return 1;
}

void on_action( object this_player, string result ) {
   msg(result);
   if (this_player()->query_readiness() > 1000)
      this_player()->set_readiness(700);
   else
      this_player()->add_readiness(-300);
}
