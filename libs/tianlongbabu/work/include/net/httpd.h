// rcsid = "$Header: /home/mud/cvsroot/tlbbmud/tlbb/tlbb_mudlib/include/net/httpd.h,v 1.1 2000/03/05 18:00:03 mud Exp $"

#ifndef __HTTP_H
#define __HTTP_H

//#define BLOCK_SIZE 8000
#define DIR_WWW "/www"
#define DIR_WWW_ERRORS DIR_WWW + "/errors"
#define DIR_WWW_GATEWAYS DIR_WWW + "/gateways"
#define USER_WWW_SUBDIR "public_html"
#define PORT_HTTP (__PORT__ - 5)
#define WWW_CHANNEL "/www/gateways/l_channel"

#define BAD_CMD \
	([ "error" : "Bad Command", "file": DIR_WWW_ERRORS+"/badcmd.html"])
#define ACCESS_DENIED \
	(["error":"Access Denied", "file":DIR_WWW_ERRORS+"/access.html"])
#define NOT_FOUND \
	(["error":"Not Found", "file":DIR_WWW_ERRORS+"/notfound.html"])
#define BAD_GATEWAY \
	(["error":"Bad Gateway","file":DIR_WWW_ERRORS+"/badgate.html"])
#define UNAUTHORIZED \
	(["error":"Unauthorized","file":DIR_WWW_ERRORS+"/unauthorized.html"])

#define LOG_HTTP "http"
#define LOG_HTTP_ERR "http_errors"

#define HTTP_DEBUG(y) do { \
    if (find_player(DEBUGGER)) tell_object(find_player(DEBUGGER),y); \
} while (0)

void listen_callback(int fd);
void write_callback(int fd);
void read_callback(int fd, string str);
static private void http_error(int fd, mapping err, string code);
void close_connection(int fd);
static private void get_file(int fd, string file, string cmd);

#endif /* __HTTP_H */
