#ifndef __HTTP_H
#define __HTTP_H

#define DIR_WWW "/www"
#define DIR_WWW_ERRORS DIR_WWW+"/errors"
#define DIR_WWW_GATEWAYS "/www/gateways"
#define USER_WWW_SUBDIR "public_html"
// Try to keep this port, so we might get a standard port for it ;)
#define PORT_HTTP                 (mud_port() - 5)

#define BAD_CMD ([ "error" : "Bad Command", "file": DIR_WWW_ERRORS+"/badcmd.html"])
#define ACCESS_DENIED (["error":"Access Denied", "file":DIR_WWW_ERRORS+"/access.html"])
#define NOT_FOUND (["error":"Not Found", "file":DIR_WWW_ERRORS+"/notfound.html"])
#define BAD_GATEWAY (["error":"Bad Gateway","file":DIR_WWW_ERRORS+"/badgate.html"])

void listen_callback(int fd);
void write_callback(int fd);
void read_callback(int fd, string str);
void resolve_incoming(string addr, string nom, int cle);
protected  void http_error(int fd, mapping err);
protected  void add_activity(int fd, string str);
void close_connection(int fd);
protected  void get_file(int fd, string file);
protected  string format_date(int x);

#endif /* __HTTP_H */
