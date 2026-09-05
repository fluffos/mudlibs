int      r; 
string   leader, follower;

mixed id(string str) { return str == "FollowRequestObject"; }

void init()
{
    add_action("ReqFol","ReqFol");
}

void set_leader(string S) { leader = S; }
void set_follower(string F) { follower = F; }

int ReqFol()
{
    if(!r)
    {
      write(capitalize(follower) + " asks you if " + 
       subjective( find_player(follower) ) + " can follow you.\n");
      write("Do you accept? [y/n] ");
      r = 1;
      input_to("chtxt");
      call_out("dest_me", 30);
      return 1;
    }
    else return 0;
}

int chtxt(string str)
{
    if(str == "Y" || str == "y" || str == "yes")
    {
      if(!find_player(follower))
        write(capitalize(follower) + " has disappeared...\n");
      else if(!interactive(find_player(follower)))
        write(capitalize(follower) + " has gone linkdead.\n");
      else if(!environment(find_player(follower)) || (environment(find_player(follower)) != environment(this_player())))
        write(capitalize(follower) + " has left the area.\n");
      else
      {
        this_player()->add_follower(follower);
        write("Okay, you are now leading "+capitalize(follower)+".\n");
        find_player(follower)->set_leader(this_player());
        find_player(follower)->do_follow();
        tell_object(find_player(follower),
        "Okay, you are now following "+capitalize(leader)+".\n");      
      }
    }
    else
    {
      write("You decline the follow request.\n");
      if(find_player(follower))
        tell_object(find_player(follower),
         capitalize(leader) + " has denied your follow request.\n");
      if(str && str != "n" && str != "no" && str != "N")
      command(str, this_player());
    }
    while(remove_call_out("dest_me") != -1);
    destruct(this_object());
    return 1;
}

drop() { return 1; }

void dest_me()
{
  if(environment()) {
    tell_object(environment(), "\nPending follow request has timed out.\n");
  }
  destruct(this_object());
}
