#include <const.h>

#define BUF_SIZE 2048

int main( string param ) {
   string *files, file_name, path, buf, label;
   int lines, process_codes, size;
   int i;  // for loop counter
   int b;  // 1 if lines == 1, otherwise 0

   WIZ_CHECK

   // checks that command is properly formatted
   if ( !param )
      return notify_fail( "==> [Format] head [-p] [-n #] filename\n" );
   if ( sscanf(param, "-p %s", param) == 1 )
      process_codes = 1;
   if ( sscanf(param, "-n %d %s", lines, param) != 2 )
      lines = this_player()->query_term_height() * 2 / 3;
   if ( lines < 1 ) lines = 2;

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

      buf = read_bytes( path + files[i], 0, BUF_SIZE );

      if ( !buf )
         return notify_fail( "==> [Error] Can't open "+files[i]+" for reading.\n" );

      label = "~CLAB" + files[i] + ":~CDEF ";
      if ( lines > 1 ) {
         label += "\n";
         b = 0;
      } else
         b = 1;
      buf = cleanup_string( label + buf );

      if ( process_codes )
         buf = process_string( buf, 0 );

      buf = implode( explode(buf, "\n")[0..lines-b], "\n" );

      if ( lines > 1 && buf[<1] != '\n' )
         msg( buf + "\n" );
      else
         msg( buf );
   }

   return 1;
}
