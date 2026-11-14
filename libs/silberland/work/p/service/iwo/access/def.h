#ifdef MASTER
#undef MASTER
#endif
#define MASTER "/secure/master.lpc"
#define ACPATH "/p/service/iwo/access/"
#define ACMAIN ACPATH "main.lpc"
#define ACSTD ACPATH "std_room.lpc"
#define ACVC ACPATH "virtual_compiler.lpc"
#define ACMASTER ACPATH "ac_master.lpc"
#define ACDOC ACPATH "doc/manual.txt"
#define ACLOGDIR "/log/game/access_log/"


#define ACSAVEFILE ACPATH "ac_data"

#define ALL 3
#define LORDS 1
#define ARCHES 2

#define NOTE_LIFETIME 86400*14

#define SYM_READ ANSI_GREEN+"(r)"+ANSI_NORMAL
#define SYM_RREAD ANSI_GREEN+ANSI_BOLD+"(R)"+ANSI_NORMAL

#define SYM_WRITE ANSI_RED+"w"+ANSI_NORMAL
#define SYM_RWRITE ANSI_RED+ANSI_BOLD+"w"+ANSI_NORMAL

#define ACDEBUG "acdebug"
