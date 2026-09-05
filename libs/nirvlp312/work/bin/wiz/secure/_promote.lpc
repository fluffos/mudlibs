object grantee;

nomask int cmd_promote(string str) 
{
  int rec_lev;
    
  if(!str) 
  {
    write ("You must name someone.\n");
    return 1;
  }
  grantee = present(str,environment(this_player())) /*find_player(str)  uncomment when command avail*/;

  if(!grantee) 
  {
    write(str+" is not within range.\n");
    return 1;
  }

  rec_lev = (int)grantee->query_level();

  if(rec_lev >= 10000 && (int)this_player()->query_level() < 10000)
  {
    write("You can't mess with a god!\n");
    return 1;
  }
  if(rec_lev > (int)this_player()->query_level()) 
  {
    write("You can't change a more powerful wizard!\n");
    return 1;
  }
  if((int)this_player()->query_level() < 100)
  {
    write("You are still a junior wizard and can't grant power!\n");
    return 1;
  }

  if(((int)this_player()->query_level() < 10000 && rec_lev >= 1000) ||
      ((int)this_player()->query_level() < 1000 && rec_lev >= 100))
  {
    write("You may not grant power to your peers\n");
    return 1;
  }

  write("What level do you want to grant "+str +"?\n"+
         capitalize(str) + " is level "+rec_lev+" now.\n");
  input_to("grant_level2");
  return 1;
}

grant_level2(string str) 
{
  int rec_lev;
  if(!str) 
  {
    grantee = 0;
    write("Aborted.\n");
    return 1;
  }
  if(!grantee)
  {
    write("Level setting eror.\n");
    illegal_patch("grant_level2");
  }
  sscanf(str,"%d",rec_lev);
  if(!rec_lev)
  {
    write("Invalid integer.\n");
    return 1;
  }

  if((int)grantee->query_level() > 20 && rec_lev< 20 && (int)this_player()->query_level() < 1000) 
  {
    write("Only a god can take away wizard status");
    return 1;
  }
  if(((int)this_player()->query_level() < 10000 && rec_lev >= 1000) ||
     ((int)this_player()->query_level() < 1000 && rec_lev >= 100)) 
  {
    write("You may not promote someone to the status of a peer"+
          " or higher.\n");
    return 1;
  }
  grantee->set_wiz_level(str);
  write("Level "+str+" granted.\n");
  tell_object(grantee, "soul off / soul on to enjoy your new abilities.\n");
  grantee->save_me(1);
  return 1;
}
