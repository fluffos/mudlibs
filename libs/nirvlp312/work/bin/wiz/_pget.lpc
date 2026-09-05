nomask int cmd_pget(string str)
{
  if(!str) return 0;
  if((int)this_player()->query_level() < 80)
    return 0;

  this_player()->pick_up("! "+str); 
}