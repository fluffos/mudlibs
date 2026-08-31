/*
 * sys_arches.h -- reconstructed placeholder.
 *
 * The original /sys/include/sys_arches.h referenced by secure/master.c,
 * secure/mmm.c and secure/backmaster.c was not present anywhere in the
 * preserved archive (this restoration's /sys/arches.h, /sys/defs.h and
 * /sys/levels.h -- note: no "include" subdirectory -- all survived only
 * as 0-byte placeholder files, and grep across the entire ~24,000-file
 * tree found zero other copies or references defining ARCHES's real
 * contents). ARCHES is only ever used as a reserved-name deny-list
 * (secure/login.c: `member_array(str, ARCHES) == -1` blocks registering
 * with one of these names). An empty list is a safe, behavior-preserving
 * reconstruction -- it just means no name is arch-reserved, which is a
 * strict subset of whatever the real (lost) list once did. See NOTES.md.
 */

#ifndef __SYS_ARCHES_H__
#define __SYS_ARCHES_H__

#define ARCHES ({ })

#endif // __SYS_ARCHES_H__
