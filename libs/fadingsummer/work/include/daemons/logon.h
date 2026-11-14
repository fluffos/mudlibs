// mudlib: Fading Summer
// file:   logon.h
// author: Lontau
// date:   22-6-2001

/* Synopsis: This header is meant to be included in the logon
   daemon.  It defines locations for various messages to be
   displayed.
*/

#ifndef _H_logon_d_
#define _H_logon_d_

#define LOGON_BANNER         "/system/etc/banner"
#define LOGON_NAME_PROMPT    "Please enter your name: "
#define LOGON_PASS_PROMPT    "Enter passkey: "
#define LOGON_NONEXISTANT    "That name is unknown to us.  Would you like to use it? "
#define LOGON_REFUSE_NAME    "Ok.  Please enter a different name: "
#define LOGON_PASS_INVALID   "Invalid passkey.\n"
#define LOGON_NAME_EMPTY     "You must enter a name.\n"
#define LOGON_NAME_INVALID   "That is an illegal name.\n"
#define LOGON_FAIL_TOO_MANY  "You have failed to logon too many times.  You will be disconnected.\n"
#define LOGON_GOODBYE        "Goodbye.\n"

#define LOGON_DEVELOPMENT_BANNER    "/system/etc/banner-dev"
#define LOGON_BUILDING_BANNER       "/system/etc/banner-build"
#define LOGON_TESTING_BANNER        "/system/etc/banner-testing"

#define LOGON_GET_NAME              0
#define LOGON_GET_PASS              1
#define LOGON_CONFIRM_NEW           2

#define LOGON_MAX_NAME_ATTEMPTS     3
#define LOGON_MAX_PASS_ATTEMPTS     3

#endif
