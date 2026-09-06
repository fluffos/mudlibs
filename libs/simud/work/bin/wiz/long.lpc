int main( string param ) {
   BUILD_CHECK

   if( !param ) {
      notify_fail( "==> [Format] long descr.\n");
      return 0;
   }
   environment(this_player())->set_long( param );
   msg( "Long description set to " + param );
   return 1;
}