// FluffOS PORT: configure_object() option ids. This driver has no native
// configure_object() efun (LDMud-specific) -- secure/simul_efun.lpc /
// object-info.lpc implements the two options this codebase actually uses
// as simul_efuns on top of this driver's own enable_commands()/
// set_heart_beat() efuns. OC_COMMANDS_ENABLED is handled by a native
// enable_commands()/disable_commands() efun pair on this driver (guarded
// by __EFUN_DEFINED__ in simul_efun.lpc, so this value is never actually
// read) -- kept for completeness/compile-time reference only.
#define OC_HEART_BEAT       1
#define OC_COMMANDS_ENABLED 2
