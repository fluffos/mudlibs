// SilberLand MUDlib
//
// sys/actions.h -- restricted action handler
//
// $Date: 1997/03/31 12:23:59 $
/* $Revision: 1.1 $
 * $Log: actions.h,v $
 * Revision 1.1  1997/03/31 12:23:59  Woody
 * prepared for revision control
 *
 * 30.08.1995	16:00	Mupfel
 * 08.03.1996	03:00	Mupfel	UndoAction
 */
 
#ifndef __ACTIONS_H__
#define __ACTIONS_H__

// no properties

// no special defines

#endif // __ACTIONS_H__

#ifdef NEED_PROTOTYPES

#ifndef __ACTIONS_H_PROTO__
#define __ACTIONS_H_PROTO__

// prototypes

int ActionAllowed(object player);
void UndoAction(object player);

#endif // __ACTIONS_H_PROTO__

#endif // NEED_PROTOTYPES

