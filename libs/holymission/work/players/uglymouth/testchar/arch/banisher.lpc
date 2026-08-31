/*
 * A banisher tool
 * by Viking Lord Uglymouth, 24-Apr-1994
 */
#define WARNINGDIR "/banish/warning/"
#define TP this_player()

int id(string str) {
  return str == "banisher";
}

string short() {
  return "A banisher";
}

void long() {
  printf("%s\nThis is a sheriff's tool to banish or unbanish people.\n"
    + "Use '(un)banish <name> for <reason>'.\n", short());
}

int get()  { return 1; }
int drop() { return 1; }

string query_auto_load() {
  return "obj/banish:";
}

void init() {
  add_action("do_banish", "banish");
  add_action("do_unbanish", "unbanish");
}

int do_banish(string str) {
  string pname, reason, pfile;
  if(!"/banish/bantool"->query_sheriff(TP->query_real_name())) {
    printf("The banisher reports you to the sheriffs for illegal use.\n"
      + "The banisher vanishes into another dimension.\n");
    write_file(WARNINGDIR + this_interactive()->query_real_name(), ctime(time())
      + " Tried to use banisher to banish " + str + "\n");
    destruct(this_object());
    return 1;
  }
  if(sscanf(str, "%s for %s", pname, reason) != 2) return 0;
  pname = lower_case(pname);
  if(!strlen(plfile = read_file("/p/"+pname[0..0]+"/"+pname+".o"))) {
    notify_fail("There is no player called "+capitalize(pname)+" in Holy Mission.\n");
    return 0;
  }
  if(file_size("/banish/"+pname+".o") > 0) {
    notify_fail("That player is already banished.\n");
    return 0;
  }
  if(!"/banish/bantool"->do_banish(pname, reason)) {
    return notify_fail("You fail to banish " + name + ".\n");
  }
  printf("You banish "+capitalize(pname)+".\n");
  return 1;
}

int do_unbanish(string str) {
  string pname, reason, plfile;
  if(!"/banish/bantool"->query_sheriff(TP->query_real_name())) {
    printf("The banisher reports you to the sheriffs for illegal use.\n"
      + "The banisher vanishes into another dimension.\n");
    write_file(WARNINGDIR + this_interactive()->query_real_name(), ctime(time())
      + " Tried to use banisher to unbanish " + str + "\n");
    destruct(this_object());
    return 1;
  }
  if(sscanf(str, "%s for %s", pname, reason) != 2) return 0;
  name = lower_case(name);
  if(file_size("/p/" + pname[0..0] + "/" + pname + ".o) <= 0) {
    notify_fail("There is no player called " + capitalize(pname)
      + " in Holy Mission.\n");
    return 0;
  }
  if(file_size("/banish/"+pname+".o") == -1) {
    notify_fail("That player was not banished.\n");
    return 0;
  }
  if(!"/banish/bantool"->do_unbanish(name, reason))
    return notify_fail("You fail to unbanish " + name + ".\n");
  printf("You unbanish "+capitalize(name)+".\n");
  return 1;
}
