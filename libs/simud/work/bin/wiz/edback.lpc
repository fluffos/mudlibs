#include <const.h>

main(string str)
{
  string filename;
  filename = this_player()->make_path_absolute(str);

  if( this_player()->query_level() < WIZLEVEL) {
     msg("==> [Error] Access denied");
     return 0;
  }

  if( file_size(filename) == -2 )
  {
    write("Error: Cannot edit a directory!\n");
    return 0;
  }

  if( !filename )
  {
    write("Error: Access Denied!\n");
    return 0;
  }

  if( file_size(filename) == -1 )
  {
    write("New File.\n");
    write_file(filename, "");
  }

  ed(filename);
  return 1;
}
