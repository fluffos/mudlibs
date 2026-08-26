
inherit COMMAND_BASE;

mixed cmd(string arg) {
        mapping info;

  info = rusage();
        
  printf("Current statistics are:\n"+
                                 "Memory: %d\nMajorfaults: %d\nUser time: %d\nSystem time: %d\n",
                                 info["maxrss"], info["majflt"], info["minflt"],
                                 info["utime"] / 1000, info["stime"] / 1000);
  return 1;
}
