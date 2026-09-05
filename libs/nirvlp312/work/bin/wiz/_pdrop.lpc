nomask int cmd_pdrop(string str)
{
  if(!str) return 0;
  if((int)this_player()->query_level() < 80)
    return 0;

  this_player()->drop_thing("! "+str); 
}