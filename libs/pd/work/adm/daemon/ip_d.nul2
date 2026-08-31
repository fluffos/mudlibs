// IP Daemon
//   Logs all connections
//   originally by Whit, speed hacks by Nulvect

#include <security.h>
#include <connection_cl.h>

#define SAVE_FILE "/adm/save/daemons/ip"

mapping Connections = ([]);

class Connection *query_all_connections(string);
int save();
int restore();

void create() {
  Connections = ([]);
  restore();
}

int save() {
  seteuid(UID_SECURE_DAEMONSAVE);
  save_object(SAVE_FILE);
  seteuid(getuid());
  return 1;
}

int restore() {
  seteuid(UID_SECURE_DAEMONSAVE);
  restore_object(SAVE_FILE);
  seteuid(getuid());
  return 1;
}

string query_ip(string user) {
  class Connection *userconns;
  userconns = query_all_connections(user);
  if (!sizeof(userconns)) return 0;
  // last entry will be most recent
  return userconns[<1]->ip;
}
int query_last_on(string user) {
  class Connection *userconns;
  userconns = query_all_connections(user);
  if (!sizeof(userconns)) return 0;
  // last entry will be most recent
  return userconns[<1]->time;
}

string *sameip(string ip) {
  mapping ipconns;
  restore();
  ipconns = filter(Connections, (:
    sizeof(filter($2, (:
      $1->ip == $2
    :), $3 ) )
  :), ip);
  return keys(ipconns);
}

class Connection *query_all_connections(string user) {
  return Connections[user];
}
// original func says it returns string but returns
// ({ (["ip":"x", "time":555]), })
string *query_all_ips(string user) {
  return map(query_all_connections(user), (: $1->ip :) );
}

static void add_user_ip(string user, string ip) {
  class Connection newcon = new(class Connection);
  restore();
  newcon->ip = ip;
  newcon->time = time();
  if (!Connections[user])
    Connections[user] = ({});
  Connections[user] += ({ newcon });
  save();
}

void delete_user(string user) {
  restore();
  map_delete(Connections, user);
  save();
}

int user_online(object o) {
  string name = o->query_true_name();
  string ip = query_ip_number(o);
  add_user_ip(name, ip);
  return 1;
}

// these are not needed
int user_offline(object o) { return 0; }
void last_on(string user, int time) { return; }

