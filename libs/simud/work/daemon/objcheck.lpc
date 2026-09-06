#include <sys/rtlimits.h>

void do_check() {
   mapping uids;
   string obname;
   object ob;
   int cnt, curr_uid, no_uid, odin_unused_size;

   uids = ([ ]);
   uids[1] = find_object("/world/world");

   int odin_max = "/secure/odin"->query_max_id();
   mapping odin_unused = "/secure/odin"->query_unused_ids();
   odin_unused_size = sizeof(odin_unused);
   foreach( obname : "/daemon/uptodate"->query_load_times() ) {
      foreach( ob : all_clones(obname) ) {
         curr_uid = ob->query_unique_id();
         if( !curr_uid ) {
            no_uid++;
            continue;
         }
         if( member(uids, curr_uid) ) {
            msg( "ERROR: " + as_string(uids[curr_uid]) + " and " + as_string(ob) + " both have UID " + curr_uid );
         }
         uids[curr_uid] = ob;
         if( curr_uid > odin_max )
            msg( "ERROR: " + as_string(ob) + " has a UID *above* Odin's max, " + odin_max );
         cnt++;
      }
   }
   // Now we verify this against what Odin has.
   int iodin;
   // Note! Because the above code calls query_unique_id(), it's possible for
   // new ID's to be allocated while it's in the middle of its checking!
   odin_unused = "/secure/odin"->query_unused_ids();
   msg("While checking, " + (odin_unused_size-sizeof(odin_unused)) + " UID's were allocated from the unused pool.");

   msg("Odin's max_id is " + odin_max + " and it has " + sizeof(odin_unused) + " wasted UID spots" );
   foreach( iodin: odin_unused ) {
      if( uids[iodin] ) {
         msg("ERROR: " + iodin + " marked free, but used by " + as_string(uids[iodin]) );
      }
   }
   msg("Actual UID's used is " + cnt);
   msg("The object with UID " + odin_max + " is " + as_string(uids[odin_max]) );
   msg("There are " + ((odin_max-sizeof(odin_unused)) - sizeof(uids)) + " unfreed UID spots in Odin.");
   if( (odin_max-sizeof(odin_unused)) - sizeof(uids) < 30 ) {
      int i;
      for( i = 1; i < odin_max; i++ )
      if( !uids[i] && !member(odin_unused, i) )
         msg("Leak: " + i);
   }
}

void check_uid() {
   int obcount;
   limited( (: do_check(); :), LIMIT_UNLIMITED, 0 );
}