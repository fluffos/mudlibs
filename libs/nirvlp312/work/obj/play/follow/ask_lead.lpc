int      r; 
string   leader, follower;

status id(string str) { return str == "LeadRequestObject"; }

void init()
{
    add_action("ReqLead","ReqLead");
}

void set_leader(string S) { leader = S; }
void set_follower(string F) { follower = F; }

int ReqLead()
{
    if(!r)
    {
      write(capitalize(leader) + " asks if you will follow " + 
       objective(find_player(leader)) + ".\n");
      write("Do you accept? [y/n] ");
      r = 1;
      input_to("chtxt");
      return 1;
    }
    else return 0;
}

int chtxt(string str)
{
    if(str == "Y" || str == "y" || str == "yes")
    {
      if(!find_player(leader))
        write(capitalize(leader) + " has disappeared...\n");
      else if(!interactive(find_player(leader)))
        write(capitalize(leader) + " has gone linkdead.\n");
      else if(!environment(find_player(leader)) ||
(environment(find_player(leader)) != environment(this_player())))
        write(capitalize(leader) + " has left the area.\n");
      else
      {
        write("Okay, you are now following "+capitalize(leader)+".\n");
        this_player()->set_leader(find_player(leader));
        this_player()->do_follow();
        find_player(leader)->add_follower(follower);
        tell_object(find_player(leader),
        "Okay, you are now leading "+capitalize(follower)+".\n");      
      }
    }
    else
    {
      write("You decline the lead request.\n");
      if(find_player(leader))
        tell_object(find_player(leader),
         capitalize(follower) + " has denied your lead request.\n");
      if(str && str != "n" && str != "no" && str != "N")
      command(str, this_player());
    }
    destruct(this_object());
    return 1;
}

drop() { return 1; }
