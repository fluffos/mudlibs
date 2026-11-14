// SilberLand MUDlib
//
// sys/functionlist.h -- functionlist header
//
// $Date: 1997/03/31 12:53:46 $
/* $Revision: 1.1 $
 * $Log: functionlist.h,v $
 * Revision 1.1  1997/03/31 12:53:46  Woody
 * prepared for revision control
 *
 */

#ifndef __FUNCTIONLIST_H__
#define __FUNCTIONLIST_H__

#include "/sys/lpctypes.h"

#define RETURN_FUNCTION_NAME	0x01
#define RETURN_FUNCTION_FLAGS	0x02
#define RETURN_FUNCTION_TYPE	0x04
#define RETURN_FUNCTION_NUMARG	0x08
#define RETURN_FUNCTION_ARGTYPE 0x10 /* not implemented */

#define NAME_INHERITED          0x80000000 /* Defined by inheritance         */
#define TYPE_MOD_STATIC         0x40000000 /* Static function or variable    */
#define TYPE_MOD_NO_MASK        0x20000000 /* The nomask => not redefineable */
#define TYPE_MOD_PRIVATE        0x10000000 /* Can't be inherited             */
#define TYPE_MOD_PUBLIC         0x08000000 /* Force inherit through private  */
#define TYPE_MOD_VARARGS        0x04000000 /* Used for type checking         */
#define TYPE_MOD_PROTECTED      0x01000000 /* cannot be called externally    */
#define NAME_HIDDEN             0x00000800 /* Not visible for inheritance    */
#define NAME_UNDEFINED          0x00000200 /* Not defined yet                */

#endif /* __FUNCTIONLIST_H__ */

