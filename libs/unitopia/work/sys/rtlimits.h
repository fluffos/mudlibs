// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/rtlimits.h
// Description:	Defines fuer set_limits(), limited() und get_limits()
// Author:	Driver (30.07.1999)
//
// $Log: rtlimits.h,v $
// Revision 1.7  2011-04-28 15:35:13  gnomi
// Vom 3.5.0 eingespielt.
//
// Revision 1.6  2009-04-21 11:52:02  gnomi
// Vom 3.3.718 eingespielt
//
// Revision 1.5  2006/10/18 20:14:32  gnomi
// Auf 3.3.714 aktualisiert.
//
// Revision 1.4  2001/08/23 09:21:54  freaky
// angepasst an ldmud-3.2.9dev323
//
// Revision 1.3  2001/04/21 14:08:44  freaky
// von ldmud-3.2.9dev281 uebernommen.
//
// Revision 1.2  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef LPC_RTLIMITS_H_
#define LPC_RTLIMITS_H_

/* Runtime limit index/tag values */

#define LIMIT_EVAL           (0)
#define LIMIT_ARRAY          (1)
#define LIMIT_MAPPING        (2)
#define LIMIT_MAPPING_KEYS   LIMIT_MAPPING
#define LIMIT_MAPPING_SIZE   (3)
#define LIMIT_BYTE           (4)
#define LIMIT_FILE           (5)
#define LIMIT_CALLOUTS       (6)
#define LIMIT_COST           (7)
#define LIMIT_MEMORY         (8)

#define LIMIT_MAX      (9)  /* Number of recognized limits */

/* Special limit values */

#define LIMIT_UNLIMITED    0   /* No limit */
#define LIMIT_KEEP       (-1)  /* Keep the old limit setting */
#define LIMIT_DEFAULT    (-2)  /* Use the default setting */

/* memory limits */
#define MALLOC_SOFT_LIMIT    1
#define MALLOC_HARD_LIMIT    2

/* low memory conditions */
#define NO_MALLOC_LIMIT_EXCEEDED     0
#define SOFT_MALLOC_LIMIT_EXCEEDED   MALLOC_SOFT_LIMIT
#define HARD_MALLOC_LIMIT_EXCEEDED   MALLOC_HARD_LIMIT

/* Flags for available reserves */
#define USER_RESERVE_AVAILABLE     0x1
#define MASTER_RESERVE_AVAILABLE   0x2
#define SYSTEM_RESERVE_AVAILABLE   0x4

#endif /* LPC_RTLIMITS_H_ */
