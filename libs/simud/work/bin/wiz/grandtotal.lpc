int main( string param ) {
   object ob, iob, bank;
   int wobcount, iobcount, worldcount, invcount;

   WIZ_CHECK

   if( !param ) {
      notify_fail( "==> [Format] grandtotal filename\n");
      return 0;
   }

   param = this_player()->make_path_absolute(param);
   ob = find_object(param);
   if( !ob ) {
      notify_fail("Can't find that object.\n");
      return 0;
   }

   wobcount = iobcount = worldcount = invcount = 0;
   bank = find_room(";bank");
   foreach( iob : all_clones(ob) ) {
      if( environment(iob) && member(all_environment(iob), bank) >= 0 ) {
         iobcount ++;
         invcount += iob->query_quantity();
      }
      else {
         wobcount ++;
         worldcount += iob->query_quantity();
      }
   }

   msg("~CTITGrand total count for " + load_name(ob));
   msg("~CLAB                 Objects in world: ~CDEF" + wobcount );
   msg("~CLAB   Objects in offline inventories: ~CDEF" + iobcount );
   if( worldcount > 0 )
      msg("~CLAB                Quantity in world: ~CDEF" + worldcount );
   if( invcount > 0 )
      msg("~CLAB          Quantity in inventories: ~CDEF" + invcount );
   return 1;
}