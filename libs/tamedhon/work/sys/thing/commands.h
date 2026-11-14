// SilberLand MUDlib
//
// sys/thing/commands.h -- command handling header
//
// $Date: 1997/03/31 15:46:06 $
/* $Revision: 1.1 $
 * $Log: commands.h,v $
 * Revision 1.1  1997/03/31 15:46:06  Woody
 * prepared for revision control
 *
 */
 
#ifndef __THING_COMMANDS_H__
#define __THING_COMMANDS_H__

// properties

#define P_COMMANDS  "commands"

#endif // __THING_COMMANDS_H__

#ifdef NEED_PROTOTYPES

#ifndef __THING_COMMANDS_H_PROTO__
#define __THING_COMMANDS_H_PROTO__

// prototypes

// add commands to the command list of the object
varargs void AddCmd(mixed cmd, mixed func, int flag);

// remove a command
varargs void RemoveCmd(mixed cmd);

#endif // __THING_COMMANDS_H_PROTO__

#endif	// NEED_PROTOYPES
