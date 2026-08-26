//  File        :  /include/commands.h
//
//  Purpose     :  this file is included by objects that want to refer
//                 to other commands (and so avoid having to know which
//                 command directory they are in)
//
//  Adding all commands to this using a perl script may be a bad idea
//  since you lose information about which commands you may freely change
//  and which get called by other objects.
//  The old defines are here for backwards compatibility. This format is
//  no longer used in favor of the format below it.
//  None of them are used in the TMI-II 1.1 release onwards and you can
//  delete them if you are getting this mudlib fresh.
#ifndef __COMMANDS_H
#define __COMMANDS_H

#define CD              "/cmds/file/_cd"
// Used in old versions of tsh
#define SU              "/cmds/wiz/_su"
// Used in old versions of the simul_efun override of exec()
#define WHO             "/cmds/std/_who"
// Used in old versions of finger


//  The following defines are the standard command reference defines.

#define CMD_ALIAS       "/cmds/std/_alias"
#define CMD_APROPOS     "/cmds/wiz/_apropos"
#define CMD_APROPOSM    "/cmds/adm/_aproposm"
#define CMD_BUG         "/cmds/std/_bug"
#define CMD_CD          "/cmds/file/_cd"
#define CMD_CLONE	"/cmds/object/_clone"
#define CMD_DEWIZ       "/cmds/adm/_dewiz"
#define CMD_ED          "/cmds/file/_ed"
#define CMD_EVAL	"/cmds/file/_eval"
#define CMD_EVENT    "/cmds/object/_event"
#define CMD_FINGER	"/cmds/std/_finger"
#define CMD_GREP       "/cmds/file/_grep"
#define CMD_HELP        "/cmds/std/_help"
#define CMD_IGNORE      "/cmds/std/_ignore"
#define CMD_LOAD	"/cmds/object/_load"
#define CMD_LOCATE      "/cmds/wiz/_locate"
#define CMD_LOOK        "/cmds/std/_look"
#define CMD_LS          "/cmds/file/_ls"
#define CMD_MAKEWIZ     "/cmds/adm/_makewiz"
#define CMD_MEM         "/cmds/xtra/_mem"
#define CMD_MUDINFO	"/cmds/xtra/_mudinfo"
#define CMD_NEWSADM	"/cmds/adm/_newsadm"
#define CMD_PRAISE      "/cmds/std/_praise"
#define CMD_REPLY	"/cmds/std/_reply"
#define CMD_SAY         "/cmds/std/_say"
#define CMD_SHUTDOWN    "/cmds/adm/_shutdown"
#define CMD_SNOOP       "/cmds/wiz/_snoop"
#define CMD_SU          "/cmds/wiz/_su"
#define CMD_TELL	"/cmds/std/_tell"
#define CMD_UPDATE      "/cmds/object/_update"
#define CMD_WHO         "/cmds/std/_who"
#define CMD_PASSWD	"/cmds/std/_passwd"
#define CMD_MAIL	"/cmds/wiz/_mail"
#define CMD_FROM	"/cmds/wiz/_from"
#define CMD_DBXFRAME     "/cmds/adm/_dbxframe"
#define CMD_DBXWHERE     "/cmds/adm/_dbxwhere"
#define CMD_SHELL	"/cmds/std/_shell"
#define CMD_CHSH	"/cmds/std/_chsh"
#define CMD_SHOW	"/cmds/std/_show"
#define CMD_TUNE	"/cmds/std/_tune"

#endif // __COMMANDS_H
