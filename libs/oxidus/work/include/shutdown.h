#ifndef __SHUTDOWN_H__
#define __SHUTDOWN_H__

// Exit codes handed to the driver's shutdown() efun. The run script keys off
// the process exit status: SYS_REBOOT restarts the driver, SYS_SHUTDOWN stops
// it. Driver boot failures exit with -1 (255), which the run script also
// stops on, so a crash on boot never loops.
#define SYS_SHUTDOWN               0   // clean exit; run script stops
#define SYS_REBOOT                 1   // exit; run script restarts the driver

// Default delay, in minutes, when an operator schedules a shutdown/reboot
// without specifying a time.
#define SHUTDOWN_DEFAULT_MINUTES  15

#endif // __SHUTDOWN_H__
