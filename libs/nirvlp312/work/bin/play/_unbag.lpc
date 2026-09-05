int cmd_unbag(string str)
{
  object bag_obj;
  string what, where;
  if(!str)
  {
    notify_fail("Unbag what?\n");
    return 0;
  }
  if(sscanf(str,"%s from %s",what,where)<2)
  {
    what = str;
    where = "bag";
  }
  if(!(bag_obj = present(where, this_player())))
    bag_obj = present(where, environment(this_player()));
  if(!bag_obj || !bag_obj->short())
  {
    write("You don't have a "+where+".\n");
    return 1;
  }
  command("get "+what+" from "+where, this_player());
  return 1;
}
