// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Rust

#include <mudlib.h>

inherit CMD;

private void main(mixed argv)
{
  map(argv[0], (: rm($1) ? outf(//"%s: removed.\n"
                                "删除 %s 成功。\n", $1) : 
                outf(//"failed to remove: %s\n",
                     "删除 %s 失败。\n", $1) :));
}
