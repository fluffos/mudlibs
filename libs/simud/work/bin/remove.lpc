int main( string param ) {
   object *alist, ob, *inv = ({});

   if( !param ) {
      msg("What would you like to remove?");
      return 1;
   }

/* give a better message when trying to remove something held
 * the below code was copped from unhold - Malap 2002-11-04
   alist = all_present( param, this_player() );
   if( !alist ) {
      notify_fail("You're not holding anything like that.\n");
      return 0;
   }
*/

   foreach ( ob : all_inventory(this_player()) )
      if (ob->query_worn())
         inv += ({ob});

   if (!sizeof(inv)) {
      msg("You aren't wearing anything!");
      return 1;
   }

   alist = all_present( param, this_player(), all_inventory(this_player()) - inv );
   if( !alist ) {
      if (all_present(param, this_player()))
        return "/bin/unhold"->main(param);
      else
        msg("I don't see anything on you that matches '" + param + "'");
      return 1;
   }
   // end code from unhold

   foreach( ob: alist )
      if( environment(ob) != this_player() ) alist -= ({ ob });

   foreach( ob: alist )
      ob->remove_armour();

   return 1;
}
