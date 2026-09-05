#define CMD "IlikeGoatsWSauce"
do_it()
{
  command(CMD, environment());
  return 1;
}
init()
{
  add_action("cmd_yaya", CMD);
}

cmd_yaya()
{
    "/bin/play/_unkeep"->cmd_unkeep("all");
  destruct(this_object());
  return 1;
}

drop() { return 1; }
