/*  -*- LPC -*-  */
// mv.c:  move a file;  Tim McIntosh (astasia@iastate.edu)

#include <cmdline.h>

#define USAGE "mv [-o] <filepath> <destination>"

int
main(string *argv, string *argv2)
{
  string source, dest, *tmp;
  int opto = flag("o");

  if( sizeof(argv2) != 2 )
    return notify_fail("usage: "+ USAGE +"\n");

  source = argv2[0];
  dest = argv2[1];

  tmp = explode(source, "/");

  source = RESOLVE_PATH(source);
  dest = RESOLVE_PATH(dest);

  if( file_size(source) == -1 )
    return notify_fail("mv: source file does not exist.\n");

  if( file_size(dest) == -2 ) {               // in case just gave dir name
    if(dest[<1] != '/')                       // make sure we get the / right
      dest += "/";
    dest += tmp[<1];
  }

// Can specify -o flag to overwrite destination

  if( (file_size(dest) != -1) && !opto )
    return notify_fail("mv: destination file already exists.\n");
  else
    rm(dest);

  if( rename(source, dest) )
  {
    string tmp2 = query_notify_fail();
    
    if( tmp2 )
      return notify_fail(tmp2);
    else
      return notify_fail("mv: call to rename() failed.\n");
  }
  
  return 1;
}
