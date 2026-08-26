
inherit COMMAND_BASE;

int cmd(string which, string type) {
  string t, disp;

  if(!type) {
    disp = "Your settings are: ";
    foreach(t in TP->query_verbose_types()) {
      disp += t + (TP->query_verbose(t) ? " (verbose) " : " (brief) ");
    }
    write(disp + "\n");
    return 1;
  }

  if(type == "all") {
    foreach(t in TP->query_verbose_types()) {
      TP->set_verbose(t, which == "verbose");
    }
    write("Ok\n");
    return 1;
  } else if(member_array(type, TP->query_verbose_types()) != -1) {
    TP->set_verbose(type, which == "verbose");
    write("Ok\n");
    return 1;
  }
}


mixed *query_patterns() {
  return ({ "<word'type'>", (: cmd("verbose", $4[0]) :),
            "", (: cmd("verbose", 0) :),
         });
} /* query_patterns() */
