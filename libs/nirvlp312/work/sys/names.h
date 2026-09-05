/*
 * /sys/names.h
 */

#ifndef _sys_names_h
#define _sys_names_h

#include "ctype.h"

/* global definitions */

#define DOMAIN                "nirvana"

#define GOD                   "boltar"
#define HOMEDIR               (islower((name([0]) ? \
                                  "/players/"+(name) : \
                                  "/domains/"+lower_case(name))
#define HOMEOF(wizard)        HOMEDIR((string)wizard->query_real_name())

#define SAVEFILE(name)        ("/save/players/"+name[0..0]+"/"+name)

/* This is the host you are normally running on
 * You can compare it with __HOST_NAME__ to make host-dependent code.
 * Rename it for test muds.
 */
#define HOME_HOST              "loafy"

/* This is the domain the home host is in.
 * You can compare it with __DOMAIN_NAME__ to make domain-dependent code.
 * Rename it for test muds.
 */
#define HOME_DOMAIN            "ironpeanut.com"

#define HOME_HOST_FULL         HOME_HOST HOME_DOMAIN

#endif /* _sys_names_h */
