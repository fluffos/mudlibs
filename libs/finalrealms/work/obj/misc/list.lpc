/*
 * Telluride
 */
int timelast;

#define LISTHAND "/obj/handlers/list"
inherit "/std/object";

void update_list();

void setup() {
  set_name("t_list");
  add_alias("list");
  set_short("Top Ten List");
  set_value(0);
  reset_get();
  set_long("There are no players on the list yet...\n");
}

void init() {
  ::init();
  if (!timelast) {
    timelast=time();
    update_list();
   }

  if ((timelast-time())>900) {
    timelast=time();
    update_list();
  }
}


void update_list() {

  set_long("Top Ten Players in The Forgotten Realms:\n"+
           "\n"+
(string)LISTHAND->query_list()+"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
        "Last updated: " + ctime(time()) + "\n");
}
