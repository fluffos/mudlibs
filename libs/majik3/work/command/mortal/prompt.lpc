int
main (string str)
{
  if (!str)
    {
      write ("Usage: prompt <prompt string>\n\n");
      write ("Prompt string can contain several special tags:\n\n");
      write ("  <hp>      - percentage of current hit points\n");
      write ("  <ep>      - percentage of current endurance points\n");
      write ("  <sp>      - percentage of current spell points\n");
/*
      write ("  <maxhp>   - maximum hit points\n");
      write ("  <maxep>   - maximum endurance points\n");
      write ("  <maxsp>   - maximum spell points\n");
      write ("  <hp%>     - hit points percent\n");
      write ("  <ep%>     - endurance points percent\n");
      write ("  <sp%>     - spell points percent\n");
*/
      write ("  <money>   - carried money\n");
      write ("  <lf>      - line feed\n");
      write ("  <cr>      - carriage return\n");
      write ("  <explore> - explore percent\n");
      write ("  <rooms>   - explore count\n");
      write ("  <time>    - current time\n");
      write ("  <cwd>     - current working directory (wiz only)\n\n");
      write (wrap("You can also \"prompt clear\" to reset defaults. Colors described in \"help colors\" are also accepted. To turn the prompt totally off, try \"prompt off\".\n"));
      return 1;
    }
  if (str == "clear")
    THIS->set("prompt", 0);
  else {
    write ("Your prompt is now: "+str+"\n");
    THIS->set("prompt", str);
  }
  return 1;
}

query_synopsis()
{
  return"prompt <prompt string>";
}

query_help()
{
  return "You can change your prompt and customize it to look what ever you"
  + " like. There are numerous variables you can add in the prompt, thus"
  + " making it very effective way of keeping eye on your characters"
  + " basic stats.\n"
  + "\n"
  + "Prompt string can contain several special tags:"
  + "\n"
  + "<hp>      - percentage of current hit points\n" 
  + "<ep>      - percentage of current endurance points\n" 
  + "<sp>      - percentage of current spell points\n"
  + "<money>   - carried money\n"
  + "<lf>      - line feed\n"
  + "<cr>      - carriage return\n" 
  + "<explore> - explore percent\n"
  + "<rooms>   - explore count\n"
  + "<time>    - current time\n"
  + "<cwd>     - current working directory (wiz only)\n";
}

query_example()
{
  return "prompt HP:<hp> SP:<sp><lf>Money:<money>\n"
  + "\n"
  + "        HP:100 SP:100\n" 
  + "        Money:0";
}

query_author()
{
  return "namhas";
}

query_position ()
{
  return POS_RESTING;
}

