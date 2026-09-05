id(str) {
  return  str == "locklist";
}
init() {
   add_action("add_locklist","addlock");
   add_action("add_msglist","addmsg");
   add_action("savelist","savelock");
   add_action("clear_locklist","clearlock");
   add_action("list_locks","listlock");
}
short() { return "The Lock List"; }
long() { 
  write(short()+"\n");
  write("addlock <addr>\n");
  write("savelock\n");
  write("clearlock <num>\n");
  write("listlock\n");
  write("addmsg <num> <msg>\n");
  return 1;
}
get() { return 1; }
add_locklist(arg) { 
 call_other("obj/locklist", "add_locklist", arg); 
 write(arg +" added.\n");
 return 1;
}
savelist() { 
  call_other("obj/locklist", "savelist", 0); 
  write("locklist saved.\n");
  return 1;
}

list_locks() { 
  call_other("obj/locklist", "list_locks",0); 
  return 1;
}
add_msglist(arg) { 
  call_other("obj/locklist", "add_msglist", arg); 
  write(arg +" added.\n");
  return 1;
}

clear_locklist(arg) { 
  int argg;
  sscanf(arg,"%d",argg);
  call_other("obj/locklist", "clear_locklist",argg); 
  write(arg +"cleared\n");
  return 1;
}
