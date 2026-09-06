#ifndef _SECURE_KERNEL_
#define _SECURE_KERNEL_ 1

/*--------------------------------------------------------------------------
 * /sys/secure/kernel.h -- Definitions of the (simul_efun) kernel.
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 */

#ifndef KERNEL
#define KERNEL        "/secure/kernel"
#endif
#ifndef SPAREKERNEL
#define SPAREKERNEL   "/secure/sparekernel"
#endif

/* Description of the extra fields in the global wizinfo list.
 * The kernel uses it to hold global variables.
 */

#define WI_MUDWHO          1  // The (partly internal) mudwho data.
#define WI_LIVING_NAME     3  // Mapping Living by Name
#define WI_NAME_LIVING     4  // Mapping Name by Living
#define WI_BOOTTIME        5  // Time of the boot.

#define BACKBONE_WIZINFO_SIZE 6 // Max above index + 1

/* The difference real time - host time in seconds.
 * If the hosts clock runs correctly, defines this to a value of 0.
 */

#if __HOST_NAME__ == "leander"
#define TIME_DELTA 420  // real time - leander time in seconds
#else
#ifndef TIME_DELTA
#define TIME_DELTA 3600
#endif
#endif

#endif /* _SECURE_KERNEL_ */
