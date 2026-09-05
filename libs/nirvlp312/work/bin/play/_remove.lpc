int cmd_remove(string str)
{
  object obj;
  if(!str)
  {
    write("Remove what?\n");
    return 1;
  }
  if(str=="all")
  {
    object *obs;
    int    x, s;
    s = sizeof(obs = all_inventory(this_player()));
    write("Removing all worn armors in your inventory...\n");
    for(x=0;x<s;x++)
    {
      if(obs[x] && obs[x]->is_armor() && obs[x]->query_worn())
      {
        write("Removing "+obs[x]->short()+"...\n");
        obs[x]->remove((string)obs[x]->query_name());
      }
    }
    write("Ok.\n");
    return 1;
  }
  if(!(obj = present(str, this_player())))
  {
    notify_fail("You do not have \""+str+"\".\n");
    return 0;
  }
  if(!obj->is_armor())
  {
    notify_fail((string)obj->query_name()+" is not an armor!\n");
    return 0;
  }
  return (int)obj->remove((string)obj->query_name());
}
