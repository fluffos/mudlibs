#ifndef _USER_H
#define _USER_H

#include <sys/tls.h>

#define PASSWD_FILE             _EtcDir "/passwd.val"
#define PASSWD_HASH_METHOD      TLS_HASH_MD5
#define PASSWD_HASH_ITERATIONS  1
#define PASSWD_PASSWORD         "password"

#define SkelDir                 PlatformEtcDir "/skel"
#define TEMPLATE_SUFFIX         ".template"
#define DOMAIN_TEMPLATE         _EtcDir "/domain.xml" TEMPLATE_SUFFIX
#define ZONE_TEMPLATE           _EtcDir "/zone.xml" TEMPLATE_SUFFIX

#endif  // _USER_H
