// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/driver_hook.h
// Description: Defines fuer set_driver_hook()
// Author:	Driver
//
// $Log: driver_hook.h,v $
// Revision 1.8  2009-04-21 11:52:02  gnomi
// Vom 3.3.718 eingespielt
//
// Revision 1.7  2006/10/18 20:14:32  gnomi
// Auf 3.3.714 aktualisiert.
//
// Revision 1.6  2001/11/18 15:56:54  freaky
// Von ldmud-3.2.9dev363 eingespielt.
//
// Revision 1.5  2001/10/20 14:15:34  freaky
// von ldmud-3.2.9dev251 eingespielt.
//
// Revision 1.4  2001/08/23 09:21:54  freaky
// angepasst an ldmud-3.2.9dev323
//
// Revision 1.3  2001/07/01 12:50:31  freaky
// von ldmud-32dev305 uebernommen.
//
// Revision 1.2  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef LPC_DRIVER_HOOK_H_
#define LPC_DRIVER_HOOK_H_ 1

/* --- Driver Hooks ---
 */

#define H_MOVE_OBJECT0           0
#define H_MOVE_OBJECT1           1
#define H_LOAD_UIDS              2
#define H_CLONE_UIDS             3
#define H_CREATE_SUPER           4
#define H_CREATE_OB              5
#define H_CREATE_CLONE           6
#define H_RESET                  7
#define H_CLEAN_UP               8
#define H_MODIFY_COMMAND         9
#define H_NOTIFY_FAIL           10
#define H_NO_IPC_SLOT           11
#define H_INCLUDE_DIRS          12
#define H_TELNET_NEG            13
#define H_NOECHO                14
#define H_ERQ_STOP              15
#define H_MODIFY_COMMAND_FNAME  16
#define H_COMMAND               17
#define H_SEND_NOTIFY_FAIL      18
#define H_AUTO_INCLUDE          19
#define H_DEFAULT_METHOD        20
#define H_DEFAULT_PROMPT        21
#define H_PRINT_PROMPT          22
#define H_REGEXP_PACKAGE        23
#define H_MSG_DISCARDED         24

#define NUM_DRIVER_HOOKS        25  /* Number of hooks */

#endif /* LPC_DRIVER_HOOK_ */

