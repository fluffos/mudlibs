/* 
 * Static (fixed room to fixed room) ship inheritable -- Wahooka Feb '97
 */

inherit "/std/room";

string *mess, 
      leavemsg = "The ship floats away from the dock.\n", 
      action = "sail", 
      messfile, 
      destination, 
      origin, 
      exitname = "ship",
      arrivemsg = "$N arrive on a ship.\n";
int running, 
    delay = 2;

void init() {
  ::init();
  if(action)
    add_action("do_play",action);
}

void print(int i) {
  int p;
  object *plist;
  if(i == sizeof(mess)) {
    object dest;
    origin->add_exit(exitname,file_name(this_object()),"path");
    plist=all_inventory(this_object());
    plist = filter(plist, (: interactive :));
    for(p = 0; p < sizeof(plist); p++) {
       plist[p]->move(destination);
       plist[p]->look_me();
    }
    tell_room(environment(plist[0]),
     replace_string(arrivemsg, "$N", nice_list(plist->query_cap_name())), plist);
    running = 0;
  mess = 0;
    return;
  }
  tell_room(this_object(),mess[i]+"\n");
  call_out("print",delay,i+1);
}

string *load_messages() {
  string *files, tip;
  files = explode(messfile, "/");
  tip = implode(files[0..sizeof(files)-2], "/");
  files = get_dir(messfile+".?");
  return explode(read_file(tip+"/"+files[random(sizeof(files))]), "\n");
}

int do_play() {
  if(running) {
    notify_fail("The ship is already in motion.\n");
    return 0;
  }
  running = 1;
  mess = load_messages();
  tell_room(find_object(origin),leavemsg);
  origin->remove_exit(exitname);
  print(0);
  return 1;
}

/* Name of the exit (to the ship) */
void set_exitname(string str) { exitname = str; }

/* Command that starts the journey */
void set_action(string str) { action = str; }

/* Message which is printed when we leave */
void set_leavemsg(string str) { leavemsg = str; }

/* Path to the message file(s)
 * Note: name the files "whatever.1", "whatever.2", etc... and just pass
 * "whatever"  The actual file will be chosen at random.
 */
void set_messfile(mixed str) { messfile = str; }

/* Time between messages */
void set_delay(int var) { delay = var; }

/* Room we're headed to */
void set_destination(string str) { destination = str; }

/* Message which is printed when we arrive 
 * $N will be expanded to a list of people on the boat */
void set_arrivemsg(string str) { arrivemsg = str; }

/* Path to room of origin */
void set_origin(string str) { 
  origin = str; 
  add_exit("dock",origin,"path");
  modify_exit("dock",({"function","check_exit"}));
}

int check_exit() {
  if(running) {
    notify_fail("Sorry, you're in the middle of the water.\n");
    return 0;
  }
  return 1;
}
