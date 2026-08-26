/* ; command, trial out by Turrican for a commands daemon. */

#include <parser.h>

inherit COMMAND_BASE;

mixed cmd(string str) {
  mixed res;

  PARSER->init_expr(str);
  res = PARSER->expr();
  printf("Returns: %O\n", ((pointerp(res) && sizeof(res) == 1)?res[0]:res));
  PARSER->finish_expr();
  return 1;
}
