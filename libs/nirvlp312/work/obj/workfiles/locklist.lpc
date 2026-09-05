#ifndef __LDMUD__
string msglist,locklist;
#define maxlock 20

add_locklist(arg) {
int i;
if(!this_player() || this_player()->query_level() < 40) return 0;
log_file("LOCKLIST", this_player()->query_name()+" "+arg+"\n");
 while (i<maxlock) {
  if(!locklist[i]) {
    locklist[i] = arg;
    i=maxlock;
  }
  i+=1;
  }
   savelist();
  return 1;
}
check_locklist(arg) {
int i;
string ajunk,bjunk;
string a,b,c,d;
 while (i<maxlock) {
  if(locklist[i]) {
    if(locklist[i] == arg) return arg;
    if(sscanf(arg, "%s.%s.%s.%s", a,b,c,d) == 4) {
      if(a+"."+b+"."+c == locklist[i]) return msglist[i];
      if(a+"."+b == locklist[i]) return msglist[i];
    }
  } 
  i+=1;
 }
return 0;
}

reset(arg) {
 if(arg) return;
 locklist=allocate(20);
 msglist=allocate(20);
 restore_object("obj/locklist");
}
savelist() {
 save_object("obj/locklist");
}
clear_locklist(arg) {
int i;
if(!this_player() || this_player()->query_level() < 99) return 0;
  locklist[arg] = 0;
 return 0;
}
list_locks() {
  int i;
  while (i<maxlock) {
    write(i+"\t"+locklist[i]+"\t"+msglist[i]+"\n");
      i+=1;
  }
  return 1;
}

add_msglist(arg) {
int i;
string msg;
  if(!this_player() || this_player()->query_level() < 40) return 0;
  if(sscanf(arg,"%d %s",i,msg) != 2) {
    write("<number> <msg>\n");
    return 1;
  }
  msglist[i] = msg;
  log_file("LOCKLIST", this_player()->query_name()+" "+arg+"\n");
  return 1;
}
#else
string *msglist;
string *locklist;

#define maxlock 20

void savelist() {
  save_object("obj/locklist");
}

int add_locklist(string arg) {
  int i;

  if (!this_player() || (int)this_player()->query_level() < 40)
    return 0;
  log_file("LOCKLIST", this_player()->query_real_name() + " " + arg + "\n");
  while (i < maxlock) {
    if (!locklist[i]) {
      locklist[i] = arg;
      i = maxlock;
    }
    i += 1;
  }
  savelist();
  return 1;
}

string check_locklist(string arg) {
  int i;
  string ajunk, bjunk, a, b, c, d;

  while (i < maxlock) {
    if (locklist[i]) {
      if (locklist[i] == arg)
        return arg;
      if (sscanf(arg, "%s.%s.%s.%s", a, b, c, d) == 4) {
        if (a + "." + b + "." + c == locklist[i])
          return msglist[i];
        if (a + "." + b == locklist[i])
          return msglist[i];
      }
    }
    i += 1;
  }
  return 0;
}

void reset(status arg) {
  if (arg)
    return;
  locklist = allocate(20);
  msglist = allocate(20);
  restore_object("obj/locklist");
}

int clear_locklist(int arg) {
  locklist[arg] = 0;
  return 0;
}

int list_locks() {
  int i;

  while (i < maxlock) {
    write(i + "\t" + locklist[i] + "\t" + msglist[i] + "\n");
    i += 1;
  }
  return 1;
}

int add_msglist(string arg) {
  int i;
  string msg;

  if (!this_player() || (int)this_player()->query_level() < 40)
    return 0;
  if (sscanf(arg, "%d %s", i, msg) != 2) {
    write("<number> <msg>\n");
    return 1;
  }
  msglist[i] = msg;
  log_file("LOCKLIST", this_player()->query_real_name() + " " + arg + "\n");
  return 1;
}
#endif

