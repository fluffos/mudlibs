/* 07/19/06 Earwax
 * Evaluation tool for testing out processing demands.
 */

status
cmd_testeval(string str)
{
  int i, total;

  for (i = 0; i < 100; i++)
  {
    total += command("testeval2", this_player());
  }

  write("100 executions performed, average is: ");
  write((total/100));
  write("\n");
  return 1;
}
