/*  -*- LPC -*-  */
#include <command.h>

int
main()
{
  object me = this_player();
  int* money = me->query_money();

  printf(@ENDSCORE
%s
Weight: %-10d
You have %d gold and %d silver.
ENDSCORE, me->short(),
	  me->query_weight(),
	  money[1], money[0]);
  return 1;
}
