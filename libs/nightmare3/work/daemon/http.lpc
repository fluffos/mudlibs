/*    /daemon/http.c
 *    from Nightmare IV
 *    an http daemon that can talk to Mosaic and other WWW clients
 *    created by Descartes of Borg 940521
 *    callback fix by Robocoder 950117
 */

#include <std.h>
#include <daemons.h>
#include <security.h>
#include <network.h>
#include "http.h"

inherit DAEMON;

nosave private int __SocketHTTP;
nosave private mapping __Sockets, __Activity;

void create() {
    daemon::create();
    set_no_clean(1);
    __Sockets = ([]);
    __Activity = ([]);
    call_out("setup", 2);
    call_out("clean_sockets", 180);
}

protected void setup() {
    if((__SocketHTTP=socket_create(STREAM,"read_callback","close_callback"))<0){
        log_file("httpd", "Failed to create socket.\n");
        return;
    }
    if(socket_bind(__SocketHTTP, PORT_HTTP) < 0) {
        socket_close(__SocketHTTP);
        log_file("httpd", "Failed to listen to socket.\n");
        return;
    }
    if(socket_listen(__SocketHTTP, "listen_callback") < 0) {
        socket_close(__SocketHTTP);
        log_file("httpd", "Failed to listen to socket.\n");
    }
}

void listen_callback(int fd) {
    int neu;

    if((neu = socket_accept(fd, "read_callback", "write_callback")) < 0)
      return;
    write_callback(neu);
}

void write_callback(int fd) {
    string tmp;
    int x;

    if(!__Sockets[fd]) {
        sscanf(socket_address(fd), "%s %*s", tmp);
        x = resolve(tmp, "resolve_incoming");
        __Sockets[fd] = ([ "address": tmp, "key": x, "time": time() ]);
        add_activity(fd, sprintf("CONNECTED (%s)\n", ctime(time())));
      }
    else close_connection(fd);
}

void read_callback(int fd, string str) {
    string cmd, args;

    if(!str || str == "") {
        http_error(fd, BAD_CMD);
        return;
      }
    str = explode(replace_string(str, "\r", ""), "\n")[0];
    sscanf(str, "%s %s", cmd, args);
    switch(lower_case(cmd)) {
        case "get": get_file(fd, args); return;
        default: http_error(fd, BAD_CMD); return;
	}
  }

void close_callback(int fd) {
    log_file("httpd", "Socket closed.\n");
    socket_close(fd);
    if(fd == __SocketHTTP) this_object()->remove();
}

void resolve_incoming(string nom, string addr, int cle) {
    int *fds;
    int i;

    i = sizeof(fds = keys(__Sockets));
    while(i--)
      if(__Sockets[fds[i]]["key"]==cle && __Sockets[fds[i]]["address"]==addr) {
          __Sockets[fds[i]]["name"] = (nom ? nom : addr);
          return;
      }
    log_file("httpd",sprintf("Ip %s resloved to %s after connection closed.\n",
      addr, (nom ? nom : "NOT RESOLVED")));
  }

private void http_error(int fd, mapping err) {
    string str;

    add_activity(fd, sprintf("ERROR: %s (%s)\n", err["error"], ctime(time())));
    retry(fd, str = read_file(err["file"]) ? str : "");
}

private void add_activity(int fd, string act) {
    if(!__Activity[fd]) __Activity[fd] = ({ act });
    else __Activity[fd] += ({ act });
}

void close_connection(int fd) {
    int i, maxi;

    maxi = sizeof(__Activity[fd]);
    if(!__Sockets[fd]["name"]) __Sockets[fd]["name"]=__Sockets[fd]["address"];
    for(i =0; i<maxi; i++)
      log_file("httpd", sprintf("%s: %s",
        __Sockets[fd]["name"], __Activity[fd][i]));
    map_delete(__Sockets, fd);
    map_delete(__Activity, fd);
    socket_close(fd);
  }

protected void clean_sockets() {
    int *cles;
    int i;

    i = sizeof(cles = keys(__Sockets));
    while(i--)
      if(time() - __Sockets[cles[i]]["time"] > 180) close_connection(cles[i]);
    call_out("clean_sockets", 180);
}

private void get_file(int fd, string file) {
    string *parts, *tmp;
    mixed str;
    string id, args;
    int x;

    add_activity(fd, sprintf("GET %s (%s)\n", file, ctime(time())));
    file = (tmp = explode(file, " "))[0];
    id = sizeof(parts) > 1 ? parts[1] : "";
    if(file[0] != '/') file = sprintf("/%s", file);
    parts = explode(file = absolute_path("/", file), "/");
    if(!sizeof(parts)) file = sprintf("%s/index.html", DIR_WWW);
    else if(parts[0][0] == '~') {
        parts[0] = sprintf("%spublic_html",
          user_path(parts[0][1..strlen(parts[0])-1]));
        file = implode(parts, "/");
      }
    if(strsrch(file, DIR_WWW) && strsrch(file, REALMS_DIRS))
      file = sprintf("%s%s", DIR_WWW, file);
    if(file_size(file) == -2) file = sprintf("%s/index.html", file);
    if(!strsrch(file, DIR_WWW_GATEWAYS)) {
        if(sscanf(file, DIR_WWW_GATEWAYS+"/%s/%s", id, args) != 2) {
            args = 0;
            sscanf(file, DIR_WWW_GATEWAYS+"/%s", id);
        }
        if(catch(str=(string)call_other(DIR_WWW_GATEWAYS+"/"+id,"gateway",args))) {
            http_error(fd, BAD_GATEWAY);
            return;
        }
        str = strip_colours(str);
    }
    else if(!file_exists(file)) {
        http_error(fd, NOT_FOUND);
        return;
      }
    else str = read_buffer(file);
    retry(fd, str);
}

void retry(int fd, string str) {
    int res;

    if((res = socket_write(fd, str)) != EECALLBACK) {
        if(res == EEWOULDBLOCK) call_out("retry", 10, fd, str);
        else close_connection(fd);
    }
}


int remove() {
    socket_close(__SocketHTTP);
    return daemon::remove();
}

 string format_date(int x) {
    string *parts;
    string str;

    parts = explode(replace_string(ctime((int)TIME_D->query_tzone("GMT")),
      "  ", " "), " ");
    switch(parts[0]) {
        case "Mon": str = "Monday, "; break;
        case "Tue": str = "Tuesday, "; break;
        case "Wed": str = "Wednesday, "; break;
        case "Thu": str = "Thursday, "; break;
        case "Fri": str = "Friday, "; break;
        case "Sat": str = "Saturday, "; break;
        case "Sun": str = "Sunday, "; break;
    }
    str = sprintf("%s%s-%s-%s %s GMT", str, parts[2], parts[1],
      parts[4][2..3], parts[3]);
    return str;
}
