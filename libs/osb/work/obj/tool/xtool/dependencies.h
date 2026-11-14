#ifndef XTOOL_DEPEND_H
#define XTOOL_DEPEND_H 1

/* Nightfall, running in native mode */
#ifdef  NIGHTFALL
#define MUD_NF 1
#undef  MUD_OSB
#undef  MUD_MG
#undef  MUD_TM
#undef  MUD_TA
#endif

/* One Step Beyond, running in native mode */
#ifdef  ONESTEPBEYOND
#ifndef MUD_NF
#define MUD_NF 1
#endif
#define MUD_OSB 1
#undef  MUD_MG
#undef  MUD_TM
#undef  MUD_TA
#endif

/* TubMUD, running in compat mode */
#ifdef  TUBMUD    
#define MUD_TM 1
#undef  MUD_OSB
#undef  MUD_MG
#undef  MUD_NF
#undef  MUD_TA
#endif

/* TappMUD, running in compat mode */
#ifdef  TAPPMUD    
#define MUD_TA 1
#undef  MUD_OSB
#undef  MUD_MG
#undef  MUD_NF
#undef  MUD_TM
#endif

/* MorgenGrauen, running in native mode (but without a common define) */
#ifndef COMPAT_FLAG
#ifndef NIGHTFALL
#define MUD_MG 1
#undef  MUD_OSB
#undef  MUD_NF
#undef  MUD_TA
#undef  MUD_TM
#endif
#endif

#endif /* XTOOL_DEPEND_H */
