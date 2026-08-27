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
#define SU              "/cmds/std/_su"
// Used in old versions of the simul_efun override of exec()
#define WHO             "/cmds/std/_who"
// Used in old versions of finger


//  The following defines are the standard command reference defines.

#define CMD_APROPOS     "/cmds/wiz/_apropos"
#define CMD_APROPOSM    "/cmds/adm/_aproposm"
#define CMD_BUG         "/cmds/std/_bug"
#define CMD_CD          "/cmds/file/_cd"
#define CMD_DEWIZ       "/cmds/adm/_dewiz"
#define CMD_ED          "/cmds/file/_ed"
#define CMD_HELP        "/cmds/std/_help"
#define CMD_IGNORE      "/cmds/std/_ignore"
#define CMD_LOOK        "/cmds/std/_look"
#define CMD_LS          "/cmds/file/_ls"
#define CMD_MAKEWIZ     "/cmds/adm/_makewiz"
#define CMD_MEM         "/cmds/xtra/_mem"
#define CMD_PRAISE      "/cmds/std/_praise"
#define CMD_SAY         "/cmds/std/_say"
#define CMD_SHUTDOWN    "/cmds/adm/_shutdown"
#define CMD_SNOOP       "/cmds/wiz/_snoop"
#define CMD_SU          "/cmds/wiz/_su"
#define CMD_WHO         "/cmds/std/_who"

#endif // __COMMANDS_H
