/* 07/19/06 Earwax
 *
 * Displays evaluation cost for a an executed command. 
 * Cost is given in terms of approximate number of LPC machine code
 * instructions executed.  More is bad, less is good.
 */

status
cmd_eval(string arg)
{
  int cost;

  if (!arg || !this_player())
    return 1;

  cost = command(arg, this_player());
  write("Eval cost:  ");
  write(cost);
  write("\n");
  return 1;
}
