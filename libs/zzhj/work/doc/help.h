// This include file is included by the help command (/cmds/usr/help).
// If you changed the structure of help docs, remember to update this file.
// The search order is from the end to the start. Put these paths optimizely.
// Why ? See /cmds/usr/help.c

#define DEFAULT_SEARCH_PATHS ({\
	"/doc/efuns/",\
	"/doc/cefuns/",\
	"/doc/cdoc/applies/",\
	"/doc/cdoc/interactive/",\
	"/doc/cdoc/master/",\
	"/doc/cefuns/",\
	"/doc/skill/",\
	"/doc/help/",\
	})

#define MOTD	"/adm/etc/motd"
