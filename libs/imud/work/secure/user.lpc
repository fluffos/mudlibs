// This users's userid (login id).
private string		userid;
nomask string query_userid()
{
  /*
  ** NOTE: allow this to return 0 so that callers can know that we
  ** are still in the login sequence.
  */
  return userid;
}

private nomask void net_dead()
{
  destruct();
}

private nomask void logon()
{
  write("welcome to imud.fluffos.info\n");
  write("The only command supported are: mudlist\n");

  write("\n--- IMUD STAT ---\n");
  write("/secure/imud/imud"->stat_me() + "\n");
  write("\n-----------------\n");

  enable_commands();
  add_action("commandHook", "", 1);

  write(">");
}

string process_input(string arg)
{
  // possible to modify player input here before driver parses it.
  return arg;
}

#define COMMAND_PREFIX "/secure/commands/"

int commandHook(string arg) {
  string cmd_path;
  object cobj;

  cmd_path = COMMAND_PREFIX + query_verb();

  cobj = load_object(cmd_path);
  if (cobj) {
    return (int)cobj->main(arg);
  } else {
    // maybe call an emote/soul daemon here
  }
  return 0;
}
