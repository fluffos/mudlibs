// FluffOS PORT: this driver has no set_driver_hook()/H_* driver-hook
// mechanism at all (an LDMud-only feature -- FluffOS/MudOS-lineage drivers
// use fixed, hardcoded applies on the master object instead of a
// configurable hook table). secure/master/hooks.lpc's addDriverHooks() is
// gutted to a no-op on this driver (see that file's own port notes); these
// constants are never actually read by anything, kept only so any stray
// reference still compiles.
#define H_MOVE_OBJECT0          0
#define H_MOVE_OBJECT1          1
#define H_LOAD_UIDS             2
#define H_CLONE_UIDS            3
#define H_CREATE_SUPER          4
#define H_CREATE_OB             5
#define H_CREATE_CLONE          6
#define H_RESET                 7
#define H_CLEAN_UP              8
#define H_MODIFY_COMMAND        9
#define H_MODIFY_COMMAND_FNAME  10
#define H_NOTIFY_FAIL           11
#define H_TELNET_NEG            12
#define H_INCLUDE_DIRS          13
#define H_AUTO_INCLUDE          14
