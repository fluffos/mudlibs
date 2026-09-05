inherit "/bin/wiz/run_mod";

#define KEYWORD "hyarThatLonesomeWhippleWind"

int cmd_run(string str)
{
  if((int)this_player()->query_level() < 40) return 0;
  if(!str) return (write("Usage: 'run <file>'\n"), 1);
  str = resolve_path(str);
  return (run_command_file(str, KEYWORD), 1);
}
