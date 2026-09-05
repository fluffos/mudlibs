#pragma strict_types

status cmd_disallow_give(string str)
{
  if((status)this_player()->query_disallow_give())
  {
    write("Players will now be able to give you things.\n");
    this_player()->set_disallow_give(0);
    return 1;
  }
  else
  {
    write("Players will no longer be able to give you things.\n");
    this_player()->set_disallow_give(1);
    return 1;
  }
}
