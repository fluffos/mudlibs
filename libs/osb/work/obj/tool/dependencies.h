/*
 * Nightfall, running in native mode
 */
#ifdef  NIGHTFALL

#define MUD_NF 1
#undef  MUD_MG
#undef  MUD_TM

#endif

/*
 * One Step Beyond, running in native mode
 */
#ifdef  ONESTEPBEYOND

#define MUD_NF 1
#undef  MUD_MG
#undef  MUD_TM

#endif

/*
 * TubMUD, running in compat mode
 */
#ifdef  TUBMUD    

#define MUD_TM 1
#undef  MUD_MG
#undef  MUD_NF

#endif

/*
 * MorgenGrauen, running in native mode (but without a common define)
 */
#ifndef COMPAT_FLAG
#ifndef NIGHTFALL

#define MUD_MG 1
#undef  MUD_NF
#undef  MUD_TM

#endif
#endif
