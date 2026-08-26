// _liston.c
// recursive listing of all variables starting from a give path.
// 11/16/93 by Emeradii@EarthMud
// 11/14/94 Leto added help

#include <mudlib.h>

inherit OBJECT;

void check(string header, int first);
int help();

int cmd_liston(string str) {
  object obj;
  string path, objid;

  if (!str || (sscanf(str,"%s %s",objid,path) != 2)) {
    notify_fail("Syntax:  liston <object> <path>\n");
    return 0;
  }
  if (!(obj = find_player(objid)) && !(obj = find_object(objid))) {
    notify_fail(objid+" is not a valid object identifier.\n");
    return 0;
  }
  set("tmp",obj->query(path));
  if (!query("tmp")) {
    write("nothing in path "+path+"\n");
    return 1;
  }
  printf("%20s : ",extract(path,0,19));
  check("                       ",1);
  return 1;
}

void check(string header, int first) {
  mapping mstuff;
  mixed *stuff;
  string *keystuff;
  int i;

  if (stringp(query("tmp")) || intp(query("tmp"))) {
    write(query("tmp")+"\n");
    return;
  }
  if (objectp(query("tmp"))) {
    write("'"+file_name(query("tmp"))+"'\n");
    return;
  }
  if (mapp(query("tmp"))) {
    mstuff = query("tmp");
    keystuff = keys(mstuff);
    if (sizeof(keystuff) < 1) {
      write("([ ])\n");
      return;
    }
    for (i = 0; i < sizeof(keystuff); i++) {
      set("tmp",mstuff[keystuff[i]]);
      if (i) write(header);
      printf("%12s : ",("["+extract(keystuff[i],0,9)+"]"));
      check(header+"               ",(!i ? 1 : 0));
    }
    return;
  }
  if (pointerp(query("tmp"))) {
    stuff = query("tmp");
    if (sizeof(stuff) < 1) {
      write("({ })\n");
      return;
    }
    for (i = 0; i < sizeof(stuff); i++) {
      set("tmp",stuff[i]);
      if (i) write(header);
      printf("%12s : ",("["+i+"]"));
      check(header+"               ",(!i ? 1 : 0));
    }
    return;
  }
  write("\n");
  return;
}

int help(){

write(wrap("Syntax:  liston <object> <path>\n\n"
"This command allows you to check variables in an object."
" For instance with 'liston leto /stats/' it will show all the"
" stats values of Leto."));
}

