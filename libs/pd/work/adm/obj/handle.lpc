void error_handler(mapping map, int flag) {
  object ob;
  string str, name="", pname="";
  int i, x;
  string *k, uid="";
  ob = this_interactive() || this_player();
  if (flag) str = "*Error caught\n";
  else str = "";
   if(map["object"])
  if(map["object"]->is_player()) name = ""+map["object"]->query_name();
  if(ob) {
    if(ob->is_player()) pname = "("+ob->query_name()+")";
    uid = "uid: " + getuid(ob) + " euid: " + geteuid(ob);
  }
  str += sprintf("\nError: %s"
     "   Time: %s\n   Current object: %O %s (%s)\n   Caller object: %O %s\n   Current program: %s\n   File: %O Line: %d\n",
                 map["error"], (string)ctime(time()), (map["object"] || "No current object"), name, uid,
                 (ob || "No Caller Object"), pname, 
                 (map["program"] || "No current program"),
                 map["file"], map["line"]);
  str += "---------- TRACE - TRACE - TRACE ----------\n";
  x = sizeof(map["trace"]);
  while(x--) {
    i = sizeof(k=keys(map["trace"][x]));
    while(i--)
      str += "    " + k[i] + ": " + identify(map["trace"][x][k[i]])+"\n";
    str += "\n";
  }
  write_file("/log/debug.log", str);
  if(flag) { return;
    if (ob && wizardp(ob)) 
      tell_object(ob, "Error: "+map["error"]+" in "+map["file"]+":"+map["line"]);
    return;
  }
  if(strlen(str) > 8191) str = "Cannot write to your error.  Prints are limited to 8191.  Check debug.log for the error.";
  if (ob && wizardp(ob)) tell_object(ob, str); else {
    message("error", str, wizards());
   if(ob)
    message("error", sprintf("ERROR: An error has occured.  Please mail an immortal with "
            "information on what you were doing at the time of this error and the following "
            "information:\nError: %sFile: %O Line: %d", map["error"], map["file"], map["line"]), ob);
  }
}

