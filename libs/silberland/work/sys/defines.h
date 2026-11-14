// SilberLand MUDlib
//
// sys/defines.h -- some useful defines
//
// $Date: 2000/11/07 00:14:54 $
/* $Revision: 1.11 $
 * $Log: defines.h,v $
 * Revision 1.11  2000/11/07 00:14:54  Woody
 * REAL_UID() und REAL_EUID() fuer UID-Umstellung
 *
 * Revision 1.10  1999/03/10 21:15:27  Woody
 * neu: BLUE_NAME, optimiert: IS_CLONE/IS_BLUE
 *
 * Revision 1.9  1999/03/01 17:55:44  Woody
 * BS_INDENT_ONCE eingefuegt
 *
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

#define REAL_UID(x)   (efun::explode(getuid(x),  ".")[<1])
#define REAL_EUID(x)  (efun::explode(geteuid(x), ".")[<1])

#ifndef IS_CLONE
#define IS_CLONE(ob) (member(file_name(ob),'#')>=0)
#endif

#ifndef IS_BLUE
#define IS_BLUE(ob) (strstr(file_name(ob),"#")==-1)
#endif

#ifndef BLUE_NAME
#define BLUE_NAME(ob) (efun::explode(file_name(ob), "#")[0])
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
 if (is_clone(this_object())) \
   call_out("EnvCheckProc",5);
#endif

#define BS_LEAVE_MY_LFS   1
#define BS_BLOCK          2
#define BS_NO_PARINDENT   4
#define BS_SINGLE_SPACE   8
#define BS_INDENT_ONCE   16

#endif /* __DEFINES_H__ */

