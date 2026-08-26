// Petrarch
// Merentha Lib 1.0
// event.c

#include <std.h>

inherit DAEMON;

mapping __Events=([]);

void add_event(string name, int time, string file, mixed *fun) {
  __Events[name]=({ time+time(), file, fun });
  save_object("/save/daemons/events");
}
void remove_event(string name) {
  map_delete(__Events, name);
  save_object("/save/daemons/events");
}
mapping query_events() { return __Events; }

void create() {
  load_object("/save/daemons/events");
  add_event("reboot", 3600*24, "/daemon/reboot", ({"reboot", 10}));
  save_object("/save/daemons/events");
  call_out("update_events", 2);
}

void update_events() {
string *events;
int i, time=time();
  i=sizeof(events=keys(__Events));
  while (i--) 
    if(__Events[events[i]][0] <= time) {
      catch(call_other(__Events[events[i]][1],__Events[events[i]][2]));
      remove_event(events[i]);
    }
  save_object("/save/daemons/events");
  call_out("update_events", 60);
}
