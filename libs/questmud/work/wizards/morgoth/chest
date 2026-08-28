#define    MAX_EQ  10
#define    SAVEDIR "castle/chest/"
static int locked, open, jammed;
static int current;
static int local_weight;
int combo, sealed;
string id,file;
string items;
string label;

can_put_and_get(str) {
  if(open) return 1;
}

reset(arg) {
  if(arg) return;
  current = random(1000)+1;
  local_weight = 40;
  if(combo) locked = 1;
}

add_weight(i) {
  return 1;
}

query_weight() { return local_weight; }

clone_eq() {
  int i;
  if(file) restore_object(file);
  else write("FATAL ERROR! No chest file.\n");
  while(i<sizeof(items)) {
    if(items[i] && file_size("/"+items[i]+".c") != -1) {
      move_object(clone_object(items[i]), this_object());
    }
    i += 1;
  }
  items = allocate(MAX_EQ);
  if(file) save_object(file);
}

save_eq() {
  int i, tmp;
  string str;
  object ob;
  items = allocate(MAX_EQ);
  ob = all_inventory(this_object());
  while(i<sizeof(ob) && i < MAX_EQ) {
    str = file_name(ob[i]);
    if(str) sscanf(str,"%s#%d",str,tmp);
    items[i] = str;
    destruct(ob[i]);
    i += 1;
  }
  if(file) save_object(file);
  else write("FATAL ERROR! No file name.\n");
}

seal(arg) {
  if(!arg || present(arg) != this_object()) return;
  if(!open) {
    write("You must open it first.\n");
    return 1;
  }
  if(sealed) {
    write(short()+" is already secured on the floor.\n");
    return 1;
  }
  write("You secure "+short()+" in the floor.\n");
  sealed = 1;
  return 1;
}

turn(arg) {
  string str;
  int num;
  if(sscanf(arg, "%s to %d", str, num) != 2) return;
  if(!str || present(str) != this_object()) return;
  if(jammed) {
    write("The lock is jammed.. wait for a while.\n");
    return 1;
  }
  write("You start operating the number.\n");
  call_out("attempt", 10, num);
  return 1;
}

attempt(i) {
  current = i;
  if(i == combo) {
    write("The lock clicks open with a sharp sound.\n");
    locked = 0;
    return 1;
  }
  write("The chest refuses to open.\n");
  jammed = 1;
  call_out("stop_jam", 22);
  return 1;
}

stop_jam() { jammed = 0; }

get() {
  if(!sealed && open) return 1;
}

close(arg) {
  if(!arg || present(arg) != this_object()) return;
  if(!open) {
    write(short()+" is already closed.\n");
    return 1;
  }
  write("You close "+short()+".\n");
  open = 0;
  locked = 1;
  current = random(1000)+1;
  save_eq();
  return 1;
}

open(arg) {
  if(!arg) return;
  if(present(arg) != this_object()) return;
  if(open) {
    write(short()+" is already open.\n");
    return 1;
  }
  if(locked) {
    write(short()+" is locked.\n");
    return 1;
  }
  write("You open "+short()+".\n");
  open = 1;
  clone_eq();
  return 1;
}

short() {
  string str;
  str = "A small chest";
  if(label) str = str+" '"+label+"'";
  if(open) str += " (open)";
  else if(!locked) str += " (unlocked)";
  return str;
}

long() {
  object ob;
  int i;
  write(short()+".\n"+
	"It is turned to "+current+".\n");
  if(!open) return;
  ob = all_inventory(this_object());
  while(i<sizeof(ob)) {
    if(ob[i]) write(ob[i]->short()+".\n");
    i += 1;
  }      
}

set_id(arg) {
  if(!id) {
    id = arg;
    file = SAVEDIR+id;
  }
}
id(str) { return str == "chest"; }
label(arg) {
  string str,tmp;
  if(!arg) return;
  if(sscanf(arg, "chest %s %s", tmp, str) != 2) return;
  tmp = "chest "+tmp;
  if(!tmp || present(tmp) != this_object()) return;
  if(!open) {
    write("You must open "+short()+" first.\n");
    return 1;
  }
  label = str;
  write("Ok.\n");
  return 1;
}

init() {
  add_action("turn", "turn");
  add_action("open", "open");
  add_action("close", "close");
  add_action("seal", "seal");
  add_action("label", "label");
}
