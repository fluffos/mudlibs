/*  -*- LPC -*-  */
// cp.c:  copy a file;  Tim McIntosh (astasia@iastate.edu)

#include <cmdline.h>

#define USAGE "cp [-o] <source> <destination>"

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

  if( file_size(source) < 0 )
    return notify_fail("cp: source file does not exist.\n");

  if( file_size(dest) == -2 ) {               // in case just gave dir name
    if(dest[<1] != '/')                       // make sure we get the / right
      dest += "/";
    dest += tmp[<1];
  }

  if( !opto && file_size(dest) != -1 )
    return notify_fail("cp: destination file already exists.\n");
  else
    rm(dest);

  if( cp(source, dest) != 1 )
  {
    string tmp2 = query_notify_fail();
    
    if( tmp2 )
      return notify_fail(tmp2);
    else
      return notify_fail("cp: call to cp() failed.\n");
  }

  return 1;
}
