#include <file_security.h>

/* Gives file access information for a directory. */

// A list of files in the directory
string *files;
// The path (w/ wildcards removed) to the directory
string path;
// The name of the UID that owns the directory being checked.
string dirowner;

#define GET_SUBDIR(x) "/secure/file_security"->get_subdir(x)

/* Takes the list in files and adds text formatting to it.
 * Precalculated ANSI is used heavily to make this function
 * fast, so any fancy tricks with the ANSI could break
 * this function.
 */
string filter_file_list() {
   int len, longest_name, i, nfile, narr, clen;
   int cols, rows, fcount, dpad1, dpad2;
   string str, owner;

   string YELLOW_STR, BRIGHT_STR, DARK_STR, BLUE_STR;

   // This is not normally good practice, but doing substring substitution
   // 200+ times for the tilde codes to list the directory was resulting
   // in as much as 1-3 seconds lag while waiting. This method is almost
   // instantaneous, just a lot more work.
   YELLOW_STR = process_string("~[110", 0);
   BRIGHT_STR = process_string("~[100", 0);
   DARK_STR = process_string("~[020", 0);
   BLUE_STR = process_string("~[140", 0);
   dpad1 = strlen(BRIGHT_STR + BLUE_STR) + 2;
   dpad2 = strlen(DARK_STR) + 2;

   len = sizeof( files );
   if( len == 0 ) return YELLOW_STR + "   No files found.\n";

   // Add rights information to files while finding the longest name.
   for( i = len - 1; i >= 0; i-- ) {
      if( files[i] == "." || files[i] == ".." )
         files -= ({ files[i] });
      else
      if( file_size(path + files[i]) == -2 ) {
         clen = strlen(files[i]) + 1;
         files[i] = DARK_STR + files[i] + "/";
      }
      else
      if( (owner = "/secure/file_security"->query_file_owner(path+files[i])) != dirowner ) {
         clen = strlen(owner) + strlen(files[i]) + 1;
         files[i] = BRIGHT_STR + files[i] + BLUE_STR + ":" + owner;
      }
      else {
         clen = strlen(files[i]);
         files[i] = DARK_STR + files[i];
      }
      if( clen > longest_name ) longest_name = clen;
   }

   // Go through and pad with spaces.
   len = sizeof( files );
   for( i = 0; i < len; i++ )
   if( strstr( files[i], ":", 0 ) >= 0 ) files[i] = pad(files[i], longest_name + dpad1, 0);
   else files[i] = pad(files[i], longest_name + dpad2, 0);

   fcount = sizeof(files);

   str = "";

   cols = this_player()->query_term_width() / (longest_name + 2);

   rows = 1 + (fcount - 1) / cols;
   nfile = 0;
   for( i = 0; i < rows * cols; i++ ) {
      narr = (nfile % cols) * rows + (nfile / cols);
      nfile++;
      if( narr < fcount ) str += files[ narr ];
      if( nfile % cols == 0 ) str += "\n";
   }
   str += YELLOW_STR + "   " + fcount + " file"+(fcount != 1?"s":"")+" listed.\n";
   return str;
}

main( string param ) {
   int no_files;
   string dir_path;

   WIZ_CHECK

   if( getuid(this_object()) != MASTER_UID ) {
      notify_fail("==> [Error] This object must possess the root uid.\n");
      return 0;
   }
   if( param ) {
      path = this_player()->make_path_absolute(param);
      if( file_size(path) == -2 ) {
         if( path[<1..] != "/" ) path += "/";
         no_files = 1;
      }
      else
         no_files = 0;
   }
   else {
      path = this_player()->query_path();
      if( path[<1..] != "/" ) path += "/";
      no_files = 1;
   }
   dir_path = path;
   while( strlen(dir_path) && dir_path[<1] != '/' ) dir_path = dir_path[..<2];
   if( !query_read_access(dir_path, this_player()) ) {
      notify_fail("==> [Error] Access denied.\n");
      return 0;
   }

   dirowner = "/secure/file_security"->query_dir_owner(path);

   if( path[<1] == '/' ) {
      msg("~CTITGroup access for ~CBRT"+path);
      msg( "   ~CLABDirectory view~CDEF: " + comma_list("/secure/file_security"->query_dir_groups(path, REQ_MINIMAL_READ)) );
      msg( "   ~CLABFile read~CDEF  : " + comma_list("/secure/file_security"->query_dir_groups(path, REQ_READ)) );
      msg( "   ~CLABFile create~CDEF: " + comma_list("/secure/file_security"->query_dir_groups(path, REQ_CREATE)) );
      msg( "   ~CLABFile modify~CDEF: " + comma_list("/secure/file_security"->query_dir_groups(path, REQ_MODIFY)) );
      msg( "   ~CLABOwner~CDEF      : " + dirowner );
   }

   if( !no_files ) {
      msg("~CTITFiles in ~CBRT"+path);

      files = get_dir( path );
      while( path[<1..] != "/" ) path = path[..<2];
      write(filter_file_list());
      msg_bare("~CDEF");
   }
   return 1;
}