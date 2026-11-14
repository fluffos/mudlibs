// SilberLand MUDlib
//
// sys/ancient.h -- ancient compatibility module
//
// $Date: 1997/03/31 12:26:13 $
/* $Revision: 1.1 $
 * $Log: ancient.h,v $
 * Revision 1.1  1997/03/31 12:26:13  Woody
 * prepared for revision control
 *
 */

// Ancient compatibility module ...

#ifndef SetIds
#define SetIds(x)       SetProp(P_IDS,x)
#endif

#ifndef SetName
#define SetName(x)      SetProp(P_NAME,x)
#endif

#ifndef SetIntLong
#define SetIntLong(x)   SetProp(P_INT_LONG,x)
#endif


#ifndef SetIntShort
#define SetIntShort(x)  SetProp(P_INT_SHORT,x)
#endif

#ifndef SetLong
#define SetLong(x)      SetProp(P_LONG,x)
#endif

#ifndef SetShort
#define SetShort(x)     SetProp(P_SHORT,x)
#endif

#ifndef SetLight
#define SetLight(x)     SetProp(P_LIGHT,x)
#endif
