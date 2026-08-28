string *terminals = ({ "unknown", "vt100", "ansi", "html", "xterm", "raw",
                       "majik" });

int
main (string str)
{
  string s;
  int n;

  if (!str)
    {
      notify_fail ("Usage: set rows <n>/columns <n>\n");
      return 0;
    }

  if (sscanf (str, "%s %d", s, n) == 2)
    {
      if (n < 1)
        {
          write ("Too small.\n");
          return 1;
        }

      if (lower_case(s) == "rows")
        THIS->set("rows", n);
      else if (lower_case(s) == "columns")
        THIS->set("columns", n);
      else
        {
          write ("You cant set "+s+"!\n");
          return 1;
        }

      write (upper_case(s) + " set to "+n+".\n");
      write ("Your settings are now: "+THIS->query_columns()+"x"+THIS->query_rows()+" "+terminals[THIS->query("term")]+"\n");
      return 1;
    }
  else
    {
      notify_fail ("Usage: set rows <n>/columns <n>\n");
      return 0;
    }

  return 1; 
}

query_author()
{
  return"namhas";
}

query_help()
{
  return "You can set the width and height of you monitor in rows and columns"
  + " to equal <n>.";
}

query_see_also()
{
  return"term(1),sclear(1)";
}

query_synopsis()
{
  return "set < rows <n> | columns <n> >";
}
