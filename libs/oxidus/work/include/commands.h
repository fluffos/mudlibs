#ifndef __COMMANDS_H__
#define __COMMANDS_H__

#include <dirs.h>

// Admin commands
#define CMD_REBOOT           DIR_CMDS_ADM "reboot"
#define CMD_SHUTDOWN         DIR_CMDS_ADM "shutdown"

// Wiz commands
#define CMD_EVAL             DIR_CMDS_DEV "eval"

// Std commands
#define CMD_GO               DIR_CMDS_ACTION "go"
#define CMD_LOOK             DIR_CMDS_ACTION "look"
#define CMD_QUIT             DIR_CMDS_STD "quit"
#define CMD_SU               DIR_CMDS_STD "su"

#endif // __COMMANDS_H__
