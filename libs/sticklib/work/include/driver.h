/*
 * driver.h - Game driver specified values.
 *
 * Never ever use the plain values, use the defines defined herein instead.
 *
 *
 * 01-Dec-92 Starbyt   ...
 */


#ifndef _DRIVER_H
#define _DRIVER_H

/* get_dir(): */

#define RD_LONGMODE      0x0001
#define RD_FULLPATH      0x0002

/* sort_array(), if object 0, use fast builtin sort routines: */

#define SA_ABCSORT		"sort_abc"
#define SA_123SORT		"sort_123"
#define SA_ABCSORT_ARRAY	"assoc_abc"
#define SA_123SORT_ARRAY	"assoc_123"

#endif /* _DRIVER_H */
