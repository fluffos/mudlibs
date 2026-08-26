/* This network header file contains the macros used by the DNS master
 * daemons and its auxiliary daemons.
 */
#ifndef __NET__DNS_H
#define __NET__DNS_H

#ifndef ROOT_UID
#include <uid.h>
#endif
#ifndef NETWORK_MASTER
#include "net/daemons.h"
#endif

#define SERVICES_PATH "/adm/daemons/network/services/"

#define PING_Q     (SERVICES_PATH+"ping_q")
#define PING_A     (SERVICES_PATH+"ping_a")
#define MUDLIST_Q  (SERVICES_PATH+"mudlist_q")
#define SUPPORT_Q  (SERVICES_PATH+"support_q")
#define STARTUP    (SERVICES_PATH+"startup")
#define SHUTDOWN   (SERVICES_PATH+"shutdown")
#define GFINGER_Q	(SERVICES_PATH+"gfinger_q")
#define AFFIRMATION_A  (SERVICES_PATH+"affirmation_a")
#define GFINGER_A	(SERVICES_PATH+"gfinger_a")
#define GTELL      (SERVICES_PATH+"gtell")
#define GWIZ       (SERVICES_PATH+"gwizmsg")
#define LOCATE_Q   (SERVICES_PATH+"locate_q")
#define LOCATE_A   (SERVICES_PATH+"locate_a")
#define GWIZLIST_Q (SERVICES_PATH+"gwizlist_q")
#define GWIZLIST_A (SERVICES_PATH+"gwizlist_a")
#define RWHO_Q     (SERVICES_PATH+"rwho_q")
#define RWHO_A     (SERVICES_PATH+"rwho_a")
#define MAIL_Q     (SERVICES_PATH+"mail_q")
#define MAIL_A     (SERVICES_PATH+"mail_a")

/* The currently known types */
#define DNS_STARTUP          "startup"
#define DNS_SHUTDOWN         "shutdown"
#define DNS_PING_Q           "ping_q"
#define DNS_PING_A           "ping_a"
#define DNS_SUPPORT_Q        "support_q"
#define DNS_SUPPORT_A        "support_a"
#define DNS_RWHO_Q           "rwho_q"
#define DNS_RWHO_A           "rwho_a"
#define DNS_MUDLIST_Q        "mudlist_q"
#define DNS_MUDLIST_A        "mudlist_a"
#define DNS_GFINGER_Q        "gfinger_q"
#define DNS_AFFIRMATION_A    "affirmation_a"
#define DNS_GFINGER_A        "gfinger_a"
#define DNS_GWIZMSG          "gwizmsg"
#define DNS_WARNING          "warning"
#define DNS_GTELL            "gtell"
#define DNS_LOCATE_Q         "locate_q"
#define DNS_LOCATE_A         "locate_a"
#define DNS_GWIZLIST_Q       "gwizlist_q"
#define DNS_GWIZLIST_A       "gwizlist_a"
#define DNS_MAIL_Q           "mail_q"
#define DNS_MAIL_A           "mail_a"

/*
 * This is the number of retrys we ping the mud for before we decide
 * it has gone down.
 */
#define MAX_RETRYS 12
#define DNS_NO_CONTACT "_dns_no_contact"
#define DNS_CONTACT "_dns_contact"

#endif //__NET__DNS_H
