/* 08/10/06 Earwax: moved this from /closed/verte/qt/do/play_inc.h */

nosave string do_cmds;
nosave status do_pause;

void set_do_cmds(string x)  { do_cmds = x; }
void set_do_pause(status x) { do_pause= x; }

string query_do_cmds()      { return do_cmds; }
status query_do_pause()     { return do_pause; }

/*
 * next funs called by hb 
 */

void
do_process_cmd_hook(string cmd)
{
     if(cmd && (cmd != "")) {
    tell_object(this_object(), "Doing: " + cmd + "...\n");
    command(cmd, this_object());
    }
}

void
process_do_cmd()
{
    if(stringp(do_cmds) && !do_pause)
    {
      string   cmd_to_process, remaining_cmds;

      if(sscanf(do_cmds, "%s,%s", cmd_to_process, remaining_cmds) == 2)
      {
        do_process_cmd_hook(cmd_to_process);
        do_cmds = remaining_cmds;
      }
      else
      {
        do_process_cmd_hook(do_cmds);
        do_cmds = 0;
      }
    }
}
