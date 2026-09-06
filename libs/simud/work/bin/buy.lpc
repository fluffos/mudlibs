int main( string param ) {
   string a, b;

   if( !param ) {
      notify_fail("You can either 'buy something' or 'buy something from someone'\n");
      return 0;
   }

   if( sscanf(param, "%s from %s", a, b) == 2 ) {
      object src;

      src = single_present( b, environment(this_player()) );
      if( !src ) {
         notify_fail("I'm not sure who you're trying to buy it from.\n");
         return 0;
      }

      if( src->on_buy(a, this_player()) ) return 1;
   }
   else {
      object ob;

      foreach( ob : all_inventory(environment(this_player())) )
         if( ob->on_buy(param, this_player()) ) return 1;
   }

   notify_fail("Couldn't find anything like that for sale here.\n");
   return 0;
}
