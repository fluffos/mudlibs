#include <const.h>

#define BUF_SIZE 2048

int main( string param ) {
   string *files, file_name, path, buf, label;
   int lines, process_codes, size, file_size;
   int i, j;  // for loop counters
   int l;     // mutable var for lines

   WIZ_CHECK

   // checks that command is properly formatted
   if ( !param )
      return notify_fail( "==> [Format] tail [-p] [-n #] filename\n" );
   if ( sscanf(param, "-p %s", param) == 1 )
      process_codes = 1;
   if ( sscanf(param, "-n %d %s", lines, param) != 2 )
      lines = this_player()->query_term_height() * 2 / 3;
   if ( lines < 1 )
      lines = 2;  // arbitrary default value
   if ( !legal_filename(param) )
      return notify_fail( "==> [Error] Not a valid filename: "+param+".\n" );

   path = this_player()->make_path_absolute( param );

   if ( !path )
      return notify_fail( "==> [Error] make_path_absolute failed.\n" );
   if ( file_size(path) == FSIZE_DIR )
      return notify_fail( "==> [Error] There are no files in that directory.\n" );

   // gets a list of all files in path, then removes any characters following the path's /
   files = get_dir( path );
   while ( path[<1..] != "/" ) path = path[..<2];

   // displays the beginning of each file
   size = sizeof( files );
   for ( i = size - 1; i >= 0; i-- ) {
      if ( files[i] == "." || files[i] == ".." || file_size(path + files[i]) == FSIZE_DIR )
         continue;
      if ( !legal_filename(files[i]) )
         return notify_fail( "==> [Error] Not a valid filename: "+files[i]+".\n" );

      file_size = file_size( path + files[i] );
      if ( file_size < BUF_SIZE )
         buf = read_bytes( path + files[i], 0, file_size );
      else
         buf = read_bytes( path + files[i], file_size - BUF_SIZE, BUF_SIZE );

      if ( !buf )
         return notify_fail( "==> [Error] Can't open "+files[i]+" for reading.\n" );

      label = "~CLAB" + files[i] + ":~CDEF ";
      if ( lines > 1 )
         label += "\n";
      msg_bare( label );
      buf = cleanup_string( buf );

      if ( process_codes )
         buf = process_string( buf, 0 );

      l = lines + 1;
      for ( j = strlen(buf); j; )
         if ( buf[--j] == '\n' && !(--l) ) break;
      if ( j == 0 && buf[0] != '\n' ) j = -1;

      if ( buf[<1] == '\n' )
         write( buf[j+1..] );
      else
         write( buf[j+1..] + "\n" );
   }

   return 1;
}
