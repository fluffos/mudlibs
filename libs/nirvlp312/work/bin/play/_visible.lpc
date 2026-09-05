/* 08/19/06 Earwax: Daemonized this */

int cmd_visible (string arg) 
{
  
  if(this_player() && (int)this_player()->query_invis() > 20)
    command("vis", this_player());
  else
    write("You are now visible.\n");
  this_player()->unset_invs_sp();
  say((string)this_player()->query_name());
  say(" appears in a puff of smoke.\n");
  return 1;
}
