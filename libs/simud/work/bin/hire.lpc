int main( string param ) {
   object ob;

   if( !param || !(ob=single_present(param, environment(this_player()))) ) {
      notify_fail( "I'm not sure who you want to hire.\n" );
      return 0;
   }

   if( !ob->on_hire() ) {
      notify_fail( "You can't hire that.\n" );
      return 0;
   }

   return 1;
}