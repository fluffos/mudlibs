
#include <std.h>
#include <security.h>
#include <daemons.h>
#include <connection_cl.h>

#define SAVE_FILE "/adm/save/daemons/identity_d"

inherit DAEMON;

class ConnData {
  string name;
  string ip;
  int time;
};

class PlayerData {
  string primary;
  string email_addr;
  string *character_names;
  string *lans;
  mapping settings;
  class ConnData *connections;
};


class PlayerData *identities;
class ConnData *connections;


void save();
void restore();
class PlayerData query_identity(string primary);
int new_identity(string primary, string email, string ip);
int add_character(string primary, string alt);
int delete_character(string primary, string alt);
string *query_characters(string primary);
string query_primary(string alt);
int delete_lan(string primary, string lan);
int add_lan(string primary, string lan);
string *query_lans(string primary);
int delete_setting(string primary, string setting);
int add_setting(string primary, string setting, mixed x);
mixed query_setting(string primary);
mapping query_settings(string primary);
string query_email(string primary);
int change_email(string primary, string email);
int add_connection(string primary, string name, string ip, int time);
int delete_connection(string primary, string name, string ip, int time);
mixed *query_connections(string primary);
int transfer_identity(string primary, string alt);
int delete_identity(string primary);
class PlayerData search_identity(object tp);
string search_primary(object tp);
void add_unassociated_connection(string name, string ip, int time);
mixed *query_unassociated_connections(string name, string ip, int time);
void associate_connections(string primary, string name, string ip);
void unassociate_connections(string primary);
varargs void manage_identity(string answer, object tp, string what, mixed extra);


void create() {
  restore();
  if (!sizeof(identities))
    identities = ({ });
  if (!sizeof(connections))
    connections = ({ });
}

void save() {
  seteuid(UID_SECURE_DAEMONSAVE);
  save_object(SAVE_FILE);
  seteuid(getuid());
}

void restore() {
  seteuid(UID_SECURE_DAEMONSAVE);
  restore_object(SAVE_FILE);
  seteuid(getuid());
}

class PlayerData query_identity(string primary) {
  class PlayerData *search =
    filter(identities, (: $1->primary == $2 :), primary);
  if (sizeof(search))
    return search[0];
  return 0;
}

int new_identity(string primary, string email, string ip) {
  class PlayerData id;
  if (query_identity(primary))
    return 0;
  id = new(class PlayerData);
  id->primary = primary;
  id->email_addr = email;
  id->character_names = ({ primary });
  id->lans = ({ });
  id->settings = ([ ]);
  id->connections = ({ });
  identities += ({ id });
  add_connection(primary, primary, ip, time());
  save();
  return 1;
}

int add_character(string primary, string alt) {
  class PlayerData id = query_identity(primary);
  if (!id)
    return 0;
  id->character_names |= ({ alt });
  save();
  return 1;
}

int delete_character(string primary, string alt) {
  class PlayerData id = query_identity(primary);
  if (!id)
    return 0;
  id->character_names -= ({ alt });
  save();
  return 1;
}

string *query_characters(string primary) {
  class PlayerData id = query_identity(primary);
  if (!id)
    return 0;
  return copy(id->character_names);
}

string query_primary(string alt) {
  class PlayerData *search = filter(identities, (:
    sizeof($1->character_names) && member_array($2, $1->character_names) != -1
  :), alt);
  if (sizeof(search))
    return search[0]->primary;
  return 0;
}

// *********************************************************************** //
// DO NOT use add_lan or delete_lan directly
// use LAN_D's interfaces for adding and deleting LANs

int add_lan(string primary, string lan) {
  class PlayerData id = query_identity(primary);
  if (!id)
    return 0;
  id->lans |= ({ lan });
  save();
  return 1;
}

int delete_lan(string primary, string lan) {
  class PlayerData id = query_identity(primary);
  if (!id)
    return 0;
  id->lans -= ({ lan });
  save();
  return 1;
}

// *********************************************************************** //

string *query_lans(string primary) {
  class PlayerData id = query_identity(primary);
  if (!id)
    return 0;
  return copy(id->lans);
}

int add_setting(string primary, string setting, mixed x) {
  class PlayerData id = query_identity(primary);
  if (!id)
    return 0;
  id->settings[setting] = x;
  save();
  return 1;
}

int delete_setting(string primary, string setting) {
  class PlayerData id = query_identity(primary);
  if (!id)
    return 0;
  map_delete(id->settings, setting);
  save();
  return 1;
}

mixed query_setting(string primary, string setting) {
  class PlayerData id = query_identity(primary);
  if (!id)
    return 0;
  return id->settings[setting];
}

mapping query_settings(string primary) {
  class PlayerData id = query_identity(primary);
  if (!id)
    return 0;
  return copy(id->settings);
}

int change_email(string primary, string email) {
  class PlayerData id = query_identity(primary);
  if (!id)
    return 0;
  id->email_addr = email;
  save();
  return 1;
}

string query_email(string primary) {
  class PlayerData id = query_identity(primary);
  if (!id)
    return 0;
  return id->email_addr;
}

int add_connection(string primary, string name, string ip, int time) {
  class PlayerData id = query_identity(primary);
  class ConnData conn;
  if (!id)
    return 0;
  conn = new(class ConnData);
  conn->name = name;
  conn->ip = ip;
  conn->time = time;
  id->connections += ({ conn });
  save();
  return 1;
}

// can do delete_connection("joe", "andy", 0, 0)
// to delete all connections from name "andy" in identity "joe"
int delete_connection(string primary, string name, string ip, int time) {
  class PlayerData id = query_identity(primary);
  class ConnData *conns;
  if (!id)
    return 0;
  conns = filter(id->connections,
    function(class ConnData c, string n, string i, int t) {
      if (n && c->name != n) return 0;
      if (i && c->ip != i) return 0;
      if (t && c->time != t) return 0;
      return 1;
    }, name, ip, time);
  if (!sizeof(conns))
    return 0;
  id->connections -= conns;
  save();
  return 1;
}

mixed *query_connections(string primary) {
  class PlayerData id = query_identity(primary);
  if (!id)
    return 0;
  return map(id->connections,
    function(class ConnData c) {
      return ({ c->name, c->ip, c->time });
    } );
}

// note: this func does NOT delete the old identity
int transfer_identity(string primary, string alt) {
  class PlayerData pri_id = query_identity(primary);
  if (!pri_id)
    return 0;

  if (member_array(alt, pri_id->character_names) != -1) {
    pri_id->primary = alt;
  }
  else {
    class PlayerData alt_id = query_identity(alt);
    if (alt_id) {
      alt_id->character_names |= pri_id->character_names;
      alt_id->lans |= pri_id->lans;
      alt_id->connections |= pri_id->connections;
    }
    else {
      return 0;
    }
  }

  save();
  return 1;
}

int delete_identity(string primary) {
  class PlayerData id = query_identity(primary);
  if (!id)
    return 0;
  unassociate_connections(primary);
  identities -= ({ id });
  save();
  return 1;
}

// try very hard to find an identity...
class PlayerData search_identity(object tp) {
  class PlayerData id;
  string name = tp->query_name();
  string primary;

  id = query_identity(name);
  if (!id) {
    primary = tp->query_primary_char();
    if (!primary || !(id = query_identity(primary))) {
      primary = query_primary(name);
    }
    if (primary) {
      id = query_identity(primary);
    }
    if (id && member_array(name, id->character_names) == -1) {
      id = 0;
    }
  }

  return id;
}

string search_primary(object tp) {
  class PlayerData id = search_identity(tp);
  if (id)

    return id->primary;
  return 0;
}


// these functions are for dealing with old connections from IP_D
// or which are not yet put into identity profiles
void add_unassociated_connection(string name, string ip, int time) {
  class ConnData c = new(class ConnData);
  c->name = name;
  c->ip = ip;
  c->time = time;
  connections += ({ c });
}

void copy_unassociated_connections(string name, string ip) {
  class Connection *oldconns;
  oldconns = IP_D->query_all_connections(name);
  oldconns = filter(oldconns,
    function(class Connection c, string i) {
      if (c->ip == i) return 1;
      return 0;
    }, ip);
  foreach (class Connection oc in oldconns)
    add_unassociated_connection(name, ip, oc->time);
  IP_D->delete_connections(name, ip);
}

mixed *query_unassociated_connections(string name, string ip, int time) {
  class ConnData *filt = filter(connections,
    function(class ConnData c, string n, string i, int t) {
      if (n && c->name != c) return 0;
      if (i && c->ip != i) return 0;
      if (t && c->time != t) return 0;
      return 1;
    }, name, ip, time);
  return map(filt,
    function(class ConnData c) {
      return ({ c->name, c->ip, c->time });
    } );
}

void associate_connections(string primary, string name, string ip) {
  class ConnData *old;
  class PlayerData id = query_identity(primary);
  if (!id) return;
  old = filter(connections,
    function(class ConnData c, string n, string i) {
      if (c->name == n && c->ip == i) return 1;
      return 0;
    }, name, ip );
  id->connections += old;
  connections -= old;
}

void unassociate_connections(string primary) {
  class PlayerData id = query_identity(primary);
  if (!id) return;
  connections += id->connections;
  id->connections = ({ });
}
// ---

varargs void manage_identity(string answer, object tp, string what, mixed extra) {
  string name, primary, ip, email;
  class PlayerData id;
  class PlayerData *search;

  if (!tp) return;
  if (!what) what = "login check";

  name = tp->query_name();
  ip = query_ip_number(tp);

  switch (what) {

    // this is meant to be called at each login
    case "login check":
      id = search_identity(tp);
      if (!id) {
        manage_identity(0, tp, "search by ip");
      }
      else {
        tp->set_primary_char(id->primary);
        add_connection(id->primary, name, ip, time() );
      }
    break;

    case "search by ip":
      // this looks horrid, but it's fast
      // find every identity that has connected with this IP address
      search = filter(identities, (:
        sizeof(filter($1->connections,
          function(class ConnData c, string i) {
            if (c->ip == i) return 1;
            return 0;
          }, $2)
        )
      :), ip);
      message("info", header_line("Identity Profile"), tp);
      if (sizeof(search)) {
        message("info", "Previous connections have been found "
          "from your IP address.\n"
          "Please enter the name of a previous character so we can "
          "add this name to your identity profile, or enter \"new\" "
          "if you have no other characters.", tp);
        input_to("manage_identity", 2, tp, "ask if alt", search);
      }
      else {
        manage_identity(0, tp, "create new");
      }
    break;

    case "ask if alt":
      if (!answer || answer == "") {
        input_to("manage_identity", 2, tp, "ask if alt", extra);
      }
      else if (answer == "new") {
        manage_identity(0, tp, "create new");
        message("info", "Since other players have connected from your "
          "IP address before, please read <help lan> for information "
          "on registering your LAN.", tp);
        message("info", header_line(), tp);
      }
      else {
        // filter down to entries with the given name in them
        search = extra;
        extra = filter(extra, (:
          member_array($2, $1->character_names) != -1
        :), answer);
        if (sizeof(extra)) {
          // there should only be one max, so just set it to the first entry
          // we can do this because extra is type "mixed"
          extra = extra[0];
          add_character(extra->primary, name);
          tp->set_primary_char(extra->primary);
          associate_connections(extra->primary, name, ip);
          add_connection(extra->primary, name, ip, time());
          message("info", "Added this character to identity profile "
            "\""+capitalize(extra->primary)+"\"" +
            (answer == extra->primary ? "." :
              "which contains the name \""+capitalize(answer)+"\"."
            ), tp);
          message("info", header_line(), tp);
        }
        else {
          // the name the player entered isn't in the list of identities
          // that also contain the player's IP, various possibile reasons
          message("info", "That character does not exist, has not connected "
            "from your IP, or is not associated with an identity profile.\n"
            "Primary characters from your IP: "+
            list(map(search, (: capitalize($1->primary) :) ))+".\n"
            "Enter one of these names, or \"new\" to create a new "
            "identity profile.", tp);
          input_to("manage_identity", 2, tp, "ask if alt", search);
        }
      }
    break;

    case "create new":
      email = tp->query_email();
      if (!email) email = "";
      if (email[0..0] == "*") email = email[1..<1];
      message("info", "Creating a new identity profile for you.\n"
        "See <help identity> for more information.", tp);
      message("info", header_line(), tp);
      new_identity(name, email, ip);
      tp->set_primary_char(name);
      associate_connections(name, name, ip);
      add_connection(name, name, ip, time());
    break;
    // end of code used at login to associate identities

    // used when suiciding, or being rid
    case "deleting":
      id = search_identity(tp);
      if (id) {
        if (id->primary == name) {
          // this is the primary name, but there are others...
          // transfer to an alt and delete this one
          if (sizeof(id->character_names) > 1) {
            // just choose the first alt besides this name
            primary = (id->character_names - ({ name }))[0];
            transfer_identity(name, primary);
            delete_character(primary, name);
          }
          // primary name with no alts, delete this identity
          else {
            delete_identity(name);
          }
        }
        // this is an alt, delete this char from the identity
        else {
          delete_character(id->primary, name);
        }
      }
      else {
        // no identity associated with this name (odd)... do nothing
      }
    break;

  }

}

