#ifndef _kernel_defs_h
#define _kernel_defs_h

#ifdef COMPAT_FLAG

#define MASTER              "obj/master"
#define SECURITY            "kernel/server"
#define ACCESS              "kernel/io"
#define SIMUL_EFUN          "obj/simul_efun"
#define SPARE_SIMUL_EFUN    "obj/spare_simul_efun"
#define OBSOLETE_SIMUL_EFUN "obj/obsolete_simul_efun"


#else

#define MASTER              "obj/master"
#define SECURITY            "kernel/server"
#define ACCESS              "kernel/io"
#define SIMUL_EFUN          "kernel/simul_efun"
#define SPARE_SIMUL_EFUN    "kernel/spare_simul_efun"
#define OBSOLETE_SIMUL_EFUN "kernel/obsolete_simul_efun"

#endif /* COMPAT_FLAG */

#endif /* _kernel_defs_h */

