// /include/net/http.h

#ifndef __HTTP_H__
#define __HTTP_H__

#define DIR_WWW "/www"
#define DIR_WWW_ERRORS (DIR_WWW + "/errors")

#define DIR_WWW_GATEWAYS (DIR_WWW + "/cgi-bin")
#define USER_WWW_SUBDIR "public_html"
#define PORT_HTTP (__PORT__ + 80)

#define BAD_CMD \
	([ "error" : "Bad Command", "file": DIR_WWW_ERRORS+"/badcmd.html"])
#define ACCESS_DENIED \
	(["error":"Access Denied", "file":DIR_WWW_ERRORS+"/access.html"])
#define NOT_FOUND \
	(["error":"Not Found", "file":DIR_WWW_ERRORS+"/notfound.html"])
#define BAD_GATEWAY \
	(["error":"Bad Gateway","file":DIR_WWW_ERRORS+"/badgate.html"])

#define LOG_HTTP "http"
#define LOG_HTTP_ERR "http_errors"

#define HTTP_DEBUG(y) do { \
    if (find_player(DEBUGGER)) tell_object(find_player(DEBUGGER),y); \
} while (0)


#endif
