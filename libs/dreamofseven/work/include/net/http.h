// http.h

#ifndef __HTTP_H__
#define __HTTP_H__

#define HTTPD_PORT   	4015
#define SERVER_ROOT	"/WWW"
#define USER_DIR     	"/WWW"
#define CGI_DIR	     	"/cgi-bin"
#define ERROR_DIR	"/errors"
#define WELCOME      	"index.html"
#define CGI_TAG	     	"EC-CGI"
#define HTTPD_LOG  	"httpd.log"

#define BAD_CMD \
	([ "error" : "Bad Command", "file": ERROR_DIR+"/badcmd.html"])
#define ACCESS_DENIED \
	(["error":"Access Denied", "file": ERROR_DIR+"/access.html"])
#define NOT_FOUND \
	(["error":"Not Found", "file": ERROR_DIR+"/notfound.html"])
#define BAD_CGI \
	(["error":"Bad CGI","file": ERROR_DIR+"/badcgi.html"])

#endif
