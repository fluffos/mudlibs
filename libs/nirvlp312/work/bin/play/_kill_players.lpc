int cmd_kill_players(string str)
{
  if((int)this_player()->query_level() < 8)
  {
    write("Your level is not high enough, young adventurer.\n");
    return 1;
  }
  if(str)
  {
    if(str == "spar")
    {
      if(!environment(this_player())->query_spar_area())
      {
        write("You are not in a sparring area.\n");
        return 1;
      }
      else
      {
        int cpk;
        
        cpk = (int)this_player()->query_pl_k();
        if(cpk == 3) {
          write("Your sparring flag is ALREADY set.\n");
          return 1;
        }
        this_player()->set_pl_k(cpk ? 3 : 2);
        write("Your sparring flag has been set.\n");
        return 1;
      }
    }
    else
    {
      write("You may only 'kill_players' or 'kill_players spar'.\n");
      return 1;
    }
  }
  else
  {
    object obj;
    if((int)this_player()->query_pl_k() == 1 || (int)this_player()->query_pl_k() == 3)
    {
      write("Your PK flag is ALREADY set.\n");
      return 1;
    }
    obj = clone_object("/obj/user/pk/pk_confirm");
    obj->setting_pk();
    return 1;
  }
}
