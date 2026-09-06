int main( string param ) {
   int i;
   string *comlist;

   if( !param ) {
      notify_fail("Use it like this: chain command1//command2//command3. Limit of 10 commands.\n");
      return 0;
   }

   comlist = explode( param, "//" );
   for( i = 0; i < sizeof(comlist) && i < 10; i++ )
      command( comlist[i], this_player() );

   return 1;
}