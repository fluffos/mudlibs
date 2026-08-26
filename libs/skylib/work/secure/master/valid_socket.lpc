/*  -*- LPC -*-  */

int valid_socket(object ob, string func, mixed *info) {
  string fname;

  fname = file_name(ob);
  if (func != "external") {
    switch (explode(fname, "/")[0]) {
      case "net" :
      case "secure" :
        return 1;
    }
  } else {
    if (fname[0..11] == "/secure/cmds")
      return 1;
  }
  
  return 0;
} /* valid_socket() */
