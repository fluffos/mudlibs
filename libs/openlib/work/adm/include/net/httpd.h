/*  -*- LPC -*-  */
#ifndef __HTTPD_H
#define __HTTPD_H

#include "net/network.h"

// WWW dir for entire mud
#define DIR_WWW "/www"

// dir looked for in user's home
#define USER_WWW_SUBDIR "WWW"

// You can use this to get files about your domains
#define REALMS_DIRS "/d"

// uses log_file with this filename
#define LOG_HTTP "net/httpd"

// WWW errors dir
#define DIR_WWW_ERRORS DIR_WWW "/errors"

// gateways dir
#define DIR_WWW_GATEWAYS DIR_WWW "/gateways"

#define BAD_CMD ([ "error" : "Bad Command", "file": DIR_WWW_ERRORS+"/badcmd.html"])
#define ACCESS_DENIED (["error":"Access Denied", "file":DIR_WWW_ERRORS+"/access.html"])
#define NOT_FOUND (["error":"Not Found", "file":DIR_WWW_ERRORS+"/notfound.html"])
#define BAD_GATEWAY (["error":"Bad Gateway","file":DIR_WWW_ERRORS+"/badgate.html"])

void listen_callback(int fd);
void write_callback(int fd);
void read_callback(int fd, string str);
void resolve_incoming(string addr, string nom, int cle);
nosave private void http_error(int fd, mapping err);
nosave private void add_activity(int fd, string str);
void close_connection(int fd);
nosave private void get_file(int fd, string file);
nosave private string format_date(int x);

#endif /* __HTTP_H */
