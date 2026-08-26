
inherit COMMAND_BASE;

mixed cmd(string str) {
  if(creatorp(TP) || TP->query_property("setm")) {
    str = str + " ";
    if(sizeof(explode("^"+str, "$N")) < 2 ||
       sizeof(explode("^"+str, "$F")) < 2)
      return notify_fail("Must have a $N and a $F in your entry message.\n");
    TP->set_msgin(str);
    write("Ok.\n");
    return 1;
  }
  return notify_fail("You are not allowed that power yet.\n");
} /* cmd() */

mixed *query_patterns() {
   return ({ "<string>", (: cmd($4[0]) :) });
} /* query_patterns() */
