#ifndef _CDEBUG_H
#define _CDEBUG_H   1

/*
** A stripped down version of Kevin's (kevin@njit.edu) BUGOUT macros
** nice job Kev 
** -- muquit
*/

#ifdef __Main__
    unsigned int Gdebug;
#else
    extern unsigned int Gdebug;
#endif

#ifndef __FILE__
#define __FILE__    "?"
#endif


#ifndef __LINE__
#define __LINE__    0
#endif

#ifdef DEBUG
#define Debug4(fmt,v1,v2,v3,v4)                              \
    if (Gdebug == 1)                                         \
    {char * trick = (fmt);                                   \
    (void) fprintf (stderr,"%s(%d): ", __FILE__,__LINE__);   \
    (void) fprintf (stderr,(trick),(v1),(v2),(v3),(v4));     \
    (void) fprintf (stderr,"\n");}

#define Debug2(fmt,v1,v2) Debug4((fmt),(v1),(v2),0,0)
#else
#define Debug4(fmt,v1,v2,v3,v4)
#define Debug2(fmt,v1,v2)
#endif
#endif  /* _CDEBUG_H */
