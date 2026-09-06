nosave object *buildings;

// checks all buildings

void create() {
   call_out( "check_buildings", 3600 * 12 + random(3600) );
}

void check_buildings() {
   remove_call_out( "check_buildings" );

   buildings = clones("/bldg/mine");
   buildings += clones("/bldg/store");
   buildings += clones("/bldg/shack");
   buildings += clones("/bldg/cottage");
   buildings += clones("/bldg/house");
   buildings += clones("/bldg/farm");
   buildings += clones("/bldg/shop");
   buildings += clones("/bldg/field");

   set_heart_beat( 1 );
}

private void escheat_building( object bldg ) {
   log_file("escheat", get_location(bldg) + " escheated, belonged to " + bldg->query_owner() + "\n");

   bldg->set_owner( 0 );

   foreach( object ilock : deep_inventory(bldg) ) {
      if( ilock->query_is_lock() ) {
         destruct( ilock );
      }
   }

   foreach( object idoor : all_inventory(environment(bldg)) ) {
      if( idoor->query_host() == bldg ) {
         foreach( object ilock : deep_inventory(idoor) ) {
            if ( ilock->query_is_lock() )
               destruct( ilock );
         }
      }
   }
}

int checking() {
   if ( !pointerp(buildings) )
      return -1;
   return sizeof(buildings);
}

void heart_beat() {
   int count;

   foreach ( object ibldg : buildings ) {
      if (++count > 5)
         return;

      buildings -= ({ ibldg });
      string owner = ibldg->query_owner();
      string base_owner;

      if ( owner == 0 )
         continue;

      /* capitalized means mud owned */
      if ( owner[0] >= 'A' && owner[0] <= 'Z' )
         continue;

      if ( sscanf( owner, "escheated %s", base_owner )) {
         ibldg->set_owner( base_owner );
         escheat_building( ibldg );
         continue;
      }

      if ( file_size("/players/" + owner + ".o") == -1 ) {
         log_file( "escheat", get_location(ibldg) + " will be escheated in about 12 hours.\n" );
         ibldg->set_owner( "escheated " + owner );
      }
   }

   call_out( "check_buildings", 3600 * 12 + random(3600) );
   buildings = 0;
   set_heart_beat( 0 );
}
