/*  -*- LPC -*-  */
#include <command.h>

int
main(string arg)
{
  if(arg == "" || !arg)
    return notify_fail("usage: eval <lpc code>\n");

  printf("Result = %O\n", eval_string(arg));
  return 1;
}
