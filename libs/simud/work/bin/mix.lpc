int main( string param ) {
   object ob, *oblist;
   int success, reason;

   if( !param ) {
      notify_fail("You want to mix anything in particular, or just the world in general?\n");
      return 0;
   }

   if( param == "the world in general" ) {
      notify_fail("Yeah, yeah, whatever. Go away.\n");
      return 0;
   }

   oblist = all_present( param, this_player() );
   if( !oblist ) oblist = all_present( param, environment(this_player()) );
   if( !oblist ) {
      notify_fail("I have no idea what you mean by '"+param+"'\n");
      return 0;
   }
   success = 0;
   reason = 0;
   foreach( ob : oblist ) {
      success |= ob->on_mix();
      if( !success )
      if( sizeof(all_inventory(ob)) == 0 )
         reason = 1;
      else if( sizeof(all_inventory(ob)) == 1 )
         reason = 2;
   }

   if( !success ) {
      switch( reason ) {
         case 0: notify_fail("Mixing that has no effect.\n"); break;
         case 1: notify_fail("What, you want to stir the air around? There is nothing in it to be mixed.\n"); break;
         case 2: notify_fail("No matter how much you stir, the contents continue to remain what they are.\n"); break;
      }
      return 0;
   }
   return 1;
}