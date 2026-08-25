// FluffOS PORT: interactive_info() flag ids. This driver has no native
// interactive_info() efun (LDMud-specific) -- secure/simul_efun.lpc (via
// interactive-info.lpc) implements it as a simul_efun on top of this
// driver's own query_ip_number()/query_ip_name()/query_idle() efuns. The
// numeric values here are this port's own invention (only interpreted by
// that simul_efun, not by the driver), kept distinct for clarity.
#define II_IP_NUMBER 1
#define II_IP_NAME   2
#define II_IDLE      3
