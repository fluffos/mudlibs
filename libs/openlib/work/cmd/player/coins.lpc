/*  -*- LPC -*-  */
#include <command.h>
#include <money.h>

int
main()
{
  int *money;

  money = this_player()->query_money();

  printf("You have %d gold coins and %d silver coins.\n",
	 money[GOLD],
	 money[SILVER]);

  return 1;
}
