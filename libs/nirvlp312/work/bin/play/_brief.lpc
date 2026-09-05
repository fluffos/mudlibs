/* 08/19/06 Earwax: Daemonized */

int cmd_brief(string arg)
{
  int brief;
  
  brief = (int)this_player()->query_brief();
  
  if (brief == 2) 
  {
    write("Verbose mode.\n"); brief = 0;
  }
  else {
    write((brief) ? "Detail mode.\n" : "Brief mode.\n");
    brief++;
  }
  
  this_player()->toggle_brief(brief);
  return 1;
}
