// FluffOS PORT: global include file (this project's convention for
// FluffOS's mandatory "global include file" config directive -- upstream
// has no single equivalent header; LDMud's own H_AUTO_INCLUDE driver hook
// filled this role there, injecting a "#pragma pedantic" line into every
// compile. That hook doesn't exist on this driver (see sys/driver_hook.h),
// so the pragma is applied directly here instead, which every compile
// picks up automatically via FluffOS's "global include file" mechanism.
#pragma pedantic

// FluffOS PORT: the handful of files that need /secure/simulated-efuns/
// portability.lpc's helpers before simul_efun.lpc itself is ready (see
// that file's own port note) call it directly via this macro rather than
// through simul_efun resolution.
#define PORT "/secure/simulated-efuns/portability"

// FluffOS PORT: dataService.lpc's connect()/disconnect()/convertString()/
// sanitizeString() moved to a real call_other object for the same reason
// PORT exists -- see /lib/modules/secure/dataServices/dataServiceUtil.lpc.
#define DB_UTIL "/lib/modules/secure/dataServices/dataServiceUtil"
