/*
 * An authority demon for the outside FTP server.
 * Based on old code from TMI2.
 * Written by Turrican, September 1999.
 */

#include <network.h>

#define MAX_LIFE 36000

inherit SERVER;

class ftp_session {
  int fd;
  string token;
  int timestamp;
  string user;
}

protected void create() {
  server::create();
  SetSocketType(STREAM);
  SetDestructOnClose(1);
  Sockets = ([]);
  call_out("setup", 2);
  call_out("clean_sockets", 3600);
} /* create() */

/** @ignore yes */
protected void setup() {
  if (eventCreateSocket(PORT_FTPAUTH) < 0) {
    if (this_object()) {
      destruct(this_object());
    }
  }
} /* setup() */

/** @ignore yes */
protected void eventNewConnection(int fd) {
  class ftp_session sess;
  string address, host;

  server::eventNewConnection(fd);
  address = socket_address(fd);
  /* If this is not coming from localhost, disconnect. */
  if ((sscanf(address, "%s %*d", host) != 2) || (host != "127.0.0.1")) {
    eventWrite(fd, "", 1);
    return;
  }
  sess = new(class ftp_session, fd : fd);
  Sockets[fd] = sess;
} /* eventNewConnection() */

/** @ignore yes */
protected string get_path(string str) {
  string *array, *array1;
  int i;

  if (str == "/")
    return "/";
  array = explode(str, "/") - ({ "" });
  array1 = ({ });
  for (i = 0; i < sizeof(array); i++) {
    if (array[i] == "..") {
      if (sizeof(array1)) {
        array1 = array1[0..<2];
      }
    } else if (array[i] != ".") {
      array1 += ({ array[i] });
    }
  }
  if (sizeof(array1))
    str = implode(array1, "/");
  else
    str = "";
  return "/" + str;
} /* get_path() */

/** @ignore yes */
protected void eventRead(int fd, string str) {
  class ftp_session sess = Sockets[fd];
  string name, rest, ret, token, type, path;
  int timestamp;

  if (!sess) {
    eventWrite(fd, "DENIED\n", 1);
    return;
  }
  if (str == "mudname") {
    eventWrite(fd, sprintf("OKAY: %s\n", mud_name()));
    return;
  }
  if (sscanf(str, "%s %s", name, rest) != 2) {
    eventWrite(fd, "Syntax error\n", 1);
    return;
  }
  name = lower_case(name);
  if (rest == "request login") {
    int anon = 0;

    if (name == "ftp") {
        anon = 1;
    }
    if (!(anon || creatorp(name))) {
      eventWrite(fd, "DENIED\n");
      return;
    }
    timestamp = time();
    token = crypt("" + timestamp, "" + random(12000));
    sess->token = token;
    sess->timestamp = timestamp;
    sess->user = name;
    if (anon) {
      ret = sprintf("OKAY: %s * /pub\n", token);
    } else {
      ret = sprintf("OKAY: %s %s /w/%s\n", token,
                    PLAYER_H->get_password(name), name);
    }
    eventWrite(fd, ret);
    return;
  }
  if (sscanf(rest, "%s %s %s", token, type, path) != 3) {
    eventWrite(fd, "Syntax error\n", 1);
    return;
  }
  if ((token != sess->token) || ((time() - sess->timestamp) > MAX_LIFE)) {
    eventWrite(fd, "DENIED\n");
    return;
  }
  path = get_path(path);
  switch (type) {
  case "read":
    if (file_size(path) == -2) {
      path += "/*";
    }
    ret = (master()->valid_read(path, name, "read_file") ? "OKAY\n" : "DENIED\n");
    eventWrite(fd, ret);
    break;
  case "write":
    if (file_size(path) == -2) {
      path += "/*";
    }
    ret = (master()->valid_write(path, name, "write_file") ? "OKAY\n" : "DENIED\n");
    eventWrite(fd, ret);
    break;
  default:
    eventWrite(fd, "DENIED\n");
    break;
  }
} /* eventRead() */

/** @ignore yes */
protected void eventSocketClosed(int fd) {
  class ftp_session sess = Sockets[fd];

  if (!sess) {
    return;
  }
  map_delete(Sockets, fd);
} /* eventSocketClosed() */

/** @ignore yes */
protected void clean_sockets() {
  class ftp_session sess;
       
  foreach (sess in values(Sockets)) {
    if (!sess->timestamp) {
      sess->timestamp = time();
      continue;
    }
    if (time() - sess->timestamp > MAX_LIFE) {
      eventWrite(sess->fd, "Timeout\n", 1);
    }
  }
  call_out("clean_sockets", 3600);
} /* clean_sockets() */

/** @ignore yes */
string *query_connections() {
  class ftp_session val;
  string *list;

  list = ({ });
  foreach (val in values(Sockets)) {
    if (val->user) {
      list += ({ capitalize(val->user) });
    } else {
      list += ({ "login" });
    }
  }
  return list;
} /* query_connections() */
