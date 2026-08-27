#include <command.h>
#include <daemons.h>
//
// user command for setting environment variables
//
int
main(string arg)
{
  mapping env = this_player()->get_environment();

  if( !arg || arg == "" ) {
    string *lines = ({ "  variable     value",
		       "  --------     -----" });

    foreach(string key, mixed val in env)
      lines += ({ sprintf("  %-10s   %-s", key, to_string(val)) });
    this_player()->more(lines);
  } else if( query_verb() == "setenv" ) {
    string key;
    mixed val;

    if( sscanf(arg, "%s %d", key, val) != 2 &&
        sscanf(arg, "%s %s", key, val) != 2 )
      return notify_fail("usage: set | set <variable name> <value>\n");

    key = replace_string(key, " ", "");  // strip spaces from key names

    if( key == "PATH" ) {
      foreach(string path in explode(val, ":"))
	if( !CMD_D->hashed_path(path) ) CMD_D->hash_path(path);
    }

    this_player()->set_env(key, val);
    printf("%s=%O\n", key, val);
  } else if( query_verb() == "unsetenv" ) {
    if( env[arg] ) {
      printf("%s removed\n", arg);
      this_player()->set_env(arg, 0);
    } else
      return notify_fail("unset: no such environment variable.\n");
  }

  return 1;
}
