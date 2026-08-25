/*
 *  Basic Chest with open and close for Valder@FR
 *   -- Wahooka@Eden, FR, et al; Dec '97
 */
 
inherit "/std/container";

int open;

void create() {
  ::create();
  /*
   * Basic setup goes here, or in inherited file...make sure to
   * include all the size stuff for containers
   */
}

void init() {
  ::init();
  add_action("openclose","open");
  add_action("openclose","close");
}

int openclose(string str) {
  string s1, s2;
  if(!strlen(str)) {
    notify_fail(capitalize(query_verb())+" what?\n");
    return 0;
  }
  if(!this_object()->id(lower_case(str))) {
    notify_fail("You cannot "+query_verb()+" any "+str+".\n");
    return 0;
  }
  switch(query_verb()) {
    case "open":
      if(open) {
        notify_fail(query_short()+" is already open!\n");
        return 0;
      }
      open = 1;
      write("You open "+query_short()+".\n");
      tell_room(environment(this_player()),this_player()->query_cap_name()+
       " opens "+query_short()+".\n", this_player());
      return 1;
    case "close":
      if(!open) {
        notify_fail(query_short()+" is already closed!\n");
        return 0;
      }
      open = 0;
      write("You close "+query_short()+".\n");
      tell_room(environment(this_player()),this_player()->query_cap_name()+
       " closes "+query_short()+".\n", this_player());
      return 1;
  }
}
   
int test_add(object ob, int flag) {
  if(!open) {
    notify_fail("The "+query_short()+" isn't open!\n");
    return 0;
  }
  return ::test_add(ob, flag);
}

int test_remove(object ob, int flag) {
  if(!open) {
    notify_fail("The "+query_short()+" isn't open!\n");
    return 0;
  }
  return ::test_remove(ob, flag);
}
