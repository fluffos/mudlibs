/*
 *  Basic Chest with open and close for Valder@FR
 *   -- Wahooka@Eden, FR, et al; Dec '97
 *       Traducido por Gareth 21.01.03
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
  add_action("openclose","abrir");
  add_action("openclose","cerrar");
}

int openclose(string str) {
  if(!strlen(str)) {
    notify_fail(capitalize(query_verb())+" que?\n");
    return 0;
  }
  if(!this_object()->id(lower_case(str))) {
    notify_fail("No puedes "+query_verb()+" ningun "+str+".\n");
    return 0;
  }
  switch(query_verb()) {
    case "abrir":
      if(open) {
        notify_fail(query_short()+" ya esta abierto!\n");
        return 0;
      }
      open = 1;
      write("Abres "+query_short()+".\n");
      tell_room(environment(this_player()),this_player()->query_cap_name()+
       " abre "+query_short()+".\n", this_player());
      return 1;
    case "close":
      if(!open) {
        notify_fail(query_short()+" ya esta cerrado!\n");
        return 0;
      }
      open = 0;
      write("Cierras "+query_short()+".\n");
      tell_room(environment(this_player()),this_player()->query_cap_name()+
       " cierra "+query_short()+".\n", this_player());
      return 1;
  }
}
   
int test_add(object ob, int flag) {
  if(!open) {
    notify_fail(query_short()+" no esta abierto!\n");
    return 0;
  }
  return ::test_add(ob, flag);
}

int test_remove(object ob, int flag) {
  if(!open) {
    notify_fail(query_short()+" no esta abierto!\n");
    return 0;
  }
  return ::test_remove(ob, flag);
}
