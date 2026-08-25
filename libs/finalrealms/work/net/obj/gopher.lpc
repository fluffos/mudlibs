/*
 * The gopher object...
 */
#include "gopher.h"
#include "globals.h"
inherit "/inherit/object";

int pending;
mixed *current_menu;
mixed *path;
string blue;
object env;

varargs void do_connect(int type, mixed *data, string search);

#define NOTIFY(STR) set_long(STR); if (environment()) {\
                     env = environment(); blue = "\n\n"+STR; \
                     move(VOID_OB); move(env); }

void create() {
  ::create();
  set_short("Gopher object");
  set_name("gopher");
  set_long("Connecting to mackerel.gu.uwa.edu.au");
  GOPHERD->do_connect(MENU, "", MACHINE_NAME, GOPHER_PORT+"",
                      "finish_func");
  pending = 1;
  current_menu = ({ });
  path = ({ ({ "", "", MACHINE_NAME, GOPHER_PORT+""  }) });
} /* create() */

void init() {
  add_action("do_pick", "pick");
  add_action("do_pop", "pop");
  add_action("do_gopher", "gopher");
  add_action("do_show", "show");
  if (blue) {
    write("\n");
    this_player()->more_string(blue);
  }
} /* init() */

void finish_func(mixed arg) {
  string str;
  int i;

  pending = 0;
  if (!arg) {
    NOTIFY("Connect failed for some reason.\ngopher <name> to connect to "+
           "annother site.\n")
    return ;
  }
  if (stringp(arg)) {
/* Text file... */
    object env;

    env = environment();
    blue = arg;
    move(VOID_OB);
    move(env);
    blue = 0;
    return ;
  }
/* Menu... */
  current_menu = arg;
  str = "";
  for (i=0;i<sizeof(arg);i++)
    switch (arg[i][TYPE]) {
      case MENU :
        str += sprintf("%2d   %s/\n", i+1, arg[i][DATA][TEXT]);
        break;
      case SEARCH :
        str += sprintf("%2d   %s+\n", i+1, arg[i][DATA][TEXT]);
        break;
      default :
        str += sprintf("%2d   %s\n", i+1, arg[i][DATA][TEXT]);
        break;
    }
  str += "'pick <n>' to pick one of the options, 'pop' to go up a level.\n"+
         "'gopher <machine> [port]' to get to another gopher.\n";
  NOTIFY(str)
} /* finish_func() */

int do_pick(string str) {
  int num;

  if (pending) {
    write("Sorry, there is a pending transaction.\n");
    return 1;
  }
  if (!str) str = "";
  sscanf(str, "%d", num);
  num--;
  if (num < 0 || num >= sizeof(current_menu)) {
    write("Out of range, 1.."+sizeof(current_menu)+".\n"+
                "Syntax pick <number>\n");
    return 1;
  }
/* Ok, do the selection... */
  switch (current_menu[num][TYPE]) {
    case MENU :
      path += ({ current_menu[num][DATA] });
      break;
    case SEARCH :
      write("What do you want to input to the menu item :\n"+
               current_menu[num][DATA][TEXT]+"? ");
      input_to("do_search", 0, num);
      path += ({ current_menu[num][DATA] });
      return 1;
  }
  write("Please wait, transaction in progress.\n");
  do_connect(current_menu[num][TYPE], current_menu[num][DATA]);
  return 1;
} /* do_pick() */

void do_search(string str, int num) {
  do_connect(SEARCH, current_menu[num][DATA], str);
} /* do_search() */

varargs void do_connect(int type, mixed *junk, string search) {
  GOPHERD->do_connect(type, junk[NAME], junk[MACHINE], junk[PORT],
                      "finish_func", search);
  pending = 1;
  return ;
} /* do_connect() */

int do_pop() {
  if (sizeof(path) == 1) {
    notify_fail("Already at the top level.\n");
    return 0;
  }
  path = path[0..sizeof(path)-2];
  write("Please wait, transaction in progress.\n");
  do_connect(MENU, path[sizeof(path)-1]);
  return 1;
} /* do_pop() */

int do_gopher(string str) {
  string dest, port;
  int p;

  if (!str) {
    notify_fail("Syntax: gopher <machine> [port]\n");
    return 0;
  }
  if (sscanf(str, "%s %d", dest, p) != 2) {
    dest = str;
    p = 70;
  }
  if (sizeof(explode(dest, " ")) > 1) {
    notify_fail("No spaces allowed in destingation field.\n");
    return 0;
  }
  NOTIFY("Connecting to "+dest+" "+p+"\n");
  path = ({ ({ "", "", dest, p+"" }) });
  do_connect(MENU, path[0]);
  return 1;
} /* do_gopher() */

int do_show(string str) {
  int num;

  if (!str) str = "";
  sscanf(str, "%d", num);
  num--;
  if (num < 0 || num >= sizeof(current_menu)) {
    write("Out of range, 1.."+sizeof(current_menu)+".\n"+
                "Syntax show <number>\n");
    return 1;
  }
  printf("Path=%s\nHost=%s\nPort=%s\nType=%s\n",
         current_menu[num][DATA][NAME], current_menu[num][DATA][MACHINE],
         current_menu[num][DATA][PORT],
         ({ "file", "menu", "search/query" })[current_menu[num][TYPE]]);
  return 1;
} /* do_show() */
