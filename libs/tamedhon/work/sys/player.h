// SilberLand MUDlib
//
// sys/player.h -- player object defines
//
// 2024/04/09 - includes als absolutpfad, damit auch das masterobjekt laden kann - Aloy
//
// $Date: 1997/03/31 13:15:21 $
/* $Revision: 1.20 $
 * $Log: player.h,v $
 * Revision 1.20  1997/03/31 13:15:21  Woody
 * prepared for revision control
 *
 * Revision 1.16  1995/06/06  08:32:32  Jof
 * P_ACTUAL_NOTIFY_FAIL
 *
 * Revision 1.15  1995/06/05  14:30:38  Jof
 * actual_notify_fail
 *
 * Revision 1.14  1995/03/01  15:53:28  Jof
 * P_LAST_KILLER
 *
 * Revision 1.13  1995/02/07  23:15:55  Jof
 * P_IP_NAME
 *
 * Revision 1.12  1995/01/13  12:06:51  Jof
 * _unparsed_args
 *
 * Revision 1.11  1995/01/09  12:25:11  Jof
 * default_notify_fail
 *
 * Revision 1.10  1995/01/09  08:47:37  Jof
 * new props (HISTMIN/SHOW_ALIAS_PROCESSING)
 *
 * Revision 1.9  1994/08/30  13:50:10  Jof
 * *** empty log message ***
 *
 * Revision 1.8  1994/07/11  18:00:07  Jof
 * *** empty log message ***
 *
 * Revision 1.7  1994/06/30  20:17:09  Hate
 * updated daemon header
 *
 * Revision 1.6  1994/05/05  09:37:13  Hate
 * Removed some obsolete Props
 * include channel.h
 *
 * Revision 1.5  1994/03/16  13:31:12  Jof
 * P_NETDEAD_INFO done
 *
 * Revision 1.4  1994/03/14  16:40:27  Jof
 * P_LAST_COMMAND_ENV
 *
 * Revision 1.3  1994/01/20  16:12:35  Jof
 * included player/comm.h
 *
 * Revision 1.2  1994/01/18  01:05:19  mud
 * *** empty log message ***
 *             
 */                            

#ifndef __PLAYER_H__
#define __PLAYER_H__

#ifdef NEED_PROTOTYPES
#undef NEED_PROTOTYPES
// we need only the properties here!!
#define TMP_NEED_PROTOTYPES
#endif

#include "/sys/player/base.h"
#include "/sys/player/description.h"
#include "/sys/player/moving.h"
#include "/sys/player/filesys.h"
#include "/sys/player/potion.h"
#include "/sys/player/quest.h"
#include "/sys/player/skills.h"
#include "/sys/player/viewcmd.h"
#include "/sys/player/comm.h"
#include "/sys/daemon.h"

#ifdef TMP_NEED_PROTOTYPES
#undef TMP_NEED_PROTOTYPES
#define NEED_PROTOTYPES
#endif

#define P_LAST_COMMAND_ENV "last_command_env"
#define P_HISTMIN "histmin"
#define P_SHOW_ALIAS_PROCESSING "show_alias_processing"
#define P_DEFAULT_NOTIFY_FAIL "default_notify_fail"
#define P_NETDEAD_INFO "netdead_info"
#define P_IP_NAME "ip_name"
#define P_AUTH_INFO "auth_info"
#define P_LAST_KILLER "last_killer"
#define P_ACTUAL_NOTIFY_FAIL "actual_notify_fail"

#define DeclareAutoload(name,param) \
  mlfp_create(({P_AUTOLOAD,name}),param)

#define UndeclareAutoload(name) \
  mlfp_remove(({P_AUTOLOAD}),name)

#define QueryAutoload(name) \
  mlfp_query(({P_AUTOLOAD,name}))

#ifdef NEED_PROTOTYPES
varargs string _unparsed_args(int level);
#endif

#endif

