#ifndef B_BASE_H
#define B_BASE_H 1

#include "/i/sys/stdprops.h"
#include <moving.h>

// Properties

#define P_Autodata      "Autodata"
#define P_Cloned        SP_Cloned
#define P_Cleanup       "Cleanup"
#define P_Creator       SP_Creator
#define P_ICreator      "ICreator"
#define P_Inherited     "Inherited"
#define P_LastReset     SP_LastReset
#define P_NoAutoload    "NoAutoload"
#define P_Props         "Props"
#define P_ResetInterval SP_ResetInterval
#define P_VMaster       SP_VMaster

// Fields in the 'props' mapping.

#define F_VALUE  0  // the base value
#define F_MODE   1  // some flags

// Mode flags

#define PM_FIXED       (1<<7)  // Property is fixed.
#define PM_NOSAVE      (1<<6)  // Property is not saved.
#define PM_PROTECTED   (1<<5)  // Property is protected.
#define PM_PERM_HOOK   (1<<4)  // Property will never take closures as them
#define PM_HOOK        (1<<3)  // Property doesn't take closures as them
#define PM_STRING      (1<<2)  // Property is dynamic string.
#define PM_EXISTS       1      // Property does exist.

// Mode fields

#define PMF_MODE   (PM_FIXED|PM_NOSAVE|PM_PROTECTED|PM_PERM_HOOK)
#define PMF_TYPE   (PM_HOOK|PM_STRING)
#define PMF_XTYPE  (PM_PERM_HOOK|PMF_TYPE)

#endif
