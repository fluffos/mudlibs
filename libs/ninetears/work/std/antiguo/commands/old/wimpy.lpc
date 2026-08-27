/* not to be used yet..
 * Baldrick.
 */
int toggle_wimpy(string str) 
  {
string wimpy;
  if (!str) {
    notify_fail("Usage: "+query_verb()+" <num> (caution read help wimpy)\n");
    return 0;
  } else {
    if (sscanf(str, "%d", wimpy) != 1) {
      notify_fail("You must set wimpy to a number.\n");
      return 0;
    }
    if (wimpy < 0 || wimpy > 100) {
      notify_fail("Wimpy must be in the range 0-100, 0 turning wimpy off.\n");
      wimpy = 0;
      return 0;
    }
  }
  if (wimpy)
    write ("You are in wimpy mode, you will run away at "+wimpy+
           "% of your max hps.\n");
  else
    write("You are in brave mode.\n");
  return 1;
}
