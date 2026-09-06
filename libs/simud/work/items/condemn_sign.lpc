inherit "/items/sign";

int condemn_time;
symbol condemn_obj;

NAME( "sign" )
DISTANT( "a condemnation sign" )
SPECIFIC( "the condemnation sign" )
ALT_NAME( ({ "sign", "a condemnation sign", "condemnation sign" }) )
PLURAL( "condemnation signs" )
ALT_PLURAL( ({ "signs", "condemnation signs" }) )
PHRASE( 0 )

/// Override; these are always razable.
int query_is_razable(object razer) {
   return 1;
}

mapping query_shape() {
   return ([
      SMAKE_C(0,0,0),
      SMAKE_C(-1,0,0),
      SMAKE_C(1,0,0),
      SMAKE_C(0,1,0) ]);
}

void on_map_paint( object painter ) {
   painter->paint_shape( query_x()-1, query_y(), "[_]", 0x10, LAYER_FURNITURE );
   painter->paint_shape( query_x(), query_y()+1, "|", 0x83, LAYER_FURNITURE );
}

string query_look() {
   if( stringp(query_message()) )
// Gpfault:  Reading is supposed to cost readiness
// don't let players get the text for free by looking
//      return ::query_look() + "\n\n" + "~CTITThe sign reads~CDEF:\n\n" + query_message();

      return "It's a simple sign post, made of a flat piece of wood bound by leather strips to a post. It has been painted ~CWRNRED~CDEF.\n\nOwned by $(OWNER)." + "\n\nThe sign has writing on it.  Try ~CCOMread~CDEFing it.";
   else
      return "It's a simple sign post, made of a flat piece of wood bound by leather strips to a post. It has been painted ~CWRNRED~CDEF.\n\nOwned by $(OWNER)." + "\n\nThe sign is blank.";
}

string query_message() {
   string days_left = "" + ((condemn_time - time()) / 2880);
   if( days_left == "0" ) days_left = "tomorrow";
   else if( days_left == "1" ) days_left = "the day after tomorrow";
   else days_left = "in " + days_left + " days";
   if( time() < condemn_time )
      return ::query_message() + "\n\nThis building is still in its warning phase. It will be condemned on " +
      "/daemon/time"->query_date(condemn_time / 2880) + ", which is " + days_left + ".";
   else
      return ::query_message() + "\n\nThis building's warning time has expired.";
}

object query_condemn_obj() {
   return find_objectref(condemn_obj);
}

void set_condemn_obj( object x ) {
   if( !objectp(x) ) return;
   condemn_obj = to_objectref( x );
}

int query_condemn_time() {
   return condemn_time;
}

void set_condemn_time( int x ) {
   condemn_time = x;
}

int on_use( object target ) {
   object bldg;
   object ilock, idoor;

   if( target ) return 0;

   bldg = query_condemn_obj();

   if( !bldg ) {
      msg( "The building has disappeared! This condemnation isn't valid anymore." );
      destruct(this_object());
      return 1;
   }

   if( condemn_time > time() ) {
      msg( "The warning time hasn't expired yet. You can't enforce the condemnation." );
      return 1;
   }

   foreach( ilock : deep_inventory(bldg) ) {
      if( ilock->query_is_lock() ) destruct(ilock);
   }
   foreach( idoor: all_inventory(environment(bldg)) ) {
      if( idoor->query_host() == bldg )
      foreach( ilock: all_inventory(idoor) )
         if( ilock->query_is_lock() ) destruct(ilock);
   }
   set_target(bldg);
   this_player()->msg_local( "~CACT~Name ~verbenforce the condemnation on ~targ by uprooting the sign and whacking the building with it. Ka-boom!~CDEF" );
   msg( "All locks have been removed from the building, and anyone can raze it now." );
   bldg->set_owner( 0 );
   destruct( this_object() );
   return 1;
}

void set_condemn_building( string building ) {
   object ob;

   if( ob = single_present(building, environment(this_player())) ) {
      string bname = ob->query_distant();
      if( !ob->query_is_building() ) {
         msg( "That's not a building, and may not be condemned." );
         return;
      }
      if( ob->query_name() == "foundstone" ) {
         msg( "Condemnation signs may not be used to destroy a foundstone." );
         return;
      }
      condemn_time = time() + 2 * 365 * 24 * 120; // 120 seconds per hour on Walraven...
      condemn_time = (condemn_time/2880) * 2880; // Round to an even date.
      condemn_obj = to_objectref(ob);
      drop_interface();
      set_message( "This building, "+ob->query_distant()+", was ~CWRNcondemned~CDEF by ~CBRT" +
      capitalize(this_player()->query_name()) + "~CDEF on " +
      "/daemon/time"->query_date() + ". To remove "
      "the condemnation, simply raze this sign. To enforce the condemnation, you "
      "should ~CCOMuse sign~CDEF after the warning time expires. Warning expires two years from the date posted." );
      msg( "OK, you'll condemn " + bname + ". Come back when the warning expires!" ) ;
      return;
   }
   else if( building == "cancel" ) {
      msg( "Never mind, then." );
      destruct(this_object());
      return;
   }
   else {
      msg( "Couldn't identify that building. Try again, or type 'cancel' to quit." );
      return;
   }
}

void on_craft() {
   msg( "What do you want to condemn? Type 'cancel' to abort.\n" );
   add_interface( "set_condemn_building", "[Building] " );
}
