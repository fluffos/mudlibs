
#include <std.h>

inherit DAEMON;

mapping userIPs;

void init_ip_list();
void init_ip(string);
int ip_exists(string);
string *query_ip(string);
void add_ip(string, string);
void remove_ip(string, string);
mapping get_same_ips();
string *get_one_ip(string);
string *get_one_ip_multi(string);

void create() {
  init_ip_list();
}

void init_ip_list() {
  foreach (object u in users()) {
    string ip = query_ip_number(u);
    string name = u->query_name();
    if (!ip_exists(ip))
      init_ip(ip);
    add_ip(ip, name);
  }
}

void init_ip(string ip) {
  if (!userIPs) userIPs = ([]);
  userIPs[ip] = ({});
}

int ip_exists(string ip) {
  return (userIPs && userIPs[ip]);
}

string *query_ip(string ip) {
  return (ip_exists(ip) ? userIPs[ip] : 0);
}

void add_ip(string ip, string name) {
  if (!ip_exists(ip))
    init_ip(ip);
  if (member_array(name, userIPs[ip]) == -1)
    userIPs[ip] += ({ name });
}

void remove_ip(string ip, string name) {
  if (ip_exists(ip))
    userIPs[ip] -= ({ name });
  if (!sizeof(userIPs[ip]))
    map_delete(userIPs, ip);
}

mapping get_same_ips() {
  mapping check;
  check = filter(userIPs, (: (sizeof($2) > 1) :) );
  return check || ([]);
}

string *get_one_ip(string ip) {
  mapping check;
  string *ret = ({});
  if (!ip) return ret;
  check = filter(userIPs, (: (strsrch($1, $3) != -1) :), ip);
  foreach (string keyIP, string *valName in check)
    ret += valName;
  return ret;
}

string *get_one_ip_multi(string ip) {
  mapping check = get_same_ips();
  return check[ip] || 0;
}
