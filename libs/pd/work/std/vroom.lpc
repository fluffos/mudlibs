#include <std.h>

inherit ROOM;

void set_server(string str);
void add_item(string id, string long);

string serverpath;

void create() {
  ::create();
  if(serverpath) {
    set_day_long(get_object(serverpath)->get_day_long());
    set_night_long(get_object(serverpath)->get_night_long());
    set_items(get_object(serverpath)->get_items());
    if(get_object(serverpath)->get_listen())
      set_listen("default", get_object(serverpath)->get_listen());
    if(get_object(serverpath)->get_smell())
      set_smell("default", get_object(serverpath)->get_smell());
    set_properties(get_object(serverpath)->get_properties());
    set_short(get_object(serverpath)->get_short());
  }
}

void set_server(string str) { serverpath = str; }

void add_item(string id, string long) {
  mapping tempmap;
  if(serverpath)
    tempmap = get_object(serverpath)->get_items();
  tempmap[id] = long;
}

/*
void reset() {
  string *stuff;
  int x;
  ::reset();

  if(!serverpath)
    return;

  stuff = get_object(serverpath)->get_reset_list();

     if(!present("monster")) {
        x = random(sizeof(stuff) + 8);
        while(x < sizeof(stuff)) {
            new(stuff[x])->move(this_object());
            x = random(sizeof(stuff) + 5);
            if(present("monster "+get_object(serverpath)->get_mob_cap()+""))
               return;
        }
    }
}
*/

void reset() {
  string *resetlist;
  int num, cap;

  ::reset();

  if (!serverpath) return;

  resetlist = load_object(serverpath)->get_reset_list();

  if (!sizeof(resetlist)) return;

  num = sizeof(filter(all_inventory(), (: $1->is_monster() :) ));

  cap = load_object(serverpath)->get_mob_cap();

  for (int i = random(cap + 1 - num); i > 0; i--)
    new(resetlist[random(sizeof(resetlist))])->move(this_object());

}
