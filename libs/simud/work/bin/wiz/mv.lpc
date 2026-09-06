#include <const.h>
#include <sys/files.h>


main(string str) {
   string *file_list, filename, start, destination;

   WIZ_CHECK

   if( !str || !sscanf(str, "%s %s", start, destination) )
      return notify_fail("==> [Format] mv source destination\n");

   start = this_player()->make_path_absolute(start);
   destination = this_player()->make_path_absolute(destination);
   if( legal_filename(start) && file_size(start) == FSIZE_DIR && start[<1] != '/' ) start += "/";

   file_list = get_dir(start);

   if( !pointerp(file_list) )
      return notify_fail("No files match!\n");

   while(start[<1] != '/' ) start = start[..<2];
   file_list = filter( file_list, (: legal_filename($2 + $1) && file_size($2 + $1) != FSIZE_DIR :), start );

   if( sizeof(file_list == 0) )
     return notify_fail("==> [Error] Can't find any files that match. Nothing moved.\n");

   if( sizeof(file_list) > 1 && file_size(destination) != FSIZE_DIR )
      return notify_fail("==> [Error] More than one file specified. Destination must be a directory.\n");

   foreach( filename: file_list ) {
      if( rename(start+filename, destination) == 0 )
         msg(sprintf("==> [Notice] Successfully moved %s to %s.", filename, destination));
      else
         msg("Error moving " + start + filename + "." );
   }

   return 1;
}

/*

// What is this? Who left this here? Malap 2004-07-09

#include <const.h>

main(string str)
{
  string filename, start, destination;

  WIZ_CHECK

  if( !str || !sscanf(str, "%s %s", start, destination) )
  {
    notify_fail("==> [Format] mv source destination\n");
    return 0;
  }

  filename = this_player()->make_path_absolute(start);

  if( !filename || !query_write_access(filename, this_player()) )
  {
    notify_fail(sprintf("==> [Error] Cannot Access %s.\n", start));
    return 0;
  }
  else
  {
    start = filename;
  }

  filename = this_player()->make_path_absolute(destination);

  if( !filename || !query_write_access(filename, this_player()) )
  {
    msg(sprintf("==> [Error] Cannot Access %s.\n", destination));
    return 0;
  }
  else
  {
    destination = filename;
  }

  if( !file_exists(start) )
  {
    notify_fail(sprintf("==> [Error] %s does not exist.\n", start));
    return 0;
  }

  if( rename(start, destination) == 0 ) {
     msg(sprintf("==> [Notice] Successfully moved %s to %s.\n", start, destination));
     return 1;
  }
  else {
     notify_fail("==> [Error] The rename failed.\n");
     return 0;
  }
}
*/
