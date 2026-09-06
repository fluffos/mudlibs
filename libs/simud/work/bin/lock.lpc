string query_action_name( mixed *action ) {
   return "Locking " + action[B_TARGET]->query_specific();
}

int main(string param)
{
   string a, b;
   object ob;

   if( !param)
      return notify_fail("What do you want to lock, and with what?\n");

   if( sscanf(param, "%s with %s", a, b) != 2 ) {
      a = param;
      b = 0;
   }

   ob = single_present(a,this_player(),(:!$1->query_locked():));
   if( !ob ) ob = single_present(a,environment(this_player()),(:!$1->query_locked():));
   if( !ob ) ob = single_present(a,this_player());
   if( !ob ) ob = single_present(a,environment(this_player()));
   if( !ob )
      return notify_fail("I don't understand what '"+a+"' is.\n");

   if( !ob->query_lock() )
      return notify_fail("That does not have a lock.\n");

   WALK_ACTION_PARAM( 1000, ob, b );

   if( sizeof(this_player()->query_actions()) ) {
      set_target( ob );
      msg( "You start walking toward ~targ." );
   }

   return 1;
}

object keything( string b ) {
   if ( b ) {
      return single_present( b, this_player() );
   } else {
      object kt;

      kt = single_present( "keyring", this_player() );
      if (kt) {
         return kt;
      }
      return single_present( "key", this_player() );
   }
}

void on_action( object ob, string b ) {
   object key;

   if( ob->query_master_ob() )
      ob = ob->query_master_ob();
   key = keything( b );
   if( !key ) {
      msg("I don't understand what '"+b+"' is.");
      return;
   }
   if( !ob->query_lock() ) {
      msg("That does not have a lock.");
      return;
   }
   if( !key->on_lock(ob) )
      msg("You can't use "+key->query_specific()+" for locking that.\n");
}
