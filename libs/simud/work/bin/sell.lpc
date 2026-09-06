int main( string param ) {
   string a, b;

   if( !param ) {
      notify_fail("You can either 'buy something' or 'buy something from someone'\n");
      return 0;
   }

   if( sscanf(param, "%s to %s", a, b) == 2 ) {
      object src;

      src = single_present( b, environment(this_player()) );
      if( !src ) {
         notify_fail("I'm not sure to whom you are trying to sell it.\n");
         return 0;
      }

      if( src->on_sell(a, this_player()) ) return 1;
   }
   else {
      object ob;

      foreach( ob : all_inventory(environment(this_player())) )
         if( ob->on_sell(param, this_player()) ) return 1;
   }

   notify_fail("It looks like nothing of that sort is being bought here.\n");
   return 0;
}
