
int follow_status()
{
    int x; string names;
    string *followers;
    object leader;
    
    leader=(object)this_player()->query_leader();
    
    followers=(string*)this_player()->query_followers();
    
    if(!followers) names = "Nobody is following you.\n";
    else
    {
      names = "You are leading:\n";
      for(x = 0; x < sizeof(followers); x++)
        if(followers[x])
        {
          if(!find_player(followers[x])) followers[x] = 0;
          else
              names += "\t"+capitalize(followers[x]) + "\n";
        }
    }
    if(!leader) write("You aren't following anybody.\n");
    else write("You are following "+leader->query_name()+".\n");
    write(names);
    return 1;
}