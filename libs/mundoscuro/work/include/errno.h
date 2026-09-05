

#ifndef ERRNO_H
#define ERRNO_H

#include "daemons.h"

varargs string build_error(string errno, mixed p1, mixed p2, mixed p3) {
    string err = errno;
    if (p1) err += " " + (string)p1;
    if (p2) err += " " + (string)p2;
    if (p3) err += " " + (string)p3;
    /* this_object() indica el objeto que produce el error */
    return err;
}

string errno(string err) {
    return explode(err," ")[0];
}

#define ERR_LOADING_DAEMON	"-1"
#define ERR_NO_ACCESS		"-2"
#define ERR_DB_CONNECT		"-5"
#define ERR_NO_INMORTAL		"-10"
#define ERR_NO_GROUP		"-11"
#define ERR_DUP_RANK		"-15"
#define ERR_DUP_LEVEL		"-16"
#define ERR_NO_RANK		"-17"
#define ERR_DUP_GROUP		"-18"
#define ERR_DUP_MEMBER		"-19"
#define ERR_NO_MEMBER		"-20"
#define ERR_NO_CHAN		"-21"
#define ERR_DUP_CHAN		"-22"
#define ERR_DUP_DOMAIN		"-23"
#define ERR_NO_DOMAIN		"-24"
#define ERR_DUP_USER		"-25"
#define ERR_NO_USER		"-26"
#define ERR_DUP_INMORTAL	"-27"

#define E(x)		build_error(x)
#define E1(x,y)		build_error(x, y)
#define E2(x,y,z)	build_error(x, y, z)
#define E3(x,y,z,p)	build_error(x, y, z, p)

#define serror(x) efun::call_other(ERROR, "error_message", x)

#endif /* ERRNO_H */

