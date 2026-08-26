// By Rust
#include <mudlib.h>

inherit CMD;

private void main(mixed argv)
{
   if (!wizardp(this_body()))
   {
      out("This command is for wizard use only.\n");
      return;
   }

   map(argv[0], (: rm($1) ? outf("%s: removed.\n", $1) : outf("failed to remove: %s\n", $1) :));
}