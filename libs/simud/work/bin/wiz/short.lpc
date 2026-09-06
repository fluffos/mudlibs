int main( string param ) {
   BUILD_CHECK

   if( !param ) {
      notify_fail( "==> [Format] short descr.\n");
      return 0;
   }
   environment(this_player())->set_short( param );
   msg( "Short description set to " + param );
   return 1;
}