/****
*  *    Command                         explore
* *     Description                     Shows how much you have explored
**      Coder                           Dazzt, Revised by Namhas
*/


int main()
{
    message ("misc", "You have explored about ^c1" + THIS->query_explore_percent() +
    "^c0% (" + THIS->query_explore() + "/" + EXPLORE_D->query_total() +
    ") of the world.\n", THIS);

    return 1;
}

query_author ()
{
  return "namhas";
}

query_help ()
{
  return "This command displays the amount of rooms you have explored "
       + "of the world. It also tells you the percentage of all rooms "
       + "that you have explored also. The more you explore and learn "
       + "about the murpe, the more explored player you shall become.";
}

query_see_also ()
{
  return "score(1)";
}
