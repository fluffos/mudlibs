#ifndef __HTTP_H
#define __HTTP_H

#include <dirs.h>

#define BAD_CMD ([ "error" : "Bad Command", "file": DIR_WWW_ERRORS+"/badcmd.html"])
#define ACCESS_DENIED (["error":"Access Denied", "file":DIR_WWW_ERRORS+"/access.html"])
#define NOT_FOUND (["error":"Not Found", "file":DIR_WWW_ERRORS+"/notfound.html"])
#define BAD_GATEWAY (["error":"Bad Gateway","file":DIR_WWW_ERRORS+"/badgate.html"])

void listen_callback(int fd);
void write_callback(int fd);
void read_callback(int fd, string str);
void resolve_incoming(string addr, string nom, int cle);
private void http_error(int fd, mapping err);
private void add_activity(int fd, string str);
void retry(int fd, string str);
void close_connection(int fd);
private void get_file(int fd, string file);
private string format_date(int x);

#endif /* __HTTP_H */
