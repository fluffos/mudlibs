// /include/net/http.h
#ifndef __HTTP_H
#define __HTTP_H

#define DIR_WWW "/www"
#define DIR_WWW_ERRORS DIR_WWW + "/errors"

#define DIR_WWW_GATEWAYS DIR_WWW + "/cgi-bin"
#define USER_WWW_SUBDIR "public_html"
//#define PORT_HTTP (__PORT__ + 80)
#define PORT_HTTP (4080)
#define WWW_CHANNEL "/www/cgi-bin/channel"


#define BAD_CMD ([ "error" : "Bad Command", "file": DIR_WWW_ERRORS+"/badcmd.html"])
#define ACCESS_DENIED (["error":"Access Denied", "file":DIR_WWW_ERRORS+"/access.html"])
#define NOT_FOUND (["error":"Not Found", "file":DIR_WWW_ERRORS+"/notfound.html"])
#define BAD_GATEWAY (["error":"Bad Gateway","file":DIR_WWW_ERRORS+"/badgate.html"])

#define LOG_HTTP "http"
#define LOG_HTTP_ERR "http_errors"

#define HTTP_DEBUG(y) do{ if (find_player(DEBUGGER)) tell_object(find_player(DEBUGGER),y); }while (0)

void listen_callback(int fd);
void write_callback(int fd);
void read_callback(int fd, string str);
protected void http_error(int fd, mapping err, string code);
void close_connection(int fd);
protected void get_file(int fd, string file, string cmd);


#define PATH_WWW(x) ("/www/" + x)
#define PROTECT_DIR
#define PROTECT_FILE ({\
        PATH_WWW("channel/join_channel.html"), \
        PATH_WWW("cgi-bin/j_channel"), \
        })

int check_path(string filename)
{
        int i;

        if(pointerp(PROTECT_FILE))
                for(i=0; i<sizeof(PROTECT_FILE); i++)
                {
                        if(filename == PROTECT_FILE[i])
                                return 0;

                        if((strsrch(filename, "/www/cgi-bin") != -1)
                        && (strsrch(filename, PROTECT_FILE[i]) != -1))
                                return 0;
                }

        return 1;
}

#define WWW_CHANNEL "/www/cgi-bin/channel"


#endif /* __HTTP_H */
