string query_action_name() {
   return "Push";
}

int main( string param ) {
   object ob;
   string s;
   int dir;

   if( !param ) {
      notify_fail("You can either push <thing> or push <thing> <direction>.\n");
      return 0;
   }

   s = 0;
   dir = 0;
   // Note! You need to do it this way because you need to allow for multi-word
   // objects to be pushed!
   if( sscanf(param, "%s north", s) == 1 ) dir = SMAKE_C(0,-1,0);
   if( sscanf(param, "%s south", s) == 1 ) dir = SMAKE_C(0,1,0);
   if( sscanf(param, "%s east", s) == 1 ) dir = SMAKE_C(1,0,0);
   if( sscanf(param, "%s west", s) == 1 ) dir = SMAKE_C(-1,0,0);
   if( !dir ) s = param;

   ob = single_present( s, environment(this_player()) );
   if( !ob ) {
      notify_fail("I don't know what you mean by '"+s+"'.\n");
      return 0;
   }

   WALK_ACTION_PARAM( 1000, ob, dir );
   if( sizeof(this_player()->query_actions()) )
      msg( "You start walking toward it." );
   return 1;
}

void on_action( object target, int dir ) {
   int ret;

   ret = target->on_push( dir );
   if( !ret )
      msg("Pushing that didn't do anything.");
}
