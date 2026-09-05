suppress_local_cmds()
{
  add_action("cmd_sell", "sell");
}

cmd_sell(str)
{
  return call_other("/bin/play/_sell", "cmd_sell", str);
}
