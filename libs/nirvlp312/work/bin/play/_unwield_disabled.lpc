int cmd_unwield(string str)
{
  object obj;
  if(!str)
  {
    write("Unwield what?\n");
    return 1;
  }
  if(!(obj = present(str, this_player())))
  {
    notify_fail("You do not have \""+str+"\".\n");
    return 0;
  }
  if(!obj->is_weapon())
  {
    notify_fail((string)obj->query_name()+" is not a weapon!\n");
    return 0;
  }
  return (int)obj->stopwield();
}
