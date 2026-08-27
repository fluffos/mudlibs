#include <cmdline.h>
#include <daemons.h>

// defaults to write prot...

int
main(string* argv, string* argv2)
{
  int optr = flag("r");
  mixed prot;

  if( sizeof(argv2) != 2 )
    return notify_fail("usage: chprot [-r] <priv> <filename>\n"
		       "       chprot [-r]  none  <filename>\n");

  argv2[1] = RESOLVE_PATH(argv2[1]);

  if( file_size(argv2[1]) == -1 )
    return notify_fail(sprintf("%s: No such file or directory.\n", argv2[1]));

  if( !sscanf(argv2[0], "%d", prot) )
    prot = argv2[0];

  if( prot == "none" )
    return SECURITY_D->unprotect_file(argv2[1], optr);
  else
    return SECURITY_D->protect_file(argv2[1], optr, prot);
}
