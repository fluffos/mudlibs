// /global/cmd/cmds/cmd.c (confusing hey? :)
// Gives info on command handler, commands etc :)

#include <standard.h>
#include <cmd.h>

inherit CMD_BASE;

nosave mapping cmd_dirs, cmd_hash;
nosave string last_dir, file;

void setup()
{
  position = 0;
}

string query_usage()
{
  return "cmd verb";
}

string query_short_help()
{
  return "Find information on a specified command.";
}

protected int cmd(string tail, object thisob)
{
  string str, *s;

  if(!tail || tail=="")
  {
    notify_fail("Get information on what command?\n");
    return 0;
  }

  str = "";
  s = ({ });

  str = (string)CMD_HANDLER->query_alias(tail);
  if(stringp(str) && str!=0 && str!="")
    tail = str;

  file = (string)CMD_HANDLER->find_cmd(tail);

  if(!file || file=="")
  {
    write("Command '"+tail+"' was not found.\n");
    return 1;
  }

  cmd_dirs = (mapping)CMD_HANDLER->query_cmds();
  cmd_hash = (mapping)CMD_HANDLER->query_hash();
  last_dir = (string)CMD_HANDLER->query_last_dir();

  s += ({ "Command: "+tail });
  s += ({ "File: "+file });
  s += ({ "Directory: "+last_dir });
  s += ({ "Command type: "+cmd_dirs[last_dir][1] });
  s += ({ "Access count: "+cmd_hash[tail]["count"] });

  write(implode(s, "\n")+"\n");

  return 1;
}
