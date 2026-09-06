#include <const.h>

string *files;
string path, filei;
int long_flag, all_flag, invalid_flag, time_flag, one_col_flag;

eval_param( string val ) {
   int i;

   for( i = 0; i < strlen(val); i++ ) {
      if( val[i] == '-' ); else
      if( val[i] == 'l' ) long_flag    = 1; else
      if( val[i] == 'a' ) all_flag     = 1; else
      if( val[i] == 't' ) time_flag    = 1; else
      if( val[i] == '1' ) one_col_flag = 1; else
      invalid_flag = 1;
   }
}

is_earlier( string file1, string file2 ) {
   return (file_time(path + file1) < file_time(path + file2));
}

string owner( string file ) {
   file = this_player()->make_path_absolute(file);
   if( file_size(file) == -2 )
      return "/secure/file_security"->query_dir_owner(file+"/");
   else
      return "/secure/file_security"->query_file_owner(file);
}

string filter_file_list() {
   int i, len, fcount, longest_name;
   string fullname, sizestr, str;
   int cols, rows, nfile, narr;

   string YELLOW_STR, GREEN_STR, CYAN_STR, WHITE_STR, GRAY_STR, DARK_STR;

   // This is not normally good practice, but doing substring substitution
   // 200+ times for the tilde codes to list the directory was resulting
   // in as much as 1-3 seconds lag while waiting. This method is almost
   // instantaneous, just a lot more work.
   YELLOW_STR = process_string("~[110", 0);
   GREEN_STR = process_string("~[100", 0);
   WHITE_STR = process_string("~[150", 0);
   GRAY_STR = process_string("~[070", 0);
   CYAN_STR = process_string("~[140", 0);
   DARK_STR = process_string("~[080", 0);

   len = sizeof( files );

   longest_name = 0;
   for( i = len - 1; i >= 0; i-- ) {
      if( !all_flag )
      if( files[i][0] == '.' || files[i][<1] == '~' || files[i] == "DEADJOE" ) {
         files -= ({ files[i] });
         continue;
      }
      if( files[i] == "." || files[i] == ".." )
         files -= ({ files[i] });
      else if( strlen(files[i]) > longest_name ) longest_name = strlen(files[i]);
   }

   len = sizeof(files);
   if( len == 0 ) return YELLOW_STR + "   No files found.\n";
   if( time_flag ) files = sort_array( files, "is_earlier" );

   for( i = 0; i < len; i++ ) {
      fullname = path + files[i];
      sizestr = as_string( file_size(fullname) );
      fcount++;
      if( long_flag ) {
         if( sizestr == "-2" ) {
			
            files[i] = pad(owner(files[i]),10,1) + CYAN_STR + "     <dir>  " + pad( files[i], longest_name + 2, 0 )
               + GRAY_STR + stime(file_time(fullname));
         } else {
            if( find_object(fullname) )
               files[i] = pad(owner(files[i]),10,1) + WHITE_STR + pad(sizestr, 10, 1) + "  " + GREEN_STR +
                          pad( files[i], longest_name + 2, 0) + GRAY_STR + stime(file_time(fullname));
            else if( files[i][<2..] == ".o" )
               files[i] = pad(owner(files[i]),10,1) + WHITE_STR + pad(sizestr, 10, 1) + "  " + DARK_STR +
                          pad( files[i], longest_name + 2, 0) + GRAY_STR + stime(file_time(fullname));
            else
               files[i] = pad(owner(files[i]),10,1) + WHITE_STR + pad(sizestr, 10, 1) + "  " + GRAY_STR +
                          pad( files[i], longest_name + 2, 0) + stime(file_time(fullname));
         }
      }
      else {
         if( sizestr == "-2" ) {
            files[i] = files[i] + "/";
            str = CYAN_STR;
         }
         else
            if( find_object(fullname) ) str = GREEN_STR;
            else if( files[i][<2..] == ".o" ) str = DARK_STR;
            else str = GRAY_STR;
         files[i] = str + pad( files[i], longest_name + 2, 0 );
      }
   }

   str = "";
// Shouldn't be needed w/ modified algorithm...
//   files -= ({ 0 });

   if( one_col_flag )
      cols = 1;
   else if( long_flag )
      cols = this_player()->query_term_width() / (longest_name + 28);
   else
      cols = this_player()->query_term_width() / (longest_name + 2);

   rows = 1 + (fcount - 1) / cols;
   nfile = 0;
   for( i = 0; i < rows * cols; i++ ) {
      narr = (nfile % cols) * rows + (nfile / cols);
      nfile++;
      if( narr < fcount ) str += files[ narr ];
      if( nfile % cols == 0 ) str += "\n";
   }
   str += YELLOW_STR + "   " + fcount + " file"+(fcount != 1?"s":"")+" found.\n";
   return str;
}

main( string param ) {
   string *flags;
   string wcards;
   int i;

   WIZ_CHECK

   long_flag = all_flag = time_flag = one_col_flag = invalid_flag = 0;
   wcards = 0;

   if( param ) {
      flags = explode( param, " " );
      for( i = 0; i < sizeof(flags); i++ )
      if( flags[i] != "" ) {
         if( flags[i][0] == '-' ) eval_param( flags[i] );
         else {
            if( wcards ) invalid_flag = 1;
            else wcards = flags[i];
         }
      }
   }

   if( invalid_flag ) {
      notify_fail("==> [Error] Invalid flag to ls. See 'help ls' for usage.\n");
      return 0;
   }

   if( wcards ) {
      path = this_player()->make_path_absolute(wcards);
      if( file_size(path) == -2 && path[<1..] != "/" ) path += "/";
   }
   else {
      path = this_player()->query_path();
      if( path[<1..] != "/" ) path += "/";
   }

   msg("~CBRTFiles in "+path);

   files = get_dir( path );
   while( path[<1..] != "/" ) path = path[..<2];
   write(filter_file_list());
   msg_bare("~CDEF");
   return 1;
}
