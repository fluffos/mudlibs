#ifndef SYS_KERNEL_H
#define SYS_KERNEL_H 1

//-------------------------------------------------------------------------
// Backbone extra_wizinfo fields to store global variables.

#define WINFO_BOOTTIME   0    // Time of reboot in seconds
#define WINFO_UNGUARDED  1    // Array of objects doing unguarded actions.
#define WINFO_USERVARS   2    // Mapping with user defined values.

#define WINFO_SIZE 3  // Number of fields to allocate

#endif
