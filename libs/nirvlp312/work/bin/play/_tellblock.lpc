int cmd_tellblock(string str)
{
  if(!str || str == "on")
  {
    this_player()->set_tellblock_index(0,"on");
    write("Total tellblock is on.\n");
    return 1;
  }
  if(str == "off")
  {
    write("Tellblock is off.\n");
    this_player()->set_tellblock_index(0,"off");
    return 1;
  }
  if(str == "reverse") {
    write("Reversing list.\n");
    this_player()->set_tellblock_index(0,"reverse");
    return 1;
  }
  else
  {
    int i,numloc;
    string nombloc;
    mixed *tb;
    
    tb = (mixed*) this_player()->query_tellblock_arr();
    
    if(str == "list")
    {
      if(tb[0]=="reverse") 
        write("Passing tells for: \n");
      else
        write("Tellblocking: \n");
      
      i = 1;
      while(i < 6)
      {
        if(tb[i]) 
          write("["+i+"] "+tb[i]+"\n");
        i += 1;
      }
      return 1;
    }
    if(sscanf(str,"%d %s",numloc,nombloc)!=2)
    {
      write("Usage: tellblock storagenum name | tellblock | tellblock off\n");
      return 1;
    }
    if(numloc < 1 || numloc > 5)
    {
      write("You must use locations 1, 2, 3, 4, or 5.\n");
      return 1;
    }
    
    if(tb[0] != "reverse")
      tb[0]="some";
    
    tb[numloc] = nombloc;
    
    if(tb[0] == "reverse")
      write("Passing tells for: \n");
    else
      write("Tellblocking: \n");
    
    i = 1;
    while(i < 6)
    {
      if(tb[i]) 
        write("["+i+"] "+tb[i]+"\n");
      i += 1;
    }
    this_player()->set_tellblock_arr(tb);
    return 1;
  }
}