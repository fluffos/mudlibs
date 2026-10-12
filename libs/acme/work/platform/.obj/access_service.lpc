/**
 * The access service objet.
 * TODO not yet supported
 * 
 * @author devo@eotl
 * @alias AccessService
 */

int is_read_allowed(string path, string euid, string fun, object caller) {
  if (check_access(path, euid, 1)) {
    return 1;
  } else if (caller->is_command()) {
    object cmd_giver = THISP;
    if (cmd_giver->check_command_access(caller, 1)) {
      return check_access(path, geteuid(cmd_giver), 1);
    }
  }

  return 0;
}

int is_write_allowed(string path, string euid, string fun, object caller) {
  if (check_access(path, euid, 0)) {
    return 1;
  } else if (caller->is_command()) {
    object cmd_giver = THISP;
    if (cmd_giver->check_command_access(caller, 0)) {
      return check_access(path, geteuid(cmd_giver));
    }
  }

  return 0;
}

int check_access(string path, string euid, int read) {
  string caller_user, caller_domain;
  int pos = strstr(euid, "@");
  if (pos != -1) {
    caller_user = euid[0..(pos - 1)];
    caller_domain = euid[(pos + 1)..];
  } else {
    caller_user = 0;
    caller_domain = euid;
  }

  // all objects may access their own domain
  string domain = get_domain(path);
  if (domain == caller_domain) {
    return 1;
  }

  // users may access their homedirs
  if (caller_user) {
    string homedir = get_homedir(caller_user);
    if (is_ancestor(path, homedir)) {
      return 1;
    }
  }

  // check domain config
  return check_domain_access(domain, caller_user, caller_domain, read);
}

int check_domain_access(string domain, string caller_user,
                        string caller_domain, int read) {
  // TODO cache config files after parsing
  // TODO needs better error handing
  // TODO the config file syntax sucks
  string op = (read ? "Read" : "Write");
  string domain_file = get_domain_file(domain);
  string *order;
  mapping user_allow = ([ ]);
  mapping domain_allow = ([ ]);
  mapping user_deny = ([ ]);
  mapping domain_deny = ([ ]);
  foreach (string line : explode(read_file(domain_file), "\n")) {
    line = trim(line);
    if (line[0] == '#') {
      continue;
    }
    string *parts = explode(line, " ");
    if (parts[0] == op + "Order") {
      order = parts[1..];
      order = filter(order, (: ($1 == "allow") || ($1 == "deny") :));
      if ((sizeof(order) < 2) || (order[0] == order[1])) {
        raise_error("Invalid Order property in domain config\n");
      }
    } else if (parts[0] == "UserAllow" + op) {
      user_allow += mkmapping(parts[1..]);
    } else if (parts[0] == "DomainAllow" + op) {
      domain_allow += mkmapping(parts[1..]);
    } else if (parts[0] == "UserDeny" + op) {
      user_deny += mkmapping(parts[1..]);
    } else if (parts[0] == "DomainDeny" + op) {
      domain_deny += mkmapping(parts[1..]);
    }
  }

  if (order[0] == "allow") {
    if (!member(user_allow, caller_user)
        && !member(domain_allow, caller_domain)) {
      return 0;
    }
    if (member(user_deny, caller_user)
        || member(domain_deny, caller_domain)) {
      return 0;
    }
    if (member(user_allow, caller_user)
        || member(domain_allow, caller_domain)) {
      return 1;
    }
    return 0;
  } else {
    if (member(user_deny, caller_user)
        || member(domain_deny, caller_domain)) {
      if (member(user_allow, caller_user)
          || member(domain_allow, caller_domain)) {
        return 1;
      } else {
        return 0;
      }
    } else {
      return 1;
    }
  }

  return 0;
}

string get_domain_file(string domain) {

}