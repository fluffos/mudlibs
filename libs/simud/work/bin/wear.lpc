int main( string param ) {
   object *alist, ob;

   if( !param ) {
      msg("What would you like to wear?");
      return 1;
   }

   alist = all_present( param, this_player() );

   if( !alist ) {
       msg("Nothing that matches "+param );
       return 1;
   }

   foreach( ob: alist )
      if( environment(ob) != this_player() ) alist -= ({ ob });

   foreach( ob: alist ) {
      //debug("wearing "+as_lpc(ob));
      if (!ob->query_armour() && !ob->query_is_apparel()) {
         // make sure we don't try to print a message about wearing chat/secure objects
         if (ob->query_specific())
            msg("You can't wear " + ob->query_specific() + ".");
         continue;
      }
      if ( ob->wear_armour() == 0 )
          msg("You can't wear "+ob->query_specific()+".");
   }

   return 1;
}
