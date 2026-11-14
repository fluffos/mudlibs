 
//  File  :  /include/network.h
//
//  Network system usage defines

#ifndef INETD_SERVICES
#define INETD_SERVICES 	"/adm/etc/services"
#endif
 
#define MUD_ADDRESSES 	"/adm/etc/mud_addresses"
#define MUD_SERVICES 	"/adm/etc/mud_services"
 
#define THIS_MUD lower_case(implode(explode(mud_name(), " "), "."))
 
#ifndef NAME_SERVER
#define NAME_SERVER 	"/adm/daemons/name_server"
#endif
 
#ifndef INETD
#define INETD 		"/adm/daemons/inetd"
#endif
 
#ifndef TS_D
#define TS_D 		"/adm/daemons/ts"
#endif
 
