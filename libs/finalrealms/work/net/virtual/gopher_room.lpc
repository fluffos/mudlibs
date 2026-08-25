/*
 * We are sent the line of the menu...
 * From this, we are supposed to figure out whats actually here...
 */
#include "gopher.h"

#define VOID_OB "/room/void"

#undef DEBUG

#ifdef DEBUG
#define TP(STR) tell_object(find_player("pinkfish"), STR)
#else
#define TP(STR)
#endif

inherit "/std/room";

mixed *my_menu,
      *junk,
      *my_junk;
string room_long, rabbit;
int search_room;
mapping blue,
        pending;

void setup() {
  blue = ([ ]);
  pending = ([ ]);
  my_menu = ({ });
  add_exit("up", "who_cares", "corridor");
  modify_exit("up", ({ "function", "do_up" }));
  add_exit("out", "/w/common", "corridor");
  modify_exit("out", ({ "function", "do_out" }));
  room_long = "";
} /* create() */

void init() {
  if (rabbit)
    write(long("", 0));
  ::init();
  if (blue[this_player()]) {
    this_player()->more_string(blue[this_player()]);
    map_delete(blue, this_player());
  }
/*
  for (i=0;i<sizeof(my_menu);i++)
    add_action("handle_item", (i+1)+"");
 */
  add_action("do_refresh", "refresh");
  add_action("do_jump", "gopher");
  add_action("do_show", "show");
} /* init() */

long() {
  object *obs;
  string *cont, str;
  int i, cols;

  if (this_player())
    cols = this_player()->query_cols();
  else
    cols = 78;
  return "You are in the gopher maze.\n"+sprintf("%-*#s", cols, room_long)+
         "\n'gopher <dest> [port]' to jump to another server, "+
           "and 'refresh'"+
           " to refresh the room.\n"+::long();
} /* query_long() */

void setup_room(mixed *junk, string arg) {
  set_short(junk[TEXT]);
  if (!arg)
    if (junk[NAME] == "1")
      GOPHER_CONTROL->add_connection("\t"+junk[MACHINE]+"\t"+
                                     junk[PORT], this_object());
    else
      GOPHER_CONTROL->add_connection(junk[NAME]+"\t"+junk[MACHINE]+"\t"+
                                     junk[PORT], this_object());
  if (arg || junk[TEXT] == "who") {
    search_room = 1;
    set_heart_beat(1);
  }
  my_junk = junk;
  set_long("Connecting.\n");
  GOPHERD->do_connect(MENU, junk[NAME], junk[MACHINE], junk[PORT],
                       "finish_lookup", arg);
} /* setup() */

mixed *query_my_junk() { return my_junk; }
mixed *query_my_menu() { return my_menu; }

void finish_lookup(mixed *junk, mixed *called) {
  int i, my_number, exit_no;
  string my_path, *bits, cont, ret;
  object *obs;

  if (!junk) {
    tell_room(this_object(), "Failed to connect.\n");
    return 0;
  }
  bits = explode(file_name(this_object()), "/");
  cont = implode(bits[0..sizeof(bits)-2], "/")+"/gopher_cont";
  tell_room(this_object(), "Connection completed.\n");
  ret = "";
  my_menu = junk;
  for (i=0;i<sizeof(junk);i++) {
    switch (junk[i][TYPE]) {
      case FILE :
        ret += sprintf("%2d: %s\n", i+1, junk[i][DATA][TEXT]);
        break;
      case MENU :
        ret += sprintf("%2d: %s/\n", i+1, junk[i][DATA][TEXT]);
        break;
      case SEARCH :
        ret += sprintf("%2d: %s <?>\n", i+1, junk[i][DATA][TEXT]);
        break;
    }
    add_exit((i+1)+"", "hmmmm", "corridor");
    modify_exit((i+1)+"", ({ "function", "handle_item", "obvious", 0 }));
  }
  room_long = ret;
  set_long("");
  rabbit = 1;
  (obs = all_inventory())->move(VOID_OB);
  obs->move(this_object());
  rabbit = 0;
} /* finish_lookup() */

void text_finish(string text, mixed *junk) {
  string tmp;
  int i;
  object *obs;

TP(sprintf("%O\n", junk));
  tmp = junk[0]+"\t"+junk[1];
  if (!pending[tmp]) {
    tell_room(this_object(), "Something weird.\n");
    return ;
  }
  TP(sprintf("BING?, %O", pending[tmp]));
  for (i=0;i<sizeof(pending[tmp]);i++) {
    blue[pending[tmp][i]] = text;
    map_delete(pending, pending[tmp][i]);
  }
  map_delete(pending, tmp);
  TP("Doing move...\n");
  (obs = all_inventory())->move(VOID_OB);
  obs->move(this_object());
} /* text_finish() */

int handle_item() {
  int num;
  object dest;
  mixed *tmp;
  string bip;

  sscanf(query_verb(), "%d", num);
  num--;
  if (pending[this_player()]) {
    notify_fail("You have a pending transaction.\n");
    return 0;
  }
  switch (my_menu[num][TYPE]) {
    case FILE :
      pending[this_player()] = 1;
      bip = my_menu[num][DATA][NAME]+"\t"+my_menu[num][DATA][PORT];
      if (!pending[bip]) {
        GOPHERD->do_connect(FILE, my_menu[num][DATA][NAME],
                                  my_menu[num][DATA][MACHINE],
                                  my_menu[num][DATA][PORT],
                                  "text_finish");
        pending[bip] = ({ this_player() });
      } else /* Someone is already getting it. */
        pending[bip] += ({ this_player() });
/* We dont actually want to move them... */
      notify_fail("Connecting....\n");
      return 0;
      break;
    case MENU :
      if (my_menu[num][DATA][NAME] == "1")
        my_menu[num][DATA][NAME] = "";
      if (!(dest = GOPHER_CONTROL->query_connection(my_menu[num][DATA][NAME]+
            "\t"+my_menu[num][DATA][MACHINE]+"\t"+my_menu[num][DATA][PORT]))) {
/* Need a new room... */
        dest = clone_object(GOPHER_ROOM);
        dest->setup_room(my_menu[num][DATA]);
      }
      modify_exit(query_verb(), ({ "dest", dest }));
      tmp = this_player()->query_property("gopher");
      if (!tmp)
        tmp = ({ });
      tmp = tmp - ({ 0 });
      this_player()->add_property("gopher", tmp+({ this_object() }));
      break;
    case SEARCH :
/* Now a search requires a room, but an unregistered one. */
      write("You need to give the magic incantation to pass this exit.\n: ");
      input_to("do_gopher_search", 0, num);
      notify_fail("");
      return 0;
  }
  return 1;
} /* handle_item() */

void do_gopher_search(string str, int num) {
  object dest;
  mixed *tmp;

  printf("In here.\n");
  dest = clone_object(GOPHER_ROOM);
  dest->setup_room(my_menu[num][DATA], str);
  tmp = this_player()->query_property("gopher");
  if (!tmp)
    tmp = ({ });
  tmp = tmp - ({ 0 });
  this_player()->add_property("gopher", tmp+({ this_object() }));
  modify_exit((num+1)+"", ({ "dest", dest }));
  this_player()->move_player("X", dest);
} /* do_search() */

int do_refresh(string str) {
  if (search_room && !str) {
    notify_fail("Syntax: refresh <text>\n");
    return 0;
  }
  if (search_room)
    setup_room(my_junk, str);
  else
    setup_room(my_junk, 0);
  write("Refreshing...\n");
  return 1;
} /* do_refresh() */

int do_up() {
  object dest, *tmp;
  int i;

  if (!(tmp = this_player()->query_property("gopher"))) {
    this_player()->remove_property("gopher");
    call_out("do_exit_command", 0, "out");
    notify_fail("");
    return 0;
  } else {
    tmp = tmp - ({ 0 });
    for (i=sizeof(tmp)-1;i>=0;i--)
      if (tmp[i]) break;
    if (i < 0) {
      this_player()->remove_property("gopher");
      call_out("do_exit_command", 0, "out");
      notify_fail("");
      return 0;
    } else {
      if (i)
        this_player()->add_property("gopher", tmp[0..i-1]);
      else
        this_player()->add_property("gopher", 0);
      dest = tmp[i];
    }
  }
  modify_exit("up", ({ "dest",  dest }));
  return 1;
} /* do_up() */

void heart_beat() {
  if (!sizeof(all_inventory()))
    dest_me();
} /* heart_beat() */

int do_jump(string str) {
  string host;
  int port;
  object dest;
  mixed *tmp;

  if (!str) {
    notify_fail("Syntax: "+query_verb()+" <site> [port]\n");
    return 0;
  }
  if (sscanf(str, "%s %d", host, port) != 2) {
    host = str;
    port = "70";
  }
  dest = GOPHER_CONTROL->query_connection("\t"+host+"\t"+port);
  if (!dest) {
    dest = clone_object(GOPHER_ROOM);
    dest->setup_room(({ "Root level of "+host, "", host, port+"" }));
  }
  tmp = this_player()->query_property("gopher");
  if (!tmp)
    tmp = ({ });
  this_player()->add_property("gopher", tmp+({ this_object() }));
  this_player()->move_player("X", dest);
  return 1;
} /* do_jump() */

/* Get me out of here! */
int do_out() {
  this_player()->remove_property("gopher");
  return 1;
} /* do_out() */

int do_show(string str) {
  int num;

  notify_fail("Syntax: show <num>\n");
  if (!str)
    return 0;
  if (sscanf(str, "%d", num) != 1 || num < 1 || num > sizeof(my_menu))
    return 0;
  num--;
  write("Text: "+my_menu[num][DATA][TEXT]+"\n");
  write("Name: "+my_menu[num][DATA][NAME]+"\n");
  write("Host: "+my_menu[num][DATA][MACHINE]+"\n");
  write("Port: "+my_menu[num][DATA][PORT]+"\n");
  return 1;
} /* do_who() */
