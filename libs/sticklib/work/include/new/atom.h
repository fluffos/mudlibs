/*
 * atom.h - include this to get standard object.
 *
 * See /std/atom.c for more information.
 *
 */
 
 
#infdef ATOM_MASTER_INCLUDE
public inherit "/std/atom";
#endif
 
 
#ifndef _ATOM_H
#define _ATOM_H
 
#include "properties.h"
#include "move_failures.h"
 
#define QUERY_NO_VBFC		1
#define QUERY_VBFC_STRING	2
#define QUERY_FULL_PROP		3
 
#define CODER_ID_ALWAYS_TRUE	"coder_id_always_true"
 
#define set_lock()		(obj_Locked = 1)
#define remove_lock()		(obj_Locked = 0)
 
#endif /* _ATOM_H */
 
 
