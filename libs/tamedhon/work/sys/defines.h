// SilberLand MUDlib
//
// sys/defines.h -- some useful defines
//
// 2024/04/15 - is_clone / is_blue vom mg - Aloy
//
// $Date: 1998/01/29 03:00:36 $
/* $Revision: 1.8 $
 * $Log: defines.h,v $
 * Revision 1.8  1998/01/29 03:00:36  Woody
 * BS_SINGLE_SPACE eingefuegt
 *
 * Revision 1.7  1997/03/31 12:46:17  Woody
 * prepared for revision control
 *
 * Revision 1.6  1995/06/19  15:33:44  Jof
 * TI wieder raus
 *
 * Revision 1.5  1995/06/19  15:31:06  Jof
 * lauter IFDEFs
 * BS_*
 *
 * Revision 1.4  1994/07/22  14:11:39  Kirk
 * removed FILTER_STRING
 *
 * Revision 1.4  1994/07/22  14:11:39  Kirk
 * removed FILTER_STRING
 *
 * Revision 1.3  1994/07/12  00:11:12  Jof
 * *** empty log message ***
 *
 * Revision 1.2  1994/01/18  01:05:19  mud
 * *** empty log message ***
 *             
 */                            

#ifndef __DEFINES_H__
#define __DEFINES_H__

#ifndef ME
#define ME this_object()
#endif

#ifndef PL
#define PL this_player()
#endif

#ifndef RPL
#define RPL this_interactive()
#endif

#ifndef CAP
#define CAP(str) capitalize(str)
#endif

#ifndef QPP
#define QPP QueryPossPronoun
#endif

// #ifndef IS_CLONE
// #define IS_CLONE(ob) (sizeof(explode(object_name(ob),"#"))>1)
// #endif
// 
// #ifndef IS_BLUE
// #define IS_BLUE(ob) (sizeof(explode(object_name(ob),"#"))==1)
// #endif
// obsolet, nur aus Kompatibilitaetsgruenden noch vorhanden
#ifndef IS_CLONE
#define IS_CLONE(ob) (clonep(ob))
#endif

// obsolet, nur aus Kompatibilitaetsgruenden noch vorhanden
#ifndef IS_BLUE
#define IS_BLUE(ob) (!clonep(ob))
#endif

#ifndef BLUE_NAME
#define BLUE_NAME(ob) load_name(ob)
//#define BLUE_NAME(ob) (explode(object_name(ob),"#")[0])
#endif

#ifndef MAX
#define MAX(a,b) (((a)>(b))?(a):(b))
#endif

#ifndef ENVCHECKPROC
#define ENVCHECKPROC \
  void EnvCheckProc() \
  { \
    if (!environment()) \
    { \
      ::remove(); \
      if (this_object()) \
	destruct(this_object()); \
    }\
  }

#define ENVCHECK \
 if (clonep(this_object())) \
   call_out("EnvCheckProc",5);
#endif

#define BS_LEAVE_MY_LFS 	1
#define BS_SINGLE_SPACE         2
#define BS_BLOCK		4
#define BS_NO_PARINDENT		8
#define BS_INDENT_ONCE         16
#define BS_PREPEND_INDENT      32
 
 // Defines fuer match_living(S)
#define MATCH_PLAYER            1
#define MATCH_NO_DOUBLES        2
#define MATCH_OBJS              4
#define MATCH_NO_INVIS          8
#define MATCH_PLAYER_FIRST     16
 
#define CATCH_NOLOG(x) catch((x) ; nolog)

#endif /* __DEFINES_H__ */

