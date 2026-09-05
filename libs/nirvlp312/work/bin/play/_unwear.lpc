int cmd_unwear(string str)
{
  object obj;
  if(!str)
  {
    write("Remove what?\n");
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
