int main( string param ) {
   if( !param ) {
      notify_fail("==> [Notice] ichannel [add/drop] channel\n");
      return 0;
   }

   if( sscanf(param, "add %s", param) == 1 ) {
      string *chans;

      chans = this_player()->query_env_var("i3_channels");
      if( !pointerp(chans) || member(chans, param) < 0 ) {
         this_player()->add_env_var( "i3_channels", param );
         msg( "Channel "+param+" was added.");
         return 1;
      }
      notify_fail( "You are already listening to that channel.\n" );
      return 0;
   }

   if( sscanf(param, "drop %s", param) == 1 ) {
      if( this_player()->remove_env_var_item("i3_channels", param) ) {
         msg("Channel "+param+" dropped.");
         return 1;
      }
      notify_fail("You weren't listening to that channel anyway!\n");
      return 0;
   }

   notify_fail("==> [Notice] ichannel [add/drop] channel\n");
   return 0;
}