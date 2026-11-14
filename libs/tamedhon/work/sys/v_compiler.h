// SilberLand MUDlib
//
// sys/v_compiler.h -- standard VC header
//
// $Date: 1997/03/31 14:00:08 $
/* $Revision: 1.1 $
 * $Log: v_compiler.h,v $
 * Revision 1.1  1997/03/31 14:00:08  Woody
 * prepared for revision control
 *
 * Revision 1.0  1994/03/24  21:26:37  Hate
 * added QueryObjects(); prototype
 *
 */

#ifndef __V_COMPILER_H__
#define __V_COMPILER_H__

#define P_STD_OBJECT    "std_object"
#define P_COMPILER_PATH "compiler_path"

#endif // __V_COMPILER_H__

#ifdef NEED_PROTOTYPES

#ifndef __V_COMPILER_H_PROTO__
#define __V_COMPILER_H_PROTO__

// to validate if the file name is in our range
string Validate(string file);

// sets costumization data in the cloned object
mixed CustomizeObject();

// this functions is called when a file is not found and may be virtual
mixed compile_object(string file);

// to get all yet cloned (and not cleaned up) objects
mixed QueryObjects();

#endif // __V_COMPILER_H_PROTO__

#endif NEED_PROTOTYPES
