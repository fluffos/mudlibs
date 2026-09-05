int cmd_rrm(string arg, string verb) {
  string *args;
  int i;
  
  if (!arg)
    args = ({ });
  else
    args = explode(arg," ")-({});
  if (!sizeof(args)) {
#if 0  /* Not sure why this isn't working, driver issue i'm guessing - Rump
        */
    notify_fail("rm what?\n", -1);
else
    notify_fail("rm what?\n");
#endif
    return 0;
  }
  for (i=0; i<sizeof(args); i++)
    write("rm " + args[i] + (rm(args[i]) ? ": Ok.\n" : ": Failed.\n"));
  return 1;
}
