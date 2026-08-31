#include <std.h>

inherit ROOM;

void set_server(string str);
string query_server();
void add_item(string id, string long);

string serverpath;

void create() {
  object srv;
  ::create();
  if (serverpath && (srv = load_object(serverpath)) ) {
    set_short(srv->query_short());
    set_day_long(srv->query_random_long(0));
    set_night_long(srv->query_random_long(1));
    set_properties(srv->query_properties());
    foreach (string k, mapping v in srv->query_senses_map())
      set_senses(k, v);
  }
}

void set_server(string str) { serverpath = str; }
string query_server() { return serverpath; }

// not sure why this is needed here
void add_item(string id, string long) {
  if (serverpath)
    load_object(serverpath)->set_item(id, long);
}

void reset() {
  object srv;
  object *newinv;

  ::reset();

  if ( !( serverpath && srv = load_object(serverpath) ) ) return;

  newinv = srv->query_random_inventory( all_inventory() ) || ({});
  if (sizeof(newinv))
    newinv->move(this_object());
}
