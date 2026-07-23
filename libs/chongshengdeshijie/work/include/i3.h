//#include <ftp.h>
#define IMUD_TCP_PORT           (__PORT__+8)
#define IMUD_UDP_PORT           (__PORT__+12)
//#define MUDLIB                  "Dragon Mudlib 1.1"
//#define BASE_MUDLIB             "Dragon Mudlib 1.1"
#define SERVICES                ([ "tell" : 1, \
                                   "emoteto" : 1, \
                                   "who" : 1, \
                                   "finger" : 1, \
                                   "locate" : 1, \
                                   "channel" : 1, \
                                   "news" : 0, \
                                   "mail" : 0, \
                                   "file" : 0, \
                                   "auth" : 0, \
                                   "ucache" : 0, \
                                   "mudlist" : 1, \
                                   "ftp" : FTP_PORT, \
                                   "http" : HTTP_PORT, \
                                ])

#define OTHER_DATA              0
#define RETRIES                 5
#define I3D_SAVE                "/data/network/i3d"

class channel {
    string c_name;           // What channel's name appears to be in messages
    string sec;              // Security class at which people can receive line
    string *exceptions;      // Array of people who can recieve this line
    string format;           // Format of string
    int off_on_create;       // Line is turned off in players by default
}

class service {
    string security;
    int enabled;
}
