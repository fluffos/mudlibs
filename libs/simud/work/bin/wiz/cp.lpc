#include <const.h>
#include <sys/files.h>

int main(string str)
{
  string filename, start, destination, *file_list;

  WIZ_CHECK

  if( !str || !sscanf(str, "%s %s", start, destination) )
  {
    notify_fail("==> [Format] cp source destination\n");
    return 0;
  }

  start = this_player()->make_path_absolute(start);
  destination = this_player()->make_path_absolute(destination);

  if( legal_filename(start) && file_size(start) == -2 && start[<1] != '/' ) start += "/";

  file_list = get_dir(start);
  if( !pointerp(file_list) ) {
     notify_fail("==> [Error] Can't find files matching "+start+".\n");
     return 0;
  }

  while( start[<1] != '/' ) start = start[..<2];
  file_list = filter( file_list, (: legal_filename($2 + $1) && file_size($2 + $1) != -2 :), start );

  if( sizeof(file_list) == 0 ) {
    notify_fail(sprintf("==> [Error] Can't find any files that match. Nothing copied.\n", start));
    return 0;
  }

  if( sizeof(file_list) > 1 && file_size(destination) != -2 ) {
     notify_fail("==> [Error] More than one file specified. Destination must be a directory.");
     return 0;
  }

  foreach( filename : file_list ) {
     if( copy_file(start+filename, destination) == 0 )
        msg(sprintf("==> [Notice] Successfully copied %s to %s.", filename, destination));
     else
        msg("==> [Error] Copying " + start + filename + " failed.");
  }
  return 1;
}
