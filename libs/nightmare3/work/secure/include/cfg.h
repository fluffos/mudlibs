#ifndef __CFG_H
#define __CFG_H

#include <dirs.h>

#define CFG_ALIASES		DIR_SECURE_CFG+"/aliases.cfg"
#define CFG_GROUPS		DIR_SECURE_CFG+"/groups.cfg"
#define CFG_LANGUAGES		(DIR_DAEMONS_CFG+"/languages.cfg")
#define CFG_PRELOAD		DIR_SECURE_CFG+"/preload.cfg"
#define CFG_PRELOAD_SOCKET	DIR_SECURE_CFG+"/socket.cfg"
#define CFG_PRIVS		DIR_SECURE_CFG+"/privs.cfg"
#define CFG_RACES		(DIR_DAEMONS_CFG+"/races.cfg")
#define CFG_READ		DIR_SECURE_CFG+"/read.cfg"
#define CFG_UNGUARDED		DIR_SECURE_CFG+"/unguarded.cfg"
#define CFG_WRITE		DIR_SECURE_CFG+"/write.cfg"

#endif /* __CFG_H */
