/*
Originally written by Mythos for his speedster.
Heavily modified by Feldegast for use in /bin
4-14-00
*/

/* This is a list of guilds who cannot use speeding. */
#define BAD_GUILDS ({ "rangers" })

cmd_run(str) {
  object obj;
  string *cmds;
  int v;
  /* conflicts */
  if(!str) {
    write("Usage: run <cmd1,cmd2,etc.>\n");
    return 1;
  }
  if(member_array(this_player()->query_guild_name(),BAD_GUILDS)!=-1) {
    notify_fail("You may not use this command.\n");
    return 0;
  }
  if(obj=present("run_object", this_player()))
    return (int)obj->do_run(str);
  cmds=explode(str,",");
  if(sizeof(cmds) > 0)
    for(v=0; v < sizeof(cmds); v++) {
      if(v >= 5) {
        write("You cannot perform more than five commands.\n");
        return 1;
      }
      if(member_array(cmds[v],({ "n", "e", "s", "w",
                                 "ne", "nw", "se", "sw",
                                 "u", "d",
                                 "enter", "in", "out", "leave" 
                              })) == -1) {
        write("The action "+cmds[v]+" may not be done.  Run commands aborted.\n");
        return 1;
      }
      command(cmds[v],this_player());
    }
  write("Run done.\n");
  return 1;
}

