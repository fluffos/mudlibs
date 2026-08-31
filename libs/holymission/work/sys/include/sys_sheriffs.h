/*
 * sys_sheriffs.h -- reconstructed placeholder.
 *
 * Referenced via #include <sys_sheriffs.h> (room/adv_guild.c and
 * others); the only real file with a matching-ish name in the archive,
 * /sys/sheriffs.h (no "sys_" prefix), is an empty 0-byte placeholder,
 * and grepping the whole ~24,000-file tree found zero other copies or
 * definitions of SHERIFFS's real contents. Only ever used as a
 * reserved-name deny-list (`member_array(name, SHERIFFS) == -1`), same
 * situation and same safe reconstruction as sys_arches.h's ARCHES in
 * this same directory -- an empty list is behavior-preserving (no name
 * is sheriff-reserved, a strict subset of whatever the real, lost list
 * once did). See NOTES.md.
 */

#ifndef __SYS_SHERIFFS_H__
#define __SYS_SHERIFFS_H__

#define SHERIFFS ({ })

#endif // __SYS_SHERIFFS_H__
