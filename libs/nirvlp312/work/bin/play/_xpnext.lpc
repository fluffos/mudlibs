int
query_next_xp(int x, object ob)
{
  int    z;
  string where;
  if(!x)
    x=(int)ob->query_level();
  x=(int)ob->query_level();
  if(x == 19)
  {
    x=(int)ob->query_extra_level();
    where="/room/exlv_guild";
  }
  else
    where="/room/adv_guild";
  z=((int)where->get_next_exp(x)-(int)ob->query_exp());
  if(z<0)z=0;
  return z;
}

int
cmd_xpnext()
{
    int     x, z;
    string  where;

    if((string)this_player()->query_real_name() == "guest" ||
       ((x = (int)this_player()->query_level()) > 19) ||
       (x < 1))
      return 0;
    
    if((int)this_player()->query_extra_level() == 100)
      return (write("You have attained the highest Mortal level in Nirvana.\n"), 1);
    z=query_next_xp(x,this_player());
    if(z <= 0) write("You are ready to advance to your Next Level.\n");
    else write("Experience needed for your Next Level: " + comma_number( z ) + ".\n");
    return 1;
}
