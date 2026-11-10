int different(string fn, string pr) {
    int tmp;

    sscanf(fn, "%s#%d", fn, tmp);
    fn += ".lpc";
    return (fn != pr) && (fn != ("/" + pr));
}

string trace_line(object obj, string prog, string file, int line) {
    string ret;
    string objfn = obj ? file_name(obj) : "<none>";

    ret = objfn;
    if( different(objfn, prog) ) ret += sprintf(" (%s)", prog);
    if( file != prog ) ret += sprintf(" at %s:%d\n", file, line);
    else ret += sprintf(" at line %d\n", line);
    return ret;
}

varargs string standard_trace(mapping mp, int flag) {
    string ret;
    mapping *trace;
    int i,n;

    ret = mp["error"] + "Object: " +
      trace_line(mp["object"], mp["program"], mp["file"], mp["line"]);
    ret += "\n";
    trace = mp["trace"];
    n = sizeof(trace);
    for (i=0; i<n; i++) {
        if( flag ) ret += sprintf("#%d: ", i);
        ret += sprintf("'%s' at %s", trace[i]["function"],
                       trace_line(trace[i]["object"], trace[i]["program"],
                                  trace[i]["file"], trace[i]["line"]));
    }
    return ret;
}

string error_handler(mapping mp, int caught) {
  string ret, file;

  ret = "---\n" + standard_trace(mp);
  if( caught ) write_file(file = "/log/catch", ret);
  else write_file(file = "/log/runtime", ret);
  if( this_player(1) ) {
    if( find_object(SEFUN_OBJ) && creatorp(this_player(1)) ) {
    //if( find_object(SEFUN_OBJ) ) {
      message("error", mp["error"] + "Trace written to " + file,
              this_player(1));
      //this_player(1)->SetLastError(mp);
    }
  }
  return ret;
}
 
