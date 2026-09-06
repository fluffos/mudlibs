#include <const.h>

main(string str) {
   string fname;
   object ob;

   if(this_player()->query_level() < WIZLEVEL) {
      notify_fail("==> [Error] Access denied\n");
      return 0;
   }

   if( !str ) {
      notify_fail("==> [Format] edit filename\n");
      return 0;
   }

   if( sscanf(str, "%~s->%~s") != 2 ) {
      fname = this_player()->make_path_absolute( str );

      if( !legal_filename(fname) ) {
         notify_fail("==> [Error] Illegal filename\n");
         return 0;
      }

      if( file_size(fname) == -2 ) {
         notify_fail("==> [Error] Cannot edit a directory!\n");
         return 0;
      }
      // Creating a new file currently means doing nothing...
   }
   else
      fname = str;

   ob = clone_object("/obj/fulledit");
   ob->move( this_player() );

   ob->start_edit( fname );

   return 1;
}
